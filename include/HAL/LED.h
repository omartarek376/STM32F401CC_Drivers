#pragma once

#include "CFG/LED_Cfg.h"
#include "MCAL/GPIO.h"

#define Led_conn_forward        0
#define Led_conn_rev            1
#define led_state_on            1
#define led_state_off           0


typedef struct {
    uint32_t port;
    uint32_t pin;
    uint8_t connection;
}ledcfg_t;



void led_setstatus(uint32_t led, uint8_t led_state);
void led_init(void);
