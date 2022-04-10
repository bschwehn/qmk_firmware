#include "features/caps_word.h"

bool custom_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }

    return true;
}
