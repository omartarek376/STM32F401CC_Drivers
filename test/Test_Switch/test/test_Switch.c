#ifdef TEST

#include "unity.h"
#include "mock_GPIO.h"
#include "Switch.h"

uint8_t * switch_status_getter = 1;
Switchcfg_t Switches[_Switch_num];

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Switch_Init_ValidParameters(void)
{
    GPIO_InitPin_IgnoreAndReturn(GPIO_ENUM_OK);
    TEST_ASSERT_EQUAL(SWITCH_ENUM_OK, Switch_init());
}

void test_Switch_Init_invalidParameters(void)
{
    Switches[Led_Switch].connection = 3;
    GPIO_InitPin_IgnoreAndReturn(GPIO_ENUM_OK);
    TEST_ASSERT_EQUAL(SWITCH_ENUM_INVALIDCONFIG, Switch_init());
}

void test_Switch_NULL(void)
{
    uint8_t * switch_state = NULL;
    TEST_ASSERT_EQUAL(SWITCH_ENUM_NULLPTR, Switch_getstatus(Led_Switch,switch_state));
}

void test_invalid_switch(void)
{
    TEST_ASSERT_EQUAL(SWITCH_ENUM_INVALIDCONFIG, Switch_getstatus(_Switch_num + 1,switch_status_getter));
}

void test_switch_getstatus_valid(void)
{
    GPIO_GetPinValue_IgnoreAndReturn(GPIO_ENUM_OK);
    TEST_ASSERT_EQUAL(SWITCH_ENUM_OK, Switch_getstatus(Led_Switch,switch_status_getter));
}

#endif // TEST
