#pragma once

#include "CFG/Switch_Cfg.h"
#include "MCAL/GPIO.h"

#define Switch_conn_pullup         1
#define Switch_conn_pushdown       0
#define Switch_state_on            1
#define Switch_state_off           0


typedef struct {
    uint32_t port;
    uint32_t pin;
    uint8_t connection;
}Switchcfg_t;



void Switch_getstatus(uint32_t Switch, uint8_t * Switch_state);
void Switch_init(void);
