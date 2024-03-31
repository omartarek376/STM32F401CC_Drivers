#include "CFG/LCD_Cfg.h"

LCD_StrCfg LCD =
{
	.RS.PIN = 13,	.RS.PORT = LCD_enumPORTB,
	.RW.PIN = 14,	.RW.PORT = LCD_enumPORTB,
	.EN.PIN = 15,	.EN.PORT = LCD_enumPORTB,
	
	.D[0].PIN = 4,	.D[0].PORT = LCD_enumPORTB,
	.D[1].PIN = 5,	.D[1].PORT = LCD_enumPORTB,
    .D[2].PIN = 6,	.D[2].PORT = LCD_enumPORTB,
    .D[3].PIN = 7,	.D[3].PORT = LCD_enumPORTB,
    .D[4].PIN = 8,	.D[4].PORT = LCD_enumPORTB,
    .D[5].PIN = 9,	.D[5].PORT = LCD_enumPORTB,
    .D[6].PIN = 10,	.D[6].PORT = LCD_enumPORTB,
    .D[7].PIN = 12,	.D[7].PORT = LCD_enumPORTB,
};