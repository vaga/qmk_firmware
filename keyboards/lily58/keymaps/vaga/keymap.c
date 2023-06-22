// Copyright 2023 Fabien C.
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>
#include "quantum.h"

#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _GAME,
    _SYM,
    _NUM,
    _NAV,
    _MOUSE,
    _FUN,
};

#define DF_GAME  DF(_GAME)
#define DF_BASE  DF(_BASE)

#define NAV_SPC   LT(_NAV,   KC_SPC)
#define MOU_TAB   LT(_MOUSE, KC_TAB)
#define SYM_ENT   LT(_SYM,   KC_ENT)
#define NUM_BSPC  LT(_NUM,   KC_BSPC)
#define FUN_SPC   LT(_FUN,  XXXXXXX)

#define HO_A    LGUI_T(KC_A)
#define HO_S    LALT_T(KC_S)
#define HO_D    LCTL_T(KC_D)
#define HO_F    LSFT_T(KC_F)
#define HO_J    RSFT_T(KC_J)
#define HO_K    RCTL_T(KC_K)
#define HO_L    LALT_T(KC_L)
#define HO_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_GRAVE, KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                           KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
        KC_ESC,   HO_A,     HO_S,     HO_D,     HO_F,     KC_G,                           KC_H,     HO_J,     HO_K,     HO_L,     HO_SCLN,  KC_QUOT,
        XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,    DF_GAME,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
                                      XXXXXXX,  XXXXXXX,  MOU_TAB,  NAV_SPC,    SYM_ENT,  NUM_BSPC, KC_DEL,   XXXXXXX
    ),

    [_GAME] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_GRV,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                           KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
        KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                           KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,    DF_BASE,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                      KC_LALT,  KC_LGUI,  FUN_SPC,   KC_SPC,     KC_ENT,   KC_BSPC,  KC_DEL,   KC_RGUI
    ),

    [_SYM] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        XXXXXXX,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_AMPR,                        XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,  KC_CIRC,  _______,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
                                      _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______
    ),

    [_NUM] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        XXXXXXX,  KC_PERC,  KC_7,     KC_8,     KC_9,     KC_ASTR,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  KC_BSLS,  KC_4,     KC_5,     KC_6,     KC_EQUAL,                       XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  XXXXXXX,
        _______,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_PLUS,  _______,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
                                      _______,  _______,  KC_0,     _______,    _______,  _______,  _______,  _______
    ),

    [_NAV] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,    _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,  _______,
                                      _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______
    ),

    [_MOUSE] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,                        KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
                                      _______,  _______,  _______,  _______,    KC_BTN1,  KC_BTN2,  _______,  _______
    ),

    [_FUN] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_F7,    KC_F8,    KC_F9,    _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_F4,    KC_F5,    KC_F6,    _______,                        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_F1,    KC_F2,    KC_F3,    _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                      _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______
    ),
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

void oled_render_layer(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _FUN:
            oled_write_ln_P(PSTR("Function"), false);
            break;
    }
}


void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

char key_line[20] = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    snprintf(
        key_line,
        sizeof(key_line),
        "Key  : %dx%d, %d",
        record->event.key.row,
        record->event.key.col,
        keycode
    );

    return true;
}

void oled_render_key(void) {
    oled_write_ln(key_line, false);
}

bool oled_task_user() {
    if (is_keyboard_master()) {
        oled_write_char('\n', false);
        oled_render_layer();
        oled_render_key();
    } else {
        oled_render_logo();
    }

    return false;
}
