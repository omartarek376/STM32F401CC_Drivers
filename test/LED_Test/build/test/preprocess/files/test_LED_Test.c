#include "src/LED.h"
#include "src/LED_Cfg.h"
#include "build/test/mocks/mock_GPIO.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






extern const ledcfg_t leds[_led_num];



void setUp(void)

{



}



void tearDown(void)

{

}







void test_LED_Init_ValidParameters(void)

{

    GPIO_InitPin_CMockIgnoreAndReturn(23, GPIO_ENUM_OK);

    UnityAssertEqualNumber((UNITY_INT)((LED_ENUM_OK)), (UNITY_INT)((led_init())), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}





void test_LED_setState_ValidParameters(void)

{

    GPIO_SetPinValue_CMockIgnoreAndReturn(30, GPIO_ENUM_OK);

    UnityAssertEqualNumber((UNITY_INT)((LED_ENUM_OK)), (UNITY_INT)((led_setstatus(led_builtin, 1))), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_LED_setState_InvalidLedName(void)

{



    UnityAssertEqualNumber((UNITY_INT)((LED_ENUM_INVALIDCONFIG)), (UNITY_INT)((led_setstatus(_led_num + 1, 1))), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

}



void test_LED_setState_InvalidState(void)

{



    UnityAssertEqualNumber((UNITY_INT)((LED_ENUM_INVALIDCONFIG)), (UNITY_INT)((led_setstatus(led_builtin, 0xff))), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

}
