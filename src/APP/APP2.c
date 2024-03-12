#include "HAL/Switch.h"
#include "HAL/LED.h"

void Runnable_APP2()
{
    uint8_t switchStatus = Switch_state_off;
    Switch_getstatus(Led_Switch, &switchStatus);
    if (switchStatus == Switch_state_on)
    {
        led_setstatus(LED_ALARM, led_state_on);
    }
    else
    {
        led_setstatus(LED_ALARM, led_state_off);
    }
}