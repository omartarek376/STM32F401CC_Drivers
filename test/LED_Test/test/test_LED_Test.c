#ifdef TEST

#include "unity.h"
#include "mock_GPIO.h"
#include "LED_Cfg.h"
#include "LED.h"

extern const ledcfg_t leds[_led_num];

void setUp(void)
{
    
}

void tearDown(void)
{
}



void test_LED_Init_ValidParameters(void)
{
    GPIO_InitPin_IgnoreAndReturn(GPIO_ENUM_OK);
    TEST_ASSERT_EQUAL(LED_ENUM_OK, led_init());
}


void test_LED_setState_ValidParameters(void)
{
    GPIO_SetPinValue_IgnoreAndReturn(GPIO_ENUM_OK);
    TEST_ASSERT_EQUAL(LED_ENUM_OK, led_setstatus(led_builtin, led_state_on));
}

void test_LED_setState_InvalidLedName(void)
{
    // Call LED_setState with an invalid LED name
    TEST_ASSERT_EQUAL(LED_ENUM_INVALIDCONFIG, led_setstatus(_led_num + 1, led_state_on));
}

void test_LED_setState_InvalidState(void)
{
    // Call LED_setState with an invalid LED state
    TEST_ASSERT_EQUAL(LED_ENUM_INVALIDCONFIG, led_setstatus(led_builtin, 0xff));
}

#endif // TEST
