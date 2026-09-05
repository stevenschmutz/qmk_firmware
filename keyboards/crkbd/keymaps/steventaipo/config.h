#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 7

// The _INNER/_OUTER/_BOTH layers are reached by holding a thumb key
// (LT(...)) and tapping a letter. Without this, QMK's default tap-hold
// timing only commits the thumb key as a "hold" if it's held alone for the
// full TAPPING_TERM before the letter is pressed -- chording them together
// quickly (the old combo-era muscle memory) instead resolves the thumb key
// as a tap, so you'd get plain Backspace/Space + the base-layer letter.
// This makes any other keypress while a thumb key is down commit it as a
// hold immediately, regardless of timing.
#define HOLD_ON_OTHER_KEY_PRESS
