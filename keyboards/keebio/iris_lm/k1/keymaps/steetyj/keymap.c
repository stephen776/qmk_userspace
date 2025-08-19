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
#define CUT      LGUI(KC_X)
#define COPY     LGUI(KC_C)
#define PASTE    LGUI(KC_V)

// Define homerow mod keys
#define HRM_A LGUI_T(KC_A)    // A - Left GUI
#define HRM_R LALT_T(KC_R)    // R - Left Alt
#define HRM_S LCTL_T(KC_S)    // S - Left Ctrl
#define HRM_T LSFT_T(KC_T)    // T - Left Shift
#define HRM_G HYPR_T(KC_G)   // G - Hyper

#define HRM_M HYPR_T(KC_M)   // M - Hyper
#define HRM_N RSFT_T(KC_N)    // N - Right Shift
#define HRM_E RCTL_T(KC_E)    // E - Right Ctrl
#define HRM_I RALT_T(KC_I)    // I - Right Alt
#define HRM_O RGUI_T(KC_O)    // O - Right Gui

// lock mac with 4 corners combo
const uint16_t PROGMEM lock_combo[] = {
    KC_GRV, KC_EQL, KC_LBRC, KC_RBRC, COMBO_END
};

combo_t key_combos[] = {
    COMBO(lock_combo, LGUI(LCTL(KC_Q))),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  HRM_A,   HRM_R,   HRM_S,   HRM_T,   HRM_G,                              HRM_M,   HRM_N,   HRM_E,   HRM_I,   HRM_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    SCRN_SHOT,         CW_TOGG,  KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC,  UPR_ENT, KC_TAB,                    KC_BSPC,  KC_SPC, KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_UPPER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_TOGG, _______, _______, TAB_PREV,TAB_NEXT, _______,                            _______, KC_HOME,  KC_UP,   KC_END,  KC_PGUP, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  _______, _______,  _______,                           KC_ESC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______,  CUT,     COPY,   _______, PASTE,    _______,          _______, _______, _______, _______, _______, _______, _______,
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
                       'L', '*', 'L',          'R', 'R', 'R'
    );

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(170, 255, 128);
}
