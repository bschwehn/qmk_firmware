// custom
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
            SEND_STRING(SS_LSFT(SS_TAP(X_PAUSE)));
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
    WF_ESC,
    WF_ESC10,
    WF_ESC3,
    XC_BSPC,
    FP_Q,
    V_A,
    V_U,
    V_O,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

// const uint16_t PROGMEM esc_combo[] = {MT(MOD_LGUI, KC_A), MT(MOD_LCTL, KC_T), COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, LT(9,KC_F), COMBO_END};
const uint16_t PROGMEM esc_combo10[] = {KC_F1, KC_F2, COMBO_END};
//const uint16_t PROGMEM esc_combo10[] = {KC_TAB, KC_F6, COMBO_END};
const uint16_t PROGMEM esc_combo3[] = {UK_BSLS, UK_LABK, COMBO_END};
//const uint16_t PROGMEM esc_combo3[] = {TD(DANCE_8), TD(DANCE_10), COMBO_END};
const uint16_t PROGMEM q_combo[] = {LT(9,KC_F),     LT(9,KC_P), COMBO_END};
const uint16_t PROGMEM auml_combo[] = {MT(MOD_LGUI, KC_A), KC_V, COMBO_END};
const uint16_t PROGMEM uuml_combo[] = {LT(8,KC_U), KC_V, COMBO_END};
const uint16_t PROGMEM ouml_combo[] = {MT(MOD_RGUI, KC_O), KC_V, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_W, LT(9,KC_F), COMBO_END};



combo_t key_combos[] = {
    [WF_ESC] = COMBO(esc_combo, CUSTOM_ESC),
    [WF_ESC10] = COMBO(esc_combo10, CUSTOM_ESC),
    [WF_ESC3] = COMBO(esc_combo3, CUSTOM_ESC),
    [FP_Q] = COMBO(q_combo, CUSTOM_QU),
    [V_A] = COMBO(auml_combo, CUSTOM_AUML),
    [V_U] = COMBO(uuml_combo, CUSTOM_UUML),
    [V_O] = COMBO(ouml_combo, CUSTOM_OUML),
    [XC_BSPC] = COMBO(bspc_combo, CUSTOM_BSPACE),
};
const key_override_t apo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUOTE);
const key_override_t dash_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(3,KC_COMMA), UK_MINS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&apo_key_override,
	&dash_key_override,
	NULL // Null terminate the array of overrides!
};
