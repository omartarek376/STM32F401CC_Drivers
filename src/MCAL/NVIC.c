#include "MCAL/NVIC.h"

#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct
{
    volatile uint32_t NVIC_ISER0; // Interrupt Set Enable Register 0
    volatile uint32_t NVIC_ISER1; // Interrupt Set Enable Register 1
    volatile uint32_t NVIC_ISER2; // Interrupt Set Enable Register 2
    volatile uint32_t NVIC_ISER3; // Interrupt Set Enable Register 3
    volatile uint32_t NVIC_ISER4; // Interrupt Set Enable Register 4
    volatile uint32_t NVIC_ISER5; // Interrupt Set Enable Register 5
    volatile uint32_t NVIC_ISER6; // Interrupt Set Enable Register 6
    volatile uint32_t NVIC_ISER7; // Interrupt Set Enable Register 7
    volatile uint32_t NVIC_ICER0; // Interrupt Clear Enable Register 0
    volatile uint32_t NVIC_ICER1; // Interrupt Clear Enable Register 1
    volatile uint32_t NVIC_ICER2; // Interrupt Clear Enable Register 2
    volatile uint32_t NVIC_ICER3; // Interrupt Clear Enable Register 3
    volatile uint32_t NVIC_ICER4; // Interrupt Clear Enable Register 4
    volatile uint32_t NVIC_ICER5; // Interrupt Clear Enable Register 5
    volatile uint32_t NVIC_ICER6; // Interrupt Clear Enable Register 6
    volatile uint32_t NVIC_ICER7; // Interrupt Clear Enable Register 7
    volatile uint32_t NVIC_ISPR0; // Interrupt Set Pending Register 0
    volatile uint32_t NVIC_ISPR1; // Interrupt Set Pending Register 1
    volatile uint32_t NVIC_ISPR2; // Interrupt Set Pending Register 2
    volatile uint32_t NVIC_ISPR3; // Interrupt Set Pending Register 3
    volatile uint32_t NVIC_ISPR4; // Interrupt Set Pending Register 4
    volatile uint32_t NVIC_ISPR5; // Interrupt Set Pending Register 5
    volatile uint32_t NVIC_ISPR6; // Interrupt Set Pending Register 6
    volatile uint32_t NVIC_ISPR7; // Interrupt Set Pending Register 7
    volatile uint32_t NVIC_ICPR0; // Interrupt Clear Pending Register 0
    volatile uint32_t NVIC_ICPR1; // Interrupt Clear Pending Register 1
    volatile uint32_t NVIC_ICPR2; // Interrupt Clear Pending Register 2
    volatile uint32_t NVIC_ICPR3; // Interrupt Clear Pending Register 3
    volatile uint32_t NVIC_ICPR4; // Interrupt Clear Pending Register 4
    volatile uint32_t NVIC_ICPR5; // Interrupt Clear Pending Register 5
    volatile uint32_t NVIC_ICPR6; // Interrupt Clear Pending Register 6
    volatile uint32_t NVIC_ICPR7; // Interrupt Clear Pending Register 7
    volatile uint32_t NVIC_IABR0; // Interrupt Active Bit Register 0
    volatile uint32_t NVIC_IABR1; // Interrupt Active Bit Register 1
    volatile uint32_t NVIC_IABR2; // Interrupt Active Bit Register 2
    volatile uint32_t NVIC_IABR3; // Interrupt Active Bit Register 3
    volatile uint32_t NVIC_IABR4; // Interrupt Active Bit Register 4
    volatile uint32_t NVIC_IABR5; // Interrupt Active Bit Register 5
    volatile uint32_t NVIC_IABR6; // Interrupt Active Bit Register 6
    volatile uint32_t NVIC_IABR7; // Interrupt Active Bit Register 7
    volatile uint32_t NVIC_IPR0;  // Interrupt Priority Register 0
    volatile uint32_t NVIC_IPR1;  // Interrupt Priority Register 1
    volatile uint32_t NVIC_IPR2;  // Interrupt Priority Register 2
    volatile uint32_t NVIC_IPR3;  // Interrupt Priority Register 3
    volatile uint32_t NVIC_IPR4;  // Interrupt Priority Register 4
    volatile uint32_t NVIC_IPR5;  // Interrupt Priority Register 5
    volatile uint32_t NVIC_IPR6;  // Interrupt Priority Register 6
    volatile uint32_t NVIC_IPR7;  // Interrupt Priority Register 7
    volatile uint32_t NVIC_IPR8;  // Interrupt Priority Register 8
    volatile uint32_t NVIC_IPR9;  // Interrupt Priority Register 9
    volatile uint32_t NVIC_IPR10; // Interrupt Priority Register 10
    volatile uint32_t NVIC_IPR11; // Interrupt Priority Register 11
    volatile uint32_t NVIC_IPR12; // Interrupt Priority Register 12
    volatile uint32_t NVIC_IPR13; // Interrupt Priority Register 13
    volatile uint32_t NVIC_IPR14; // Interrupt Priority Register 14
    volatile uint32_t NVIC_IPR15; // Interrupt Priority Register 15
    volatile uint32_t NVIC_IPR16; // Interrupt Priority Register 16
    volatile uint32_t NVIC_IPR17; // Interrupt Priority Register 17
    volatile uint32_t NVIC_IPR18; // Interrupt Priority Register 18
    volatile uint32_t NVIC_IPR19; // Interrupt Priority Register 19
    volatile uint32_t NVIC_IPR20; // Interrupt Priority Register 20
    volatile uint32_t NVIC_IPR21; // Interrupt Priority Register 21
    volatile uint32_t NVIC_IPR22; // Interrupt Priority Register 22
    volatile uint32_t NVIC_IPR23; // Interrupt Priority Register 23
    volatile uint32_t NVIC_IPR24; // Interrupt Priority Register 24
    volatile uint32_t NVIC_IPR25; // Interrupt Priority Register 25
    volatile uint32_t NVIC_IPR26; // Interrupt Priority Register 26
    volatile uint32_t NVIC_IPR27; // Interrupt Priority Register 27
    volatile uint32_t NVIC_IPR28; // Interrupt Priority Register 28
    volatile uint32_t NVIC_IPR29; // Interrupt Priority Register 29
    volatile uint32_t NVIC_IPR30; // Interrupt Priority Register 30
    volatile uint32_t NVIC_IPR31; // Interrupt Priority Register 31
    volatile uint32_t NVIC_IPR32; // Interrupt Priority Register 32
    volatile uint32_t NVIC_IPR33; // Interrupt Priority Register 33
    volatile uint32_t NVIC_IPR34; // Interrupt Priority Register 34
    volatile uint32_t NVIC_IPR35; // Interrupt Priority Register 35
    volatile uint32_t NVIC_IPR36; // Interrupt Priority Register 36
    volatile uint32_t NVIC_IPR37; // Interrupt Priority Register 37
    volatile uint32_t NVIC_IPR38; // Interrupt Priority Register 38
    volatile uint32_t NVIC_IPR39; // Interrupt Priority Register 39
    volatile uint32_t NVIC_IPR40; // Interrupt Priority Register 40
    volatile uint32_t NVIC_IPR41; // Interrupt Priority Register 41
    volatile uint32_t NVIC_IPR42; // Interrupt Priority Register 42
    volatile uint32_t NVIC_IPR43; // Interrupt Priority Register 43
    volatile uint32_t NVIC_IPR44; // Interrupt Priority Register 44
    volatile uint32_t NVIC_IPR45; // Interrupt Priority Register 45
    volatile uint32_t NVIC_IPR46; // Interrupt Priority Register 46
    volatile uint32_t NVIC_IPR47; // Interrupt Priority Register 47
    volatile uint32_t NVIC_IPR48; // Interrupt Priority Register 48
    volatile uint32_t NVIC_IPR49; // Interrupt Priority Register 49
    volatile uint32_t NVIC_IPR50; // Interrupt Priority Register 50
    volatile uint32_t NVIC_IPR51; // Interrupt Priority Register 51
    volatile uint32_t NVIC_IPR52; // Interrupt Priority Register 52
    volatile uint32_t NVIC_IPR53; // Interrupt Priority Register 53
    volatile uint32_t NVIC_IPR54; // Interrupt Priority Register 54
    volatile uint32_t NVIC_IPR55; // Interrupt Priority Register 55
    volatile uint32_t NVIC_IPR56; // Interrupt Priority Register 56
    volatile uint32_t NVIC_IPR57; // Interrupt Priority Register 57
    volatile uint32_t NVIC_IPR58; // Interrupt Priority Register 58
    volatile uint32_t NVIC_IPR59; // Interrupt Priority Register 59
    volatile uint32_t NVIC_STIR;  // Software Triggered Interrupt Register
} NVIC_T;

static NVIC_T *const NVIC = (NVIC_T *)NVIC_BASE_ADDRESS;