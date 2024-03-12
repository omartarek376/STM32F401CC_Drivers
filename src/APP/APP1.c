#include "HAL/LED.h"
uint8_t Led_state = led_state_off;
void Runnable_APP1()
{
    if (Led_state == led_state_off)
    {
        led_setstatus(LED_BUILTIN,led_state_on);
        Led_state = led_state_on;
    }
    else
    {
        led_setstatus(LED_BUILTIN,led_state_off);
        Led_state = led_state_off;
    }
}

