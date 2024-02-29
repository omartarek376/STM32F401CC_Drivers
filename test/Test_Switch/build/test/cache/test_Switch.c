#include "src/Switch.h"
#include "build/test/mocks/mock_GPIO.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






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

    GPIO_InitPin_CMockIgnoreAndReturn(20, GPIO_ENUM_OK);

    UnityAssertEqualNumber((UNITY_INT)((SWITCH_ENUM_OK)), (UNITY_INT)((Switch_init())), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}



void test_Switch_Init_invalidParameters(void)

{

    Switches[Led_Switch].connection = 3;

    GPIO_InitPin_CMockIgnoreAndReturn(27, GPIO_ENUM_OK);

    UnityAssertEqualNumber((UNITY_INT)((SWITCH_ENUM_INVALIDCONFIG)), (UNITY_INT)((Switch_init())), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_Switch_NULL(void)

{

    uint8_t * switch_state = 

                            ((void *)0)

                                ;

    UnityAssertEqualNumber((UNITY_INT)((SWITCH_ENUM_NULLPTR)), (UNITY_INT)((Switch_getstatus(Led_Switch,switch_state))), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

}



void test_invalid_switch(void)

{

    UnityAssertEqualNumber((UNITY_INT)((SWITCH_ENUM_INVALIDCONFIG)), (UNITY_INT)((Switch_getstatus(_Switch_num + 1,switch_status_getter))), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}



void test_switch_getstatus_valid(void)

{

    GPIO_GetPinValue_CMockIgnoreAndReturn(44, GPIO_ENUM_OK);

    UnityAssertEqualNumber((UNITY_INT)((SWITCH_ENUM_OK)), (UNITY_INT)((Switch_getstatus(Led_Switch,switch_status_getter))), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}
