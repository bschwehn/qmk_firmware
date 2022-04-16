#include "features/caps_word.h"

enum custom_combo {
    CUSTOM_QU = ML_SAFE_RANGE + 5,
};

bool custom_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
    case CUSTOM_QU:
        if (record->event.pressed) {
            SEND_STRING("qu");
        } else {
        }
        break;
}
    return true;
}
