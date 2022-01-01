#include QMK_KEYBOARD_H

//define layers
enum layers {
    base,
    app,
    sreset
};

//define emojis
enum unicode_names {
    ROCKET,  // 🚀
    COOL, // 😎
};

//define unicodes for emojis
const uint32_t PROGMEM unicode_map[] = {
    [ROCKET] = 0x1F680,
    [COOL] = 0x1F60E,
};

//define custom macros
enum custom_keycodes {

  //BASE LAYER
  OPENFIGMA = SAFE_RANGE,
  OPENMIRO,
  OPENCURA,
  OPENONSHAPE,

  OPENSLACK,
  OPENASANA,
  OPENFLOW,
  OPENSAFARI,

  SYSPREF, 
  VOLMUTE, 

  WINLEFT,
  MAXIMISE,
  WINRIGHT,

  //APP LAYER 
  COMPONENT,
  GROUP,
  FRAME,
  OUTLINESTROKE,

  SKETCH,
  EXTRUDE,
  FILLET,

  UNDO, //i want to add REDO soon
  COPY,
  PASTE,
  

};

//define 'keymap' array. each position corresponds to a single button on the 4x4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //base layer
    [base]=LAYOUT_ortho_4x4(
        OPENFIGMA, OPENMIRO, OPENCURA, OPENONSHAPE,
        OPENSLACK, OPENASANA, OPENFLOW, OPENSAFARI,
        SYSPREF, VOLMUTE, X(ROCKET), X(COOL),
        TG(app), WINLEFT, MAXIMISE, WINRIGHT
        ),
   //app layer
    [app]=LAYOUT_ortho_4x4(
        COMPONENT, GROUP, FRAME, OUTLINESTROKE,
        SKETCH, EXTRUDE, FILLET, KC_O,
        UNDO, COPY, PASTE, KC_R,
        TG(app), KC_NO, MO(sreset), KC_NO
        ),
    //soft reset layer
    [sreset]=LAYOUT_ortho_4x4(
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_TRNS, RESET
        )
};

//macros send string
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case OPENFIGMA:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_8))));
        }
        break;

    case OPENMIRO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_7))));
        }
        break;

    case OPENCURA:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_6))));
        }
        break;

    case OPENONSHAPE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_5))));
        }
        break;

    case OPENSLACK:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_4))));
        }
        break;

    case OPENASANA:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_3))));
        }
        break;

    case OPENFLOW:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_2))));
        }
        break;

    case OPENSAFARI:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_1))));
        }
        break;

    case SYSPREF:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LCMD(SS_TAP(X_COMM))));
        }
        break;

    case VOLMUTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X__MUTE));
        }
        break;

    case WINLEFT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_LEFT))));
            
        }
        break;

    case MAXIMISE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_ENTER))));
        }
        break;

    case WINRIGHT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_RIGHT))));
        }
        break;

    case COMPONENT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCMD(SS_LALT(SS_TAP(X_K))));
        }
        break;

    case GROUP:
        if (record->event.pressed) {
           SEND_STRING(SS_LCMD(SS_TAP(X_G)));
        }
        break;

    case FRAME:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_LCMD(SS_TAP(X_G))));
        }
        break;

    case OUTLINESTROKE:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LCMD(SS_TAP(X_O))));
        }
        break;

    case SKETCH:
        if (record->event.pressed) {
           SEND_STRING(SS_LSFT(SS_TAP(X_S)));
        }
        break;

    case EXTRUDE:
        if (record->event.pressed) {
           SEND_STRING(SS_LSFT(SS_TAP(X_E)));
        }
        break;

    case FILLET:
        if (record->event.pressed) {
           SEND_STRING(SS_LSFT(SS_TAP(X_F)));
        }
        break;

    case UNDO:
        if (record->event.pressed) {
           SEND_STRING(SS_LCMD(SS_TAP(X_Z)));
        }
        break;

    case COPY:
        if (record->event.pressed) {
           SEND_STRING(SS_LCMD(SS_TAP(X_C)));
        }
        break;

    case PASTE:
        if (record->event.pressed) {
           SEND_STRING(SS_LCMD(SS_TAP(X_V)));
        }
        break;
    }
    return true;
};
