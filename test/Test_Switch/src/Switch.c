#include "Switch.h"
#include "GPIO.h"

#define NULL ((void*)0)


extern const Switchcfg_t Switches[_Switch_num];

SWITCH_ERROR_STATE Switch_init(void)
{
    SWITCH_ERROR_STATE ERROR_STATE = SWITCH_ENUM_NOK;
    GPIO_CONFIG_T Switch;
    Switch.Speed = GPIO_SPEED_HIGH;
    for(uint8_t idx = 0; idx < _Switch_num; idx++)
    {
        if (Switches[idx].connection == Switch_conn_pullup)
        {
            Switch.Mode = GPIO_MODE_IN_PU;
            Switch.Pin = Switches[idx].pin;
            Switch.Port = Switches[idx].port;
            GPIO_InitPin(&Switch);
            ERROR_STATE = SWITCH_ENUM_OK;
        }
        else if (Switches[idx].connection == Switch_conn_pushdown)
        {
            Switch.Mode = GPIO_MODE_IN_PD;
            Switch.Pin = Switches[idx].pin;
            Switch.Port = Switches[idx].port;
            GPIO_InitPin(&Switch);
            ERROR_STATE = SWITCH_ENUM_OK;
        }
        else
        {
            ERROR_STATE = SWITCH_ENUM_INVALIDCONFIG;
        }
    }
    return ERROR_STATE;
}


SWITCH_ERROR_STATE Switch_getstatus(uint32_t Switch, uint8_t * Switch_state)
{
    SWITCH_ERROR_STATE ERROR_STATE = SWITCH_ENUM_NOK;
    if (Switch_state == NULL)
    {
        ERROR_STATE = SWITCH_ENUM_NULLPTR;
    }
    else
    {
        if (Switch >= _Switch_num)
        {
            ERROR_STATE = SWITCH_ENUM_INVALIDCONFIG;
        }
        else
        {
            GPIO_GetPinValue(Switches[Switch].port, Switches[Switch].pin, Switch_state);
            //*Switch_state ^= Switches[Switch].connection;
            ERROR_STATE = SWITCH_ENUM_OK;
        }
    }
    return ERROR_STATE;
}