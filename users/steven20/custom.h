
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
    CKC_TAB,
    SMTD_KEYCODES_END,

    KC_LAYER0,
    KC_LAYER1,
    KC_LAYER2,
    KC_LAYER3,
    KC_MOD_GA,
    KC_MOD_GC,
    KC_MOD_GS,
    KC_MOD_AC,
    KC_MOD_AS,
    KC_MOD_RS,
    KC_MOD_CS,
    KC_MOD_GAC,
    KC_MOD_GAS,
    KC_MOD_GCS,
    KC_MOD_ACS,
    KC_MOD_GACS,

    // TD_ESC_CAPS,
    // TD_CEE_TEE,
    // TD_GEE_AITCH,
    // TD_ARR_EN,
    // TD_EL_ES,



    QK_LAYER_LOCK,
    CTRL_TICK,
    CTRL_CUT,
    CTRL_ALL,
    CTRL_COPY,
    CTRL_SAVE,
    CTRL_PASTE,
    CTRL_FIND,
    CTRL_UNDO,
    CTRL_C,
    CTRL_R,        
    SHIFT_ENTER,
    QUOTE_BOLD,
    SHOW_WORKSPACES
};

//Tap dance enums
enum {
    TD_CEE_TEE,
    TD_GEE_AITCH,
    TD_ARR_EN,
    TD_EL_ES,
    TD_ESC_LAYER,
    TD_QUOTE_A_BOLD,
    TD_COMMA_OH_CUT,
    TD_DOT_EE_LAYER_PARA,
    TD_PEE_U_LAYER_NUM,

};

// from https://getreuer.info/posts/keyboards/triggers/index.html
#define PEE_PASTE LT(0, KC_P)
#define QUOTE_BOLD LT(0, KC_QUOT)
#define COMMA_CUT LT(0, KC_COMM)
#define DOT_COPY LT(0, KC_DOT)
#define ALT_DOWN LT(0, KC_Z)
