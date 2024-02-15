#include <stdio.h>
#include "RCC.h"
#include "GPIO.h"


int main()
{
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOC_ENABLE , STATE_ON);
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE , STATE_ON);
	GPIO_CONFIG_T Led;
	Led.Port = GPIO_PORT_C;
	Led.Pin = GPIO_PIN_13;
	Led.Mode = GPIO_MODE_OP_PP_PD;
	Led.Speed = GPIO_SPEED_MED;
	GPIO_InitPin(&Led);

	GPIO_CONFIG_T Led2;
	Led2.Port = GPIO_PORT_A;
	Led2.Pin = GPIO_PIN_1;
	Led2.Mode = GPIO_MODE_IN_PD;
	Led2.Speed = GPIO_SPEED_MED;
	GPIO_InitPin(&Led2);

	uint8_t state = 0;

	while (1)
	{
		GPIO_GetPinValue(GPIO_PORT_A, GPIO_PIN_1, &state); 
		if (state == STATE_ON)
		{
			GPIO_SetPinValue(GPIO_PORT_C, GPIO_PIN_13, 0);
		}
		else
		{
			GPIO_SetPinValue(GPIO_PORT_C, GPIO_PIN_13, 1);
		}
	}
	return 0;
}
