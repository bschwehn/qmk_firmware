#include "features/caps_word.h"
#include "keymap_uk.h"

enum custom_combo {
    CUSTOM_QU = ML_SAFE_RANGE + 5,
    CUSTOM_AUML,
    CUSTOM_UUML,
    CUSTOM_OUML,
    CUSTOM_ESC,
    CUSTOM_END_CAPS,
};

bool send_with_caps_word(uint16_t keycode, uint16_t mod_state) {
    bool is_caps_word = caps_word_get();
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
    if (!process_caps_word(keycode, record)) { return false; }
    uint8_t mod_state = get_mods();
    static bool is_shifted;
    is_shifted = get_mods() & MOD_MASK_SHIFT;
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
            return send_with_caps_word(KC_A, mod_state);
        case CUSTOM_UUML:
            return send_with_caps_word(KC_U, mod_state);
        case CUSTOM_OUML:
            return send_with_caps_word(KC_O, mod_state);
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
