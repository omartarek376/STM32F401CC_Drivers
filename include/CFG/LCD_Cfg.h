#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


/* make this value = 1 if you want to operate in 4 bit mode */
#define BitMode_4       0

#include <stdio.h>

typedef enum{
	LCD_enumPORTA,
	LCD_enumPORTB,
	LCD_enumPORTC
}LCD_enumPortID_t;


typedef struct
{
	LCD_enumPortID_t PORT;
	uint8_t PIN;
}LCD_PINCfg;


typedef struct
{
	LCD_PINCfg RS;
	LCD_PINCfg RW;
	LCD_PINCfg EN;
	LCD_PINCfg D[8];
}LCD_StrCfg;


#endif /* LCD_CONFIG_H */