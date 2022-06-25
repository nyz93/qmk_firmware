#pragma once
#include QMK_KEYBOARD_H

enum user_tapdance_keys {
    KC_TD_C,
    KC_TD_X,
    KC_TD_V,
};

enum custom_keycodes {
    KC_PER_HOST_ALT_TAB = SAFE_RANGE,
    NEW_SAFE_RANGE
};

enum layers { DEFAULT, LOWER, RAISE, ADJUST, MOUSE };
