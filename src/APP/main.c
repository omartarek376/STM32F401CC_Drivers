#include "MCAL/RCC.h"
#include "MCAL/GPIO.h"


int main()
{
	RCC_Cfg_PLL_Prescalars(7,6,200,10);
	RCC_Enable_Clock(RCC_ENABLE_PLL, STATE_ON);
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOC_ENABLE , STATE_ON);
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE , STATE_ON);

	GPIO_CONFIG_T Led;
	Led.Port = GPIO_PORT_C;
	Led.Pin = GPIO_PIN_13;
	Led.Mode = GPIO_MODE_OP_PP_PD;
	Led.Speed = GPIO_SPEED_MED;
	GPIO_InitPin(&Led);

	GPIO_CONFIG_T In_A1;
	In_A1.Port = GPIO_PORT_A;
	In_A1.Pin = GPIO_PIN_1;
	In_A1.Mode = GPIO_MODE_IN_PD;
	In_A1.Speed = GPIO_SPEED_MED;
	GPIO_InitPin(&In_A1);

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
