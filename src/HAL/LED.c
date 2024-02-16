#include "HAL/LED.h"
#include "MCAL/GPIO.h"

extern const ledcfg_t leds[_led_num];

void led_init(void)
{
    GPIO_CONFIG_T led;
    led.Mode = GPIO_MODE_OP_PP;
    led.Speed = GPIO_SPEED_HIGH;
    for(uint8_t idx = 0; idx < _led_num; idx++)
    {
        led.Pin = leds[idx].pin;
        led.Port = leds[idx].port;
        GPIO_InitPin(&led);
    }
}


void led_setstatus(uint32_t led, uint8_t led_state)
{
    GPIO_SetPinValue(leds[led].port, leds[led].pin, leds[led].connection^led_state);
}