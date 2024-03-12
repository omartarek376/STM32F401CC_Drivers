#pragma once

typedef enum{
    LED_RED,
    LED_YELLOW,
    LED_GREEN,
    LED_BUILTIN,
    LED_ALARM,
    _led_num        // user will not use it ,this indicates the num of leds stated by user
}leds_t;