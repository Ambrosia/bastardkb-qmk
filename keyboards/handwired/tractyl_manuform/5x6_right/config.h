/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1832
#define DEVICE_VER 0x0001
#define PRODUCT Charybdis

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { D5, F0, C6, D4, B5 }
#define MATRIX_COL_PINS { F1, C7, B7, D7, E6, B4 }

#define DIODE_DIRECTION ROW2COL

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3


#define ROTATIONAL_TRANSFORM_ANGLE     -25

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW             0
#define BOOTMAGIC_LITE_COLUMN          0
#define BOOTMAGIC_LITE_ROW_RIGHT       6
#define BOOTMAGIC_LITE_COLUMN_RIGHT    5

#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 4095
#define DYNAMIC_KEYMAP_LAYER_COUNT     16
#define LAYER_STATE_16BIT

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2
#define MASTER_RIGHT

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_STATE_SYNC, RPC_ID_SLAVE_STATE
