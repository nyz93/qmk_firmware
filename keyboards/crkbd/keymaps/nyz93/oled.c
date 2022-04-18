#include QMK_KEYBOARD_H
#include "user_host.h"
void oled_render_host(void) {
    oled_write_P(PSTR("            "), false);
    if (user_is_host_linux()) {
        oled_write_ln_P(PSTR("OS: Linux"), false);
    } else {
        oled_write_ln_P(PSTR("OS: macOS"), false);
    }
}
void oled_render_keylog_r2g(void);
void oled_render_layer_state_r2g(void);
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state_r2g();
        oled_render_keylog_r2g();
    } else {
        oled_render_host();
    }
    return false;
}

