#include "MCAL/RCC.h"
#include "MCAL/GPIO.h"
#include "HAL/LED.h"


int main()
{
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE , STATE_ON);
	led_init();

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
			led_setstatus(led_red, led_state_on);
			led_setstatus(led_green, led_state_on);
		}
		else
		{
			GPIO_SetPinValue(GPIO_PORT_C, GPIO_PIN_13, 1);
			led_setstatus(led_red, led_state_off);
			led_setstatus(led_green, led_state_off);
		}
	}
	return 0;
}
