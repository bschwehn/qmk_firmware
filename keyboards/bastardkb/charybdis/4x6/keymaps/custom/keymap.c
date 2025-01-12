#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_uk.h"
#include "keys.h"
#include <stdio.h>
#include "features/achordion.h"
#include "features/layer_lock.h"
#include "features/mouse_turbo_click.h"


#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif // CONSOLE_ENABLE

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
    LR_EXTRAS
};

enum tap_dance_codes {
    DANCE_SCROLLLEAD,
    DANCE_4,
    DANCE_6,
    DANCE_7,
    DANCE_8,
    DANCE_9,
    DANCE_10,
    DANCE_11,
    DANCE_12,
};
/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LR_POINTER

static uint16_t auto_pointer_layer_timer = 0;
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define KC_BSPACE KC_BSPC
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
//#define LT_DQUO LT(LR_POINTER, UK_DQUO)
//#define LT_DQUO TD(DANCE_PT_DQUOT)
#define LT_DQUO CUSTOM_PT_DQUO

#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_R MT(MOD_LALT, KC_R)
#define HRM_S MT(MOD_LSFT, KC_S)
#define HRM_T MT(MOD_LCTL, KC_T)
#define HRM_G MT(MOD_RALT, KC_G)

#define HRM_M MT(MOD_RALT, KC_M)
#define HRM_N MT(MOD_LCTL, KC_N)
#define HRM_E MT(MOD_RSFT, KC_E)
#define HRM_I MT(MOD_LALT, KC_I)
#define HRM_O MT(MOD_RGUI, KC_O)

//#define AL_BSPC MT(MOD_LCTL, KC_BSPC)
#define AL_BSPC LT(LR_EXTRAS, KC_BSPC)
#define TD_ENT TD(DANCE_12)
// #define AL_THMB3 MT(MOD_LSFT, KC_ENT)
#define AL_THMB3 TD(DANCE_12)

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

#include "g/keymap_combo.h"

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LR_POINTER);
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif     // POINTING_DEVICE_ENABLE
void leave_pointer_layer() {
    auto_pointer_layer_timer = 0;
    layer_off(LR_POINTER);
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
#endif // RGB_MATRIX_ENABLE
}

void custom_matrix_scan_user(void) {
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE_AUTO_LEAVE
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        leave_pointer_layer();
    }
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
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
    // combos are on 0/0, need  to work with hold
    if (other_record->event.key.row == 0 && other_record->event.key.col == 0) return true;
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
#ifdef ACHORDION_COOLDOWN
    if (!record->event.pressed) {
        save_keystroke_time(keycode, record);
    }
#endif
    if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    uint8_t mod_state = get_mods();
    static bool is_shifted;
    is_shifted = get_mods() & MOD_MASK_SHIFT;
    static uint16_t dquo_timer;
    if (record->event.pressed) {
        dprintln("press");
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
        case CUSTOM_ESC:
            uint8_t layer = biton32(layer_state);
            uint8_t highlayer = get_highest_layer(layer_state);

            dprintln("custom esc");
            dprintf("layer: %d high %d\n pointer: %d",
                    layer, highlayer, LR_POINTER);
            if (highlayer == LR_POINTER) {
                leave_pointer_layer();
            }
            else if (layer > 0) {
                leave_pointer_layer();
                layer_move(0);
            } else {
                tap_code16(KC_ESC);
            }
            return false;
        case CUSTOM_EMPROP:
            SEND_STRING(SS_TAP(X_NUHS) SS_TAP(X_KP_PLUS));
            return false;
        case CUSTOM_DARROW:
            SEND_STRING("=>");
            return false;
        case CUSTOM_ARROW:
            SEND_STRING("->");
            return false;
        case CUSTOM_HTTPS:
            SEND_STRING("https://");
            return false;
        case CUSTOM_VIMSAVE:
            SEND_STRING(":w\n");
            return false;
        }
    }
    switch (keycode) {
    case CUSTOM_PT_DQUO:
        if (record->event.pressed) {
            dquo_timer = timer_read();
            layer_on(LR_POINTER);  //turn on layer 7
        } else {
            layer_off(LR_POINTER);  //turn off layer 7
            if (timer_elapsed(dquo_timer) < TAPPING_TERM) {
                if (is_shifted) {
                    tap_code16(UK_UNDS);
                }
                else {
                    tap_code16(UK_DQUO);
                }
            }
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
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LR_BASE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮           ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               KC_6,    KC_0,    KC_8,    KC_9,    KC_0,   KC_BTN1,
  // ├──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    LT_F,    LT_P,    KC_B,               KC_J,    LT_L,    LT_U,    KC_Y,    UK_COLN, LT_DQUO,
  // ├──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────┤
       KC_ESC,    HRM_A,   HRM_R,   HRM_S,   HRM_T,   HRM_G,               HRM_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,  QK_ALT_REPEAT_KEY,
  // ├──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────┤
        KC_LCTL,    LT_Z,    LT_X,    LT_C,    LT_D,    KC_V,               KC_K,    LT_H,  LT_COMMA, KC_DOT,  UK_DQUO, TT(LR_POINTER), //TT not working for some reason
  // ╰──────────────────────────────────────────────────────┤           ├──────────────────────────────────────────────────────╯
        AL_BSPC, KC_SPC,   AL_THMB3,      QK_LEAD,  AL_BSPC,
        MT(MOD_LCTL, KC_DEL), LLOCK,     QK_REPEAT_KEY
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LR_BRACES] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD,/*TURBO*/KC_NA,UK_BSLS,UK_LABK,UK_RABK,UK_PERC,  UK_AT, UK_QUES, UK_PIPE, UK_ASTR, UK_GRV, KC_NA,
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
                                  // LCTL(KC_Z), KC_HOME, LSFT(KC_INSERT), KC_PGDN,
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    KC_DOWN, KC_RIGHT, LSFT(KC_INSERT), LCTL(KC_INSERT), LSFT(KC_DELETE), KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PAUSE, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    KC_UP, KC_LEFT, KC_APP, KC_SCRL, KC_INSERT, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
                                           KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_FUN] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MNXT, LSFT(KC_TAB)  , KC_F1, KC_F2, KC_F3, KC_F10,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPLY, KC_TAB        , KC_F4, KC_F5, KC_F6, KC_F11,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_MPRV, KC_APPLICATION, KC_F7, KC_F8, KC_F9, KC_F12,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_VOLD,
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
                KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    QK_BOOT, QK_REBOOT, KC_NA, KC_NA, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    S_D_MOD, S_D_RMOD, DPI_MOD, DPI_RMOD, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_NA, KC_BTN1, KC_BTN2, KC_BTN3, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NA, _______, DRGSCRL, SNIPING, KC_NA, KC_NA,    KC_NA, KC_NA, SNIPING, DRGSCRL, KC_NA, KC_NA,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           KC_NA, KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LR_EXTRAS] = LAYOUT_charybdis_4x6(
    // note: MT from base works if pressed earlier, MT not working with custom keys
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA, KC_NA, KC_NA, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_NA, KC_NA, CUSTOM_UUML, KC_NA, KC_NA, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, CUSTOM_AUML, KC_LALT, KC_LSFT, KC_LCTL, KC_NA,    KC_NA, CUSTOM_DARROW, KC_LSFT, KC_LALT, CUSTOM_OUML, KC_NA,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,    KC_NA, CUSTOM_HTTPS, CUSTOM_ARROW, KC_NA, CUSTOM_EMPROP, KC_NA,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NA, KC_NA, KC_NA,    KC_NA, KC_NA,
                                           KC_NA, KC_NA,    KC_NA
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on


layer_state_t layer_state_set_user(layer_state_t state) {
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
    /* |RGB                  |HSV                  | */
    /*      |---------------------|---------------------| */
    /*      |`RGB_AZURE`          |`HSV_AZURE`          | */
    /*      |`RGB_BLACK`/`RGB_OFF`|`HSV_BLACK`/`HSV_OFF`| */
    /*      |`RGB_BLUE`           |`HSV_BLUE`           | */
    /*      |`RGB_CHARTREUSE`     |`HSV_CHARTREUSE`     | */
    /*      |`RGB_CORAL`          |`HSV_CORAL`          | */
    /*      |`RGB_CYAN`           |`HSV_CYAN`           | */
    /*      |`RGB_GOLD`           |`HSV_GOLD`           | */
    /*      |`RGB_GOLDENROD`      |`HSV_GOLDENROD`      | */
    /*      |`RGB_GREEN`          |`HSV_GREEN`          | */
    /*      |`RGB_MAGENTA`        |`HSV_MAGENTA`        | */
    /*      |`RGB_ORANGE`         |`HSV_ORANGE`         | */
    /*      |`RGB_PINK`           |`HSV_PINK`           | */
    /*      |`RGB_PURPLE`         |`HSV_PURPLE`         | */
    /*      |`RGB_RED`            |`HSV_RED`            | */
    /*      |`RGB_SPRINGGREEN`    |`HSV_SPRINGGREEN`    | */
    /*      |`RGB_TEAL`           |`HSV_TEAL`           | */
    /*      |`RGB_TURQUOISE`      |`HSV_TURQUOISE`      | */
    /*      |`RGB_WHITE`          |`HSV_WHITE`          | */
    /*      |`RGB_YELLOW`         |`HSV_YELLOW`         | */
    uint8_t high_layer = get_highest_layer(state);
    dprintln("layer switch");
    dprintf("high %d\n pointer: %d",
            high_layer, LR_POINTER);

    switch (high_layer) {
        case LR_NAV:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_CORAL);
            break;
        case LR_NUM:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GOLD);
            break;
        case LR_BRACES:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
            // currently pointer layer is activated on press instead of normal layer toggle
            // due to issues with lt and special chararcters -- need better solution or
            // keybord blinks whenever I hit "
        /* case LR_POINTER: */
        /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE); */
        /*     rgb_matrix_sethsv_noeeprom(HSV_TEAL); */
        /*     break; */
        case LR_FUN:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
        default: // for any other layers, or the default layer
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
            break;
        }
        return state;
}

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
    case MC_0:
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

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
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

void on_dance_scroll(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(QK_LEAD);
        tap_code16(QK_LEAD);
        tap_code16(QK_LEAD);
    }
    if(state->count > 3) {
        tap_code16(QK_LEAD);
    }
}

void dance_scroll_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SCROLLLEAD].step = dance_step(state);
    switch (dance_state[DANCE_SCROLLLEAD].step) {
        case SINGLE_TAP: register_code16(QK_LEAD); break;
    case SINGLE_HOLD: register_code16(DRGSCRL); dprintln("reg crgscrl"); break;
        case DOUBLE_TAP: register_code16(QK_LEAD); register_code16(QK_LEAD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(QK_LEAD); register_code16(QK_LEAD);
    }
}

void dance_scroll_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SCROLLLEAD].step) {
        case SINGLE_TAP: unregister_code16(QK_LEAD); break;
        case SINGLE_HOLD: unregister_code16(UK_MINS); break;
        case DOUBLE_TAP: unregister_code16(QK_LEAD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(QK_LEAD); break;
    }
    dance_state[DANCE_SCROLLLEAD].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(UK_MINS); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(UK_MINS); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[4].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
        tap_code16(UK_COLN);
    }
    if(state->count > 3) {
        tap_code16(UK_COLN);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(UK_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(UK_COLN); register_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_COLN); register_code16(UK_COLN);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(UK_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(UK_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_COLN); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
        tap_code16(UK_LCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_LCBR);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(UK_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(UK_LCBR); register_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_LCBR); register_code16(UK_LCBR);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(UK_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(UK_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_LCBR); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
        tap_code16(UK_RCBR);
    }
    if(state->count > 3) {
        tap_code16(UK_RCBR);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(UK_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
        case DOUBLE_TAP: register_code16(UK_RCBR); register_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_RCBR); register_code16(UK_RCBR);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(UK_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code16(UK_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_RCBR); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
        tap_code16(UK_AMPR);
    }
    if(state->count > 3) {
        tap_code16(UK_AMPR);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(UK_AMPR); break;
        case SINGLE_HOLD: register_code16(KC_RSFT); break;
        case DOUBLE_TAP: register_code16(UK_AMPR); register_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_AMPR); register_code16(UK_AMPR);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(UK_AMPR); break;
        case SINGLE_HOLD: unregister_code16(KC_RSFT); break;
        case DOUBLE_TAP: unregister_code16(UK_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_AMPR); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
    }
    if(state->count > 3) {
        tap_code16(UK_DLR);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(UK_DLR); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(UK_DLR); register_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DLR); register_code16(UK_DLR);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(UK_DLR); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DLR); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPC);
        tap_code16(KC_SPC);
        tap_code16(KC_SPC);
    }
    if(state->count > 3) {
        tap_code16(KC_SPC);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_SPC); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(KC_ENT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPC); register_code16(KC_SPC);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_SPC); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(KC_ENT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPC); break;
    }
    dance_state[12].step = 0;

}

void on_dance_scroll(tap_dance_state_t *state, void *user_data);

void dance_scroll_finished(tap_dance_state_t *state, void *user_data);
void dance_scroll_reset(tap_dance_state_t *state, void *user_data);



tap_dance_action_t tap_dance_actions[] = {
    [DANCE_SCROLLLEAD] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_scroll, dance_scroll_finished, dance_scroll_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};

void matrix_scan_user(void) {
    custom_matrix_scan_user();
}
// custom
#ifdef LEADER_ENABLE
void leader_end_set_rgb(void) {
    rgb_matrix_sethsv_noeeprom(HSV_RED);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
}
void leader_end_user(void) {
    leader_end_set_rgb();
    if (leader_sequence_one_key(KC_BSPACE)) {
        tap_code(KC_BSPACE);
    }
    else if (leader_sequence_one_key(KC_A)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("1"))));
    }
    else if  (leader_sequence_one_key(KC_R)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("2"))));
    }
    else if  (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("3"))));
    }
    else if  (leader_sequence_one_key(KC_T)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("4"))));
    }
    else if  (leader_sequence_one_key(KC_G)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("5"))));
    }
    else if  (leader_sequence_one_key(KC_M)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("6"))));
    }
    else if  (leader_sequence_one_key(KC_N)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("7"))));
    }
    else if  (leader_sequence_one_key(KC_E)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("8"))));
    }
    else if  (leader_sequence_one_key(KC_I)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("9"))));
    }
    else if  (leader_sequence_one_key(KC_O)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("0"))));
    }
    else if  (leader_sequence_two_keys(KC_A, KC_A)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("a"))));
    }
    else if (leader_sequence_two_keys(KC_R, KC_R)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("r"))));
    }
    else if (leader_sequence_two_keys(KC_S, KC_S)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("s"))));
    }
    else if (leader_sequence_two_keys(KC_T, KC_T)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("t"))));
    }
    else if (leader_sequence_two_keys(KC_G, KC_G)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("g"))));
    }
    else if (leader_sequence_two_keys(KC_M, KC_M)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("m"))));
    }
    else if (leader_sequence_two_keys(KC_N, KC_N)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("n"))));
    }
    else if (leader_sequence_two_keys(KC_E, KC_E)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("e"))));
    }
    else if (leader_sequence_two_keys(KC_I, KC_I)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("i"))));
    }
    else if (leader_sequence_two_keys(KC_O, KC_O)) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_LALT("o"))));
    }
    else if (leader_sequence_two_keys(KC_S, KC_R)) {
        tap_code(KC_SCROLL_LOCK);
    }
    else if (leader_sequence_two_keys(KC_S, KC_P)) {
        tap_code(KC_PSCR);
    }
    else if (leader_sequence_two_keys(KC_S, KC_I)) {
        tap_code(KC_INSERT);
    }
    else if (leader_sequence_two_keys(KC_S, KC_H)) {
        tap_code(KC_HOME);
    }
    else if (leader_sequence_two_keys(KC_S, KC_E)) {
        tap_code(KC_END);
    }
    else if (leader_sequence_two_keys(KC_S, KC_U)) {
        tap_code(KC_PAGE_UP);
    }
    else if (leader_sequence_two_keys(KC_S, KC_D)) {
        tap_code(KC_PAGE_DOWN);
    }
    else if (leader_sequence_two_keys(KC_S, KC_N)) {
        tap_code(KC_NUM_LOCK);
    }
    else if (leader_sequence_two_keys(KC_S, KC_C)) {
        tap_code(KC_CAPS_LOCK);
    }
    else if (leader_sequence_two_keys(KC_S, KC_A)) {
        tap_code(KC_APPLICATION);
    }
    else if (leader_sequence_two_keys(KC_S, KC_B)) {
        tap_code(KC_PAUSE);
    }
    else if (leader_sequence_three_keys(KC_S, KC_B, KC_B)) {
        register_code(KC_LCTL);
        tap_code(KC_PAUSE);
        unregister_code(KC_LCTL);
    }
    else if (leader_sequence_two_keys(KC_Q, KC_Q)) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
    }
    // note: need to press leader while in braces layer already
    else if (leader_sequence_one_key(UK_QUES)) {
        SEND_STRING("Home row single: Gui+C+Alt+ 1-0\n "
                    "Home row double: Gui+C+Alt+letter\n"
                    "S,R: scroll lock\n "
                    "S,P: print screen\n "
                    "S,H: home\n "
                    "S,E: end\n "
                    "S,I: insert\n "
                    "S,U: page up\n "
                    "S,D: page down\n "
                    "S,N: num lock\n "
                    "S,C: caps lock\n "
                    "S,H: home\n "
                    "Q,Q: Alt+F4\n "
                    "?: help\n "
                    "S,B: Break\n "
                    "S,B,B: C+Break\n");
    }
    // does not seem to work actually
    else if (leader_sequence_four_keys(KC_B, KC_O, KC_O, KC_T)) {
        tap_code16(QK_BOOT);
    }
}
void leader_start_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    rgb_matrix_sethsv_noeeprom(HSV_PINK);
}
#endif

const key_override_t apo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUOTE);
const key_override_t dash_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(LR_BRACES,KC_COMMA), UK_MINS);
const key_override_t dquote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_DQUO, UK_UNDS);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_COLN, UK_SCLN);
//const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_COLN, UK_UNDS);

//#define LT_DQUO LT(LR_POINTER, UK_DQUO)
// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &apo_key_override,
    &dash_key_override,
    &dquote_key_override,
    &coln_key_override,
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
// TODO: not sure if this is still used, maybe replaced with QUICK_TAP_TERM
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

void keyboard_post_init_user(void) {
    debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    ///debug_mouse=true;
}
