#include "MCAL/RCC.h"

#define RCC_BASE_ADDRESS 				0x40023800
#define RCC_HSI_RDY						0x00000002
#define RCC_HSE_RDY						0x00020000
#define RCC_PLL_RDY						0x02000000
#define RCC_SYSCLK_CLR_MASK				0x00000003
#define PLL_CLR_PRESCALARS				0xF0FC8000
#define PLLQ_SHIFT						24
#define PLLP_SHIFT						16
#define PLLN_SHIFT						6
#define PLLP_PRE_2						0x00000000
#define PLLP_PRE_4						0x00000001
#define PLLP_PRE_6						0x00000002
#define PLLP_PRE_8						0x00000003
#define APB1_CLR_PRE					0xFFFFE3FF
#define APB2_CLR_PRE					0xFFFF1FFF
#define AHB_CLR_PRE						0xFFFFFF0F

typedef struct
{
	volatile uint32_t CR;          		// Clock control register
	volatile uint32_t PLLCFGR;     		// PLL configuration register
	volatile uint32_t CFGR;        		// Clock configuration register
	volatile uint32_t CIR;         		// Clock interrupt register
	volatile uint32_t AHB1RSTR;    		// AHB1 peripheral reset register
	volatile uint32_t AHB2RSTR;    		// AHB2 peripheral reset register
	volatile uint32_t RESERVED0;   		// Reserved
	volatile uint32_t RESERVED1;   		// Reserved
	volatile uint32_t APB1RSTR;    		// APB1 peripheral reset register
	volatile uint32_t APB2RSTR;    		// APB2 peripheral reset register
	volatile uint32_t RESERVED2;		// Reserved
	volatile uint32_t RESERVED3;		// Reserved
	volatile uint32_t AHB1ENR;     		// AHB1 peripheral clock enable register
	volatile uint32_t AHB2ENR;     		// AHB2 peripheral clock enable register
	volatile uint32_t RESERVED4;		// Reserved
	volatile uint32_t RESERVED5;   		// Reserved
	volatile uint32_t APB1ENR;     		// APB1 peripheral clock enable register
	volatile uint32_t APB2ENR;     		// APB2 peripheral clock enable register
	volatile uint32_t RESERVED6;		// Reserved
	volatile uint32_t RESERVED7;		// Reserved
	volatile uint32_t AHB1LPENR;   		// AHB1 peripheral clock enable in low power mode register
	volatile uint32_t AHB2LPENR;   		// AHB2 peripheral clock enable in low power mode register
	volatile uint32_t RESERVED8;		// Reserved
	volatile uint32_t RESERVED9;   		// Reserved
	volatile uint32_t APB1LPENR;   		// APB1 peripheral clock enable in low power mode register
	volatile uint32_t APB2LPENR;   		// APB2 peripheral clock enable in low power mode register
	volatile uint32_t RESERVED10;		// Reserved
	volatile uint32_t RESERVED11;		// Reserved
	volatile uint32_t BDCR;        		// Backup domain control register
	volatile uint32_t CSR;         		// Clock control & status register
	volatile uint32_t RESERVED12;		// Reserved
	volatile uint32_t RESERVED13;		// Reserved
	volatile uint32_t SSCGR;       		// Spread spectrum clock generation register
	volatile uint32_t PLLI2SCFGR;  		// PLLI2S configuration register
	volatile uint32_t DCKCFGR;  		// DCK configuration register
}RCC_T;


static RCC_T * const RCC = (RCC_T*)RCC_BASE_ADDRESS;


RCC_Error_State RCC_Enable_Clock(uint32_t RCC_ENABLE , uint8_t STATE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	uint32_t Temp_clk_option = 0;

	switch(RCC_ENABLE)
	{
		case RCC_ENABLE_HSE:
		Temp_clk_option = RCC_HSE_RDY;
		break;

		case RCC_ENABLE_HSI:
		Temp_clk_option = RCC_HSI_RDY;
		break;

		case RCC_ENABLE_PLL:
		Temp_clk_option = RCC_PLL_RDY;
		break;

		default:
		Loc_Error_Status = RCC_INVALID_CONFIG;
		break;
	}

	switch(STATE)
	{
		case STATE_ON:
		{
			RCC->CR |= RCC_ENABLE;
			Loc_Error_Status = RCC_OK;
			while(!((RCC->CR & Temp_clk_option) == Temp_clk_option));
			break;
		}

		case STATE_OFF:
		{
			RCC->CR &= ~RCC_ENABLE;
			Loc_Error_Status = RCC_OK;
			break;
		}

		default:
		{
			Loc_Error_Status = RCC_INVALID_CONFIG;
			break;
		}
	}

	return Loc_Error_Status;
}


RCC_Error_State RCC_Set_SystemClock(uint32_t RCC_SYSCLK)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;

	switch(RCC_SYSCLK)
	{
		case RCC_SYSCLK_HSI:
		if ((RCC->CR & RCC_HSI_RDY) == RCC_HSI_RDY)
		{
			uint32_t temp = RCC->CFGR;
			temp &= ~RCC_SYSCLK_CLR_MASK;
			temp |= RCC_SYSCLK;
			RCC->CFGR = temp;
			Loc_Error_Status = RCC_OK;
		}
		else
		{
			Loc_Error_Status = RCC_INVALID_CONFIG;
			break;
		}
		

		case RCC_SYSCLK_HSE:
		if ((RCC->CR & RCC_HSE_RDY) == RCC_HSE_RDY)
		{
			uint32_t temp = RCC->CFGR;
			temp &= ~RCC_SYSCLK_CLR_MASK;
			temp |= RCC_SYSCLK;
			RCC->CFGR = temp;
			Loc_Error_Status = RCC_OK;
		}
		else
		{
			Loc_Error_Status = RCC_INVALID_CONFIG;
			break;
		}
		


		case RCC_SYSCLK_PLL:
		if ((RCC->CR & RCC_PLL_RDY) == RCC_PLL_RDY)
		{
			uint32_t temp = RCC->CFGR;
			temp &= ~RCC_SYSCLK_CLR_MASK;
			temp |= RCC_SYSCLK;
			RCC->CFGR = temp;
			Loc_Error_Status = RCC_OK;
		}
		else
		{
			Loc_Error_Status = RCC_INVALID_CONFIG;
			break;
		}
		

		default:
		Loc_Error_Status = RCC_INVALID_CONFIG;
		break;
	}

	return Loc_Error_Status;
}


RCC_Error_State RCC_Cfg_PLL_Prescalars(uint32_t PLLQ , uint32_t PLLP , uint32_t PLLN , uint32_t PLLM)	
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	uint32_t Temp_PLL_Conf = RCC->PLLCFGR;
	Temp_PLL_Conf &= PLL_CLR_PRESCALARS;
	uint8_t Exit_Flag = 0;

	if ((PLLQ > 15) || (PLLQ < 2))
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
		Exit_Flag = 1;
	}
	else
	{
		Temp_PLL_Conf |= PLLQ << PLLQ_SHIFT;
	}

	if ((PLLP == 2) || (PLLP == 4) || (PLLP == 6) || (PLLP == 8))
	{
		switch(PLLP)
		{
			case 2:
			Temp_PLL_Conf |= PLLP_PRE_2 << PLLP_SHIFT;
			break;

			case 4:
			Temp_PLL_Conf |= PLLP_PRE_4 << PLLP_SHIFT;
			break;

			case 6:
			Temp_PLL_Conf |= PLLP_PRE_6 << PLLP_SHIFT;
			break;

			case 8:
			Temp_PLL_Conf |= PLLP_PRE_8 << PLLP_SHIFT;
			break;

			default:
			break;
		}
	}
	else
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
		Exit_Flag = 1;
	}

	if ((PLLN > 432) || (PLLN < 192))
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
		Exit_Flag = 1;
	}
	else
	{
		Temp_PLL_Conf |= PLLN << PLLN_SHIFT;
	}

	if ((PLLM > 63) || (PLLM < 2) || (Exit_Flag == 1))
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
		Exit_Flag = 1;
	}
	else
	{
		Temp_PLL_Conf |= PLLM;
	}

	if (Exit_Flag == 0)
	{
		RCC->PLLCFGR = Temp_PLL_Conf;
	}

	return Loc_Error_Status;
}


RCC_Error_State RCC_Cfg_PLL_CLKSRC(uint32_t PLL_CLKSRC)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;

	switch(PLL_CLKSRC)
	{
		case PLL_CLKSRC_HSE:
		if((RCC->CR & RCC_HSE_RDY) == RCC_HSE_RDY)
		{
			RCC->PLLCFGR |= PLL_CLKSRC;
			Loc_Error_Status = RCC_OK;
		}
		else{break;}
		

		case PLL_CLKSRC_HSI:
		if((RCC->CR & RCC_HSI_RDY) == RCC_HSI_RDY)
		{
			RCC->PLLCFGR &= PLL_CLKSRC;
			Loc_Error_Status = RCC_OK;
		}
		else{break;}
		
	}

		return Loc_Error_Status;
}



RCC_Error_State RCC_Enable_AHB1_Peripheral(uint32_t AHB1 , uint8_t STATE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	switch(STATE)
	{
		case STATE_ON:
		RCC->AHB1ENR |= AHB1;
		break;

		case STATE_OFF:
		RCC->AHB1ENR &= ~AHB1;
		break;

		default:
		Loc_Error_Status = RCC_INVALID_CONFIG;
		break;
	}
	return Loc_Error_Status;
}


RCC_Error_State RCC_Enable_AHB2_Peripheral(uint32_t AHB2 , uint8_t STATE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	switch(STATE)
	{
		case STATE_ON:
		RCC->AHB2ENR |= AHB2;
		break;

		case STATE_OFF:
		RCC->AHB2ENR &= ~AHB2;
		break;

		default:
		Loc_Error_Status = RCC_INVALID_CONFIG;
		break;
	}
	return Loc_Error_Status;
}

RCC_Error_State RCC_Enable_APB1_Peripheral(uint32_t APB1 , uint8_t STATE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	switch(STATE)
	{
		case STATE_ON:
		RCC->APB1ENR |= APB1;
		break;

		case STATE_OFF:
		RCC->APB1ENR &= ~APB1;
		break;

		default:
		Loc_Error_Status = RCC_INVALID_CONFIG;
		break;
	}
	return Loc_Error_Status;
}

RCC_Error_State RCC_Enable_APB2_Peripheral(uint32_t APB2 , uint8_t STATE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	switch(STATE)
	{
		case STATE_ON:
		RCC->APB2ENR |= APB2;
		break;

		case STATE_OFF:
		RCC->APB2ENR &= ~APB2;
		break;

		default:
		Loc_Error_Status = RCC_INVALID_CONFIG;
		break;
	}
	return Loc_Error_Status;
}


RCC_Error_State APB1_Prescalar(uint32_t APB1_PRE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	if ((APB1_PRE == APB1_PRE_1) || (APB1_PRE == APB1_PRE_2) || (APB1_PRE == APB1_PRE_4) || (APB1_PRE == APB1_PRE_8) || (APB1_PRE == APB1_PRE_16))
	{
		uint32_t Temp_Pre = RCC->CFGR;
		Temp_Pre &= APB1_CLR_PRE;
		Temp_Pre |= APB1_PRE;
		RCC->CFGR = APB1_PRE;
		Loc_Error_Status = RCC_OK;
	}
	else
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
	}
	return Loc_Error_Status;
}


RCC_Error_State APB2_Prescalar(uint32_t APB2_PRE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	if ((APB2_PRE == APB2_PRE_1) || (APB2_PRE == APB2_PRE_2) || (APB2_PRE == APB2_PRE_4) || (APB2_PRE == APB2_PRE_8) || (APB2_PRE == APB2_PRE_16))
	{
		uint32_t Temp_Pre = RCC->CFGR;
		Temp_Pre &= APB2_CLR_PRE;
		Temp_Pre |= APB2_PRE;
		RCC->CFGR = APB2_PRE;
		Loc_Error_Status = RCC_OK;
	}
	else
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
	}
	return Loc_Error_Status;
}


RCC_Error_State AHB_Prescalar(uint32_t AHB_PRE)
{
	RCC_Error_State Loc_Error_Status = RCC_NOK;
	if ((AHB_PRE == AHB_PRE_1) || (AHB_PRE == AHB_PRE_2) || (AHB_PRE == AHB_PRE_4) || (AHB_PRE == AHB_PRE_8) || (AHB_PRE == AHB_PRE_16) /
	(AHB_PRE == AHB_PRE_64) || (AHB_PRE == AHB_PRE_128) || (AHB_PRE == AHB_PRE_256) || (AHB_PRE == AHB_PRE_512))
	{
		uint32_t Temp_Pre = RCC->CFGR;
		Temp_Pre &= AHB_CLR_PRE;
		Temp_Pre |= AHB_PRE;
		RCC->CFGR = AHB_PRE;
		Loc_Error_Status = RCC_OK;
	}
	else
	{
		Loc_Error_Status = RCC_INVALID_CONFIG;
	}
	return Loc_Error_Status;
}
