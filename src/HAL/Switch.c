#include "HAL/Switch.h"
#include "MCAL/GPIO.h"

extern const Switchcfg_t Switches[_Switch_num];

void Switch_init(void)
{
    GPIO_CONFIG_T Switch;
    Switch.Speed = GPIO_SPEED_HIGH;
    for(uint8_t idx = 0; idx < _Switch_num; idx++)
    {
        if (Switches[idx].connection == Switch_conn_pullup)
        {
            Switch.Mode = GPIO_MODE_IN_PU;
        }
        else
        {
            Switch.Mode = GPIO_MODE_IN_PD;
        }
        Switch.Pin = Switches[idx].pin;
        Switch.Port = Switches[idx].port;
        GPIO_InitPin(&Switch);
    }
}


void Switch_getstatus(uint32_t Switch, uint8_t * Switch_state)
{
    GPIO_GetPinValue(Switches[Switch].port, Switches[Switch].pin, Switch_state);
    *Switch_state ^= Switches[Switch].connection;
}