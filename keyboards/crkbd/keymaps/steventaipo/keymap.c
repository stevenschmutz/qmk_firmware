#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
 _TAIPO,
 _INNER,  // held while the inner thumb (Backspace) is down
 _OUTER,  // held while the outer thumb (Space) is down
 _BOTH,   // held while both thumbs are down together
};

// custom.h/sm_td.h/aliases.c/macros.h/tapdance.ref (SMTD home-row mods, tap
// dance, and the CTRL_*/paste-cut-copy custom keycodes) were leftovers from
// the bigger stevenschmutz userspace this was copied from -- nothing in the
// _TAIPO layout or taipo combos below references any of it, so it was pure
// dead weight pushing the firmware over the flash limit. Removed. No custom
// process_record_user is needed either: the layout is plain keycodes and
// the taipo combos are handled entirely by process_combo_event in
// g/keymap_combo.h, so QMK's default weak process_record_user is enough.
#include "g/keymap_combo.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Default taipo flavor (see users/steventaipo/taipo_default.def). Both
  // hands carry the same letters -- combos.def-based combos match by
  // keycode, not physical position, so either hand (or a mix of both)
  // can form any chord.
  [_TAIPO] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_R,          KC_S,      KC_N,         KC_I,   KC_NO,          KC_NO,   KC_I,       KC_N,       KC_S,       KC_R,   KC_NO,
        KC_NO, KC_A,          KC_O,      KC_T,         KC_E,    KC_NO,         KC_NO,    KC_E,       KC_T,       KC_O,       KC_A,   KC_NO,
                                  // The unused outermost left thumb slot is a manual
                                  // EEPROM-clear key -- not load-bearing now that
                                  // keyboard_post_init_user() resyncs on every boot, but
                                  // handy to keep around for a VIA-enabled board.
                                  QK_CLEAR_EEPROM, LT(_INNER, KC_BSPC), LT(_OUTER, KC_SPC),   LT(_OUTER, KC_SPC), LT(_INNER, KC_BSPC), KC_NO
    ),

  // Held while the inner thumb (Backspace) is down. Single letters here are
  // straight substitutions for the old "letter + Backspace" combos; letter
  // pairs/triples still combo together (see taipo_default.def's tpInner*
  // combos) to reach the rest of what used to be *It chords.
  [_INNER] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_GT,         KC_RCBR,   KC_RBRC,      KC_RPRN, KC_NO,         KC_NO,   KC_RPRN,    KC_RBRC,    KC_RCBR,    KC_GT,  KC_NO,
        KC_NO, KC_LT,         KC_LCBR,   KC_LBRC,      KC_LPRN, KC_NO,         KC_NO,   KC_LPRN,    KC_LBRC,    KC_LCBR,    KC_LT,  KC_NO,
                                  KC_NO, KC_TRNS,      KC_TRNS,                KC_TRNS,    KC_TRNS, KC_NO
    ),

  // Held while the outer thumb (Space) is down. Single letters are shifted
  // letters (the old *Ot singles); pairs/triples combo per taipo_default.def's
  // tpOuter* combos.
  [_OUTER] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, S(KC_R),       S(KC_S),   S(KC_N),      S(KC_I), KC_NO,         KC_NO,   S(KC_I),    S(KC_N),    S(KC_S),    S(KC_R), KC_NO,
        KC_NO, S(KC_A),       S(KC_O),   S(KC_T),      S(KC_E), KC_NO,         KC_NO,   S(KC_E),    S(KC_T),    S(KC_O),    S(KC_A), KC_NO,
                                  KC_NO, KC_TRNS,      KC_TRNS,                KC_TRNS,    KC_TRNS, KC_NO
    ),

  // Held while both thumbs are down together (reached via the tpBoth combo
  // in taipo_default.def, which chords the two thumb layer-tap keys).
  // Single letters are the old *ItOt singles (media/system keys); pairs
  // combo per taipo_default.def's tpBoth* combos to reach the F-keys.
  [_BOTH] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_PRINT_SCREEN, KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN, KC_MEDIA_PLAY_PAUSE, KC_NO,   KC_NO, KC_MEDIA_PLAY_PAUSE, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_PRINT_SCREEN, KC_NO,
        KC_NO, KC_MEDIA_NEXT_TRACK, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, KC_MEDIA_PREV_TRACK, KC_NO, KC_NO, KC_MEDIA_PREV_TRACK, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MEDIA_NEXT_TRACK, KC_NO,
                                  KC_NO, KC_TRNS,      KC_TRNS,                KC_TRNS,    KC_TRNS, KC_NO
    ),

};

void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...
}

// VIA/RAW_ENABLE's dynamic keymap is EEPROM-backed and is what actually gets
// read at runtime (keycode_at_keymap_location()), not this PROGMEM array
// directly -- the array only ever seeds EEPROM on a reset. In practice a
// QK_CLEAR_EEPROM press wasn't reliably resyncing it after a reflash (traced
// via the debug console: process_record_user kept seeing bare KC_BSPC
// instead of LT(_INNER, KC_BSPC)), so force the resync unconditionally on
// every boot instead. Tradeoff: any layout tweak made from the VIA GUI won't
// survive a power cycle -- fine while this keymap's source of truth is this
// file, not VIA.
void keyboard_post_init_user(void) {
  dynamic_keymap_reset();
}
