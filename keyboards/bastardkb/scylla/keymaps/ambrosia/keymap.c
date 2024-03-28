/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_uk.h"

#define _BASE 0
#define _QWERTY 1
#define _NAV 2
#define _MOUSE 3
#define _MEDIA 4
#define _NUM 5
#define _SYM 6
#define _FUNNY 7

#define GRAPHITE_LAYERS 1 << _BASE

#define DF_BASE TD(TD_LAYER_MOVE_BASE)
#define DF_QWER TD(TD_LAYER_MOVE_QWER)

#define TD_ALTS TD(TD_LALT_RALT)
#define TD_HASH TD(TD_HASH_GRV)

// Tap dance stuff
enum {
    TD_BSLS_HASH,
    TD_QUOT_GRV,
    TD_LALT_RALT,
    TD_HASH_GRV,
    TD_LAYER_MOVE_BASE,
    TD_LAYER_MOVE_QWER,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BSLS_HASH] = ACTION_TAP_DANCE_DOUBLE(UK_BSLS, UK_HASH),
    [TD_QUOT_GRV] = ACTION_TAP_DANCE_DOUBLE(UK_QUOT, UK_GRV),
    [TD_LALT_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
    [TD_HASH_GRV] = ACTION_TAP_DANCE_DOUBLE(UK_HASH, UK_GRV),
    [TD_LAYER_MOVE_BASE] = ACTION_TAP_DANCE_LAYER_MOVE(XXXXXXX, _BASE),
    [TD_LAYER_MOVE_QWER] = ACTION_TAP_DANCE_LAYER_MOVE(XXXXXXX, _QWERTY),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_4x6_5(
        TD_HASH,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    UK_EQL,
        //-------------------------------------------------//-----------------------------------------------------------//
        TD_ALTS, UK_B,    UK_L,    UK_D,    UK_W,    UK_Z,    UK_QUOT, UK_F,    UK_O,    UK_U,    UK_J,    UK_SCLN,
        //-------------------------------------------------//-----------------------------------------------------------//
        UK_BSLS, UK_N,    UK_R,    UK_T,    UK_S,    UK_G,    UK_Y,    UK_H,    UK_A,    UK_E,    UK_I,    UK_COMM,
        //-------------------------------------------------//-----------------------------------------------------------//
        UK_LBRC, UK_Q,    UK_X,    UK_M,    UK_C,    UK_V,    UK_K,    UK_P,    UK_DOT,  UK_MINS, UK_SLSH, UK_RBRC,
        //-------------------------------------------------//-----------------------------------------------------------//
        LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB), LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUNNY, KC_DEL),
        KC_LSFT, KC_LCTL, KC_LGUI, KC_LSFT
    ),

    [_QWERTY] = LAYOUT_split_4x6_5(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_BSLS_HASH),
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TD(TD_QUOT_GRV),
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        //-------------------------------------------------//-----------------------------------------------------------//
        LT(_MEDIA, KC_ESC), KC_SPC, KC_TAB, LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUNNY, KC_DEL),
        UK_LBRC, MO(_NAV), KC_LGUI, UK_RBRC
    ),

    [_MEDIA] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DF_QWER, DF_BASE, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_SAI, RGB_HUI, _______,
        _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_VAD, RGB_VAI, RGB_SPI, _______,
        _______, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE,
        _______, _______, RGB_TOG, RGB_MOD
    ),

    [_NAV] = LAYOUT_split_4x6_5(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,  DF_QWER, DF_BASE, XXXXXXX, CW_TOGG, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        XXXXXXX, _______, XXXXXXX, KC_ENT, KC_BSPC, KC_DEL,
        _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DF_QWER, DF_BASE, XXXXXXX, XXXXXXX, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        _______, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
        XXXXXXX, XXXXXXX, _______, KC_BTN2, KC_BTN1, KC_BTN3,
        _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, UK_LCBR, UK_CIRC, UK_AMPR, UK_PERC, UK_RCBR, XXXXXXX, DF_BASE, DF_QWER, _______, _______, _______,
        UK_PND,  UK_COLN, UK_PLUS, UK_LABK, UK_RABK, UK_DLR,  XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, UK_HASH, UK_PIPE, UK_EQL,  UK_TILD, UK_EXLM, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______,
        UK_ASTR, KC_SPC,  KC_TAB,  _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, UK_PND,  KC_7,    KC_8,    KC_9,    KC_QUOT, XXXXXXX, DF_BASE, DF_QWER, _______, _______, _______,
        _______, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_COMM, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______,
        KC_DOT,  KC_0,    KC_MINS, XXXXXXX, _______, XXXXXXX,
        _______, _______, _______, _______
    ),

    [_FUNNY] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_PSCR, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ, XXXXXXX, DF_BASE, DF_QWER, _______, _______, _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______,
        KC_MENU, KC_SPC,  KC_TAB,  XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______
    ),
};


const key_override_t grph_quot_override = ko_make_with_layers(MOD_MASK_SHIFT, UK_QUOT, UK_UNDS, GRAPHITE_LAYERS);
const key_override_t grph_mins_override = ko_make_with_layers(MOD_MASK_SHIFT, UK_MINS, UK_DQUO, GRAPHITE_LAYERS);
const key_override_t grph_slsh_override = ko_make_with_layers(MOD_MASK_SHIFT, UK_SLSH, UK_LABK, GRAPHITE_LAYERS);
const key_override_t grph_comm_override = ko_make_with_layers(MOD_MASK_SHIFT, UK_COMM, UK_QUES, GRAPHITE_LAYERS);
const key_override_t grph_dquo_override = ko_make_with_layers(MOD_MASK_SHIFT, UK_2, UK_AT, GRAPHITE_LAYERS);


const key_override_t **key_overrides = (const key_override_t *[]){
    &grph_quot_override,
    &grph_mins_override,
    &grph_slsh_override,
    &grph_comm_override,
    &grph_dquo_override,
    NULL
};
