#ifndef __CODES_H__
#define __CODES_H__

// Implicitly includes <avr/pgmspace.h> to provide access to progmem features
//#include <Arduino.h>

// Split up declarations and definitions to remove warnings.

extern const prog_uint16_t show_hide_info[] PROGMEM;
const prog_uint16_t show_hide_info[] = { 4216, 8900, 4380, 580, 500, 600, 500, 580, 1620, 580, 500, 600, 500, 580, 500, 600, 480, 600, 500, 580, 1620, 580, 1620, 600, 500, 580, 1620, 580, 1620, 600, 1600, 600, 1620, 580, 1620, 600, 500, 580, 1620, 580, 500, 600, 1600, 600, 500, 580, 1620, 580, 500, 600, 1620, 580, 1620, 600, 480, 600, 1620, 580, 500, 600, 1600, 600, 500, 580, 1620, 580, 500, 600, 39300, 8860, 2160, 580, 0 };

extern const prog_uint16_t amp_power_onoff[] PROGMEM;
const prog_uint16_t amp_power_onoff[] = { 40908, 2420, 560, 1200, 560, 620, 540, 1220, 540, 640, 540, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 620, 540, 620, 560, 1200, 560, 1200, 560, 620, 560, 620, 21680, 2360, 560, 1200, 560, 620, 560, 1200, 560, 600, 560, 1220, 540, 620, 560, 620, 560, 600, 560, 620, 560, 620, 540, 620, 560, 1200, 560, 1200, 560, 620, 560, 620, 21700, 2380, 540, 1220, 540, 620, 560, 1200, 560, 620, 560, 1200, 560, 600, 560, 620, 560, 620, 540, 640, 540, 620, 560, 620, 560, 1200, 560, 1200, 540, 620, 560, 620, 0 };

extern const prog_uint16_t tv_power_onoff[] PROGMEM;
const prog_uint16_t tv_power_onoff[] = { 7488, 8860, 4420, 540, 560, 540, 540, 540, 1660, 560, 520, 560, 540, 540, 540, 560, 540, 540, 540, 560, 1640, 560, 1660, 540, 540, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 540, 540, 540, 540, 540, 560, 1660, 540, 540, 540, 540, 560, 540, 540, 540, 540, 1680, 540, 1660, 540, 1660, 540, 540, 560, 1660, 540, 1660, 540, 1660, 540, 1660, 560, 39340, 8800, 2200, 540, 0 };

extern const prog_uint16_t ps3_source[] PROGMEM;
const prog_uint16_t ps3_source[] = { 34128, 2420, 540, 620, 560, 1220, 540, 1220, 540, 1200, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 620, 540, 620, 560, 1220, 540, 1200, 560, 620, 560, 620, 21180, 2380, 540, 620, 560, 1200, 560, 1200, 560, 1200, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 600, 560, 620, 560, 1200, 560, 1200, 560, 620, 560, 600, 21140, 2360, 560, 620, 540, 1220, 540, 1220, 540, 1220, 540, 1220, 540, 620, 560, 620, 560, 620, 560, 600, 560, 620, 560, 620, 540, 1220, 540, 1220, 560, 600, 560, 620, 21200, 2380, 560, 620, 560, 1200, 560, 1200, 560, 1200, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 600, 560, 620, 560, 1200, 560, 1200, 560, 620, 560, 600, 0 };

extern const prog_uint16_t nintendo_source[] PROGMEM;
const prog_uint16_t nintendo_source[] = { 50856, 2420, 560, 620, 560, 1200, 560, 600, 560, 620, 560, 620, 540, 1220, 560, 600, 560, 620, 560, 620, 540, 620, 560, 620, 560, 1200, 560, 1200, 560, 620, 540, 620, 22340, 2360, 540, 620, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 600, 560, 1200, 560, 1220, 540, 620, 560, 620, 22320, 2360, 540, 640, 540, 1220, 540, 620, 560, 620, 540, 620, 560, 1220, 540, 620, 560, 620, 560, 600, 560, 620, 560, 620, 540, 1220, 560, 1200, 560, 600, 560, 620, 22420, 2380, 560, 620, 560, 1200, 560, 620, 540, 620, 560, 620, 540, 1220, 560, 620, 540, 620, 560, 620, 560, 620, 540, 620, 560, 1200, 560, 1200, 560, 620, 560, 620, 0 };

extern const prog_uint16_t xbox_source[] PROGMEM;
const prog_uint16_t xbox_source[] = { 27752, 2440, 540, 1220, 560, 1200, 560, 620, 540, 620, 560, 620, 540, 640, 540, 620, 560, 620, 560, 620, 540, 620, 560, 620, 540, 1220, 560, 1200, 560, 600, 560, 1220, 21820, 2360, 560, 1200, 560, 1200, 560, 620, 540, 640, 540, 620, 560, 620, 560, 600, 560, 620, 560, 620, 540, 620, 560, 620, 560, 1200, 560, 1200, 560, 620, 540, 1220, 21720, 2360, 560, 1200, 560, 1220, 540, 620, 560, 620, 540, 620, 560, 620, 560, 620, 540, 620, 560, 620, 560, 600, 560, 620, 560, 1200, 560, 1200, 560, 620, 560, 1200, 0 };

extern const prog_uint16_t amp_volume_up[] PROGMEM;
const prog_uint16_t amp_volume_up[] = { 56072, 2420, 560, 620, 540, 1220, 540, 620, 560, 620, 560, 1200, 560, 620, 560, 600, 560, 620, 560, 620, 540, 620, 560, 620, 560, 1200, 560, 1200, 560, 620, 540, 620, 22300, 2360, 560, 620, 540, 1220, 540, 620, 560, 620, 560, 1200, 560, 620, 540, 620, 560, 620, 560, 600, 560, 620, 560, 620, 560, 1200, 560, 1200, 560, 600, 560, 620, 22320, 2360, 560, 620, 540, 1220, 540, 640, 540, 620, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 600, 560, 620, 560, 1200, 560, 1200, 560, 620, 560, 600, 0 };

extern const prog_uint16_t amp_volume_down[] PROGMEM;
const prog_uint16_t amp_volume_down[] = { 61760, 2440, 540, 1220, 540, 1220, 540, 620, 560, 620, 560, 1200, 560, 600, 560, 620, 560, 620, 540, 640, 540, 620, 560, 620, 540, 1220, 540, 1220, 540, 620, 560, 620, 21680, 2360, 540, 1220, 540, 1220, 560, 620, 540, 620, 560, 1200, 560, 620, 540, 640, 540, 620, 560, 620, 560, 600, 560, 620, 560, 1200, 560, 1200, 560, 620, 560, 600, 21740, 2360, 560, 1200, 560, 1200, 560, 620, 540, 620, 560, 1200, 560, 620, 560, 620, 540, 620, 560, 620, 560, 620, 540, 620, 560, 1200, 560, 1200, 560, 620, 560, 620, 0 };

extern const prog_uint16_t aircon_power_onoff[] PROGMEM;
const prog_uint16_t aircon_power_onoff[] = { 2380, 3460, 1680, 420, 1300, 400, 1280, 420, 440, 400, 440, 420, 440, 420, 1280, 400, 460, 400, 440, 400, 1300, 400, 1300, 400, 440, 420, 1300, 400, 440, 420, 440, 420, 1280, 400, 1300, 400, 460, 400, 1280, 420, 1280, 400, 460, 400, 440, 420, 440, 400, 440, 400, 460, 400, 460, 380, 460, 400, 440, 420, 440, 400, 440, 420, 440, 400, 460, 400, 440, 420, 440, 400, 440, 420, 440, 400, 440, 420, 440, 400, 460, 400, 440, 400, 460, 400, 440, 420, 440, 400, 460, 400, 440, 400, 460, 400, 440, 400, 460, 400, 440, 400, 460, 400, 440, 400, 460, 400, 440, 400, 460, 400, 1300, 420, 1280, 400, 460, 400, 440, 400, 0 };

extern const prog_uint16_t tv_channel_0[] PROGMEM;
const prog_uint16_t tv_channel_0[] = { 29340, 8880, 4420, 540, 560, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 540, 540, 560, 540, 540, 540, 1680, 520, 1680, 540, 540, 540, 1660, 540, 1680, 540, 1660, 540, 1660, 540, 1660, 540, 560, 540, 540, 540, 540, 540, 560, 540, 1660, 540, 560, 540, 540, 540, 540, 540, 1680, 520, 1680, 540, 1660, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1660, 540, 39340, 8820, 2220, 520, 0 };

extern const prog_uint16_t tv_channel_1[] PROGMEM;
const prog_uint16_t tv_channel_1[] = { 14272, 8880, 4420, 540, 560, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 540, 540, 560, 540, 540, 540, 1660, 560, 1660, 540, 540, 540, 1680, 520, 1680, 540, 1660, 540, 1660, 540, 1680, 520, 1680, 540, 540, 540, 540, 540, 560, 540, 1660, 540, 540, 560, 540, 540, 540, 540, 560, 520, 1680, 540, 1660, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1680, 520, 39340, 8820, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_2[] PROGMEM;
const prog_uint16_t tv_channel_2[] = { 26888, 8880, 4440, 520, 560, 540, 540, 540, 1680, 520, 560, 540, 540, 540, 560, 540, 540, 540, 540, 540, 1680, 540, 1660, 540, 540, 540, 1680, 520, 1680, 540, 1660, 540, 1660, 540, 1680, 520, 560, 540, 1660, 540, 560, 520, 560, 540, 1660, 540, 560, 540, 540, 540, 540, 540, 1680, 520, 560, 540, 1660, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1680, 520, 39340, 8820, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_3[] PROGMEM;
const prog_uint16_t tv_channel_3[] = { 61640, 8880, 4420, 540, 540, 540, 560, 520, 1680, 540, 540, 540, 560, 520, 560, 540, 540, 540, 560, 520, 1680, 540, 1680, 520, 560, 520, 1680, 540, 1660, 540, 1660, 540, 1680, 520, 1680, 540, 1660, 540, 1660, 540, 560, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 560, 520, 560, 540, 540, 540, 1680, 520, 1680, 540, 540, 540, 1680, 520, 1680, 540, 1660, 540, 39340, 8800, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_4[] PROGMEM;
const prog_uint16_t tv_channel_4[] = { 23844, 8880, 4420, 540, 540, 540, 560, 520, 1680, 540, 540, 540, 560, 540, 540, 540, 540, 540, 560, 540, 1660, 540, 1680, 520, 560, 540, 1660, 540, 1660, 540, 1680, 520, 1680, 520, 1680, 540, 540, 540, 560, 540, 1660, 540, 540, 540, 1680, 520, 560, 540, 540, 540, 560, 540, 1660, 540, 1660, 540, 540, 560, 1660, 540, 540, 540, 1680, 520, 1680, 540, 1660, 540, 39340, 8800, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_5[] PROGMEM;
const prog_uint16_t tv_channel_5[] = { 29144, 8880, 4440, 520, 560, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 560, 520, 560, 540, 540, 540, 1680, 520, 1680, 540, 540, 540, 1660, 540, 1680, 520, 1680, 540, 1660, 540, 1660, 540, 1680, 540, 540, 540, 1660, 540, 560, 520, 1680, 540, 540, 540, 560, 540, 540, 540, 540, 540, 1680, 540, 540, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1660, 540, 39340, 8820, 2220, 520, 0 };

extern const prog_uint16_t tv_channel_6[] PROGMEM;
const prog_uint16_t tv_channel_6[] = { 19424, 8860, 4440, 540, 540, 540, 560, 520, 1680, 540, 540, 540, 540, 540, 560, 540, 540, 540, 560, 540, 1660, 540, 1660, 540, 560, 520, 1680, 540, 1660, 540, 1660, 540, 1680, 520, 1680, 540, 540, 540, 1680, 520, 1680, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 560, 520, 1680, 540, 540, 540, 540, 540, 1680, 540, 540, 540, 1660, 540, 1680, 520, 1680, 540, 39340, 8800, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_7[] PROGMEM;
const prog_uint16_t tv_channel_7[] = { 60400, 8880, 4420, 540, 540, 540, 560, 540, 1660, 540, 540, 540, 560, 540, 540, 540, 540, 560, 540, 540, 1660, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1660, 540, 1680, 540, 1660, 540, 1660, 540, 1660, 560, 1660, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 560, 520, 560, 540, 540, 540, 560, 540, 1660, 540, 540, 540, 1680, 520, 1680, 540, 1660, 540, 39340, 8800, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_8[] PROGMEM;
const prog_uint16_t tv_channel_8[] = { 59000, 8880, 4420, 540, 540, 540, 560, 540, 1660, 540, 540, 540, 560, 540, 540, 540, 540, 560, 540, 540, 1660, 540, 1680, 520, 560, 540, 1660, 540, 1660, 540, 1680, 540, 1660, 540, 1660, 540, 560, 520, 560, 540, 540, 540, 1660, 560, 1660, 540, 540, 540, 560, 520, 560, 540, 1660, 540, 1680, 520, 1680, 540, 540, 540, 540, 560, 1660, 540, 1660, 540, 1660, 540, 39340, 8800, 2220, 540, 0 };

extern const prog_uint16_t tv_channel_9[] PROGMEM;
const prog_uint16_t tv_channel_9[] = { 49740, 8860, 4420, 540, 560, 540, 540, 540, 1660, 540, 560, 540, 540, 540, 540, 540, 560, 540, 540, 540, 1660, 560, 1660, 540, 540, 540, 1660, 540, 1680, 540, 1660, 540, 1660, 540, 1660, 560, 1660, 540, 540, 540, 540, 540, 1680, 540, 1660, 540, 540, 540, 560, 540, 540, 540, 540, 560, 1660, 540, 1660, 540, 540, 540, 560, 540, 1660, 540, 1660, 540, 1660, 540, 39340, 8820, 2220, 540, 0 };

extern const prog_uint16_t tv_volume_up[] PROGMEM;
const prog_uint16_t tv_volume_up[] = { 37324, 8860, 4420, 560, 540, 540, 540, 540, 1660, 560, 540, 540, 540, 540, 540, 560, 540, 540, 540, 560, 1640, 560, 1660, 540, 540, 540, 1660, 540, 1660, 560, 1660, 540, 1660, 540, 1660, 540, 540, 560, 1660, 540, 540, 540, 540, 560, 540, 540, 540, 560, 520, 560, 540, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 39320, 8820, 2200, 560, 0 };

extern const prog_uint16_t tv_volume_down[] PROGMEM;
const prog_uint16_t tv_volume_down[] = { 11216, 8860, 4420, 540, 560, 540, 540, 540, 1660, 560, 520, 560, 540, 540, 540, 560, 540, 540, 540, 560, 1640, 560, 1660, 540, 540, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 540, 560, 520, 560, 540, 540, 540, 560, 540, 540, 540, 540, 540, 560, 540, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 540, 1660, 560, 39320, 8820, 2200, 560, 0 };

extern const prog_uint16_t tv_mute[] PROGMEM;
const prog_uint16_t tv_mute[] = { 15252, 8860, 4420, 540, 540, 560, 540, 540, 1660, 560, 520, 560, 540, 540, 540, 540, 560, 540, 540, 540, 1660, 560, 1640, 560, 540, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 540, 540, 540, 540, 1660, 560, 540, 540, 540, 560, 540, 540, 540, 540, 540, 560, 1640, 560, 1660, 540, 540, 540, 1680, 540, 1660, 540, 1660, 540, 1660, 560, 39320, 8820, 2200, 560, 0 };

extern const prog_uint16_t trigger_emberplug[] PROGMEM;
const prog_uint16_t trigger_emberplug[] = { 38688, 8880, 4400, 560, 540, 540, 540, 560, 1640, 560, 540, 540, 540, 560, 540, 540, 540, 540, 560, 540, 1660, 540, 1660, 540, 540, 560, 1660, 540, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 540, 540, 1660, 560, 540, 540, 540, 540, 540, 560, 540, 540, 540, 560, 520, 560, 1660, 540, 540, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 39340, 8820, 2200, 540, 0 };

extern const prog_uint16_t tv_input[] PROGMEM;
const prog_uint16_t tv_input[] = { 17284, 8880, 4400, 560, 540, 540, 540, 560, 1660, 540, 540, 540, 540, 560, 540, 540, 540, 540, 560, 540, 1660, 540, 1660, 560, 520, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 560, 1640, 560, 540, 540, 1660, 540, 540, 560, 520, 560, 540, 540, 540, 560, 540, 540, 540, 560, 1640, 560, 540, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 39320, 8840, 2200, 540, 0 };

extern const prog_uint16_t channel_up[] PROGMEM;
const prog_uint16_t channel_up[] = { 37212, 8880, 4420, 540, 540, 560, 540, 540, 1660, 540, 540, 560, 540, 540, 540, 560, 520, 560, 540, 540, 1660, 540, 1680, 540, 540, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 540, 540, 540, 540, 540, 560, 540, 540, 540, 560, 520, 560, 540, 540, 540, 540, 1660, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 0 };

extern const prog_uint16_t channel_down[] PROGMEM;
const prog_uint16_t channel_down[] = { 45860, 8880, 4420, 540, 540, 540, 540, 560, 1660, 540, 540, 540, 560, 540, 540, 540, 540, 560, 520, 560, 1660, 540, 1660, 540, 560, 540, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 560, 540, 540, 540, 540, 560, 520, 560, 540, 540, 540, 560, 540, 540, 540, 540, 1660, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 0 };

extern const prog_uint16_t tv_subtitle[] PROGMEM;
const prog_uint16_t tv_subtitle[] = { 30788, 8880, 4420, 540, 540, 560, 540, 540, 1660, 540, 540, 560, 540, 540, 540, 540, 560, 540, 540, 540, 1660, 560, 1640, 560, 540, 540, 1660, 560, 1640, 560, 1660, 540, 1660, 540, 1660, 560, 1640, 560, 540, 540, 540, 540, 1660, 560, 1660, 540, 1660, 540, 540, 560, 540, 540, 540, 560, 1640, 560, 1660, 540, 540, 540, 540, 560, 540, 540, 1660, 540, 1660, 560, 39320, 8820, 2220, 540, 0 };
  
#endif