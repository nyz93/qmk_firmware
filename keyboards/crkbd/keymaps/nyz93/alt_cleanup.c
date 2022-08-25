#include QMK_KEYBOARD_H

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_LALT && !record->event.pressed) {
        layer_clear();
        reset_oneshot_layer();
    }
}
