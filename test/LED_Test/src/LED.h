#pragma once
#include <stdint.h>
#include "LED_Cfg.h"


#define Led_conn_forward        0
#define Led_conn_rev            1
#define led_state_on            1
#define led_state_off           0


typedef struct {
    uint32_t port;
    uint32_t pin;
    uint8_t connection;
}ledcfg_t;

typedef enum
{
    LED_ENUM_OK,
    LED_ENUM_NOK,
    LED_ENUM_INVALIDCONFIG
}LED_ERROR_STATE;



LED_ERROR_STATE led_setstatus(uint32_t led, uint8_t led_state);
LED_ERROR_STATE led_init(void);
