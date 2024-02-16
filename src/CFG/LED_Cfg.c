#include "HAL/LED.h"

const ledcfg_t leds[_led_num]=
{
    [led_red]=
    {
        .port=GPIO_PORT_A,
        .pin=GPIO_PIN_2,
        .connection= Led_conn_forward,
    },
    [led_green]=
    {
        .port=GPIO_PORT_A,
        .pin=GPIO_PIN_3,
        .connection= Led_conn_rev,
    }
};