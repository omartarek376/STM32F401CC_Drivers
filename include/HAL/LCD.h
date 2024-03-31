#ifndef LCD_H_
#define LCD_H_

#include <stdio.h>


#define LCD_CLEAR_DISPLAY       0x01
#define LCD_RETURN_HOME         0x02
#define LCD_ENTRY_MODE_SET      0x04
#define LCD_DISPLAY_CONTROL     0x08
#define LCD_CURSOR_SHIFT        0x10
#define LCD_FUNCTION_SET        0x20
#define LCD_SET_CGRAM_ADDRESS   0x40
#define LCD_SET_DDRAM_ADDRESS   0x80


typedef enum
{
	LCD_enumNOK,
	LCD_enumInvalidConfig,
	LCD_enumOK
}LCD_enuErrorStatus;
	


/**
 *@brief  : Function to initialize the LCD.
 *@param  : Nothing
 *@return : Error State                                                                     
 */
void LCD_init();
/**
 *@brief  : Function to give command for the LCD to get executed.
 *@param  : LCD_CLEAR_DISPLAY, LCD_RETURN_HOME, LCD_ENTRY_MODE_SET, LCD_DISPLAY_CONTROL, LCD_CURSOR_SHIFT, LCD_FUNCTION_SET, LCD_SET_CGRAM_ADDRESS, LCD_SET_DDRAM_ADDRESS.
 *@return : Error State                                                                     
 */
LCD_enuErrorStatus LCD_enuWriteCommand(uint8_t Copy_uint8_tCommand);
/**
 *@brief  : Function change where the next character will be printed at.
 *@param  : position on the LCD in terms of X & Y.
 *@return : Error State                                                                     
 */
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(uint8_t Copy_uint8_tX, uint8_t Copy_uint8_tY);
/**
 *@brief  : Function to display an entire string on the LCD.
 *@param  : String to be printed and the length of said string (excluding the null pointer).
 *@return : Error State                                                                     
 */
LCD_enuErrorStatus LCD_enuWriteString(uint8_t* Copy_pchPattern, uint8_t Copy_uint8_tLength);

#endif /* LCD_H_ */