#include QMK_KEYBOARD_H
#include "donotcommit.h"

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Create an instance of 'tap' for the 'left alt' tap dance.
static tap lalttap_state = {
    .is_press_action = true,
    .state = 0
};

// Create an instance of 'tap' for the 'f15' tap dance.
static tap f15tap_state = {
    .is_press_action = true,
    .state = 0
};

enum custom_keycodes {
   FILL_PASSWORD = SAFE_RANGE,
};

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the f15 tap dance. Put it here so it can be used in any keymap
void f15_finished(qk_tap_dance_state_t *state, void *user_data);
void f15_reset(qk_tap_dance_state_t *state, void *user_data);

// For the alt tap dance. Put it here so it can be used in any keymap
void alt_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_reset(qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-------------------------------.
 * |   7   |   8   |   9   | 0/<-- |
 * |-------+-------+-------+-------|
 * |   4   |   5   |   6   |   .   |
 * |-------+-------+-------+-------|
 * |   1   |   2   |   3   |  ENT  |
 * `-------------------------------'
 */
[0] = LAYOUT( \
  KC_KP_7,              KC_KP_8,      KC_KP_9,      TD(0),                  \
  KC_KP_4,              KC_KP_5,      KC_KP_6,      KC_KP_DOT,               \
  KC_KP_1,              KC_KP_2,      KC_KP_3,	    LT(1, KC_KP_ENTER)       \
),

/* LAYER 1
 * ,-------------------------------.
 * |  NUM  |   /   |   *   |   -   |
 * |-------+-------+-------+-------|
 * | RESET |   5   |   6   |   +   |
 * |-------+-------+-------+-------|
 * |   1   |   2   |   3   |  ENT  |
 * `-------------------------------'
 */
[1] = LAYOUT( \
  KC_NUMLOCK,           KC_KP_SLASH,         KC_KP_ASTERISK,      KC_KP_MINUS,    \
  RESET,                KC_KP_5,             KC_KP_6,             KC_KP_PLUS,     \
  DF(2),                DF(3),               KC_KP_3,             KC_KP_ENTER     \
),

/* LAYER 2
 * ,---------------------------.
 * |  F21  |ENTER | FP  | TAB  |
 * |-------+------+-----+------|
 * |  F17  | F18  | F19 | F20  |
 * |-------+------+-----+------|
 * |  F13  | F14  | F15 | F16  |
 * `---------------------------'
 */
[2] = LAYOUT( \
  KC_F21,         KC_ENTER,  FILL_PASSWORD,        KC_TAB,    \
  KC_F17,         KC_F18,    KC_F19,               KC_F20,     \
  KC_F13,         KC_F14,    TD(1),                KC_F16     \
),

/* LAYER 3 - Gaming (keyboard mode)
 * ,-----------------------.
 * |  Q  |  W  |  E  |  R  |
 * |-----+-----+-----+-----|
 * |  A  |  S  |  D  |  F  |
 * |-----+-----+-----+-----|
 * |SHIFT|CTRL | ALT |SPACE|
 * `-----------------------'
 */
[3] = LAYOUT( \
  KC_Q    ,  KC_W    , KC_E ,      KC_R,        \
  KC_A    ,  KC_S    , KC_D ,      KC_F,        \
  KC_LSFT ,  KC_LCTL , TD(2),	   KC_SPACE     \
)
};


uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

void f15_finished(qk_tap_dance_state_t *state, void *user_data) {
    f15tap_state.state = cur_dance(state);
    switch (f15tap_state.state) {
        case SINGLE_TAP: register_code(KC_F15); break;
        case SINGLE_HOLD: register_code(KC_F15); break;
        case DOUBLE_TAP: register_code(KC_F15); break;
        case DOUBLE_HOLD: set_single_persistent_default_layer(0); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_F15); register_code(KC_F15); break;
        case TRIPLE_TAP: tap_code(KC_F15); tap_code(KC_F15); register_code(KC_F15);
    }
}

void f15_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (f15tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_F15); break;
        case SINGLE_HOLD: unregister_code(KC_F15); break;
        case DOUBLE_TAP: unregister_code(KC_F15); break;
        case DOUBLE_HOLD: break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_F15);
        case TRIPLE_TAP: unregister_code(KC_F15);
    }
    f15tap_state.state = 0;
}

void alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    lalttap_state.state = cur_dance(state);
    switch (lalttap_state.state) {
        case SINGLE_TAP: register_code(KC_LALT); break;
        case SINGLE_HOLD: register_code(KC_LALT); break;
        case DOUBLE_TAP: register_code(KC_LALT); break;
        case DOUBLE_HOLD: set_single_persistent_default_layer(0); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_LALT); register_code(KC_LALT); break;
        case TRIPLE_TAP: tap_code(KC_LALT); tap_code(KC_LALT); register_code(KC_LALT);
    }
}

void alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lalttap_state.state) {
        case SINGLE_TAP: unregister_code(KC_LALT); break;
        case SINGLE_HOLD: unregister_code(KC_LALT); break;
        case DOUBLE_TAP: unregister_code(KC_LALT); break;
        case DOUBLE_HOLD: break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_LALT);
        case TRIPLE_TAP: unregister_code(KC_LALT);
    }
    lalttap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [0] = ACTION_TAP_DANCE_DOUBLE(KC_KP_0, KC_BSPC),
        [1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f15_finished, f15_reset),
        [2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset),
};		

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FILL_PASSWORD:
        if (record->event.pressed) {
            // when keycode FILL_PASSWORD is pressed
            SEND_STRING(PW);
        } else {
        }
        break;
    }
    return true;
};
