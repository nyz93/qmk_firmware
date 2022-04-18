#include QMK_KEYBOARD_H
#include "user_host.h"
#include "user_keymap.h"

void oled_render_host(void) {
    oled_write_P(PSTR("            "), false);
    if (user_is_host_linux()) {
        oled_write_ln_P(PSTR("OS: Linux"), false);
    } else {
        oled_write_ln_P(PSTR("OS: macOS"), false);
    }
}

void oled_render_keylog_r2g(void);
void oled_render_layer_state_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case DEFAULT:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        case MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state_user();
        oled_render_keylog_r2g();
    } else {
        oled_render_host();
    }
    return false;
}
