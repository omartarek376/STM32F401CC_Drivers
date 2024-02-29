#include "LED.h"
#include "GPIO.h"

extern const ledcfg_t leds[_led_num];

LED_ERROR_STATE led_init(void)
{
    LED_ERROR_STATE ERROR_STATE = LED_ENUM_NOK;
    GPIO_CONFIG_T led;
    led.Mode = GPIO_MODE_OP_PP;
    led.Speed = GPIO_SPEED_HIGH;
    for(uint8_t idx = 0; idx < _led_num; idx++)
    {
        led.Pin = leds[idx].pin;
        led.Port = leds[idx].port;
        if (led.Pin < GPIO_PIN_0 || led.Pin > GPIO_PIN_15 || led.Port < GPIO_PORT_A || led.Port > GPIO_PORT_C)
        {
            ERROR_STATE = LED_ENUM_INVALIDCONFIG;
        }
        else
        {
            GPIO_InitPin(&led);
            if (ERROR_STATE == LED_ENUM_NOK)
            {
                ERROR_STATE = LED_ENUM_OK;
            }
        }
    }
    return ERROR_STATE;
}


LED_ERROR_STATE led_setstatus(uint32_t led, uint8_t led_state)
{
    LED_ERROR_STATE ERROR_STATE = LED_ENUM_NOK;
    if ((led_state == led_state_on || led_state == led_state_off) && led < _led_num)
    {
        GPIO_SetPinValue(leds[led].port, leds[led].pin, leds[led].connection^led_state);
        ERROR_STATE = LED_ENUM_OK;
    }
    else
    {
        ERROR_STATE = LED_ENUM_INVALIDCONFIG;
    }
    return ERROR_STATE;
}