#include QMK_KEYBOARD_H
#include "custom.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _ALPHA1,
//    _NAV,
//    _ART_MOU,
    _ART_BASE,
    _ART_NUM,
    _ART_CUS,
    _ART_PARA,
    _ART_NAV,
    _ART_SYM,    
};


#include "sm_td.h"
#include "aliases.c"
#include "g/keymap_combo.h"
#include "macros.h"
#include "tapdance.ref"

/*
// copied from https://beta.docs.qmk.fm/faqs/faq_debug#which-matrix-position-is-this-keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
*/

/* 

NOTE: 2025-May-31 - Mouse layer not working because there's no firrmware space anymore :(

Layer lock
https://getreuer.info/posts/keyboards/layer-lock/index.html (in use)
https://docs.qmk.fm/features/layer_lock#how-do-i-enable-layer-lock (newer version)


*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                       KC_NO,TD(TD_QUOTE_A_BOLD), TD(TD_COMMA_OH_CUT),
                          TD(TD_DOT_EE_LAYER_PARA) ,TD(TD_PEE_U_LAYER_NUM), KC_NO,
                                                                                    KC_NO , TD(TD_GEE_AITCH) , TD(TD_CEE_TEE) , TD(TD_ARR_EN), TD(TD_EL_ES),KC_NO,

                      KC_NO,CKC_SCLN, TD(TD_Q_WORKSPACE), CKC_J,LT(_ART_SYM,KC_K), KC_NO,                     KC_NO, CKC_M, KC_W, KC_V, ALT_DOWN,KC_NO,
      //,-----------------------------------------------------.                    -----------------------------------------------------.
                                 KC_NO,  KC_TAB, LT(_ART_NAV,KC_SPC),                            RSFT_T(KC_ENT), LT(_ART_BASE,KC_DOT), KC_NO

                ),

  
/*
    [_NAV] = LAYOUT_split_3x6_3(
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_NO,   KC_VOLU, MOU_1_3, MOU_1_2,MOU_1_1 , MOU_1_4,                        KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO,
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_VOLD, MOU_2_1, MOU_2_2, MOU_2_3, CTRL_TICK,                           KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,KC_NO,
          //,--------------             ---------------------------------------.                    ,-----------------------------------------------------.
       KC_NO,  KC_MUTE,KC_NO,MS_BTN3,KC_DEL,MOU_2_4,                                 LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RBRC),KC_NO,KC_TRNS,KC_NO,
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                 KC_NO,  QK_LAYER_LOCK,KC_TRNS,                                              KC_TRNS, KC_NO, KC_NO
                 ),

*/

    [_ART_BASE] = LAYOUT_split_3x6_3 (
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,LEFT_1_4,        LEFT_1_3,    LEFT_1_2,       LEFT_1_1, KC_NO,                           KC_NO, BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,LEFT_2_4,        LEFT_2_3,    LEFT_2_2,       LEFT_2_1,KC_NO,                          KC_NO, BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,QK_LAYER_LOCK,LT(_ART_NAV,KC_NO),                                              KC_NO,KC_NO,KC_NO),



    [_ART_NUM] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, NUM_1_1, NUM_1_2, NUM_1_3, NUM_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, NUM_2_1, NUM_2_2, NUM_2_3, NUM_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,QK_LAYER_LOCK,KC_NO,                                              KC_NO,KC_NO,KC_NO),

 /*   [_ART_CUS] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, CUS_1_1, CUS_1_2, CUS_1_3, CUS_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, CUS_2_1, CUS_2_2, CUS_2_3, CUS_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO,KC_NO, QK_LAYER_LOCK),

*/
    [_ART_PARA] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, PUNC_1_1, PUNC_1_2, PUNC_1_3, PUNC_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, PUNC_2_1, PUNC_2_2, PUNC_2_3, PUNC_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,QK_LAYER_LOCK,KC_NO,                                              KC_NO,KC_NO,KC_NO),


/*    [_ART_MOU] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, MOU_1_1, MOU_1_2, MOU_1_3, MOU_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, MOU_2_1, MOU_2_2, MOU_2_3, MOU_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO,KC_NO, QK_LAYER_LOCK),
*/
    [_ART_NAV] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,CTRL_TICK,KC_NO,                                          KC_NO, NAV_1_1, NAV_1_2, NAV_1_3, NAV_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, NAV_2_1, NAV_2_2, NAV_2_3, NAV_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,QK_LAYER_LOCK,KC_NO,                                              KC_NO,KC_NO,KC_NO),

    [_ART_SYM] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, SYM_1_1, SYM_1_2, SYM_1_3, SYM_1_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, SYM_2_1, SYM_2_2, SYM_2_3, SYM_2_4,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,QK_LAYER_LOCK,KC_NO,                                              KC_NO,KC_NO,KC_NO),




};

void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...
}
