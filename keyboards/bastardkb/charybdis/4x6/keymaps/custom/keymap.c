#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keys.h"
#include <stdio.h>
#include "features/achordion.h"
#include "features/layer_lock.h"
#include "features/repeat.h"
#include "features/mouse_turbo_click.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LR_BASE = 0,
    LR_BRACES,
    LR_NAV,
    LR_FUN,
    LR_NUM,
    LR_POINTER,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LR_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define KC_NA KC_TRANSPARENT
#define LOWER MO(LR_BRACES)
#define RAISE MO(LR_NAV)
#define PT_Z LT(LR_POINTER, KC_Z)
#define PT_SLSH LT(LR_POINTER, KC_SLSH)

#define LT_F LT(LR_NUM, KC_F)
#define LT_P LT(LR_NUM, KC_P)
#define LT_L LT(LR_FUN, KC_L)
#define LT_U LT(LR_FUN, KC_U)
//#define LT_APO KC_QUOTE // was td4
#define LT_APO TD(DANCE_4)
#define LT_Z LT(LR_NAV, KC_Z)
#define LT_X LT(LR_NAV, KC_X)
#define LT_C LT(LR_BRACES, KC_C)
#define LT_D LT(LR_BRACES, KC_D)
#define LT_H LT(LR_BRACES, KC_H)
#define LT_COMMA LT(LR_BRACES, KC_COMMA)
#define LT_DQUO LT(LR_POINTER, UK_DQUO)

#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_R MT(MOD_LALT, KC_R)
#define HRM_S MT(MOD_LSFT, KC_S)
#define HRM_T MT(MOD_LCTL, KC_T)

#define HRM_N MT(MOD_LCTL, KC_N)
#define HRM_E MT(MOD_RSFT, KC_E)
#define HRM_I MT(MOD_LALT, KC_I)
#define HRM_O MT(MOD_RGUI, KC_O)


//#define HRM_COLN MT(MOD_LGUI, UK_COLN) // td 6
#define HRM_COLN TD(DANCE_6) // td 6
#define HRM_SCLN MT(MOD_LALT, UK_SCLN)
//#define HRM_LCBR MT(MOD_LSFT, UK_LCBR) // td 7
#define HRM_LCBR TD(DANCE_7) // td 7
//#define HRM_RCBR MT(MOD_LCTL, UK_RCBR) // td 8
#define HRM_RCBR TD(DANCE_8) // td 8

#define HRM_EQ MT(MOD_LCTL, UK_EQL)
//#define HRM_AMPR MT(MOD_RSFT, UK_AMPR) //td 9
#define HRM_AMPR TD(DANCE_9) //td 9
//#define HRM_DLR MT(MOD_LALT, UK_DLR) // td 10
#define HRM_DLR TD(DANCE_10) // td 10
#define HRM_MINS MT(MOD_RGUI, UK_MINS)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LR_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

void custom_matrix_scan_user(void) {
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LR_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
    achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 600;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
        return true;  // Eagerly apply Shift and Ctrl mods.

    default:
        return false;
    }
}
#ifdef ACHORDION_COOLDOWN
static int32_t last_stroke_time;
// save last release time, so we can check when making a tap/hold
// decision later on. I thought about using the last
// N key strokes, or current WPM, but just the single delta
// between last release and current potential mod tap seems
// to be sufficient
void save_keystroke_time(uint16_t keycode,
                        const keyrecord_t* record) {

       last_stroke_time = timer_read32();
       //    last_stroke_time = record->event.time;
    dprintf("cooldown: Key 0x%04X released at %ld\n",
            keycode, last_stroke_time);
}

// prevent accidental activation of ctrl, alt, gui chords
// when typing fast (and sloppy).
// I don't have accidental activation often, but if it happens,
// it can be quite annoying as I seem to trigger GUI+r and GUI+e most
// often, which triggers layout functions in i3wm.
// accidental activation of shift or a LT key is not nearly as bad,
// it just causes a normal typo, and I want to type them fast,
// so not changing their behaviour here
bool achordion_cooldown(uint16_t tap_hold_keycode,
const keyrecord_t* tap_hold_record) {
    // I initially used tap_hold_record->event.time, but due to the uint16 overflow,
    // I think this would trigger incorrectly with a probabilty of ACHORDION_COOLDOWN / 65535
    // with cooldown set to 150, this is 0.2%, which is quite high.
    // using timer_elapsed32 now, but need to substract the tapping term (I think)
    // as this method will not be called until the tapping_term is expired
    // that is, after event.time.
    // TAPPING_TERM is not really correct, as we can get here earlier due to
    // permissive hold. May be we should have one timer updated on every release and
    // a second on every press instead, but seems to work well enough.

    uint16_t last_stroke_16 = last_stroke_time % (2<<16);
    uint16_t event_delta = (tap_hold_record->event.time < last_stroke_16) ?
        last_stroke_16 - tap_hold_record->event.time :
        tap_hold_record->event.time - last_stroke_16;

    int32_t delta = timer_elapsed32(last_stroke_time) - TAPPING_TERM;

    dprintf("cooldown: Key 0x%04X released at %d, delta: %ld, event_delta: %d\n",
            tap_hold_keycode, tap_hold_record->event.time, delta, event_delta);

    // if I was typing fast before the potential chord, as detected by the
    // delta to release time of the previous key, I prevent alt, gui
    // activation. I don't type those fast after a differnt key
    if (delta < ACHORDION_COOLDOWN) {
        const bool is_mt = QK_MOD_TAP <= tap_hold_keycode && tap_hold_keycode <= QK_MOD_TAP_MAX;
        if (is_mt) {
            uint8_t mod = (tap_hold_keycode >> 8) & 0x1f;
            switch (mod) {
                // while I use mostly vim keybindings, turns out I still use plenty of ctrl+
                // shortcuts
                // case MOD_LCTL:
                // case MOD_RCTL:
            case MOD_LGUI:
            case MOD_RGUI:
            case MOD_LALT:
                dprintf("cooldown: mod %d, applying cooldown\n",
                        mod);
                return true;  // Prevent accidental alt, win only.
            default:
                // I do use shift and ctrl during fast typing...
                dprintf("cooldown: mod %d, NOT applying cooldown\n",
                        mod);
                return false;
            }
        } else {
            // I do use layers during fast typing...
            dprintln("cooldown: not mod key, NOT applying cooldown");
        }
    }
    return false;
}
#endif

static bool custom_on_left_hand(keypos_t pos) {
    return pos.row < MATRIX_ROWS / 2;
}

bool custom_achordion_opposite_hands(const keyrecord_t* tap_hold_record,
                              const keyrecord_t* other_record) {
    return custom_on_left_hand(tap_hold_record->event.key)
        != custom_on_left_hand(other_record->event.key);
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    uint16_t row = tap_hold_record->event.key.row;

#ifdef ACHORDION_COOLDOWN
    bool within_cooldown = achordion_cooldown(tap_hold_keycode,tap_hold_record);
    if (within_cooldown) {
        dprintln("cooldown: within cooldown, should tap");
        return false;
    }
#endif

    // holding key on thumb or bottom cow
    if (row == 4 || row == 9) return true;
    row = other_record->event.key.row;
    // other key on thumb
    if (row == 4 || row == 9) return true;
    if (other_keycode == LLOCK) return true;
    return custom_achordion_opposite_hands(tap_hold_record, other_record);
}
static bool is_caps_word = false;
void caps_word_set_user(bool active) {
    is_caps_word = active;
}
bool send_grave_with_caps_word(uint16_t keycode, uint16_t mod_state) {
    del_mods(MOD_MASK_SHIFT);
    if (is_caps_word) {
        del_weak_mods(MOD_BIT(KC_LSFT));
    }
    register_code(KC_RALT);
    register_code16(UK_2);
    unregister_code16(UK_2);
    unregister_code(KC_RALT);
    set_mods(mod_state);
    if (is_caps_word) {
        register_weak_mods(MOD_BIT(KC_LSFT));
    }
    tap_code(keycode);
    return false;
}

bool custom_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        save_keystroke_time(keycode, record);
    }
    if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    process_repeat_key(keycode, record);
    uint8_t mod_state = get_mods();
    static bool is_shifted;
    is_shifted = get_mods() & MOD_MASK_SHIFT;
    if (record->event.pressed) {
        switch (keycode) {
        case CUSTOM_QU:
            if (is_caps_word) {
                del_weak_mods(MOD_BIT(KC_LSFT));
                SEND_STRING("QU");
                register_weak_mods(MOD_BIT(KC_LSFT));
            } else if (is_shifted) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING("Qu");
                set_mods(mod_state);
            } else {
                SEND_STRING("qu");
            }
            return false;
        case CUSTOM_AUML:
            return send_grave_with_caps_word(KC_A, mod_state);
        case CUSTOM_UUML:
            return send_grave_with_caps_word(KC_U, mod_state);
        case CUSTOM_OUML:
            return send_grave_with_caps_word(KC_O, mod_state);
        case CUSTOM_BSPACE:
            tap_code(KC_BSPACE);
            return false;
        case CUSTOM_ENTER:
            tap_code(KC_ENTER);
            return false;
            return false;
        case CUSTOM_ESC:
            uint8_t layer = biton32(layer_state);
            if (layer > 0) {
                layer_move(0);
            } else {
                tap_code16(KC_ESC);
            }
            return false;
        }
    }
    return true;
}

__attribute__((weak)) bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case CUSTOM_QU ... CUSTOM_END_CAPS:
        register_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
        return true;

        // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_MINS:
    case KC_UNDS:
        return true;

    default:
        return false;  // Deactivate Caps Word.
    }
}
enum tap_dance_codes {
    DANCE_4,
    DANCE_6,
    DANCE_7,
    DANCE_8,
    DANCE_9,
    DANCE_10,
    DANCE_11,
    DANCE_12,
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LR_BASE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮           ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,
  // ├──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,               KC_J,    LT_L,    LT_U,    KC_Y,    LT_APO, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────┤
       KC_ESC,    HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_G,               KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,  KC_ENT,
  // ├──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────┤
        KC_LCTL,    LT_Z,    LT_X,    LT_C,    LT_D,    KC_V,               KC_K,    LT_H,  LT_COMMA, KC_DOT,  LT_DQUO, PT_SLSH,
  // ╰──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────╯
        KC_SPC, KC_SPC,   LOWER,      KC_LEAD,  KC_BSPACE,
        KC_DEL, LLOCK,     CUSTOM_REPEAT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LR_BRACES] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD,/*TURBO*/KC_NA,UK_BSLS,UK_LABK,UK_RABK,UK_PERC,  UK_AT, UK_QUES, UK_PIPE, UK_ASTR, UK_GRV, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG,HRM_COLN,HRM_SCLN,HRM_LCBR,HRM_RCBR,UK_PLUS,     UK_CIRC, HRM_EQ, HRM_AMPR, HRM_DLR, HRM_MINS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_RMOD, UK_LPRN, UK_RPRN, UK_LBRC, UK_RBRC, UK_MINS,   UK_TILD, UK_EXLM, UK_UNDS, UK_SLSH, UK_HASH, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
       /*LLOCK*/
       KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
       KC_NA, KC_NA, KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LR_NAV] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    LCTL(KC_Z), LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),LCTL(KC_Y), KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PAUSE, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INSERT, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
                                           KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_FUN] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT, LSFT(KC_TAB)  , KC_F1, KC_F2, KC_F3, KC_F10,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY, KC_TAB        , KC_F4, KC_F5, KC_F6, KC_F11,    XXXXXXX, KC_NA, KC_NA, KC_NA, KC_NA, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV, KC_APPLICATION, KC_F7, KC_F8, KC_F9, KC_F12,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
        KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
        KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_NUM] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,      UK_0,    UK_1,    UK_2,    UK_3,   TD(DANCE_11), KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_KP_MINUS, UK_4,  UK_5,    UK_6,   KC_KP_DOT, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_KP_PLUS , UK_7,  UK_8,    UK_9,   KC_COMMA, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
        KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
        KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LR_POINTER] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EEP_RST, QK_BOOT,    QK_BOOT, EEP_RST, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on


#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    #endif
if (!custom_record_user(keycode, record)) { return false; }
  switch (keycode) {
    case MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
  }

  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[13];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(UK_MINS); break;
        case DOUBLE_TAP: register_code16(KC_QUOTE); register_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(UK_MINS); break;
        case DOUBLE_TAP: unregister_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[4].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
    }
    if(state->count > 3) {
        tap_code16(UK_COLN);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(UK_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(UK_COLN); register_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_COLN); register_code16(UK_COLN);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(UK_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_COLN); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_LCBR);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(UK_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(UK_LCBR); register_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LCBR); register_code16(UK_LCBR);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(UK_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LCBR); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_RCBR);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(UK_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(UK_RCBR); register_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_RCBR); register_code16(UK_RCBR);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(UK_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_RCBR); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
    }
    if(state->count > 3) {
        tap_code16(UK_AMPR);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(UK_AMPR); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: register_code16(UK_AMPR); register_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_AMPR); register_code16(UK_AMPR);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(UK_AMPR); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: unregister_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_AMPR); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
    }
    if(state->count > 3) {
        tap_code16(UK_DLR);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(UK_DLR); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(UK_DLR); register_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DLR); register_code16(UK_DLR);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(UK_DLR); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DLR); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[12].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};

// custom
#ifdef LEADER_ENABLE
LEADER_EXTERNS();
void matrix_scan_user(void) {
    custom_matrix_scan_user();
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // Replace the sequences below with your own sequences.
        SEQ_ONE_KEY(KC_T) {
            // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
            SEND_STRING(SS_LCTRL(SS_LSFT("t")));
        }
        // Note: This is not an array, you don't need to put any commas
        // or semicolons between sequences.
        SEQ_TWO_KEYS(KC_S, KC_P) {
            tap_code(KC_PSCREEN);
        }
        SEQ_TWO_KEYS(KC_S, KC_B) {
            tap_code(KC_PAUSE);
        }
        SEQ_THREE_KEYS(KC_S, KC_B, KC_B) {
            register_code(KC_LCTRL);
            tap_code(KC_PAUSE);
            unregister_code(KC_LCTRL);
        }
        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
  }
}
#endif
enum combos {
    WF_ESC,
    WF_ESC10,
    WF_ESC3,
    XC_ENTER,
    ZX_BSPC,
    FP_Q,
    V_A,
    V_U,
    V_O,
    UY_ENTER,
    SLEEP,
    APP,
    TAB,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

// const uint16_t PROGMEM esc_combo[] = {MT(MOD_LGUI, KC_A), MT(MOD_LCTL, KC_T), COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, LT(4,KC_F), COMBO_END};
const uint16_t PROGMEM esc_combo10[] = {KC_F1, KC_F2, COMBO_END};
//const uint16_t PROGMEM esc_combo10[] = {KC_TAB, KC_F6, COMBO_END};
const uint16_t PROGMEM esc_combo3[] = {UK_BSLS, UK_LABK, COMBO_END};
//const uint16_t PROGMEM esc_combo3[] = {TD(DANCE_8), TD(DANCE_10), COMBO_END};
const uint16_t PROGMEM q_combo[] = {LT(4,KC_F),     LT(4,KC_P), COMBO_END};
const uint16_t PROGMEM auml_combo[] = {MT(MOD_LGUI, KC_A), KC_V, COMBO_END};
const uint16_t PROGMEM uuml_combo[] = {LT(3,KC_U), KC_V, COMBO_END};
const uint16_t PROGMEM ouml_combo[] = {MT(MOD_RGUI, KC_O), KC_V, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {LT(2,KC_Z), LT(2,KC_X), COMBO_END};
const uint16_t PROGMEM enter_left_combo[] = {LT(2,KC_X), LT(1,KC_C), COMBO_END};
const uint16_t PROGMEM enter_combo[] = {LT(3,KC_U), KC_Y, COMBO_END};
const uint16_t PROGMEM sleep_combo[] = {KC_Q, KC_SPACE, COMBO_END};
const uint16_t PROGMEM app_combo[] = {KC_DOT, UK_DQUO, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W,  COMBO_END};

combo_t key_combos[] = {
    [WF_ESC] = COMBO(esc_combo, CUSTOM_ESC),
    [WF_ESC10] = COMBO(esc_combo10, CUSTOM_ESC),
    [WF_ESC3] = COMBO(esc_combo3, CUSTOM_ESC),
    [FP_Q] = COMBO(q_combo, CUSTOM_QU),
    [V_A] = COMBO(auml_combo, CUSTOM_AUML),
    [V_U] = COMBO(uuml_combo, CUSTOM_UUML),
    [V_O] = COMBO(ouml_combo, CUSTOM_OUML),
    [ZX_BSPC] = COMBO(bspc_combo, CUSTOM_BSPACE),
    [UY_ENTER] = COMBO(enter_combo, CUSTOM_ENTER),
    [XC_ENTER] = COMBO(enter_left_combo, CUSTOM_ENTER),
    [SLEEP] = COMBO(sleep_combo, KC_SYSTEM_SLEEP),
    [APP] = COMBO(app_combo, KC_APPLICATION),
    [TAB] = COMBO(tab_combo, KC_TAB),
};

const key_override_t apo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUOTE);
const key_override_t dash_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(LR_BRACES,KC_COMMA), UK_MINS);
const key_override_t dquote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, UK_UNDS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&apo_key_override,
	&dash_key_override,
    &dquote_key_override,
	NULL // Null terminate the array of overrides!
};
#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(1,KC_C):
        // Immediately select the hold action when another key is pressed.
        return false;
    default:
        // Do not select the hold action when another key is pressed.
        return false;
    }
}
#endif
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MT(MOD_LSFT, KC_S):
    case MT(MOD_RSFT, KC_E):
    case LT(4,KC_F):
    case LT(4,KC_P):
    case LT(2,KC_Z):
    case LT(2,KC_X):
    case LT(1,KC_C):
    case LT(1,KC_D):
    case LT(1,KC_H):
    case LT(1,KC_COMMA):
        return true;
    default:
        return false;
    }
}
