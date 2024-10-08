#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _DVORAK,
    _SYMBOL,
    _NAV,
    _NUMERIC,
    _ART_MOU,
};

#include "aliases.c"
#include "g/keymap_combo.h"
enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  CTRL_TICK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, LGUI_T(KC_QUOT), KC_COMM, KC_DOT, KC_P, KC_Y,                         KC_F, KC_G, KC_C, KC_R, KC_L, KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, KC_A, KC_O, KC_E, KC_U, LT(3,KC_I),                                          KC_D, KC_H, KC_T, KC_N, KC_S, KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, LSFT_T(KC_SCLN), KC_Q, KC_J, KC_K,  LT(_ART_MOU,KC_X),                            KC_B, KC_M, KC_W, KC_V, RSFT_T(KC_Z), KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_TRNS, LSFT_T(KC_TAB), LT(2,KC_SPC),                     SC_SENT, LT(1,KC_BSPC), KC_TRNS

            ),


	[_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_GRV, KC_CIRC, KC_AT, KC_DLR, KC_TILD,                                 KC_AMPR, KC_EXLM, KC_PIPE, KC_UNDS, KC_HASH, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_SLSH, KC_LBRC, KC_LCBR, KC_LPRN, KC_SLSH,                              KC_HASH, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_TRNS, KC_QUES, KC_GRV, KC_PERC, KC_QUES,                                 KC_TRNS, KC_BSLS, KC_COLN, KC_TRNS, KC_TRNS, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, QK_BOOT),


	[_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_PGDN, KC_UP, KC_PGUP, KC_END, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_F2, CTRL_TICK,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,                                     LCTL(KC_UP), LCTL(KC_DOWN), KC_NO, KC_NO, KC_TRNS, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            QK_BOOT, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS),


	[_NUMERIC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,                                     KC_PLUS, KC_7, KC_8, KC_9, KC_SLSH, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,                                       KC_0, KC_4, KC_5, KC_6, KC_DOT, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4,                                       KC_MINS, KC_1, KC_2, KC_3, KC_ASTR, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_EQL),

[_ART_MOU] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_MS_BTN4, MOU_1_1, MOU_1_2, MOU_1_3, MOU_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_MS_BTN5, MOU_2_1, MOU_2_2, MOU_2_3, MOU_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,TG(_ART_MOU),                                         KC_NO,KC_NO,KC_MS_BTN3,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO,KC_NO,KC_NO),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case CTRL_TICK:  // Types ctrl + backtick
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("`"));
      }
      return false;

  }
  return true;
}
