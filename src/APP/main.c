#include "MCAL/SYSTICK.h"
#include "HAL/Switch.h"
#include "HAL/LED.h"
#include "MCAL/RCC.h"
#include "HAL/Scheduler.h"



int main(int argc, char* argv[])
{
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOC_ENABLE,STATE_ON);
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE,STATE_ON);
	Switch_init();
	led_init();
	Sched_Init();
	Sched_Start();
}