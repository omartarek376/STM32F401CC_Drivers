#include "MCAL/DMA.h"

#define NULL ((void*)0)
#define DMA1_BASE_ADDRESS           0x40026000
#define DMA2_BASE_ADDRESS           0x40026400

typedef struct {
    volatile uint32_t LISR;      // Low interrupt status register
    volatile uint32_t HISR;      // High interrupt status register
    volatile uint32_t LIFCR;     // Low interrupt flag clear register
    volatile uint32_t HIFCR;     // High interrupt flag clear register

    struct {
       volatile uint32_t CR;      // control register
       volatile uint32_t NDTR;    // number of data register
       volatile uint32_t PAR;     // peripheral address register
       volatile uint32_t M0AR;    // memory 0 address register
       volatile uint32_t M1AR;    // memory 1 address register
       volatile uint32_t FCR;     // FIFO control register
    } Cfg_Reg[8];

} Dma_tRegister;


static Dma_tRegister * const DMA1 = (Dma_tRegister*)DMA1_BASE_ADDRESS;
static Dma_tRegister * const DMA2 = (Dma_tRegister*)DMA2_BASE_ADDRESS;


DMA_Error DMA_Init(DMA_Settings* settings) 
{
    DMA_Error Error_State = DMA_ENUM_NOK;
    if (settings == NULL) 
    {
        return DMA_ENUM_NULLPTR;
    }
    else
    {
        Error_State = DMA_ENUM_OK;
    }

    return Error_State;
}

DMA_Error DMA_StartTransfer(DMA_Settings* settings, uint32_t srcAddress, uint32_t destAddress, uint32_t dataSize) 
{
    DMA_Error Error_State = DMA_ENUM_NOK;
    if (settings == NULL) 
    {
        return DMA_ENUM_NULLPTR;
    }
    else
    {
        Error_State = DMA_ENUM_OK;
    }

    return Error_State;
}

DMA_Error DMA_EnableInterrupt(DMA_Settings* settings) 
{
    DMA_Error Error_State = DMA_ENUM_NOK;
    if (settings == NULL) 
    {
        return DMA_ENUM_NULLPTR;
    }
    else
    {
        Error_State = DMA_ENUM_OK;
    }

    return Error_State;
}

DMA_Error DMA_DisableInterrupt(DMA_Settings* settings) 
{
    DMA_Error Error_State = DMA_ENUM_NOK;
    if (settings == NULL) 
    {
        return DMA_ENUM_NULLPTR;
    }
    else
    {
        Error_State = DMA_ENUM_OK;
    }

    return Error_State;
}

DMA_Error DMA_SetCallback(DMA_Settings* settings, void (*callback)(void)) 
{
    DMA_Error Error_State = DMA_ENUM_NOK;
    if (settings != NULL) 
    {
        settings->callback = callback;
        Error_State = DMA_ENUM_OK;
    }

    return Error_State;
}