#include "features/caps_word.h"

enum custom_combo {
    CUSTOM_QU = ML_SAFE_RANGE + 5,
};

bool custom_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
    case CUSTOM_QU:
        static bool isShifted;
        if (record->event.pressed) {
            isShifted = get_mods() & MOD_MASK_SHIFT;
            if (isShifted) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING("Qu");
            } else {
                SEND_STRING("qu");
            }
        } else {
            if (isShifted) {
            }
        }
        return false;
    }
    return true;
}
