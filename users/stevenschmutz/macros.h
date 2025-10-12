

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}


// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
// From : https://getreuer.info/posts/keyboards/triggers/index.html
static bool process_tap_or_long_press_key (
    keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

   if (!process_smtd(keycode, record)) {
        return false;
    }
    if (!process_layer_lock(keycode, record, QK_LAYER_LOCK)) { 
      return false; 
    }


 const uint8_t mods = get_mods();
 const uint8_t oneshot_mods = get_oneshot_mods();


 switch (keycode) {
    case CTRL_TICK:  // Types ctrl + backtick
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("`"));
      }
        return false;
        break;


    case BRACES:  // Types [], {}, or <> and puts cursor between braces.
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING("{}");
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING("[]");
      } else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
        SEND_STRING("<>");
      } else {
        SEND_STRING("()");
      }
      tap_code(KC_LEFT);  // Move cursor between braces.
      register_mods(mods);  // Restore mods.
    }            
  return false;
  break;

    case ENTER_VARIATIONS:  // Types shift_enter or alt_enter.
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
      } else {
        SEND_STRING("}");
      }
      register_mods(mods);  // Restore mods.
    }            
  return false;
  break;

    case KC_BSPC: {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
        uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
        uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }

        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    } return false;



    case PEE_PASTE:  // Comma on tap, Ctrl+C on long press.
      layer_state_set_user(get_highest_layer(layer_state)); //Change the colour back to the current level
      return process_tap_or_long_press_key(record, C(KC_V));
      break;

   case DOT_COPY:  // Dot on tap, Ctrl+V on long press.
  #ifdef  OLED_ENABLE
      rgblight_sethsv(HSV_GOLD);  //Change the led to show it's been copied
  #endif
      
      return process_tap_or_long_press_key(record, C(KC_C));
    break;

    case COMMA_CUT:  // Dot on tap, Ctrl+X on long press.
      return process_tap_or_long_press_key(record, C(KC_X));
    break; 


    case ALT_DOWN:  // Dot on tap, Ctrl+X on long press.
      return process_tap_or_long_press_key(record, A(KC_DOWN));
    break;
  
    case CTRL_CUT:  // Types ctrl + x
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("x"));
      }
          return false;
        break;
        
    case CTRL_COPY:  // Types ctrl + C
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("c"));
      }
          return false;
        break;
    case CTRL_PASTE:  // Types ctrl + V
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("v"));
      }
        return false;
        break;
        
    case CTRL_SAVE:  // Types ctrl + S
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("s"));
      }
          return false;
        break;

    case CTRL_FIND:  // Types ctrl + f
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("f"));
      }
          return false;
        break;

    case CTRL_UNDO:  // Types ctrl + z
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("z"));
      }
          return false;
        break;

    case SHIFT_CTRL_COPY:  // Types ctrl + Shift+c
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LCTL("c")));
      }
          return false;
        break;


    case SHIFT_CTRL_PASTE:  // Types ctrl + shift + v
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LCTL("v")));
      }
          return false;
        break;
   
    case SHIFT_CTRL_HOME:  // Types ctrl + shift + home
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_HOME))));
      }
          return false;
        break;
   
    case SHIFT_CTRL_END:  // Types ctrl + shift + home
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_END))));
      }
          return false;
        break;
    
    case CTRL_R:  // Types ctrl + f
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("r"));
      }
          return false;
        break;
    
    case CTRL_C:  // Types ctrl + f
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("c"));
      }
          return false;
        break;




      return true;
   }






  return process_record_keymap(keycode, record);
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI, 2)
        SMTD_MT(CKC_SCLN, KC_SCLN, KC_LEFT_GUI, 2)
        SMTD_MT(CKC_O, KC_O, KC_LALT, 2)
        SMTD_MT(CKC_E, KC_E, KC_E, 2)
        SMTD_MT(CKC_U, KC_U, KC_U, 2)
        //SMTD_MT(CKC_S, KC_S, KC_S, 2)
        //SMTD_MT(CKC_N, KC_N, KC_N, 2)
        SMTD_MT(CKC_N, KC_N, KC_N, 2)
        SMTD_MT(CKC_H, KC_H, KC_LSFT, 2)
        SMTD_MT(CKC_D, KC_D, KC_D, 2)
        //SMTD_LT(CKC_K, KC_K, _SECOND_SYMBOLS)
        //SMTD_LT(CKC_M, KC_M, _SECOND_SYMBOLS)
        //SMTD_LT(CKC_I, KC_I, _NAVIGATION)
        SMTD_MT(CKC_M, KC_M, KC_RSFT, 2)
        SMTD_MT(CKC_K, KC_K, KC_LSFT, 2)
        SMTD_MT(CKC_Q, KC_Q, KC_LALT, 2)
        SMTD_MT(CKC_J, KC_J, KC_LEFT_CTRL, 2)
      }
}
