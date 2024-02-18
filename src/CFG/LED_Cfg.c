#include "HAL/LED.h"

const ledcfg_t leds[_led_num]=
{
    [led_builtin]=
    {
        .port=GPIO_PORT_C,
        .pin=GPIO_PIN_13,
        .connection= Led_conn_rev,
    }
};