#include QMK_KEYBOARD_H

void user_init_host_sync(void);
void keyboard_post_init_user(void) {
    user_init_host_sync();
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}
