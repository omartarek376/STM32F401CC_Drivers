#ifndef DMA_H
#define DMA_H

#include <stdint.h>

// DMA controller numbers
typedef enum {
    DMA_CONTROLLER_1,
    DMA_CONTROLLER_2
} DMA_Controller;

// DMA channel numbers
typedef enum {
    DMA_CHANNEL_0,
    DMA_CHANNEL_1,
    DMA_CHANNEL_2,
    DMA_CHANNEL_3,
    DMA_CHANNEL_4,
    DMA_CHANNEL_5,
    DMA_CHANNEL_6,
    DMA_CHANNEL_7
} DMA_Channel;

// DMA transfer direction
typedef enum {
    DMA_DIR_PERIPHERAL_TO_MEMORY,
    DMA_DIR_MEMORY_TO_PERIPHERAL,
    DMA_DIR_MEMORY_TO_MEMORY
} DMA_Direction;

// DMA transfer size
typedef enum {
    DMA_SIZE_8BITS,
    DMA_SIZE_16BITS,
    DMA_SIZE_32BITS
} DMA_Size;

// DMA interrupt enable/disable
typedef enum {
    DMA_INTERRUPT_DISABLE,
    DMA_INTERRUPT_ENABLE
} DMA_Interrupt;

// DMA priority levels
typedef enum {
    DMA_PRIORITY_LOW,
    DMA_PRIORITY_MEDIUM,
    DMA_PRIORITY_HIGH,
    DMA_PRIORITY_VERY_HIGH
} DMA_Priority;

// DMA error states
typedef enum {
    DMA_ENUM_OK,
    DMA_ENUM_NOK,
    DMA_ENUM_NULLPTR,
    DMA_ENUM_INVALID_CONFIG,
} DMA_Error;

// DMA settings struct
typedef struct {
    DMA_Controller controller;
    DMA_Channel channel;
    DMA_Direction direction;
    DMA_Size size;
    DMA_Interrupt interrupt;
    DMA_Priority priority;
    void (*callback)(void); 
} DMA_Settings;

// DMA initialization function
DMA_Error DMA_Init(DMA_Settings* settings);

// DMA start transfer function
DMA_Error DMA_StartTransfer(DMA_Settings* settings, uint32_t srcAddress, uint32_t destAddress, uint32_t dataSize);

// DMA interrupt enable/disable function
DMA_Error DMA_EnableInterrupt(DMA_Settings* settings);

DMA_Error DMA_DisableInterrupt(DMA_Settings* settings);

// DMA callback setting function
DMA_Error DMA_SetCallback(DMA_Settings* settings, void (*callback)(void));

#endif // DMA_H