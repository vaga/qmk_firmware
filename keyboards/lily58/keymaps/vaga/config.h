// Copyright 2023 Fabien C.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_LEFT

/* OLED */
#undef OLED_FONT_H
#define OLED_FONT_H "keyboards/lily58/keymaps/vaga/glcdfont.c"

/* RGB Lighting */
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 64

/* Tap-hold */
#define TAPPING_TERM 130

/* Mouse */
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_INTERVAL     16
#define MOUSEKEY_WHEEL_DELAY  0
#define MOUSEKEY_MAX_SPEED    6
#define MOUSEKEY_TIME_TO_MAX  64
