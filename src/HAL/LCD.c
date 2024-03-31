#include "MCAL/GPIO.h"
#include "CFG/LCD_Cfg.h"
#include "HAL/LCD.h"

#define LCD_NoRequest                                       0

#define LCD_Start                                           0
#define INIT_STAGE1                                         1
#define INIT_STAGE2                                         2
#define INIT_STAGE3                                         3
#define INIT_STAGE4                                         4
#define LCD_InitDone                                        5

#define LCD_WritingRequest                                  5
#define LCD_CommandRequest                                  6

#define ENABLE_ON                                           1
#define ENABLE_OFF                                          0

#if BitMode_4 == 0
    #define NUM_PINS                                        8
#else
    #define NUM_PINS                                        4
#endif

#define LCD_IDLE                                            0
#define LCD_BUSY                                            1


static uint8_t LCD_prvInitState = LCD_Start;
static uint8_t LCD_prvRequest = LCD_NoRequest;
//static uint8_t Loc_Time_ms = 0;
static uint8_t LCD_prvCommand;
static uint8_t Loc_Enable_State = ENABLE_OFF;
//static uint8_t LCD_State = LCD_IDLE;
static uint8_t * LCD_prvBuffer = NULL;
static uint8_t LCD_prvBufferLen = 0;
static uint8_t LCD_prvIndex = 0;


extern LCD_StrCfg LCD;


LCD_enuErrorStatus LCD_enuWriteCommand(uint8_t Copy_uint8_tCommand)
{
	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;

	if (LCD_prvRequest != LCD_WritingRequest)
	{
		LCD_prvRequest = LCD_CommandRequest;
		
		GPIO_SetPinValue(LCD.RS.PORT,LCD.RS.PIN,PIN_STATE_LOW);
		GPIO_SetPinValue(LCD.RW.PORT,LCD.RW.PIN,PIN_STATE_LOW);
		
		#if BitMode_4 == 0
		
		uint8_t bit;
		
		bit = (Copy_uint8_tCommand >> 7) & 0x01;
		GPIO_SetPinValue(LCD.D[7].PORT,LCD.D[7].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 6) & 0x01;
		GPIO_SetPinValue(LCD.D[6].PORT,LCD.D[6].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 5) & 0x01;
		GPIO_SetPinValue(LCD.D[5].PORT,LCD.D[5].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 4) & 0x01;
		GPIO_SetPinValue(LCD.D[4].PORT,LCD.D[4].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 3) & 0x01;
		GPIO_SetPinValue(LCD.D[3].PORT,LCD.D[3].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 2) & 0x01;
		GPIO_SetPinValue(LCD.D[2].PORT,LCD.D[2].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 1) & 0x01;
		GPIO_SetPinValue(LCD.D[1].PORT,LCD.D[1].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 0) & 0x01;
		GPIO_SetPinValue(LCD.D[0].PORT,LCD.D[0].PIN,bit);

		if (Loc_Enable_State == ENABLE_OFF)
		{
			GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_HIGH);
			Loc_Enable_State = ENABLE_ON;
		}
		else if (Loc_Enable_State == ENABLE_ON)
		{
			GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_LOW);
			Loc_Enable_State = ENABLE_OFF;
			LCD_prvRequest = LCD_NoRequest;
			if (LCD_prvInitState < LCD_InitDone)
			{
				LCD_prvInitState++;
			}
		}
		#endif
		
		#if BitMode_4 == 1
		
		uint8_t bit;
		
		bit = (Copy_uint8_tCommand >> 7) & 0x01;
		GPIO_SetPinValue(LCD.D7.PORT,LCD.D7.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 6) & 0x01;
		GPIO_SetPinValue(LCD.D6.PORT,LCD.D6.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 5) & 0x01;
		GPIO_SetPinValue(LCD.D5.PORT,LCD.D5.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 4) & 0x01;
		GPIO_SetPinValue(LCD.D4.PORT,LCD.D4.PIN,bit);
		
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_HIGH);
		_delay_ms(0.1);
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_LOW);
		_delay_ms(2);
		
		bit = (Copy_uint8_tCommand >> 3) & 0x01;
		GPIO_SetPinValue(LCD.D7.PORT,LCD.D7.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 2) & 0x01;
		GPIO_SetPinValue(LCD.D6.PORT,LCD.D6.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 1) & 0x01;
		GPIO_SetPinValue(LCD.D5.PORT,LCD.D5.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 0) & 0x01;
		GPIO_SetPinValue(LCD.D4.PORT,LCD.D4.PIN,bit);
		
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_HIGH);
		_delay_ms(0.1);
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_LOW);
		_delay_ms(2);
		
		#endif
	}
	loc_enumReturnStatus = LCD_enumOK;
	return loc_enumReturnStatus;
}

static LCD_enuErrorStatus LCD_enuWriteData(uint8_t Copy_uint8_tCommand)
{
	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
	if (LCD_prvRequest != LCD_CommandRequest)
	{
		LCD_prvRequest = LCD_WritingRequest;
		
		GPIO_SetPinValue(LCD.RS.PORT,LCD.RS.PIN,PIN_STATE_HIGH);
		GPIO_SetPinValue(LCD.RW.PORT,LCD.RW.PIN,PIN_STATE_LOW);
		
		#if BitMode_4 == 0
		
		uint8_t bit;
		
		bit = (Copy_uint8_tCommand >> 7) & 0x01;
		GPIO_SetPinValue(LCD.D[7].PORT,LCD.D[7].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 6) & 0x01;
		GPIO_SetPinValue(LCD.D[6].PORT,LCD.D[6].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 5) & 0x01;
		GPIO_SetPinValue(LCD.D[5].PORT,LCD.D[5].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 4) & 0x01;
		GPIO_SetPinValue(LCD.D[4].PORT,LCD.D[4].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 3) & 0x01;
		GPIO_SetPinValue(LCD.D[3].PORT,LCD.D[3].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 2) & 0x01;
		GPIO_SetPinValue(LCD.D[2].PORT,LCD.D[2].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 1) & 0x01;
		GPIO_SetPinValue(LCD.D[1].PORT,LCD.D[1].PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 0) & 0x01;
		GPIO_SetPinValue(LCD.D[0].PORT,LCD.D[0].PIN,bit);

		if (Loc_Enable_State == ENABLE_OFF)
		{
			GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_HIGH);
			Loc_Enable_State = ENABLE_ON;
		}
		else if (Loc_Enable_State == ENABLE_ON)
		{
			GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_LOW);
			Loc_Enable_State = ENABLE_OFF;
			LCD_prvIndex++;
			if (LCD_prvIndex == LCD_prvBufferLen)
			{
				LCD_prvRequest = LCD_NoRequest;
			}
		}
		#endif
		
		#if BitMode_4 == 1
		
		uint8_t bit;
		
		bit = (Copy_uint8_tCommand >> 7) & 0x01;
		GPIO_SetPinValue(LCD.D7.PORT,LCD.D7.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 6) & 0x01;
		GPIO_SetPinValue(LCD.D6.PORT,LCD.D6.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 5) & 0x01;
		GPIO_SetPinValue(LCD.D5.PORT,LCD.D5.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 4) & 0x01;
		GPIO_SetPinValue(LCD.D4.PORT,LCD.D4.PIN,bit);
		
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_HIGH);
		_delay_ms(0.1);
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_LOW);
		_delay_ms(2);
		
		bit = (Copy_uint8_tCommand >> 3) & 0x01;
		GPIO_SetPinValue(LCD.D7.PORT,LCD.D7.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 2) & 0x01;
		GPIO_SetPinValue(LCD.D6.PORT,LCD.D6.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 1) & 0x01;
		GPIO_SetPinValue(LCD.D5.PORT,LCD.D5.PIN,bit);
		
		bit = (Copy_uint8_tCommand >> 0) & 0x01;
		GPIO_SetPinValue(LCD.D4.PORT,LCD.D4.PIN,bit);
		
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_HIGH);
		_delay_ms(0.1);
		GPIO_SetPinValue(LCD.EN.PORT,LCD.EN.PIN,PIN_STATE_LOW);
		_delay_ms(2);
		
		#endif
	}
	loc_enumReturnStatus = LCD_enumOK;
	return loc_enumReturnStatus;
}

void LCD_init()
{
    #if BitMode_4 == 0
        int starting_bit = 0;
    #else
        int starting_bit = 4;
    #endif

    for (int i = starting_bit; i < NUM_PINS; i++)
    {
        GPIO_CONFIG_T GPIO_InitStructure = 
        {
            .Port = LCD.D[i].PORT,
            .Pin = LCD.D[i].PIN,
            .Speed = GPIO_SPEED_HIGH,
            .Mode = GPIO_MODE_OP_PP
        };
        GPIO_InitPin(&GPIO_InitStructure);
    }
    LCD_prvInitState++;

    #if BitMode_4 == 0

    switch(LCD_prvInitState)
    {
        // Function Set: 8-bit mode, 2 lines, 5x8 font
        case INIT_STAGE1:
        LCD_enuWriteCommand(0x38);
        break;

        // Display ON/OFF control: Display on, Cursor off, Blink off
        case INIT_STAGE2:
        LCD_enuWriteCommand(0x0C);
        break;

        // Clear Display
        case INIT_STAGE3:
        LCD_enuWriteCommand(LCD_CLEAR_DISPLAY);
        break;

        // Entry mode set: Increment cursor position, No display shift
        case INIT_STAGE4:
        LCD_enuWriteCommand(0x06);
        break;

        default:
        break;
    }
	#endif
}


LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(uint8_t Copy_uint8_tX, uint8_t Copy_uint8_tY)
{
	if (Copy_uint8_tX >= 0 && Copy_uint8_tX < 16 && Copy_uint8_tY >= 0 && Copy_uint8_tY < 2) 
	{
		uint8_t address = (Copy_uint8_tY == 0) ? (LCD_SET_DDRAM_ADDRESS + Copy_uint8_tX) : (0xC0 + Copy_uint8_tX);
		LCD_enuWriteCommand(address);
		return LCD_enumOK;
	} 
		else 
		{
			return LCD_enumNOK;
		}
}


LCD_enuErrorStatus LCD_enuWriteString(uint8_t* Copy_pchPattern, uint8_t Copy_uint8_tLength)
{

	LCD_enuErrorStatus loc_enumReturnStatus = LCD_enumNOK;
	if (Copy_pchPattern == NULL) 
	{
		loc_enumReturnStatus = LCD_enumInvalidConfig;
	}

	else
	{
		LCD_prvBuffer = (uint8_t *)&Copy_pchPattern;
		LCD_prvBufferLen = Copy_uint8_tLength;
		LCD_prvRequest = LCD_WritingRequest; 
		LCD_enuWriteData(LCD_prvBuffer[LCD_prvIndex]);
		loc_enumReturnStatus = LCD_enumOK;
	}

	return loc_enumReturnStatus;
}

void LCD_RunnerTask(void)
{
	if (LCD_prvInitState != LCD_InitDone)
	{
		LCD_init();
	}
	else
	{
		switch(LCD_prvRequest)
            {
            case LCD_WritingRequest:
                LCD_enuWriteData(LCD_prvBuffer[LCD_prvIndex]);
                break;

            case LCD_CommandRequest:
                LCD_enuWriteCommand(LCD_prvCommand);
                break;

            case LCD_NoRequest:
                // Do Nothing
                break;
		}
	}
}