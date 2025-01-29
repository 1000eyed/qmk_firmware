// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



enum layer_names {
    _QWERTY, _COLEMAK, _NUM, _NAV, _FUN
};

enum custom_keycodes {
    SS_NOT_EQUAL = SAFE_RANGE,
    SS_R_IN,
    SPC_ALT,
    KEY_TAB,
    KEY_STAB
};


// ================================== keymap ======================================= //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ] │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ 
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ ` │ a │ s │ d │ f │ g │ h │ j │ k │ l │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┘
     * │Sft│ z │ x │ c │ v │ b │ n │ m │ , │ . │┌─────┐ 
     * ├───┴┬──┴───┴───┴───┴───┴───┴───┴───┴───┘│  /  │
     * │Ctrl│┌───┬───────────────────────────┬──┴┐    │
     * └────┘│Win│           Spc\Alt         │Cnl│    │
     *       └───┴───────────────────────────┴───┴────┘
     */
    [_QWERTY] = LAYOUT_sevenu(
        KC_RBRC,           KC_Q,      KC_W,     KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
        LT(_NAV,KC_GRV),   KC_A,  KEY_STAB,  KEY_TAB,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,           KC_Z,      KC_X,     KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL,           KC_LGUI,                            SPC_ALT,                      UG_NEXT
    ),
    [_COLEMAK] = LAYOUT_sevenu(
        KC_RBRC,           KC_Q,      KC_W,     KC_F,        KC_P,      KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,      KC_SCLN,    KC_LBRC,
        LT(_NAV,KC_GRV),   KC_A,  KEY_STAB,  KEY_TAB,        KC_T,      KC_G,     KC_M,     KC_N,     KC_E,     KC_I,      KC_O,       KC_QUOT,
        KC_LSFT,           KC_Z,      KC_X,     KC_C,        KC_D,      KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,    KC_SLSH,
        KC_LCTL,        KC_LGUI,                         SPC_ALT,                      UG_NEXT
    ),
    [_NUM] = LAYOUT_sevenu(
        KC_TRNS,          KC_TRNS,    KC_7,     KC_8,     KC_9,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_0,   KEY_STAB,  KEY_TAB,     KC_6,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_TRNS,    KC_1,     KC_2,     KC_3,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, 
        KC_TRNS,          KC_TRNS,                         KC_TRNS,                            TG(_NUM)
    ),
    [_NAV] = LAYOUT_sevenu(
        KC_NO,        KC_NO,      A(KC_F4),    KC_NO,      C(KC_ENT),      KC_NO,     KC_HOME,        C(KC_LEFT),     C(KC_RIGHT),     KC_END,         KC_NO,    KC_NO,
        KC_NO,        KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,     KC_LEFT,        KC_DOWN,        KC_UP,           KC_RGHT,        KC_NO,    KC_NO,
        KC_TRNS,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,     S(KC_HOME),     RCS(KC_LEFT),  RCS(KC_RGHT),     S(KC_END),      KC_EXLM,
        KC_TRNS,      KC_TRNS,                           KC_TRNS,                      TG(_NAV)
    ),
    [_FUN] = LAYOUT_sevenu(
        KC_TRNS,          KC_F12,    KC_F7,     KC_F8,     KC_F9,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_F10, KEY_STAB,  KEY_TAB,      KC_F6,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_F11,    KC_F1,     KC_F2,     KC_F3,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, 
        KC_TRNS,          KC_TRNS,                         KC_TRNS,                            TG(_NUM)
    )
};



// ================================== combos ======================================= //

// horizontal: left hand 
const uint16_t PROGMEM c_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_ent[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KEY_STAB, KEY_TAB, COMBO_END};
const uint16_t PROGMEM c_cop[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_cut[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM c_pst[] = {KC_C, KC_V, COMBO_END};

// horizontal: right hand 
const uint16_t PROGMEM c_bsp[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM c_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_lpc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_rpc[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_lbb[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_rbb[] = {KC_COMM, KC_DOT, COMBO_END};

// vertical: left hand 
const uint16_t PROGMEM c_dog[] = {KC_W, KEY_STAB, COMBO_END};
const uint16_t PROGMEM c_hsh[] = {KC_E, KEY_TAB, COMBO_END};
const uint16_t PROGMEM c_dlr[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM c_pct[] = {KC_T, KC_G, COMBO_END};

const uint16_t PROGMEM c_grv[] = {KEY_STAB, KC_X, COMBO_END};
const uint16_t PROGMEM c_bsl[] = {KEY_TAB, KC_C, COMBO_END};
const uint16_t PROGMEM c_eql[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM c_tld[] = {KC_G, KC_B, COMBO_END};

// vertical: right hand 
const uint16_t PROGMEM c_crt[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM c_pls[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM c_str[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM c_amp[] = {KC_O, KC_L, COMBO_END};

const uint16_t PROGMEM c_und[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM c_mns[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM c_fsl[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_pip[] = {KC_L, KC_DOT, COMBO_END};

// special cases
const uint16_t PROGMEM c_rpp[] = {KC_M, KC_K, KC_L,  COMBO_END};
const uint16_t PROGMEM c_req[] = {KC_J, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_rne[] = {KEY_TAB, KC_V, COMBO_END};
const uint16_t PROGMEM c_rin[] = {KEY_STAB, KEY_TAB, KC_V, COMBO_END};

// layer switch
const uint16_t PROGMEM to_qwerty[] = {KC_RBRC, LT(_NAV,KC_GRV), COMBO_END};
const uint16_t PROGMEM to_colemak[] = {KC_LBRC, KC_QUOT, COMBO_END};
const uint16_t PROGMEM sticky_func[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM tog_nav[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM switch_num[] = {KEY_STAB, KC_F, COMBO_END};

combo_t key_combos[] = {
    // horizontal: left hand
    COMBO(c_esc, KC_ESC), COMBO(c_ent, KC_ENT), COMBO(c_tab, KC_TAB), COMBO(c_cop, C(KC_INS)), COMBO(c_cut, C(KC_X)), COMBO(c_pst, S(KC_INS)),
    // horizontal: right hand
    COMBO(c_bsp, KC_BSPC), COMBO(c_del, KC_DEL), COMBO(c_lpc, KC_LPRN), COMBO(c_rpc, KC_RPRN), COMBO(c_lbb, KC_LBRC), COMBO(c_rbb, KC_RBRC),
    // vertical: left hand 
    COMBO(c_dog, KC_AT), COMBO(c_hsh, KC_HASH), COMBO(c_dlr, KC_DLR), COMBO(c_pct, KC_PERC), COMBO(c_grv, KC_GRV), COMBO(c_bsl, KC_BSLS), COMBO(c_eql, KC_EQL), COMBO(c_tld, KC_TILD),
    // vertical: right hand 
    COMBO(c_crt, KC_CIRC), COMBO(c_pls, KC_PLUS), COMBO(c_str, KC_ASTR), COMBO(c_amp, KC_AMPR), COMBO(c_und, KC_UNDS), COMBO(c_mns, KC_MINS), COMBO(c_fsl, KC_SLSH), COMBO(c_pip, KC_PIPE),
    // special cases
    COMBO(c_rpp, RCS(KC_M)), COMBO(c_req, A(KC_MINS)), COMBO(c_rne, SS_NOT_EQUAL), COMBO(c_rin, SS_R_IN),
    // layer switch
    COMBO(to_qwerty, TO(_QWERTY)), COMBO(to_colemak, TO(_COLEMAK)), COMBO(sticky_func, OSL(_FUN)), COMBO(tog_nav, TG(_NAV)), COMBO(switch_num, TG(_NUM))
};


// ================================ overrides ===================================== //

// paretheses to angled braces, brackets to braces
const key_override_t ko_lpc = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LT);
const key_override_t ko_rpc = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_GT);
const key_override_t ko_lbb = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LCBR);
const key_override_t ko_rbb = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RCBR);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&ko_lpc, &ko_rpc, &ko_lbb, &ko_rbb 
};

// ================================ custom ======================================== //

// define timer for disallowing combos and mods
#define IDLE_TYPING_TIMEOUT_MS 150
#define SPC_ALT_SWIFT_RESOLUTION 150
#define SPC_ALT_SPAM_DELAY 500              // delay before space starts spamming (milliseconds)
#define SPC_ALT_SPAM_INTERVAL 50            // interval between space key presses while spamming (milliseconds)

// SPC_ALT specific variables
//static bool spc_hold_tap_active = false;        // is the SPC_ALT key currently pressed?

static bool spc_hold_resolved = false;          // has SPC_ALT been resolved as a hold?
static bool spc_hold_resolved_swiftly = false;  // has SPC_ALT been resolved as a hold earlier than timer elapsed?
static uint16_t spc_hold_tap_timer = 0;         // timer to track tapping duration of SPC_ALT
static uint16_t idle_timer = 0;                 // timer to track keyboard idle status
static uint16_t spc_spam_timer = 0;             // space spam timer
bool mods_shift_status = false;
bool mods_shift_status_buffer = false;
bool mods_ctrl_status = false;
bool mods_ctrl_status_buffer = false;
bool mods_alt_status = false;
bool mods_alt_status_buffer = false;
bool mods_gui_status = false;
bool mods_gui_status_buffer = false;


void matrix_scan_user(void) {
    if (idle_timer && timer_expired(timer_read(), idle_timer)) {
        // keyboard is idle
        idle_timer = 0;
    }
    if (spc_hold_tap_timer && timer_expired(timer_read(), spc_hold_tap_timer)) {
        // space_alt timer expired, press ALT 
        spc_hold_tap_timer = 0;
        spc_hold_resolved = true;
        register_code(KC_LALT);
    }
    if (spc_spam_timer && timer_expired(timer_read(), spc_spam_timer)) {
        // reset spam timer
        spc_spam_timer = (timer_read() + SPC_ALT_SPAM_INTERVAL) | 1; 
        // spam space
        tap_code(KC_SPC); 
    }

    // light up MODS status
    mods_shift_status_buffer = get_mods() & MOD_MASK_SHIFT;
    if (mods_shift_status != mods_shift_status_buffer) {
        mods_shift_status = mods_shift_status_buffer;
        rgblight_set_layer_state(0, mods_shift_status);
    }
    mods_ctrl_status_buffer = get_mods() & MOD_MASK_CTRL;
    if (mods_ctrl_status != mods_ctrl_status_buffer) {
        mods_ctrl_status = mods_ctrl_status_buffer;
        if (mods_ctrl_status) {
            gpio_write_pin_high(B6);
        } else {
            gpio_write_pin_low(B6);
        }
        // gpio_write_pin(B6, mods_ctrl_status);
        rgblight_set_layer_state(1, mods_ctrl_status);
    }
    mods_alt_status_buffer = get_mods() & MOD_MASK_ALT;
    if (mods_alt_status != mods_alt_status_buffer) {
        mods_alt_status = mods_alt_status_buffer;
        rgblight_set_layer_state(2, mods_alt_status);
    }
    mods_gui_status_buffer = get_mods() & MOD_MASK_GUI;
    if (mods_gui_status != mods_gui_status_buffer) {
        mods_gui_status = mods_gui_status_buffer;
        rgblight_set_layer_state(3, mods_gui_status);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // get current layer
    uint8_t CURRENT_LAYER = get_highest_layer(layer_state);

    // my keycodes
    switch (keycode) {
        case SS_NOT_EQUAL:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            return false;
        case SS_R_IN:
            if (record->event.pressed) {
                SEND_STRING("%in%");
            }
            return false;
        case SPC_ALT:
            if (record->event.pressed) {
                // check if keyboard is not idle, e.g. I am typing rigorously or not
                if (idle_timer == 0) {
                    // keyboard idle
                    spc_hold_tap_timer = (record->event.time + SPC_ALT_SWIFT_RESOLUTION) | 1;       // start hold timer
                } else {            
                    // keyboard not idle        
                    spc_spam_timer = (record->event.time + SPC_ALT_SPAM_DELAY) | 1;                 // start spam timer
                    tap_code(KC_SPC);
                }
                return false;
            } else {
                // if needed, tap space and stop the timer so that ALT is not registered later after release
                if (spc_hold_tap_timer) {
                    spc_hold_tap_timer = 0;
                    tap_code(KC_SPC);
                }
                // stop space spam timer if needed
                if (spc_spam_timer) {
                    spc_spam_timer = 0;
                }
                // unregister ALT if needed
                if (spc_hold_resolved) {
                    spc_hold_resolved = false;
                    unregister_code(KC_LALT);
                } 
                if (spc_hold_resolved_swiftly) {
                    spc_hold_resolved_swiftly = false;
                }
            }
            return false;
        case KEY_TAB:
            if (record->event.pressed) {
                // if hold alt decision still pending, resolve hold immediately, tap TAB and stop timer
                if (spc_hold_tap_timer) {
                    spc_hold_resolved = true;
                    spc_hold_resolved_swiftly = true;
                    spc_hold_tap_timer = 0;
                    register_code(KC_LALT);
                    tap_code(KC_TAB);
                // if timer is stopped and hold resolved swiftly, only tap TAB
                } else if (!spc_hold_tap_timer && spc_hold_resolved_swiftly) {
                    tap_code(KC_TAB);
                // if timer is stopped and hold resolved slowly (or not resolved at all), only tap key, depending on layer
                } else {
                    switch (CURRENT_LAYER) {
                        case _QWERTY:
                            tap_code(KC_D);
                            break;
                        case _COLEMAK:
                            tap_code(KC_S);
                            break;
                        case _NUM:
                            tap_code(KC_5);
                            break;
                        case _FUN:
                            tap_code(KC_F5);
                            break;
                        default:
                            break;
                    }
                }
            }
            return false;
        case KEY_STAB:
            if (record->event.pressed) {
                if (spc_hold_tap_timer) {
                    spc_hold_resolved = true;
                    spc_hold_resolved_swiftly = true;
                    spc_hold_tap_timer = 0;
                    register_code(KC_LALT);
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                } else if (!spc_hold_tap_timer && spc_hold_resolved_swiftly) {
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                } else {
                    switch (CURRENT_LAYER) {
                        case _QWERTY:
                            tap_code(KC_S);
                            break;
                        case _COLEMAK:
                            tap_code(KC_R);
                            break;
                        case _NUM:
                            tap_code(KC_4);
                            break;
                        case _FUN:
                            tap_code(KC_F4);
                            break;
                        default:
                            break;
                    }
                }
            }
            return false;
    }

    if (record->event.pressed) {
        if ((keycode >= KC_A && keycode <= KC_Z) || keycode == KC_LBRC || keycode == KC_RBRC || keycode == LT(_NAV,KC_GRV) || keycode == KC_QUOT || keycode == KC_SCLN || keycode == KC_DOT || keycode == KC_COMM || keycode == KC_SLSH) {
            idle_timer = (record->event.time + IDLE_TYPING_TIMEOUT_MS) | 1;
        }
    }

    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // only enable combos if keyboard is idle
    return idle_timer == 0;
}

// lighting layers and status
const rgblight_segment_t PROGMEM _NUM_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {28, 15, HSV_CYAN}
);
const rgblight_segment_t PROGMEM _FUN_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {28, 15, HSV_RED}
);
const rgblight_segment_t PROGMEM _NAV_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {28, 15, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM _SHIFT_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 4, HSV_GREEN}
);
const rgblight_segment_t PROGMEM _CTRL_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN}
);
const rgblight_segment_t PROGMEM _ALT_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 18, HSV_GREEN}
);
const rgblight_segment_t PROGMEM _GUI_LED[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 3, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM _LAYERS_LED[] = RGBLIGHT_LAYERS_LIST(
    _SHIFT_LED,
    _CTRL_LED,
    _ALT_LED,
    _GUI_LED,
    _NUM_LED,
    _FUN_LED,
    _NAV_LED
);

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output (CTRL individual LED test)
  gpio_set_pin_output(B6);
  // gpio_write_pin_low(B6);
  gpio_write_pin_high(B6);
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = _LAYERS_LED;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FUN));
    rgblight_set_layer_state(6, layer_state_cmp(state, _NAV));
    return state;
}