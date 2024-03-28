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

#include "keycodes.h"
#include "magic.h"
#include QMK_KEYBOARD_H
#include "keymap_uk.h"

#define _BASE 0
#define _GAMING 1
#define _NAV 2
#define _SYM 3
#define _NUM 4
#define _SYS 5

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))
#define OS_CMD OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_SHFT OSM(MOD_LSFT)
#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define SW_WIN G(KC_TAB)
#define SW_LANG C(KC_SPC)
#define DF_BASE DF(_BASE)
#define DF_GMNG DF(_GAMING)

enum custom_keycodes {
    MGC = SAFE_RANGE,
    SKIP_MGC,
};

uint16_t magic_rules(uint16_t keycode) {
    switch(keycode) {
        case KC_A: return KC_O;
        case KC_G: return KC_S;
        case KC_H: return KC_Y;
        case KC_U: return KC_E;
        case KC_X: return KC_T;
        case KC_Y: return KC_H;
        default: return keycode;
    }
}

uint16_t skip_magic_rules(uint16_t keycode) {
    switch(keycode) {
        case KC_A: return KC_O;
        case KC_B: return KC_N;
        case KC_D: return KC_T;
        case KC_F: return KC_S;
        case KC_G: return KC_S;
        case KC_H: return KC_Y;
        case KC_J: return KC_Y;
        case KC_K: return KC_T;
        case KC_L: return KC_R;
        case KC_M: return KC_K;
        case KC_O: return KC_A;
        case KC_P: return KC_N;
        case KC_Q: return KC_E;
        case KC_R: return KC_L;
        case KC_U: return KC_E;
        case KC_V: return KC_T;
        case KC_X: return KC_T;
        case KC_Y: return KC_H;
        case KC_COMM: return KC_I;
        case KC_DOT: return KC_I;
        case KC_MINS: return KC_I;
        case KC_SLSH: return KC_A;
        case KC_SCLN: return KC_E;
        default: return keycode;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case MGC:
            apply_magic(magic_rules, skip_magic_rules, MGC);
            return false;

        case SKIP_MGC:
            apply_skip_magic(magic_rules, skip_magic_rules, SKIP_MGC);
            return false;

        default:
            record_key(keycode);
            return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LALT, UK_J,    UK_B,    UK_G,    UK_D,    UK_K,    UK_Z,    UK_C,    UK_O,    UK_U,    UK_COMM, _______,
        //-------------------------------------------------//-----------------------------------------------------------//
        UK_Q,    UK_H,    UK_N,    UK_S,    UK_T,    UK_M,    MGC,     SKIP_MGC,UK_A,    UK_E,    UK_I,    UK_MINS,
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LCTL, UK_Y,    UK_P,    UK_F,    UK_V,    UK_X,    UK_QUOT, UK_W,    UK_SLSH, UK_SCLN, UK_DOT,  _______,
        //-------------------------------------------------//-----------------------------------------------------------//
                                               LA_NAV,  UK_R,    UK_L,    KC_LSFT, KC_SPC, LA_SYM,
                                                            _______, _______, MO(_SYS),_______
    ),

    [_NAV] = LAYOUT_split_4x6_5(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   QK_BOOT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_TAB,  SW_WIN,  XXXXXXX, XXXXXXX, KC_VOLU, KC_HOME, HOME,    KC_UP,   END,     KC_DEL,  _______,
        _______, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_VOLD, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
        _______, SPACE_L, SPACE_R, BACK,    FWD,     KC_MPLY, KC_END,  KC_PGDN, KC_PGUP, SW_LANG, KC_ENT,  _______,
                                               _______, _______, _______, _______, _______, _______,
                                                            _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_split_4x6_5(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, UK_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,  _______,
        _______, UK_MINS, UK_ASTR, UK_EQL,  UK_UNDS, UK_DLR,  UK_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, _______,
        _______, UK_PLUS, UK_PIPE, UK_DQUO, UK_SLSH, UK_PERC, UK_PND,  UK_BSLS, KC_AMPR, KC_QUES, KC_EXLM, _______,
                                               _______, _______, _______, _______, _______, _______,
                                                            _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_4x6_5(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,    _______,
        _______, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  KC_F10,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, _______,
        _______, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,   _______,
                                               _______, _______, _______, _______, _______, _______,
                                                            _______, _______, _______, _______
    ),

    [_SYS] = LAYOUT_split_4x6_5(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, DF_BASE, DF_GMNG, _______, _______, _______, _______, RM_TOGG, RM_PREV, RM_NEXT, _______, _______,
        _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_SYRQ, _______, _______, RM_HUED, RM_SATD, RM_SATU, RM_HUEU, _______,
        _______, _______, _______, _______, _______, _______, _______, RM_SPDD, RM_VALD, RM_VALU, RM_SPDU, _______,
                                               _______, _______, _______, _______, _______, _______,
                                                            _______, _______, _______, _______
    ),

    [_GAMING] = LAYOUT_split_4x6_5(
        UK_HASH, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    UK_EQL,
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LALT, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    UK_MINS,
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LCTL, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, UK_GRV,
        //-------------------------------------------------//-----------------------------------------------------------//
        KC_LSFT, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        //-------------------------------------------------//-----------------------------------------------------------//
        MO(_NAV),KC_SPC, KC_ESC, KC_DEL, KC_BSPC, MO(_SYS),
        KC_LSFT, KC_TAB, KC_ENT, KC_LSFT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}
