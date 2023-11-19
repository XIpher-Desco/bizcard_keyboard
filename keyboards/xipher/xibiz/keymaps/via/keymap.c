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

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 2, .col = 1},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 2, .col = 0},
    .pressed = false
};

keyevent_t encoder2_ccw = {
    .key = (keypos_t){.row = 2, .col = 3},
    .pressed = false
};

keyevent_t encoder2_cw = {
    .key = (keypos_t){.row = 2, .col = 2},
    .pressed = false
};

void matrix_scan_user(void) {
    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

    if (IS_PRESSED(encoder2_ccw)) {
        encoder2_ccw.pressed = false;
        encoder2_ccw.time = (timer_read() | 1);
        action_exec(encoder2_ccw);
    }

    if (IS_PRESSED(encoder2_cw)) {
        encoder2_cw.pressed = false;
        encoder2_cw.time = (timer_read() | 1);
        action_exec(encoder2_cw);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    } else if (index == 1) {
        if (clockwise) {
            encoder2_cw.pressed = true;
            encoder2_cw.time = (timer_read() | 1);
            action_exec(encoder2_cw);
        } else {
            encoder2_ccw.pressed = true;
            encoder2_ccw.time = (timer_read() | 1);
            action_exec(encoder2_ccw);
        }
    }
    return true;
}