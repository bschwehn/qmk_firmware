#include "features/achordion.h"
#include "features/layer_lock.h"
#include "keymap_uk.h"

enum charybdis_keymap_layers {
    LR_BASE = 0,
    LR_BRACES,
    LR_NAV,
    LR_FUN,
    LR_NUM,
    LR_POINTER,
};
enum custom_combo {
    CUSTOM_QU = SAFE_RANGE + 5,
    CUSTOM_AUML,
    CUSTOM_UUML,
    CUSTOM_OUML,
    CUSTOM_BSPC,
    CUSTOM_END_CAPS,
    CUSTOM_ESC,
    CUSTOM_ENTER,
    CUSTOM_PT_DQUO,
    CUSTOM_LAST
};

enum custom_ext {
    LLOCK = CUSTOM_LAST
};

void custom_matrix_scan_user(void) {
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

    /*uint16_t last_stroke_16 = last_stroke_time % (2<<16);
    uint16_t event_delta = (tap_hold_record->event.time < last_stroke_16) ?
        last_stroke_16 - tap_hold_record->event.time :
        tap_hold_record->event.time - last_stroke_16;

        */
    int32_t delta = timer_elapsed32(last_stroke_time) - TAPPING_TERM;

    /*  dprintf("cooldown: Key 0x%04X released at %d, delta: %ld, event_delta: %d\n",
            tap_hold_keycode, tap_hold_record->event.time, delta, event_delta);
            */

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
    dprintf("custom_on_left_hand: row %d col %d\n", pos.row, pos.col);
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
#ifdef ACHORDION_COOLDOWN
    bool within_cooldown = achordion_cooldown(tap_hold_keycode,tap_hold_record);
    if (within_cooldown) {
        dprintln("cooldown: within cooldown, should tap");
        return false;
    }
#endif
    uint16_t row = tap_hold_record->event.key.row;
    dprintf("achordion_chort: row %d\n", row);
    // holding key on thumb or buttom cow
    if (row == 3 || row == 7) return true;
    row = other_record->event.key.row;
    // other key on thumb
    if (row == 3 || row == 7) return true;
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
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    uint8_t mod_state = get_mods();
    static bool is_shifted;
    is_shifted = get_mods() & MOD_MASK_SHIFT;
    static uint16_t dquo_timer;
    if (record->event.pressed) {
        switch (keycode) {
        case CUSTOM_QU:
            if (is_shifted) {
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
        case CUSTOM_BSPC:
            tap_code(KC_BSPC);
            return false;
        case CUSTOM_ENTER:
            tap_code(KC_ENTER);
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
