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
