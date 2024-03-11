#include "MCAL/SYSTICK.h"
#include "MCAL/GPIO.h"
#include "HAL/LED.h"
#include "MCAL/RCC.h"

uint8_t LED_State = led_state_on;
uint8_t count = 0;


void LED_Handler(void)
{
	count++;
	if (count == 100)
	{
		if (LED_State == led_state_off)
		{
			led_setstatus(led_builtin , led_state_on);
			LED_State = led_state_on;
		}
		else
		{
			led_setstatus(led_builtin , led_state_off);
			LED_State = led_state_off;
		}
		count = 0;
	}
}



int main()
{
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOC_ENABLE,STATE_ON);
	led_init();
	led_setstatus(led_builtin , led_state_off);
	
	STK_Init(SOURCE_AHB_DIV_8);
	STK_SetTimeMS(10);
	STK_EnableInterrupt();
	STK_SetCallback(LED_Handler);
	STK_Start(STK_MODE_PERIODIC);
	
	while (1)
	{
	}
	return 0;
}
