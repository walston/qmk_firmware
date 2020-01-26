#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define LFUN 1 // function layer
#define LNUM 2 // num-pad
#define LMDA 3 // media keys

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *d
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐       ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │       │  7  │  8  │  9  │  0  │  -  │  =  │ BkSp     │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘    ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ Tab    │  Q  │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │ \     │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │ Ctrl    │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │ LShift   │  Z  │  X  │  C  │  V  │  B  │       │  N  │  M  │  <  │  >  │  ?  │Shift│ Up  │ Ly3 │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘      ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ Ly2  │ Alt │ Cmd  │             │ Ly1 │       │               │ Cmd   │ Alt  │ Left│ Down│Right│
 * └------┴-----┴------┴-------------┴-----┘       └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[BASE] = LAYOUT_ymdk_sp64(
  // left hand
  MT(RESET, KC_GRAVE), KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,
  KC_TAB,              KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,
  KC_LCTL,             KC_A,    KC_S,    KC_D,     KC_F,    KC_G,
  KC_LSFT,             KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,
  LT(LNUM, KC_NO),   KC_LALT, KC_LGUI, KC_SPACE, LT(LFUN, KC_SPACE),
  // right hand
  KC_7,     KC_8,    KC_9,    KC_0,    KC_MINUS,  KC_EQUAL,                 KC_BSPACE,
  KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRACKET,   KC_RBRACKET, KC_BSLS,
  KC_H,     KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,                  KC_ENTER,
  KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,     KC_UP, LT(LFUN, KC_NO),
  KC_SPACE,          KC_RGUI, KC_RALT,            KC_LEFT,   KC_DOWN,        KC_RIGHT
),
/* Keymap 1: Function Layer / Vim Arrows
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐       ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │ Esc │ F1  │  F2 │ F3  │ F4  │ F5  │ F6  │       │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘    ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │       │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │       │     │Left │ Up  │Down │Right│     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │       │     │     │     │     │     │     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘      ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ Ly2  │     │      │             │ Ly1 │       │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘       └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[LFUN] = LAYOUT_ymdk_sp64(
  // left hand
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  // right hand
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,           KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, KC_TRNS,          KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,          KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: NumPad
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐       ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │     │     │     │     │     │     │     │       │  7  │  8  │  9  │     │ Vol-│ Vol+│ Mute     │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘    ┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │       │     │  4  │  5  │  6  │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │       │     │  1  │  2  │  3  │     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │       │     │  0  │     │     │     │     │     │ Ly3 │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘      ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ Ly2  │     │      │             │ Ly1 │       │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘       └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[LNUM] = LAYOUT_ymdk_sp64(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  // right hand
  KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_VOLU,  KC_VOLD,          KC_MUTE,
  KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_P1,   KC_P2,   KC_P3,   KC_DOWN, KC_RIGHT, KC_TRNS,          KC_TRNS,
  KC_P0,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,          KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐       ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │     │     │     │     │     │     │     │       │     │     │     │     │     │     │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘    ┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │       │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │       │     │     │     │     │     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐      └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │       │     │     │     │     │     │     │     │ Ly3 │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘      ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ Ly2  │     │      │             │ Ly1 │       │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘       └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[LMDA] = LAYOUT_ymdk_sp64(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}
