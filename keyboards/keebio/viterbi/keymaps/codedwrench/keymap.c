#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _GAME 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  GAME
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |Numlck| `    |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |Bckspc|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn| Esc  |A,GUI |S,Alt |D,Shft|F,Ctrl|   G  |      |   H  |J,Ctrl|K,Shft|L,Alt |;,GUI |   "  | Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   \  | Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Shift|  =   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Print| Ctrl | Lower| GUI  | Alt  |SpcFN |SpcFN |      |Home  | End  | Alt  | Menu | Raise| Ctrl | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_NLCK, KC_GRV              , KC_1               , KC_2               , KC_3                , KC_4                , KC_5               , KC_6      , KC_7               , KC_8               , KC_9               , KC_0                 , KC_MINS              , KC_BSPC,
    KC_PGUP, KC_TAB              , KC_Q               , KC_W               , KC_E                , KC_R                , KC_T               , KC_Y      , KC_U               , KC_I               , KC_O               , KC_P                 , KC_LBRC              , KC_RBRC,
    KC_PGDN, KC_ESC              , MT(MOD_LGUI, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LSFT, KC_D)  , MT(MOD_LCTL, KC_F)  , KC_G               , KC_H      , MT(MOD_RCTL, KC_J) , MT(MOD_RSFT, KC_K) , MT(MOD_RALT, KC_L) , MT(MOD_RGUI, KC_SCLN), KC_QUOT              , KC_ENT ,
    KC_BSLS, KC_LSFT             , KC_Z               , KC_X               , KC_C                , KC_V                , KC_B               , KC_N      , KC_M               , KC_COMM            , KC_DOT             , KC_SLSH              , KC_RSFT              , KC_EQL ,
    KC_PSCR, KC_LCTL             , LOWER              , KC_LGUI            , KC_LALT             , LT(_LOWER, KC_SPC)  , LT(_RAISE, KC_SPC) , KC_HOME   , KC_END             , KC_RALT            , KC_MENU            , RAISE                , KC_RCTL              , KC_DEL
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  |      |      |      |      |      |      |      | Left |Down  |Up    |Right |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9    , KC_F10 , KC_F11 , KC_F12 ,
    KC_MINS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9     , KC_0   , KC_MINS, KC_EQL ,
    KC_EQL , KC_TAB , _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT , _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______  , _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD  , KC_VOLU, KC_MPLY, KC_MUTE
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   _  |   +  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pause|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |ScrLck|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Prev | Next | Play | Vol- | Vol+ | Mute |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    KC_PAUS, KC_TAB , _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    KC_SLCK, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, KC_INS , _______, _______, _______, _______, _______,     _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE
  ),

/* Adjust
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | RESET|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  | F10  | F11  | F12  | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Caps |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pause|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |ScrLck|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |Insert|      |      |      |      |      |      | GAME | Prev | Next | Play | Vol- | Vol+ | Mute |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_ADJUST] = LAYOUT_ortho_5x14(
    RESET  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 ,  KC_F11, KC_F12 , KC_DEL ,
    KC_CLCK, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
    KC_PAUS, KC_TAB , _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    KC_SLCK, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, KC_INS , _______, _______, _______, _______, _______,     DF(_GAME), KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE
  ),

/* GAME
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | Esc  | `    |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |BckSpc|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |ScrlUp|ScrlDn|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  | Enter| Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Shift|  =   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl | Ctrl |MacPly| GUI  | Alt  |Space |Space |      |Space |Space | Alt  | Menu |MacRec| Ctrl |QWERTY|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_GAME] = LAYOUT_ortho_5x14(
    KC_ESC  , KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4   , KC_5     , KC_6   , KC_7   , KC_8    , KC_9    , KC_0    , KC_MINS , KC_BSPC,
    KC_TAB  , KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R   , KC_T     , KC_Y   , KC_U   , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC,
    KC_WH_U , KC_WH_D , KC_A    , KC_S    , KC_D    , KC_F   , KC_G     , KC_H   , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_ENT  , KC_ENT ,
    KC_LSFT , KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V   , KC_B     , KC_N   , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_EQL ,
    KC_LCTL , KC_LCTL , DM_PLY1 , KC_LGUI , KC_LALT , KC_SPC , KC_SPC   , KC_SPC , KC_SPC , KC_RALT , KC_MENU , DM_REC1 , KC_RCTL , DF(_QWERTY)
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
