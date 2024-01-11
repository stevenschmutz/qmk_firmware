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
};

// Details taken from keyboards/crkbd/keymaps/markstos/keymap.c
enum combos {
  DF_DASH,
  JK_ESC
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  // Add commonly used dash to home row
  [DF_DASH]    = COMBO(df_combo, KC_MINS),
  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),
};

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  CTRL_TICK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, LGUI_T(KC_QUOT), KC_COMM, KC_DOT, LCTL_T(KC_P), KC_Y,                         KC_F, KC_G, KC_C, KC_R, KC_L, KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, KC_A, KC_O, KC_E, KC_U, LT(3,KC_I),                                          KC_D, KC_H, KC_T, KC_N, KC_S, KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, LSFT_T(KC_SCLN), KC_Q, KC_J, KC_K, KC_X,                             KC_B, KC_M, KC_W, KC_V, RSFT_T(KC_Z), KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        LCTL_T(KC_ESC), LSFT_T(KC_TAB), LT(2,KC_SPC),                     SC_SENT, LT(1,KC_BSPC), LALT_T(KC_DEL)

            ),


	[_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_GRV, KC_CIRC, KC_AT, KC_DLR, KC_TILD,                                 KC_AMPR, KC_EXLM, KC_PIPE, KC_UNDS, KC_HASH, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_SLSH, KC_LBRC, KC_LCBR, KC_LPRN, KC_SLSH,                              KC_HASH, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_TRNS, KC_QUES, KC_GRV, KC_PERC, KC_QUES,                                 KC_PSCR, KC_BSLS, KC_COLN, KC_TRNS, KC_TRNS, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, QK_BOOT),


	[_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_PGDN, KC_UP, KC_PGUP, KC_END, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_NO, KC_NO, UPDIR, KC_F2, CTRL_TICK,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,
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
                KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_EQL)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;
    case CTRL_TICK:  // Types ctrl + backtick
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("`"));
      }
      return false;
  }
  return true;
}



