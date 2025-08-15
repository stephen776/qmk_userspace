// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Compile a firmware with your new keymap by typing: qmk compile -kb keebio/iris_lm/k1 -km steetyj.

#include QMK_KEYBOARD_H

enum custom_layers {
     _QWERTY,
     _UPPER,
};


/* #define CTRL_ESC MT(MOD_LCTL, KC_ESC) */
/* #define SFT_TAB MT(MOD_LSFT, KC_TAB) */
#define UPR_SPC LT(_UPPER, KC_SPC)
#define UPR_ENT LT(_UPPER, KC_ENT)
#define SCRN_SHOT LCTL(LSFT(LGUI(KC_4)))

#define TAB_NEXT  LCTL(KC_TAB)
#define TAB_PREV  LCTL(LSFT(KC_TAB))

// Define homerow mod keys
#define HRM_A LSFT_T(KC_A)    // A - Left Shift
#define HRM_R LCTL_T(KC_R)    // R - Left Ctrl
#define HRM_S LALT_T(KC_S)    // S - Left Alt
#define HRM_T LGUI_T(KC_T)    // T - Left GUI
#define HRM_G HYPR_T(KC_G)   // G - Hyper

#define HRM_M HYPR_T(KC_M)   // M - Hyper
#define HRM_N RGUI_T(KC_N)    // N - Right GUI
#define HRM_E RALT_T(KC_E)    // E - Right Alt
#define HRM_I RCTL_T(KC_I)    // I - Right Ctrl
#define HRM_O RSFT_T(KC_O)    // O - Right Shift


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS,  HRM_A,   HRM_R,   HRM_S,   HRM_T,   HRM_G,                              HRM_M,   HRM_N,   HRM_E,   HRM_I,   HRM_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    SCRN_SHOT,         _______,  KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC,  UPR_ENT, KC_LSFT,                   KC_BSPC, UPR_SPC, KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_UPPER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, _______, _______, _______, _______,  _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      RM_TOGG, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______,  _______,                           KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______,  _______, _______, _______, _______, _______,          _______, _______,TAB_PREV,TAB_NEXT, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',          'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',          'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',          'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L','R', 'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',          'R', 'R', 'R'
    );
