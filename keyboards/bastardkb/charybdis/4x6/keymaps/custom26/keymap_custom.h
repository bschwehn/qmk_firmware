#include "keymap_uk.h"

enum charybdis_keymap_layers {
    LR_BASE = 0,
    LR_BRACES,
    LR_NAV,
    LR_FUN,
    LR_NUM,
    LR_POINTER,
    LR_EXTRAS
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
    CUSTOM_ARROW,
    CUSTOM_DARROW,
    CUSTOM_EMPROP,
    CUSTOM_VIMSAVE,
    CUSTOM_HTTPS,
    CUSTOM_JIGGLE,
    CUSTOM_LAST,

};

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
    print("in custom_record_user\n");
    uint8_t mod_state = get_mods();
    static bool is_shifted;
    is_shifted = get_mods() & MOD_MASK_SHIFT;
    static uint16_t dquo_timer;
    if (record->event.pressed) {
        // ---- jiggler
        static deferred_token token = INVALID_DEFERRED_TOKEN;
        static report_mouse_t report = {0};
        if (keycode == CUSTOM_JIGGLE) {
            if (token) {
                // If jiggler is currently running, stop when any key is pressed.
                cancel_deferred_exec(token);
                token = INVALID_DEFERRED_TOKEN;
                report = (report_mouse_t){};  // Clear the mouse.
                host_mouse_send(&report);
            } else if (keycode == CUSTOM_JIGGLE) {
                uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
                    // Deltas to move in a circle of radius 20 pixels over 32 frames.
                    static const int8_t deltas[32] = {
                        0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
                        0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
                    static uint8_t phase = 0;
                    // Get x delta from table and y delta by rotating a quarter cycle.
                    report.x = deltas[phase];
                    report.y = deltas[(phase + 8) & 31];
                    phase = (phase + 1) & 31;
                    host_mouse_send(&report);
                    return 300;  // Call the callback every 16 ms.
                }
                token = defer_exec(1, jiggler_callback, NULL);  // Schedule callback.
            }
        }
        // -- jiggler
        uprintf("custom_record_user: %s", get_keycode_string(keycode));
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

char chordal_hold_handedness(keypos_t key) {

    /* if (key.col == 0 || key.col == MATRIX_COLS - 1) { */
    /*     return '*';  // Exempt the outer columns. */
    /* } */

    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    char ret = key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
    return ret;
}


/* bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, */
/*                       uint16_t other_keycode, keyrecord_t* other_record) { */
/*     // Exceptionally allow some one-handed chords for hotkeys. */
/*     /\* switch (tap_hold_keycode) { *\/ */
/*     /\*     case LCTL_T(KC_Z): *\/ */
/*     /\*         if (other_keycode == KC_C || other_keycode == KC_V) { *\/ */
/*     /\*             return true; *\/ */
/*     /\*         } *\/ */
/*     /\*         break; *\/ */

/*     /\*     case RCTL_T(KC_SLSH): *\/ */
/*     /\*         if (other_keycode == KC_N) { *\/ */
/*     /\*             return true; *\/ */
/*     /\*         } *\/ */
/*     /\*         break; *\/ */
/*     /\* } *\/ */
/*     /\* // Otherwise defer to the opposite hands rule. *\/ */
/*     bool res = get_chordal_hold_default(tap_hold_record, other_record); */
/*     // uprintf("chordal result: %u\n", res); */
/*     return res; */
/* } */
