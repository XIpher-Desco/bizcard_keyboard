// Copyright 2022 Xiphelier  (@Xiphelier)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keycode {
  BASE = 0,
  LOWER,
  UPPER,
  LIGHT,
  SP1,
  SP2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, 
        KC_5, KC_6, KC_7, KC_8, KC_9,
        // ENCODER
        KC_A, KC_B, KC_C, KC_D
  ),
  [LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ENCODER
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  [UPPER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ENCODER
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  [LIGHT] = LAYOUT(
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
        RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_TOG,
        // ENCODER
        RGB_MOD, RGB_RMOD, XXXXXXX, XXXXXXX
  ),
  [SP1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ENCODER
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  [SP2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ENCODER
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   {
      ENCODER_CCW_CW(KC_MINS, KC_EQL), 
      ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)
      },
    [LOWER] =   {
      ENCODER_CCW_CW(KC_RBRC, KC_LBRC), 
      ENCODER_CCW_CW(KC_MINS, KC_QUOT)
      },
    [LOWER] =   {
      ENCODER_CCW_CW(KC_RBRC, KC_LBRC), 
      ENCODER_CCW_CW(KC_MINS, KC_QUOT)
      },
    [LIGHT] = { 
      ENCODER_CCW_CW(RGB_VAI, RGB_VAD), 
      ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)
      },
    [SP1] =   {
      ENCODER_CCW_CW(KC_RBRC, KC_LBRC), 
      ENCODER_CCW_CW(KC_MINS, KC_QUOT)
      },
    [SP2] =   {
      ENCODER_CCW_CW(KC_RBRC, KC_LBRC), 
      ENCODER_CCW_CW(KC_MINS, KC_QUOT)
      },
};