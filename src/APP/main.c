#include "MCAL/NVIC.h"
#include "MCAL/STM32F401CC_NVIC.h"
#include "MCAL/GPIO.h"
#include "MCAL/RCC.h"
#include "HAL/LED.h"

void delay_ms(uint32_t ms)
 {
    for (volatile uint32_t i = 0; i < ms * 16000; ++i)
    {

    }
}
void EXTI0_IRQHandler(void)
{
	led_setstatus(led_builtin , STATE_ON);
	NVIC_Trigger_Software_Interrupt(IRQ_EXT1_INTERRRUPT);
	delay_ms(50);
}


void EXTI1_IRQHandler(void)
{
	NVIC_SetPendingIRQ(IRQ_EXT0_INTERRRUPT);
	led_setstatus(led_builtin, STATE_OFF);
	delay_ms(50);
}


int main()
{
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOC_ENABLE,STATE_ON);
	led_init();
	NVIC_EnableIRQ(IRQ_EXT0_INTERRRUPT);
	NVIC_EnableIRQ(IRQ_EXT1_INTERRRUPT);	
	NVIC_SetPriority(IRQ_EXT0_INTERRRUPT,0x30);
	NVIC_SetPriority(IRQ_EXT1_INTERRRUPT,0x10);
	NVIC_SetPriorityGrouping(GROUP_7);
	volatile uint8_t x = NVIC_GetPriority(IRQ_EXT0_INTERRRUPT);
	NVIC_Trigger_Software_Interrupt(IRQ_EXT0_INTERRRUPT);
	
	while (1)
	{
	}
	return 0;
}
