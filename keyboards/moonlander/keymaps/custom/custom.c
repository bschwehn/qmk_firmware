// custom
LEADER_EXTERNS();
void matrix_scan_user(void) {
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
            register_code(KC_LSFT);
            tap_code(KC_PAUSE);
            unregister_code(KC_LSFT);
        }
        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }

        SEQ_THREE_KEYS(KC_A, KC_A, KC_A) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            SEND_STRING(SS_LSFT("a"));
        }

        SEQ_TWO_KEYS(KC_A, KC_A) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            tap_code(KC_A);
        }

        SEQ_THREE_KEYS(KC_A, KC_O, KC_O) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            SEND_STRING(SS_LSFT("o"));
        }

        SEQ_TWO_KEYS(KC_A, KC_O) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            tap_code(KC_O);
        }
        SEQ_THREE_KEYS(KC_A, KC_U, KC_U) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            SEND_STRING(SS_LSFT("u"));
        }

        SEQ_TWO_KEYS(KC_A, KC_U) {
            register_code(KC_RALT);
            register_code16(UK_2);
            unregister_code16(UK_2);
            unregister_code(KC_RALT);
            tap_code(KC_U);
        }
        SEQ_ONE_KEY(TD(DANCE_1)) {
            SEND_STRING("` ");
        }
  }
}

enum combos {
    AT_ESC,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM esc_combo[] = {MT(MOD_LGUI, KC_A), MT(MOD_LCTL, KC_T), COMBO_END};


combo_t key_combos[] = {
    [AT_ESC] = COMBO(esc_combo, KC_ESC),
};
