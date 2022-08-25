// clang-format off
#include QMK_KEYBOARD_H
#include "user_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[DEFAULT] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                              KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, TD(KC_TD_X), TD(KC_TD_C), TD(KC_TD_V), KC_B,         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                                        KC_LGUI, OSL(LOWER), KC_SPC, KC_ENT, OSL(RAISE), KC_RALT
    ),
	[LOWER] = LAYOUT_split_3x6_3(
    KC_PER_HOST_ALT_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,                               KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, TG(MOUSE),                         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,
                                        KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, MO(ADJUST), KC_RALT
    ),
	[RAISE] = LAYOUT_split_3x6_3(
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                        KC_LGUI, MO(ADJUST), KC_SPC, KC_ENT, KC_TRNS, KC_LALT
    ),
	[ADJUST] = LAYOUT_split_3x6_3(
    LALT(KC_F1), LALT(KC_F2), LALT(KC_F3), LALT(KC_F4), LALT(KC_F5), LALT(KC_F6),             LALT(KC_F7), LALT(KC_F8), LALT(KC_F9), LALT(KC_F10), LALT(KC_F11), LALT(KC_F12),
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                        KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_RALT
    ),
	[MOUSE] = LAYOUT_split_3x6_3(
    KC_NO, KC_NO, KC_MS_U, KC_NO, KC_WH_U, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, TG(MOUSE),                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                        KC_NO, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN3, KC_NO
    )
};
