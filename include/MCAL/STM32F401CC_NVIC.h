#pragma once

#define GROUP_0_SUB 0x05FA0000          //[4] bits Preempt Group &  [0] bits Subpriority Group
#define GROUP_1_SUB 0x05FA0400          //[3] bits Preempt Group &  [1] bits Subpriority Group
#define GROUP_2_SUB 0x05FA0500          //[2] bits Preempt Group &  [2] bits Subpriority Group
#define GROUP_3_SUB 0x05FA0600          //[1] bits Preempt Group &  [3] bits Subpriority Group
#define GROUP_4_SUB 0x05FA0700          //[0] bits Preempt Group &  [4] bits Subpriority Group

#define IRQ_WINDOW_WATCHDOG_TIMER 0
#define IRQ_EXTERNAL_LINE16 1
#define IRQ_EXTERNAL_LINE21 2
#define IRQ_EXTERNAL_LINE22 3
#define IRQ_FLASH_INTERRUPT 4
#define IRQ_RCC_INTERRUPT 5
#define IRQ_EXT0_INTERRRUPT 6
#define IRQ_EXT1_INTERRRUPT 7
#define IRQ_EXT2_INTERRRUPT 8
#define IRQ_EXT3_INTERRRUPT 9
#define IRQ_EXT4_INTERRRUPT 10
#define IRQ_DMA1_STREAM0 11
#define IRQ_DMA1_STREAM1 12
#define IRQ_DMA1_STREAM2 13
#define IRQ_DMA1_STREAM3 14
#define IRQ_DMA1_STREAM4 15
#define IRQ_DMA1_STREAM5 16
#define IRQ_DMA1_STREAM6 17
#define IRQ_ADC_INTERRUPT 18
#define IRQ_EXT9_INTERRUPT 23
#define IRQ_TIM1_BRK_INTERRUPT 24
#define IRQ_TIM1_UP_INTERRUPT 25
#define IRQ_TIMI1_TRG_INTERRUPT 26
#define IRQ_TIMI1_CC_INTERRUPT 27
#define IRQ_TIMI2_INTERRUPT 28
#define IRQ_TIMI3_INTERRUPT 29
#define IRQ_TIMI4_INTERRUPT 30
#define IRQ_I2C1_EV_INTERRUPT 31
#define IRQ_I2C1_ER_INTERRUPT 32
#define IRQ_I2C2_EV_INTERRUPT 33
#define IRQ_I2C2_ER_INTERRUPT 34
#define IRQ_SPI1_INTERRUPT 35
#define IRQ_SPI2_INTERRUPT 36
#define IRQ_USART1_INTERRUPT 37
#define IRQ_USART2_INTERRUPT 38
#define IRQ_EXTI15_INTERRUPT 40
#define IRQ_EXTI17_INTERRUPT 41
#define IRQ_EXTI18_INTERRUPT 42
#define IRQ_DMA1_INTERRUPT 47
#define IRQ_SDIO_INTERRUPT 49
#define IRQ_TIM5_INTERRUPT 50
#define IRQ_SPI3_INTERRUPT 51
#define IRQ_DMA2_STREAM0_INTERRUPT 56
#define IRQ_DMA2_STREAM1_INTERRUPT 57
#define IRQ_DMA2_STREAM2_INTERRUPT 58
#define IRQ_DMA2_STREAM3_INTERRUPT 59
#define IRQ_DMA2_STREAM4_INTERRUPT 60
#define IRQ_OTG_FS_INTERRUPT 67
#define IRQ_DMA2_STREAM5_INTERRUPT 68
#define IRQ_DMA2_STREAM6_INTERRUPT 69
#define IRQ_DMA2_STREAM7_INTERRUPT 70
#define IRQ_USART6_INTERRUPT 71
#define IRQ_I2C3_EV_INTERRUPT 72
#define IRQ_I2C3_ER_INTERRUPT 73
#define IRQ_FPU_INTERRUPT 81
#define IRQ_SPI4_INTERRUPT 84