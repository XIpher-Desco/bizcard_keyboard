// Copyright 2022 Xiphelier  (@Xiphelier)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_names {
  _BASE = 0,
  _CLISTA,
  _CLISTA2,
  _DCSWORLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
        TG(_CLISTA), KC_2, KC_3, KC_4, KC_5,
        TG(_DCSWORLD), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // LEVER
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ENCODER
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  [_CLISTA] = LAYOUT(
        LCTL(KC_S), KC_GRV, RCS(KC_N), LCTL(KC_U), KC_BSPC,
        KC_K, KC_O, KC_W, KC_M, LCTL(KC_D),
        KC_U, TG(_CLISTA), LCTL(KC_Z), KC_F14, KC_Y,
        LT(_CLISTA2, KC_J), KC_S, LCTL(KC_Z), RCS(KC_Z), TG(_CLISTA),
        LCTL(KC_H), LCA_T(KC_G), LALT_T(KC_E), LCTL_T(KC_B), LSFT_T(KC_P),
        // LEVER
        XXXXXXX, KC_COMMA, KC_G, KC_DOT, XXXXXXX,
        // ENCODER
        KC_NUHS, KC_RBRC, KC_MS_WH_UP, KC_MS_WH_DOWN,KC_MINS, KC_EQL
  ),
  [_CLISTA2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // LEVER
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ENCODER
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  [_DCSWORLD] = LAYOUT(
        HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5),
        HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), HYPR(KC_0),
        HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D), HYPR(KC_E),
        HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_I), TG(_DCSWORLD),
        HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), HYPR(KC_N), HYPR(KC_O),
        // LEVER
        HYPR(KC_P), HYPR(KC_Q), HYPR(KC_R), HYPR(KC_S), HYPR(KC_T),
        // ENCODER
        HYPR(KC_U), HYPR(KC_V), HYPR(KC_W), HYPR(KC_X), HYPR(KC_Y), HYPR(KC_Z)
  ),
};

// ENCODER FOR VIA
bool encoder_update_user(uint8_t index, bool clockwise) {
  keypos_t key;
  if (index == 0) {
    if (clockwise) {
        key.row = 0;
        key.col = 5;
    } else {
        key.row = 1;
        key.col = 5;
    }
  } else if (index == 1){
    if (clockwise) {
      key.row = 2;
      key.col = 5;
    } else {
      key.row = 3;
      key.col = 5;
    }
  } else if (index == 2){
    if (clockwise) {
      key.row = 4;
      key.col = 5;
    } else {
      key.row = 5;
      key.col = 5;
    }
  }
  uint8_t  layer   = layer_switch_get_layer(key);
  uint16_t keycode = keymap_key_to_keycode(layer, key);
  tap_code16(keycode);
  return true;
}

// 接続時のデフォルトをクリスタにする
void matrix_init_user(void) {
  layer_on(_CLISTA);
}