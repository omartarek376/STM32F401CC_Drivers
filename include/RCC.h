#pragma once
#include <stdint.h>

#define STATE_ON				1
#define STATE_OFF				0

#define RCC_ENABLE_HSI 			0x00000001
#define RCC_ENABLE_HSE 			0x00010000
#define RCC_ENABLE_PLL 			0x01000000

#define RCC_SYSCLK_HSI			0x00000000
#define RCC_SYSCLK_HSE			0x00000001
#define RCC_SYSCLK_PLL			0x00000002

#define PLL_CLKSRC_HSI			0xFFBFFFFF
#define PLL_CLKSRC_HSE			0x00400000

/*RCC AHB1 peripherals*/
#define AHB1_GPIOA_ENABLE		0x00000001
#define AHB1_GPIOB_ENABLE		0x00000002
#define AHB1_GPIOC_ENABLE		0x00000004
#define AHB1_GPIOD_ENABLE		0x00000008
#define AHB1_GPIOE_ENABLE		0x00000010
#define AHB1_GPIOH_ENABLE		0x00000080
#define AHB1_CRCRST_ENABLE		0x00001000
#define AHB1_DMA1_ENABLE		0x00200000
#define AHB1_DMA2_ENABLE		0x00400000

/*RCC AHB2 peripherals*/
#define AHB2_OTGFS_ENABLE		0x00000080

/*RCC APB1 peripherals*/
#define APB1_TIM2_ENABLE		0x00000001
#define APB1_TIM3_ENABLE		0x00000002
#define APB1_TIM4_ENABLE		0x00000004
#define APB1_TIM5_ENABLE		0x00000008
#define APB1_WWDG_ENABLE		0x00000800
#define APB1_SPI2_ENABLE		0x00004000
#define APB1_SPI3_ENABLE		0x00008000
#define APB1_USART2_ENABLE		0x00020000
#define APB1_I2C1_ENABLE		0x00200000
#define APB1_I2C2_ENABLE		0x00400000
#define APB1_I2C3_ENABLE		0x00800000
#define APB1_PWR_ENABLE			0x10000000

/*RCC APB2 peripherals*/
#define APB2_TIM1_ENABLE       	0x00000001
#define APB2_USART1_ENABLE     	0x00000010
#define APB2_USART6_ENABLE     	0x00000020
#define APB2_ADC1_ENABLE       	0x00000100
#define APB2_SDIO_ENABLE       	0x00000800
#define APB2_SPI1_ENABLE       	0x00001000
#define APB2_SPI4_ENABLE       	0x00002000
#define APB2_SYSCFG_ENABLE     	0x00004000
#define APB2_TIM9_ENABLE       	0x00010000
#define APB2_TIM10_ENABLE      	0x00020000
#define APB2_TIM11_ENABLE      	0x00040000

#define APB1_PRE_1				0x00000000
#define APB1_PRE_2				0x00001000
#define APB1_PRE_4				0x00001400
#define APB1_PRE_8				0x00001800
#define APB1_PRE_16				0x00001C00

#define APB2_PRE_1				0x00000000
#define APB2_PRE_2				0x00008000
#define APB2_PRE_4				0x0000A000
#define APB2_PRE_8				0x0000C000
#define APB2_PRE_16				0x0000E000

#define AHB_PRE_1     			0x00000000
#define AHB_PRE_2     			0x00000080
#define AHB_PRE_4     			0x00000090
#define AHB_PRE_8     			0x000000A0
#define AHB_PRE_16    			0x000000B0
#define AHB_PRE_64    			0x000000C0
#define AHB_PRE_128   			0x000000D0
#define AHB_PRE_256   			0x000000E0
#define AHB_PRE_512  			0x000000F0


typedef enum
{
	RCC_OK,
	RCC_NOK,
	RCC_INVALID_CONFIG,
	RCC_CLK_IN_USE
}RCC_Error_State;



/**
 * @brief 				Enable or disable a specific clock in the RCC (Reset and Clock Control) peripheral.
 * @param RCC_ENABLE 	The bitmask representing the clock(s) to be enabled or disabled. 
 * @param STATE      	The state to set for the clock(s). Use the value STATE_ON to enable the clock(s) and STATE_OFF to disable them.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation.
 * @note 				This function directly modifies the RCC registers to enable or disable the specified clock(s). 
 *       				It does not perform any validation on the parameters RCC_ENABLE and STATE. It's the caller's responsibility 
 *       				to ensure that the parameters are valid and that the specified clock(s) are available on the device.
 */
RCC_Error_State RCC_Enable_Clock(uint32_t RCC_ENABLE , uint8_t STATE);									
/**
 * @brief 				Set the system clock source in the RCC (Reset and Clock Control) peripheral.
 * @param RCC_SYSCLK 	The system clock source to be set. This parameter should be one of the predefined values representing valid system clock sources.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to set the system clock source. It does not perform any validation on the parameter RCC_SYSCLK. 
 *       				It's the caller's responsibility to ensure that the parameter is valid and that the specified system clock source is available on the device.
 */
RCC_Error_State RCC_Set_SystemClock(uint32_t RCC_SYSCLK);												
/**
 * @brief 				Configure the prescalars for the PLL in the RCC (Reset and Clock Control) peripheral.
 * @param PLLQ 			The PLLQ prescalar value to be set (2<= PLLQ <=15).
 * @param PLLP 			The PLLP prescalar value to be set (PLLP = 2,4,6,8).
 * @param PLLN 			The PLLN prescalar value to be set (192<= PLLN <=432).
 * @param PLLM 			The PLLM prescalar value to be set (2<= PLLM <=63).
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to configure the PLL prescalars. 
 *       				It does not perform any validation on the parameters PLLQ, PLLP, PLLN, and PLLM. 
 *       				It's the caller's responsibility to ensure that the parameters are valid and within the allowed range.
 */
RCC_Error_State RCC_Cfg_PLL_Prescalars(uint32_t PLLQ , uint32_t PLLP , uint32_t PLLN , uint32_t PLLM);	
/**
 * @brief 				Configure the PLL clock source in the RCC (Reset and Clock Control) peripheral.
 * @param PLL_CLKSRC 	The PLL clock source to be configured. This parameter should be one of the predefined values representing valid PLL clock sources.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to configure the PLL clock source. It does not perform any validation on the parameter PLL_CLKSRC. 
 *       				It's the caller's responsibility to ensure that the parameter is valid and that the specified PLL clock source is available on the device.
 */
RCC_Error_State RCC_Cfg_PLL_CLKSRC(uint32_t PLL_CLKSRC);												
/**
 * @brief 				Enable or disable a specific peripheral on the AHB1 bus in the RCC (Reset and Clock Control) peripheral.
 * @param AHB1 			The bitmask representing the peripheral(s) to be enabled or disabled on the AHB1 bus. Each bit in the bitmask corresponds to a specific peripheral. 
 * @param STATE 		The state to set for the peripheral(s) on the AHB1 bus. Use the value STATE_ON to enable the peripheral(s) and STATE_OFF to disable them.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to enable or disable the specified peripheral(s) on the AHB1 bus. 
 *       				It does not perform any validation on the parameters AHB1 and STATE. It's the caller's responsibility 
 *       				to ensure that the parameters are valid and that the specified peripheral(s) on the AHB1 bus are available on the device.
 */
RCC_Error_State RCC_Enable_AHB1_Peripheral(uint32_t AHB1 , uint8_t STATE);								
/**
 * @brief 				Enable or disable a specific peripheral on the AHB2 bus in the RCC (Reset and Clock Control) peripheral.
 * @param AHB1 			The bitmask representing the peripheral(s) to be enabled or disabled on the AHB2 bus. Each bit in the bitmask corresponds to a specific peripheral. 
 * @param STATE 		The state to set for the peripheral(s) on the AHB2 bus. Use the value STATE_ON to enable the peripheral(s) and STATE_OFF to disable them.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to enable or disable the specified peripheral(s) on the AHB2 bus. 
 *       				It does not perform any validation on the parameters AHB2 and STATE. It's the caller's responsibility 
 *       				to ensure that the parameters are valid and that the specified peripheral(s) on the AHB2 bus are available on the device.
 */
RCC_Error_State RCC_Enable_AHB2_Peripheral(uint32_t AHB2 , uint8_t STATE);
/**
 * @brief 				Enable or disable a specific peripheral on the APB1 bus in the RCC (Reset and Clock Control) peripheral.
 * @param APB1 			The bitmask representing the peripheral(s) to be enabled or disabled on the APB1 bus. Each bit in the bitmask corresponds to a specific peripheral. 
 * @param STATE 		The state to set for the peripheral(s) on the APB1 bus. Use the value STATE_ON to enable the peripheral(s) and STATE_OFF to disable them.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to enable or disable the specified peripheral(s) on the APB1 bus. 
 *       				It does not perform any validation on the parameters APB1 and STATE. It's the caller's responsibility 
 *       				to ensure that the parameters are valid and that the specified peripheral(s) on the APB1 bus are available on the device.
 */								
RCC_Error_State RCC_Enable_APB1_Peripheral(uint32_t APB1 , uint8_t STATE);
/**
 * @brief 				Enable or disable a specific peripheral on the APB2 bus in the RCC (Reset and Clock Control) peripheral.
 * @param APB2 			The bitmask representing the peripheral(s) to be enabled or disabled on the APB2 bus. Each bit in the bitmask corresponds to a specific peripheral. 
 * @param STATE 		The state to set for the peripheral(s) on the APB2 bus. Use the value STATE_ON to enable the peripheral(s) and STATE_OFF to disable them.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to enable or disable the specified peripheral(s) on the APB2 bus. 
 *       				It does not perform any validation on the parameters APB2 and STATE. It's the caller's responsibility 
 *       				to ensure that the parameters are valid and that the specified peripheral(s) on the APB2 bus are available on the device.
 */									
RCC_Error_State RCC_Enable_APB2_Peripheral(uint32_t APB2 , uint8_t STATE);								
/**
 * @brief 				Set the prescaler for the APB1 bus in the RCC (Reset and Clock Control) peripheral.
 * @param APB1_PRE 		The prescaler value to be set for the APB1 bus. This parameter should be one of the predefined values representing valid prescaler options.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to set the prescaler for the APB1 bus. It does not perform any validation on the parameter APB1_PRE. 
 *       				It's the caller's responsibility to ensure that the parameter is valid and that the specified prescaler value for the APB1 bus is available on the device.
 */
RCC_Error_State APB1_Prescalar(uint32_t APB1_PRE);																														
/**
 * @brief 				Set the prescaler for the APB2 bus in the RCC (Reset and Clock Control) peripheral.
 * @param APB2_PRE 		The prescaler value to be set for the APB2 bus. This parameter should be one of the predefined values representing valid prescaler options.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to set the prescaler for the APB2 bus. It does not perform any validation on the parameter APB2_PRE. 
 *       				It's the caller's responsibility to ensure that the parameter is valid and that the specified prescaler value for the APB2 bus is available on the device.
 */

RCC_Error_State APB2_Prescalar(uint32_t APB2_PRE);																												
/**
 * @brief 				Set the prescaler for the AHB bus in the RCC (Reset and Clock Control) peripheral.
 * @param AHB_PRE 		The prescaler value to be set for the AHB bus. This parameter should be one of the predefined values representing valid prescaler options.
 * @return 				RCC_Error_State This function returns an error state indicating the success or failure of the operation:
 * @note 				This function directly modifies the RCC registers to set the prescaler for the AHB bus. It does not perform any validation on the parameter AHB_PRE. 
 *       				It's the caller's responsibility to ensure that the parameter is valid and that the specified prescaler value for the AHB bus is available on the device.
 */
RCC_Error_State AHB_Prescalar(uint32_t AHB_PRE);														
