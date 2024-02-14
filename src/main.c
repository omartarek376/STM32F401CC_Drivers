#include <stdio.h>
#include "RCC.h"


int main()
{
	//RCC_Set_SystemClock(RCC_SYSCLK_HSI);
	//RCC_Enable_Clock(RCC_ENABLE_PLL , STATE_OFF);
	RCC_Cfg_PLL_CLKSRC(PLL_CLKSRC_HSE);
	RCC_Cfg_PLL_Prescalars(7,4,210,10);
	RCC_Enable_Clock(RCC_ENABLE_PLL , STATE_ON);
	RCC_Set_SystemClock(RCC_SYSCLK_PLL);
	RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE , STATE_ON);
	//APB1_Prescalar(APB1_PRE_2);
	//RCC_Enable_AHB1_Peripheral(AHB1_GPIOA_ENABLE , STATE_OFF);
	while (1)
	{

	}
	return 0;
}
