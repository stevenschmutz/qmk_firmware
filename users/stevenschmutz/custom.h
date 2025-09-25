
enum custom_keycodes {
  SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    CKC_O,
    CKC_E,
    CKC_U,
    CKC_S,
    CKC_N,
    CKC_T,
    CKC_H,
    CKC_M,
    CKC_K,
    CKC_I,
    CKC_Y,
    CKC_X,
    CKC_D,
    CKC_J,
    CKC_Q,
    CKC_SCLN,
    CKC_ESC,
    CKC_SPC,
    SMTD_KEYCODES_END,

    QK_LAYER_LOCK,
    CTRL_TICK,
    CTRL_CUT,
    CTRL_COPY,
    CTRL_SAVE,
    CTRL_PASTE,
    CTRL_FIND,
    CTRL_UNDO,
    CTRL_C,
    CTRL_R,        
    SHIFT_CTRL_COPY,
    SHIFT_CTRL_PASTE,
    SHIFT_CTRL_HOME,
    SHIFT_CTRL_END,
    SHORTCUT_QU,
};

// from https://getreuer.info/posts/keyboards/triggers/index.html
#define PEE_COPY LT(0, KC_P)
#define COMMA_CUT LT(0, KC_COMM)
#define DOT_PASTE LT(0, KC_DOT)
#define SHORTCUT_QU LT(0, CKC_Q)