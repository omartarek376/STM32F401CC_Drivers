#include "MCAL/NVIC.h"

#define NVIC_ISER               ((volatile uint32_t *)0xE000E100)
#define NVIC_ICER               ((volatile uint32_t *)0xE000E180)
#define NVIC_ISPR               ((volatile uint32_t *)0xE000E200)
#define NVIC_ICPR               ((volatile uint32_t *)0xE000E280)
#define NVIC_IAB                ((volatile uint32_t *)0xE000E300)
#define NVIC_IPR                ((volatile uint32_t *)0xE000E400)
#define NVIC_STIR               *((volatile uint32_t *)0xE000EF00)
#define ACIR	                *((volatile uint32_t *)0xE000ED0C)

#define REGISTER_OFFSET         32
#define GET_BIT                 0x01
#define PRIORITY_OFFSET         4
#define PRIORITY_CLR_MSK        0xFF
#define BIT_OFFSET              8
#define PRIORITY_BIT_MSK        0x3
#define IPR_INDEX_SHIFT         2

void NVIC_EnableIRQ(uint8_t IRQ)
{
    NVIC_ISER[IRQ / REGISTER_OFFSET] = 1 << (IRQ % REGISTER_OFFSET);
}

void NVIC_DisableIRQ(uint8_t IRQ)
{
    NVIC_ICER[IRQ / REGISTER_OFFSET] = 1 << (IRQ % REGISTER_OFFSET);
}

void NVIC_SetPendingIRQ(uint8_t IRQ)
{
    NVIC_ISPR[IRQ / REGISTER_OFFSET] = 1 << (IRQ % REGISTER_OFFSET);
}

void NVIC_ClearPendingIRQ(uint8_t IRQ)
{
    NVIC_ICPR[IRQ / REGISTER_OFFSET] = 1 << (IRQ % REGISTER_OFFSET);
}

INTERRUPT_ACTIVE_STATUS_T NVIC_GetPendingIRQ(uint8_t IRQ)
{
    return (NVIC_IAB[IRQ / REGISTER_OFFSET] >> (IRQ % REGISTER_OFFSET)) & GET_BIT;
}

void NVIC_SetPriority(uint8_t IRQ, uint8_t priority)
{
    uint32_t bitOffset = (IRQ % PRIORITY_OFFSET) * BIT_OFFSET;
    NVIC_IPR[IRQ / PRIORITY_OFFSET] &= ~(PRIORITY_CLR_MSK << bitOffset);
    NVIC_IPR[IRQ / PRIORITY_OFFSET] |= (priority << bitOffset);
}


uint8_t NVIC_GetPriority(uint8_t IRQ)
{
    uint32_t bitOffset = (IRQ % PRIORITY_OFFSET) * BIT_OFFSET;
    return (NVIC_IPR[IRQ / PRIORITY_OFFSET] >> bitOffset >> PRIORITY_OFFSET) & PRIORITY_CLR_MSK;
}


void NVIC_Trigger_Software_Interrupt (uint8_t IRQ)
{
    NVIC_STIR |= IRQ;
}


void NVIC_SetPriorityGrouping(uint32_t GROUP)
{
    ACIR = GROUP;
}

