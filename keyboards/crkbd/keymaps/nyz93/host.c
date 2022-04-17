#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "user_host.h"

bool is_linux = false;

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (data[0] == 0x11) {
        is_linux = data[1] == 1;
    }
}

bool user_is_host_linux(void) {
    return is_linux;
}

bool process_record_user_host(uint16_t keycode, keyrecord_t *record) {
    return true;
}
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}
