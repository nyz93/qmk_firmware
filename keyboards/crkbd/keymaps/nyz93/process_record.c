#include QMK_KEYBOARD_H

bool process_record_user_shift(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user_shift(keycode, record)) {
        return false;
    }
    return true;
}
