#include QMK_KEYBOARD_H
#include "user_keymap.h"
#include "user_host.h"

typedef struct { uint8_t kc; } dance_key_arg;
void dance_key_c_type(qk_tap_dance_state_t *state, void* user_data) {
    dance_key_arg* arg = (dance_key_arg*)user_data;
    uint8_t kc = arg->kc;
    if (state->count > 1) {
        register_code(kc);
        unregister_code(kc);
    }
}
void dance_key_c_done(qk_tap_dance_state_t *state, void* user_data) {
    dance_key_arg* arg = (dance_key_arg*)user_data;
    uint8_t kc = arg->kc;

    if (state->interrupted || !state->pressed) {
        register_code(kc);
        unregister_code(kc);
    } else {
        if (user_is_host_linux()) {
            register_code(KC_LEFT_CTRL);
            register_code(kc);
            unregister_code(kc);
            unregister_code(KC_LEFT_CTRL);
        } else {
            register_code(KC_LEFT_GUI);
            register_code(kc);
            unregister_code(kc);
            unregister_code(KC_LEFT_GUI);
        }
    }
}

#define ACTION_TAP_DANCE_HOLD_HOSTMOD(keycode) \
    { .fn = {dance_key_c_type, dance_key_c_done, NULL }, .user_data = (void*)&((dance_key_arg){ keycode }) }
qk_tap_dance_action_t tap_dance_actions[] = {
    [KC_TD_C] = ACTION_TAP_DANCE_HOLD_HOSTMOD(KC_C),
    [KC_TD_X] = ACTION_TAP_DANCE_HOLD_HOSTMOD(KC_X),
    [KC_TD_V] = ACTION_TAP_DANCE_HOLD_HOSTMOD(KC_V),
};
