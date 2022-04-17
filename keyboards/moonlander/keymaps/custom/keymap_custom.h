#include "features/caps_word.h"

enum custom_combo {
    CUSTOM_QU = ML_SAFE_RANGE + 5,
};

bool custom_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }
    uint8_t mod_state = get_mods();
    switch (keycode) {
    case CUSTOM_QU:
        static bool is_shifted;
        if (record->event.pressed) {
            if (caps_word_get()) {
                SEND_STRING("QU");
            } else {
                is_shifted = get_mods() & MOD_MASK_SHIFT;
                if (is_shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("Qu");
                    set_mods(mod_state);
                } else {
                    SEND_STRING("qu");
                }
            }
        } else {
        }
        return false;
    }
    return true;
}

__attribute__((weak)) bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case CUSTOM_QU:
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
