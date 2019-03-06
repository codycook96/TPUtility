#ifndef CKL_KEYS_H
#define CKL_KEYS_H

#include <iostream>

namespace ckl{
	
	enum key{
		key_null,
		key_mouse_left,
		key_mouse_right,
		key_cancel,
		key_mouse_middle,
		key_mouse_x1,
		key_mouse_x2,
		key_backspace,
		key_tab,
		key_clear,
		key_enter,
		key_shift,
		key_control,
		key_alt,
		key_pause,
		key_caps_lock,
		key_escape,
		key_space,
		key_page_up,
		key_page_down,
		key_end,
		key_home,
		key_arrow_left,
		key_arrow_up,
		key_arrow_right,
		key_arrow_down,
		key_select,
		key_print,
		key_execute,
		key_print_screen,
		key_insert,
		key_del,
		key_help,
		key_D0,
		key_D1,
		key_D2,
		key_D3,
		key_D4,
		key_D5,
		key_D6,
		key_D7,
		key_D8,
		key_D9,
		key_A,
		key_B,
		key_C,
		key_D,
		key_E,
		key_F,
		key_G,
		key_H,
		key_I,
		key_J,
		key_K,
		key_L,
		key_M,
		key_N,
		key_O,
		key_P,
		key_Q,
		key_R,
		key_S,
		key_T,
		key_U,
		key_V,
		key_W,
		key_X,
		key_Y,
		key_Z,
		key_windows_left,
		key_windows_right,
		key_applications,
		key_sleep,
		key_numpad0,
		key_numpad1,
		key_numpad2,
		key_numpad3,
		key_numpad4,
		key_numpad5,
		key_numpad6,
		key_numpad7,
		key_numpad8,
		key_numpad9,
		key_multiply,
		key_add,
		key_separator,
		key_subtract,
		key_decimal,
		key_divide,
		key_F1,
		key_F2,
		key_F3,
		key_F4,
		key_F5,
		key_F6,
		key_F7,
		key_F8,
		key_F9,
		key_F10,
		key_F11,
		key_F12,
		key_F13,
		key_F14,
		key_F15,
		key_F16,
		key_F17,
		key_F18,
		key_F19,
		key_F20,
		key_F21,
		key_F22,
		key_F23,
		key_F24,
		key_num_lock,
		key_scroll_lock,
		key_shift_left,
		key_shift_right,
		key_control_left,
		key_control_right,
		key_alt_left,
		key_alt_right,
		key_browser_back,
		key_browser_forward,
		key_browser_refresh,
		key_browser_stop,
		key_browser_search,
		key_browser_favorites,
		key_browser_home,
		key_volume_mute,
		key_volume_up,
		key_volume_down,
		key_track_next,
		key_track_prev,
		key_media_stop,
		key_media_play_pause,
		key_mail,
		key_media_select,
		key_app1,
		key_app2,
		key_semicolon,
		key_plus,
		key_comma,
		key_hyphen,
		key_period,
		key_question,
		key_grave,
		key_bracket_left,
		key_backslash,
		key_bracket_right,
		key_apostrophe,
		key_miscellaneous,
		key_double_zero,
		key_process,
		key_packet,
		key_attn,
		key_crsel,
		key_exsel,
		key_erase_eof,
		key_play,
		key_zoom,
		key_pa1
	};
	
	key getKey(int n){
		switch(n){
			case 0x00: return key_null;
			case 0x01: return key_mouse_left;
			case 0x02: return key_mouse_right;
			case 0x03: return key_cancel;
			case 0x04: return key_mouse_middle;
			case 0x05: return key_mouse_x1;
			case 0x06: return key_mouse_x2;
			case 0x08: return key_backspace;
			case 0x09: return key_tab;
			case 0x0C: return key_clear;
			case 0x0D: return key_enter;
			case 0x10: return key_shift;
			case 0x11: return key_control;
			case 0x12: return key_alt;
			case 0x13: return key_pause;
			case 0x14: return key_caps_lock;
			case 0x1B: return key_escape;
			case 0x20: return key_space;
			case 0x21: return key_page_up;
			case 0x22: return key_page_down;
			case 0x23: return key_end;
			case 0x24: return key_home;
			case 0x25: return key_arrow_left;
			case 0x26: return key_arrow_up;
			case 0x27: return key_arrow_right;
			case 0x28: return key_arrow_down;
			case 0x29: return key_select;
			case 0x2A: return key_print;
			case 0x2B: return key_execute;
			case 0x2C: return key_print_screen;
			case 0x2D: return key_insert;
			case 0x2E: return key_del;
			case 0x2F: return key_help;
			case 0x30: return key_D0;
			case 0x31: return key_D1;
			case 0x32: return key_D2;
			case 0x33: return key_D3;
			case 0x34: return key_D4;
			case 0x35: return key_D5;
			case 0x36: return key_D6;
			case 0x37: return key_D7;
			case 0x38: return key_D8;
			case 0x39: return key_D9;
			case 0x41: return key_A;
			case 0x42: return key_B;
			case 0x43: return key_C;
			case 0x44: return key_D;
			case 0x45: return key_E;
			case 0x46: return key_F;
			case 0x47: return key_G;
			case 0x48: return key_H;
			case 0x49: return key_I;
			case 0x4A: return key_J;
			case 0x4B: return key_K;
			case 0x4C: return key_L;
			case 0x4D: return key_M;
			case 0x4E: return key_N;
			case 0x4F: return key_O;
			case 0x50: return key_P;
			case 0x51: return key_Q;
			case 0x52: return key_R;
			case 0x53: return key_S;
			case 0x54: return key_T;
			case 0x55: return key_U;
			case 0x56: return key_V;
			case 0x57: return key_W;
			case 0x58: return key_X;
			case 0x59: return key_Y;
			case 0x5A: return key_Z;
			case 0x5B: return key_windows_left;
			case 0x5C: return key_windows_right;
			case 0x5D: return key_applications;
			case 0x5F: return key_sleep;
			case 0x60: return key_numpad0;
			case 0x61: return key_numpad1;
			case 0x62: return key_numpad2;
			case 0x63: return key_numpad3;
			case 0x64: return key_numpad4;
			case 0x65: return key_numpad5;
			case 0x66: return key_numpad6;
			case 0x67: return key_numpad7;
			case 0x68: return key_numpad8;
			case 0x69: return key_numpad9;
			case 0x6A: return key_multiply;
			case 0x6B: return key_add;
			case 0x6C: return key_separator;
			case 0x6D: return key_subtract;
			case 0x6E: return key_decimal;
			case 0x6F: return key_divide;
			case 0x70: return key_F1;
			case 0x71: return key_F2;
			case 0x72: return key_F3;
			case 0x73: return key_F4;
			case 0x74: return key_F5;
			case 0x75: return key_F6;
			case 0x76: return key_F7;
			case 0x77: return key_F8;
			case 0x78: return key_F9;
			case 0x79: return key_F10;
			case 0x7A: return key_F11;
			case 0x7B: return key_F12;
			case 0x7C: return key_F13;
			case 0x7D: return key_F14;
			case 0x7E: return key_F15;
			case 0x7F: return key_F16;
			case 0x80: return key_F17;
			case 0x81: return key_F18;
			case 0x82: return key_F19;
			case 0x83: return key_F20;
			case 0x84: return key_F21;
			case 0x85: return key_F22;
			case 0x86: return key_F23;
			case 0x87: return key_F24;
			case 0x90: return key_num_lock;
			case 0x91: return key_scroll_lock;
			case 0xA0: return key_shift_left;
			case 0xA1: return key_shift_right;
			case 0xA2: return key_control_left;
			case 0xA3: return key_control_right;
			case 0xA4: return key_alt_left;
			case 0xA5: return key_alt_right;
			case 0xA6: return key_browser_forward;
			case 0xA7: return key_browser_back;
			case 0xA8: return key_browser_refresh;
			case 0xA9: return key_browser_stop;
			case 0xAA: return key_browser_search;
			case 0xAB: return key_browser_favorites;
			case 0xAC: return key_browser_home;
			case 0xAD: return key_volume_mute;
			case 0xAE: return key_volume_up;
			case 0xAF: return key_volume_down;
			case 0xB0: return key_track_next;
			case 0xB1: return key_track_prev;
			case 0xB2: return key_media_stop;
			case 0xB3: return key_media_play_pause;
			case 0xB4: return key_mail;
			case 0xB5: return key_media_select;
			case 0xB6: return key_app1;
			case 0xB7: return key_app2;
			case 0xBA: return key_semicolon;
			case 0xBB: return key_plus;
			case 0xBC: return key_comma;
			case 0xBD: return key_hyphen;
			case 0xBE: return key_period;
			case 0xBF: return key_question;
			case 0xC0: return key_grave;
			case 0xDB: return key_bracket_left;
			case 0xDC: return key_backslash;
			case 0xDD: return key_bracket_right;
			case 0xDE: return key_apostrophe;
			case 0xDF: return key_miscellaneous;
			case 0xE4: return key_double_zero;
			case 0xE5: return key_process;
			case 0xE7: return key_packet;
			case 0xF6: return key_attn;
			case 0xF7: return key_crsel;
			case 0xF8: return key_exsel;
			case 0xF9: return key_erase_eof;
			case 0xFA: return key_play;
			case 0xFB: return key_zoom;
			case 0xFD: return key_pa1;
			default: return key_null;
		}
	}
		
		/* Implementation requires mapping or converting strings to int for switch
		key getKey(std::string s){
		switch(s){
			case "mouse_left": return key_mouse_left;
			case "mouse_right": return key_mouse_right;
			case "cancel": return key_cancel;
			case "mouse_middle": return key_mouse_middle;
			case "mouse_x1": return key_mouse_x1;
			case "mouse_x2": return key_mouse_x2;
			case "backspace": return key_backspace;
			case "tab": return key_tab;
			case "clear": return key_clear;
			case "enter": return key_enter;
			case "shift": return key_shift;
			case "control": return key_control;
			case "alt": return key_alt;
			case "pause": return key_pause;
			case "caps_lock": return key_caps_lock;
			case "escape": return key_escape;
			case "space": return key_space;
			case "page_up": return key_page_up;
			case "page_down": return key_page_down;
			case "end": return key_end;
			case "home": return key_home;
			case "arrow_left": return key_arrow_left;
			case "arrow_up": return key_arrow_up;
			case "arrow_right": return key_arrow_right;
			case "arrow_down": return key_arrow_down;
			case "select": return key_select;
			case "print": return key_print;
			case "execute": return key_execute;
			case "print_screen": return key_print_screen;
			case "insert": return key_insert;
			case "del": return key_del;
			case "help": return key_help;
			case "D0": return key_D0;
			case "D1": return key_D1;
			case "D2": return key_D2;
			case "D3": return key_D3;
			case "D4": return key_D4;
			case "D5": return key_D5;
			case "D6": return key_D6;
			case "D7": return key_D7;
			case "D8": return key_D8;
			case "D9": return key_D9;
			case "A": return key_A;
			case "B": return key_B;
			case "C": return key_C;
			case "D": return key_D;
			case "E": return key_E;
			case "F": return key_F;
			case "G": return key_G;
			case "H": return key_H;
			case "I": return key_I;
			case "J": return key_J;
			case "K": return key_K;
			case "L": return key_L;
			case "M": return key_M;
			case "N": return key_N;
			case "O": return key_O;
			case "P": return key_P;
			case "Q": return key_Q;
			case "R": return key_R;
			case "S": return key_S;
			case "T": return key_T;
			case "U": return key_U;
			case "V": return key_V;
			case "W": return key_W;
			case "X": return key_X;
			case "Y": return key_Y;
			case "Z": return key_Z;
			case "windows_left": return key_windows_left;
			case "windows_right": return key_windows_right;
			case "applications": return key_applications;
			case "sleep": return key_sleep;
			case "numpad0": return key_numpad0;
			case "numpad1": return key_numpad1;
			case "numpad2": return key_numpad2;
			case "numpad3": return key_numpad3;
			case "numpad4": return key_numpad4;
			case "numpad5": return key_numpad5;
			case "numpad6": return key_numpad6;
			case "numpad7": return key_numpad7;
			case "numpad8": return key_numpad8;
			case "numpad9": return key_numpad9;
			case "multiply": return key_multiply;
			case "add": return key_add;
			case "separator": return key_separator;
			case "subtract": return key_subtract;
			case "decimal": return key_decimal;
			case "divide": return key_divide;
			case "F1": return key_F1;
			case "F2": return key_F2;
			case "F3": return key_F3;
			case "F4": return key_F4;
			case "F5": return key_F5;
			case "F6": return key_F6;
			case "F7": return key_F7;
			case "F8": return key_F8;
			case "F9": return key_F9;
			case "F10": return key_F10;
			case "F11": return key_F11;
			case "F12": return key_F12;
			case "F13": return key_F13;
			case "F14": return key_F14;
			case "F15": return key_F15;
			case "F16": return key_F16;
			case "F17": return key_F17;
			case "F18": return key_F18;
			case "F19": return key_F19;
			case "F20": return key_F20;
			case "F21": return key_F21;
			case "F22": return key_F22;
			case "F23": return key_F23;
			case "F24": return key_F24;
			case "num_lock": return key_num_lock;
			case "scroll_lock": return key_scroll_lock;
			case "shift_left": return key_shift_left;
			case "shift_right": return key_shift_right;
			case "control_left": return key_control_left;
			case "control_right": return key_control_right;
			case "alt_left": return key_alt_left;
			case "alt_right": return key_alt_right;
			case "browser_forward": return key_browser_forward;
			case "browser_back": return key_browser_back;
			case "browser_refresh": return key_browser_refresh;
			case "browser_stop": return key_browser_stop;
			case "browser_search": return key_browser_search;
			case "browser_favorites": return key_browser_favorites;
			case "browser_home": return key_browser_home;
			case "volume_mute": return key_volume_mute;
			case "volume_up": return key_volume_up;
			case "volume_down": return key_volume_down;
			case "track_next": return key_track_next;
			case "track_prev": return key_track_prev;
			case "media_stop": return key_media_stop;
			case "media_play_pause": return key_media_play_pause;
			case "mail": return key_mail;
			case "media_select": return key_media_select;
			case "app1": return key_app1;
			case "app2": return key_app2;
			case "semicolon": return key_semicolon;
			case "plus": return key_plus;
			case "comma": return key_comma;
			case "hyphen": return key_hyphen;
			case "period": return key_period;
			case "question": return key_question;
			case "grave": return key_grave;
			case "bracket_left": return key_bracket_left;
			case "backslash": return key_backslash;
			case "bracket_right": return key_bracket_right;
			case "apostrophe": return key_apostrophe;
			case "miscellaneous": return key_miscellaneous;
			case "double_zero": return key_double_zero;
			case "process": return key_process;
			case "packet": return key_packet;
			case "attn": return key_attn;
			case "crsel": return key_crsel;
			case "exsel": return key_exsel;
			case "erase_eof": return key_erase_eof;
			case "play": return key_play;
			case "zoom": return key_zoom;
			case "pa1": return key_pa1;
			default: return key_null;
		}
	}
	*/
	
	int getKeyCode(key k){
		switch(k){
			case key_null: return 0x001;
			case key_mouse_left: return 0x01;
			case key_mouse_right: return 0x02;
			case key_cancel: return 0x03;
			case key_mouse_middle: return 0x04;
			case key_mouse_x1: return 0x05;
			case key_mouse_x2: return 0x06;
			case key_backspace: return 0x08;
			case key_tab: return 0x09;
			case key_clear: return 0x0C;
			case key_enter: return 0x0D;
			case key_shift: return 0x10;
			case key_control: return 0x11;
			case key_alt: return 0x12;
			case key_pause: return 0x13;
			case key_caps_lock: return 0x14;
			case key_escape: return 0x1B;
			case key_space: return 0x20;
			case key_page_up: return 0x21;
			case key_page_down: return 0x22;
			case key_end: return 0x23;
			case key_home: return 0x24;
			case key_arrow_left: return 0x25;
			case key_arrow_up: return 0x26;
			case key_arrow_right: return 0x27;
			case key_arrow_down: return 0x28;
			case key_select: return 0x29;
			case key_print: return 0x2A;
			case key_execute: return 0x2B;
			case key_print_screen: return 0x2C;
			case key_insert: return 0x2D;
			case key_del: return 0x2E;
			case key_help: return 0x2F;
			case key_D0: return 0x30;
			case key_D1: return 0x31;
			case key_D2: return 0x32;
			case key_D3: return 0x33;
			case key_D4: return 0x34;
			case key_D5: return 0x35;
			case key_D6: return 0x36;
			case key_D7: return 0x37;
			case key_D8: return 0x38;
			case key_D9: return 0x39;
			case key_A: return 0x41;
			case key_B: return 0x42;
			case key_C: return 0x43;
			case key_D: return 0x44;
			case key_E: return 0x45;
			case key_F: return 0x46;
			case key_G: return 0x47;
			case key_H: return 0x48;
			case key_I: return 0x49;
			case key_J: return 0x4A;
			case key_K: return 0x4B;
			case key_L: return 0x4C;
			case key_M: return 0x4D;
			case key_N: return 0x4E;
			case key_O: return 0x4F;
			case key_P: return 0x50;
			case key_Q: return 0x51;
			case key_R: return 0x52;
			case key_S: return 0x53;
			case key_T: return 0x54;
			case key_U: return 0x55;
			case key_V: return 0x56;
			case key_W: return 0x57;
			case key_X: return 0x58;
			case key_Y: return 0x59;
			case key_Z: return 0x5A;
			case key_windows_left: return 0x5B;
			case key_windows_right: return 0x5C;
			case key_applications: return 0x5D;
			case key_sleep: return 0x5F;
			case key_numpad0: return 0x60;
			case key_numpad1: return 0x61;
			case key_numpad2: return 0x62;
			case key_numpad3: return 0x63;
			case key_numpad4: return 0x64;
			case key_numpad5: return 0x65;
			case key_numpad6: return 0x66;
			case key_numpad7: return 0x67;
			case key_numpad8: return 0x68;
			case key_numpad9: return 0x69;
			case key_multiply: return 0x6A;
			case key_add: return 0x6B;
			case key_separator: return 0x6C;
			case key_subtract: return 0x6D;
			case key_decimal: return 0x6E;
			case key_divide: return 0x6F;
			case key_F1: return 0x70;
			case key_F2: return 0x71;
			case key_F3: return 0x72;
			case key_F4: return 0x73;
			case key_F5: return 0x74;
			case key_F6: return 0x75;
			case key_F7: return 0x76;
			case key_F8: return 0x77;
			case key_F9: return 0x78;
			case key_F10: return 0x79;
			case key_F11: return 0x7A;
			case key_F12: return 0x7B;
			case key_F13: return 0x7C;
			case key_F14: return 0x7D;
			case key_F15: return 0x7E;
			case key_F16: return 0x7F;
			case key_F17: return 0x80;
			case key_F18: return 0x81;
			case key_F19: return 0x82;
			case key_F20: return 0x83;
			case key_F21: return 0x84;
			case key_F22: return 0x85;
			case key_F23: return 0x86;
			case key_F24: return 0x87;
			case key_num_lock: return 0x90;
			case key_scroll_lock: return 0x91;
			case key_shift_left: return 0xA0;
			case key_shift_right: return 0xA1;
			case key_control_left: return 0xA2;
			case key_control_right: return 0xA3;
			case key_alt_left: return 0xA4;
			case key_alt_right: return 0xA5;
			case key_browser_back: return 0xA6;
			case key_browser_forward: return 0xA7;
			case key_browser_refresh: return 0xA8;
			case key_browser_stop: return 0xA9;
			case key_browser_search: return 0xAA;
			case key_browser_favorites: return 0xAB;
			case key_browser_home: return 0xAC;
			case key_volume_mute: return 0xAD;
			case key_volume_up: return 0xAE;
			case key_volume_down: return 0xAF;
			case key_track_next: return 0xB0;
			case key_track_prev: return 0xB1;
			case key_media_stop: return 0xB2;
			case key_media_play_pause: return 0xB3;
			case key_mail: return 0xB4;
			case key_media_select: return 0xB5;
			case key_app1: return 0xB6;
			case key_app2: return 0xB7;
			case key_semicolon: return 0xBA;
			case key_plus: return 0xBB;
			case key_comma: return 0xBC;
			case key_hyphen: return 0xBD;
			case key_period: return 0xBE;
			case key_question: return 0xBF;
			case key_grave: return 0xC0;
			case key_bracket_left: return 0xDB;
			case key_backslash: return 0xDC;
			case key_bracket_right: return 0xDD;
			case key_apostrophe: return 0xDE;
			case key_miscellaneous: return 0xDF;
			case key_double_zero: return 0xE4;
			case key_process: return 0xE5;
			case key_packet: return 0xE7;
			case key_attn: return 0xF6;
			case key_crsel: return 0xF7;
			case key_exsel: return 0xF8;
			case key_erase_eof: return 0xF9;
			case key_play: return 0xFA;
			case key_zoom: return 0xFB;
			case key_pa1: return 0xFD;
			default: return 0x00;
		}
	}
	
	std::string getKeyText(key k){
		switch(k){
			case key_null: return "null";
			case key_mouse_left: return "mouse_left";
			case key_mouse_right: return "mouse_right";
			case key_cancel: return "cancel";
			case key_mouse_middle: return "mouse_middle";
			case key_mouse_x1: return "mouse_x1";
			case key_mouse_x2: return "mouse_x2";
			case key_backspace: return "backspace";
			case key_tab: return "tab";
			case key_clear: return "clear";
			case key_enter: return "enter";
			case key_shift: return "shift";
			case key_control: return "control";
			case key_alt: return "alt";
			case key_pause: return "pause";
			case key_caps_lock: return "caps_lock";
			case key_escape: return "escape";
			case key_space: return "space";
			case key_page_up: return "page_up";
			case key_page_down: return "page_down";
			case key_end: return "end";
			case key_home: return "home";
			case key_arrow_left: return "arrow_left";
			case key_arrow_up: return "arrow_up";
			case key_arrow_right: return "arrow_right";
			case key_arrow_down: return "arrow_down";
			case key_select: return "select";
			case key_print: return "print";
			case key_execute: return "execute";
			case key_print_screen: return "print_screen";
			case key_insert: return "insert";
			case key_del: return "del";
			case key_help: return "help";
			case key_D0: return "D0";
			case key_D1: return "D1";
			case key_D2: return "D2";
			case key_D3: return "D3";
			case key_D4: return "D4";
			case key_D5: return "D5";
			case key_D6: return "D6";
			case key_D7: return "D7";
			case key_D8: return "D8";
			case key_D9: return "D9";
			case key_A: return "A";
			case key_B: return "B";
			case key_C: return "C";
			case key_D: return "D";
			case key_E: return "E";
			case key_F: return "F";
			case key_G: return "G";
			case key_H: return "H";
			case key_I: return "I";
			case key_J: return "J";
			case key_K: return "K";
			case key_L: return "L";
			case key_M: return "M";
			case key_N: return "N";
			case key_O: return "O";
			case key_P: return "P";
			case key_Q: return "Q";
			case key_R: return "R";
			case key_S: return "S";
			case key_T: return "T";
			case key_U: return "U";
			case key_V: return "V";
			case key_W: return "W";
			case key_X: return "X";
			case key_Y: return "Y";
			case key_Z: return "Z";
			case key_windows_left: return "windows_left";
			case key_windows_right: return "windows_right";
			case key_applications: return "applications";
			case key_sleep: return "sleep";
			case key_numpad0: return "numpad0";
			case key_numpad1: return "numpad1";
			case key_numpad2: return "numpad2";
			case key_numpad3: return "numpad3";
			case key_numpad4: return "numpad4";
			case key_numpad5: return "numpad5";
			case key_numpad6: return "numpad6";
			case key_numpad7: return "numpad7";
			case key_numpad8: return "numpad8";
			case key_numpad9: return "numpad9";
			case key_multiply: return "multiply";
			case key_add: return "add";
			case key_separator: return "separator";
			case key_subtract: return "subtract";
			case key_decimal: return "decimal";
			case key_divide: return "divide";
			case key_F1: return "F1";
			case key_F2: return "F2";
			case key_F3: return "F3";
			case key_F4: return "F4";
			case key_F5: return "F5";
			case key_F6: return "F6";
			case key_F7: return "F7";
			case key_F8: return "F8";
			case key_F9: return "F9";
			case key_F10: return "F10";
			case key_F11: return "F11";
			case key_F12: return "F12";
			case key_F13: return "F13";
			case key_F14: return "F14";
			case key_F15: return "F15";
			case key_F16: return "F16";
			case key_F17: return "F17";
			case key_F18: return "F18";
			case key_F19: return "F19";
			case key_F20: return "F20";
			case key_F21: return "F21";
			case key_F22: return "F22";
			case key_F23: return "F23";
			case key_F24: return "F24";
			case key_num_lock: return "num_lock";
			case key_scroll_lock: return "scroll_lock";
			case key_shift_left: return "shift_left";
			case key_shift_right: return "shift_right";
			case key_control_left: return "control_left";
			case key_control_right: return "control_right";
			case key_alt_left: return "alt_left";
			case key_alt_right: return "alt_right";
			case key_browser_back: return "browser_back";
			case key_browser_forward: return "browser_forward";
			case key_browser_refresh: return "browser_refresh";
			case key_browser_stop: return "browser_stop";
			case key_browser_search: return "browser_search";
			case key_browser_favorites: return "browser_favorites";
			case key_browser_home: return "browser_home";
			case key_volume_mute: return "volume_mute";
			case key_volume_up: return "volume_up";
			case key_volume_down: return "volume_down";
			case key_track_next: return "track_next";
			case key_track_prev: return "track_prev";
			case key_media_stop: return "media_stop";
			case key_media_play_pause: return "media_play_pause";
			case key_mail: return "mail";
			case key_media_select: return "media_select";
			case key_app1: return "app1";
			case key_app2: return "app2";
			case key_semicolon: return "semicolon";
			case key_plus: return "plus";
			case key_comma: return "comma";
			case key_hyphen: return "hyphen";
			case key_period: return "period";
			case key_question: return "question";
			case key_grave: return "grave";
			case key_bracket_left: return "bracket_left";
			case key_backslash: return "backslash";
			case key_bracket_right: return "bracket_right";
			case key_apostrophe: return "apostrophe";
			case key_miscellaneous: return "miscellaneous";
			case key_double_zero: return "double_zero";
			case key_process: return "process";
			case key_packet: return "packet";
			case key_attn: return "attn";
			case key_crsel: return "crsel";
			case key_exsel: return "exsel";
			case key_erase_eof: return "erase_eof";
			case key_play: return "play";
			case key_zoom: return "zoom";
			case key_pa1: return "pa1";
			default: return "null";
		}
	}
	
	std::string getKeyText(int n){
		return getKeyText(getKey(n));
	}
	
	std::ostream& operator<<(std::ostream& os, const key& k){  
		os << getKeyText(k); 
		return os;  
	}  
	
}	



#endif


/*
enum key {	escape, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, del,
				home, end, page_up, page_down, insert,
				grave, one, two, three, four, five, six, seven, eight, nine, zero, hyphen, equal, backspace,
				tilde, exclamation, at, pound, dollar, percent, caret, ampersand, asterisk, open_parenthesis, close_parenthesis, underscore, plus,
				tab, q, w, e, r, t, y, u, i, o, p, open_bracket, close_bracket, back_slash, 
				Q, W, E, R, T, Y, U, I, O, P, open_brace, close_brace, pipe,
				a, s, d, f, g, h, j, k, l, semicolon, quote, enter,
				A, S, D, F, G, H, J, K, L, colon, apostrophe, 
				z, x, c, v, b, n, m, comma, period, forward_slash,
				Z, X, C, V, B, N, M, less_than, greater_than, question,
				space, up, down, left, right };
	
	key keypress(){
		
		switch(getch()){
			
			//ROW 1
			case 0: 
				//Special Character (function keys)
				break;
			case 244:
				//Special Character (function 11, 12, del, home, etc)
				break;
			case 27: return escape;
			
			//ROW 2 STANDARD
			case 96: return grave;
			case 49: return one;
			case 50: return two;
			case 51: return three;
			case 52: return four;
			case 53: return five;
			case 54: return six;
			case 55: return seven;
			case 56: return eight;
			case 57: return nine;
			case 48: return zero;
			case 45: return hyphen;
			case 61: return equal;
			case 8: return backspace;
			//ROW 2 SHIFT
			case 126: return tilde;
			case 33: return exclamation;
			case 64: return at;
			case 35: return pound;
			case 36: return dollar;
			case 37: return percent;
			case 94: return caret;
			case 38: return ampersand;
			case 42: return asterisk;
			case 40: return open_parenthesis;
			case 41: return close_parenthesis;
			case 95: return hyphen;
			case 43: return equal;			
			
			//ROW 3 STANDARD 
			case 9: return tab;
			case 113: return q;
			case 119: return w;
			case 101: return e;
			case 114: return r;
			case 116: return t;
			case 121: return y;
			case 117: return u;
			case 105: return i;
			case 111: return o;
			case 112: return p;
			case 91: return open_bracket;
			case 93: return close_bracket;
			case 92: return back_slash;
			//ROW 3 SHIFT
			case 81: return Q;
			case 87: return W;
			case 69: return E;
			case 82: return R;
			case 84: return T;
			case 89: return Y;
			case 85: return U;
			case 73: return I;
			case 79: return O;
			case 80: return P;
			case 123: return open_brace;
			case 125: return close_brace;
			case 124: return pipe;
			
			//ROW 4 STANDARD
			//a, s, d, f, g, h, j, k, l, semicolon, quote, enter,
			
			case : return a;
			case : return s;
			case : return d;
			case : return f;
			case : return g;
			case : return h;
			case : return j;
			case : return k;
			case : return l;
			case : return semicolon;
			case : return quote;
			case : return enter;
			
			//A, S, D, F, G, H, J, K, L, colon, apostrophe,
			case : return A;
			case : return S;
			case : return D;
			case : return F;
			case : return G;
			case : return H;
			case : return J;
			case : return K;
			case : return L;
			case : return colon;
			case : return apostrophe;
		}
	}
*/