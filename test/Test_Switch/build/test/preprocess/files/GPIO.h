       



typedef struct

{

    uint32_t Port;

    uint32_t Pin;

    uint32_t Speed;

    uint32_t Mode;

}GPIO_CONFIG_T;



typedef enum

{

    GPIO_ENUM_OK,

    GPIO_ENUM_NOK,

    GPIO_ENUM_INVALID_CONFIG

}GPIO_ERROR_STATE;



GPIO_ERROR_STATE GPIO_InitPin(GPIO_CONFIG_T * Config);

GPIO_ERROR_STATE GPIO_SetPinValue(uint32_t GPIO_PORT, uint32_t GPIO_PIN, uint32_t PIN_STATE);

GPIO_ERROR_STATE GPIO_GetPinValue(uint32_t GPIO_PORT, uint32_t GPIO_PIN, uint8_t * PinValue);
