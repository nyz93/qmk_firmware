#include QMK_KEYBOARD_H
#include "user_keymap.h"
#include "user_host.h"

bool is_alt_tabbing = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == DEFAULT) {
        if (user_is_host_linux()) {
            unregister_code(KC_LEFT_ALT);
        } else {
            unregister_code(KC_LEFT_GUI);
        }
        is_alt_tabbing = false;
    }
    return state;
}

bool process_record_user_per_host(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_PER_HOST_ALT_TAB) {
        if (record->event.pressed) {
            if (!is_alt_tabbing) {
                is_alt_tabbing = true;
                if (user_is_host_linux()) {
                    register_code(KC_LEFT_ALT);
                } else {
                    register_code(KC_LEFT_GUI);
                }
            }
            register_code(KC_TAB);
            return false;
        } else {
            unregister_code(KC_TAB);
        }
    }
    return true;
}
