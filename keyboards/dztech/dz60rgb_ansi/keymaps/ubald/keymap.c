#include QMK_KEYBOARD_H

#include "ubald.h"

#define _BASE  0
#define _FN    1
#define _RGB   2
#define _SLACK 3

enum custom_keycodes {
    SL_A = SAFE_RANGE,SL_B, SL_C, SL_D, SL_E, SL_F, SL_G, SL_H, SL_I, SL_J, SL_K, SL_L, SL_M,
    SL_N, SL_O, SL_P, SL_Q, SL_R, SL_S, SL_T, SL_U, SL_V, SL_W, SL_X, SL_Y, SL_Z,
    SL_AT, SL_HA, SL_EX, SL_QU
};

#define ALPHABET_WHITE ":alphabet-white-"
#define ALPHABET_YELLOW ":alphabet-yellow-"

bool slack_w(keyrecord_t *record, const char *str) {
    if (record->event.pressed) {
        SEND_STRING(ALPHABET_WHITE);
        send_string(str);
        SEND_STRING(":");
    }
    return false;
}

bool slack_y(keyrecord_t *record, const char *str) {
    if (record->event.pressed) {
        SEND_STRING(ALPHABET_YELLOW);
        send_string(str);
        SEND_STRING(":");
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case S(SL_A): return slack_y(record, "a");
    // case S(SL_B): return slack_y(record, "b");
    // case S(SL_C): return slack_y(record, "c");
    // case S(SL_D): return slack_y(record, "d");
    // case S(SL_E): return slack_y(record, "e");
    // case S(SL_F): return slack_y(record, "f");
    // case S(SL_G): return slack_y(record, "g");
    // case S(SL_H): return slack_y(record, "h");
    // case S(SL_I): return slack_y(record, "i");
    // case S(SL_J): return slack_y(record, "j");
    // case S(SL_K): return slack_y(record, "k");
    // case S(SL_L): return slack_y(record, "l");
    // case S(SL_M): return slack_y(record, "m");
    // case S(SL_N): return slack_y(record, "n");
    // case S(SL_O): return slack_y(record, "o");
    // case S(SL_P): return slack_y(record, "p");
    // case S(SL_Q): return slack_y(record, "q");
    // case S(SL_R): return slack_y(record, "r");
    // case S(SL_S): return slack_y(record, "s");
    // case S(SL_T): return slack_y(record, "t");
    // case S(SL_U): return slack_y(record, "u");
    // case S(SL_V): return slack_y(record, "v");
    // case S(SL_W): return slack_y(record, "w");
    // case S(SL_X): return slack_y(record, "x");
    // case S(SL_Y): return slack_y(record, "y");
    // case S(SL_Z): return slack_y(record, "z");
    // case S(SL_AT): return slack_y(record, "at");
    // case S(SL_HA): return slack_y(record, "hash");
    // case S(SL_EX): return slack_y(record, "exclamation");
    // case S(SL_QU): return slack_y(record, "question");
    case SL_A: return slack_w(record, "a");
    case SL_B: return slack_w(record, "b");
    case SL_C: return slack_w(record, "c");
    case SL_D: return slack_w(record, "d");
    case SL_E: return slack_w(record, "e");
    case SL_F: return slack_w(record, "f");
    case SL_G: return slack_w(record, "g");
    case SL_H: return slack_w(record, "h");
    case SL_I: return slack_w(record, "i");
    case SL_J: return slack_w(record, "j");
    case SL_K: return slack_w(record, "k");
    case SL_L: return slack_w(record, "l");
    case SL_M: return slack_w(record, "m");
    case SL_N: return slack_w(record, "n");
    case SL_O: return slack_w(record, "o");
    case SL_P: return slack_w(record, "p");
    case SL_Q: return slack_w(record, "q");
    case SL_R: return slack_w(record, "r");
    case SL_S: return slack_w(record, "s");
    case SL_T: return slack_w(record, "t");
    case SL_U: return slack_w(record, "u");
    case SL_V: return slack_w(record, "v");
    case SL_W: return slack_w(record, "w");
    case SL_X: return slack_w(record, "x");
    case SL_Y: return slack_w(record, "y");
    case SL_Z: return slack_w(record, "z");
    case SL_AT: return slack_w(record, "at");
    case SL_HA: return slack_w(record, "hash");
    case SL_EX: return slack_w(record, "exclamation");
    case SL_QU: return slack_w(record, "question");
    default:
      return true;
  }
}

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case _FN:
        rgb_matrix_set_color_all(255, 255, 255);
        break;
    case _SLACK:
        rgb_matrix_set_color_all(255, 0, 0);
        break;
    case _RGB:
        rgb_matrix_set_color_all(0, 0, 255);
        break;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [_BASE] = LAYOUT_60_ansi(
    //     KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    //     KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    //     CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    //     KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    //     KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   MO(2),   KC_RCTL
    // ),
    // [_EMPTY] = LAYOUT_60_ansi(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______,                            _______,                            _______, _______, _______, _______
    // ),
    [_BASE] = LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,     KC_BSLS,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,    KC_BSPC,
        CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,              KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,              KC_RSFT,
        MO(_FN),        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_RGB), TG(_SLACK), KC_RCTL
    ),
    [_FN] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, KC_CALC, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, KC_SLCK, KC_PAUS, KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,  KC_DEL,           _______,
        _______,          _______, _______, _______, _______, _______, KC_END,  _______, _______,  KC_END,  KC_PGDN,          _______,
        _______, _______, _______,                            _______,                             _______, _______, _______, RESET
    ),
    // [_MEDIA] = LAYOUT_60_ansi(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     KC_MPRV,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______,          KC_MNXT,
    //     _______, _______, _______,                            _______,                            _______, _______, _______, RESET
    // ),
    [_RGB] = LAYOUT_60_ansi(
        _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______,  _______, _______, _______,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD,  RGB_SAI,  RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, RGB_RMOD, _______, _______, _______,
        _______, _______, _______, _______, _______,  _______,  _______, _______, RGB_SPI, RGB_SPD, _______,  _______,          _______,
        _______,          _______, _______, _______,  _______,  _______, _______, _______, _______, _______,  _______,          _______,
        _______, _______, _______,                              _______,                            _______,  _______, _______, RESET
    ),
    [_SLACK] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, SL_Q,    SL_W,    SL_E,    SL_R,    SL_T,    SL_Y,    SL_U,    SL_I,    SL_O,    SL_P,    _______, _______, _______,
        _______, SL_A,    SL_S,    SL_D,    SL_F,    SL_G,    SL_H,    SL_J,    SL_K,    SL_L,    _______, _______,          _______,
        _______,          SL_Z,    SL_X,    SL_C,    SL_V,    SL_B,    SL_N,    SL_M,    _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RESET
    )
};
