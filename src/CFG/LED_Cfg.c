#include "HAL/LED.h"
#include "MCAL/GPIO.h"

const ledcfg_t leds[_led_num]=
{
    [LED_BUILTIN]=
    {
        .port=GPIO_PORT_C,
        .pin=GPIO_PIN_13,
        .connection= Led_conn_rev,
    },
    [LED_RED]=
    {
        .port=GPIO_PORT_A,
        .pin=GPIO_PIN_1,
        .connection= Led_conn_forward,
    },
    [LED_YELLOW]=
    {
        .port=GPIO_PORT_A,
        .pin=GPIO_PIN_2,
        .connection= Led_conn_forward,
    },
    [LED_GREEN]=
    {
        .port=GPIO_PORT_A,
        .pin=GPIO_PIN_3,
        .connection= Led_conn_forward,
    },
    [LED_ALARM]=
    {
        .port=GPIO_PORT_A,
        .pin=GPIO_PIN_4,
        .connection= Led_conn_forward,
    }
};

