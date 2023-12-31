#include QMK_KEYBOARD_H
#include "user_host.h"
#include "user_keymap.h"
#include "version.h"

void oled_render_host(void) {
    oled_write_P(PSTR("            "), false);
    if (user_is_host_linux()) {
        oled_write_ln_P(PSTR("OS: Linux"), false);
    } else {
        oled_write_ln_P(PSTR("OS: macOS"), false);
    }
}

void oled_render_version(void) {
    const char* hash = PSTR(QMK_GIT_HASH);
    int pad = (OLED_DISPLAY_WIDTH/OLED_FONT_WIDTH) - strlen(hash) - 9;
    for(int i = 0; i<pad; i++) {
        oled_write_char(' ', false);
    }
    oled_write_P(PSTR("Version: "), false);
    oled_write_ln_P(hash, false);
}

void oled_render_keylog(void);
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
        oled_render_keylog();
    } else {
        oled_render_host();
        oled_render_version();
    }
    return false;
}
