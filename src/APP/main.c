#include "MCAL/RCC.h"
#include "MCAL/GPIO.h"
#include "HAL/LED.h"
#include "HAL/Switch.h"


int main()
{
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE , STATE_ON);
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOC_ENABLE , STATE_ON);

	Switch_init();
	led_init();
	
	uint8_t state = 0;

	while (1)
	{
		Switch_getstatus(Led_Switch, &state); 
		if (state == Switch_state_on)
		{
			led_setstatus(led_builtin, STATE_ON);
		}
		else
		{
			led_setstatus(led_builtin, STATE_OFF);
		}
	}
	return 0;
}
