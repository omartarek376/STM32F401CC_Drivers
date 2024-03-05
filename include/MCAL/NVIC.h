#pragma once

#include <stdint.h>


typedef enum{
    INTERRUPT_NOTACTIVE,
    INTERRUPT_ACTIVE
}INTERRUPT_ACTIVE_STATUS_T;

void NVIC_EnableIRQ(uint8_t IRQ);
void NVIC_DisableIRQ(uint8_t IRQ);
void NVIC_SetPendingIRQ(uint8_t IRQ);
void NVIC_ClearPendingIRQ(uint8_t IRQ);
INTERRUPT_ACTIVE_STATUS_T NVIC_GetPendingIRQ(uint8_t IRQ);
void NVIC_SetPriority(uint8_t IRQ, uint8_t priority);
uint8_t NVIC_GetPriority(uint8_t IRQ);
void NVIC_Trigger_Software_Interrupt (uint8_t IRQ);
void NVIC_SetPriorityGrouping(uint32_t GROUP);