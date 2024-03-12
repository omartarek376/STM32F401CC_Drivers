/*
 * TrafficLight.c
 *
 *  Created on: 12 Mar 2024
 *      Author: Momen El Sayed
 */
#include "HAL/LED.h"

#define PERIODICITY_SEC		1
uint8_t prev;
void greenOn (void)
{
	led_setstatus(LED_GREEN, led_state_on);
	led_setstatus(LED_YELLOW, led_state_off);
	led_setstatus(LED_RED, led_state_off);
}

void yellowOn (void)
{
	led_setstatus(LED_GREEN, led_state_off);
	led_setstatus(LED_YELLOW, led_state_on);
	led_setstatus(LED_RED, led_state_off);
}

void redOn (void)
{
	led_setstatus(LED_GREEN, led_state_off);
	led_setstatus(LED_YELLOW, led_state_off);
	led_setstatus(LED_RED, led_state_on);
}

enum{
	red,
	yellow,
	green
}light;


void TrafficLights_Runnable (void)
{
	static uint32_t seconds = 0;
	seconds += PERIODICITY_SEC;
	switch(light)
	{
	case green:
		greenOn();
		if(seconds == 5)
		{
			seconds = 0;
			light = yellow;
			prev = green;
		}
		break;
	case yellow:
		yellowOn();
		if((seconds == 2) && (prev == green))
		{
			seconds = 0;
			light = red;
			prev = yellow;
		}
		else if((seconds == 2) && (prev == red))
		{
			seconds = 0;
			light = green;
			prev = yellow;
		}
		break;
	case red:
		redOn();
		if(seconds == 5)
		{
			seconds = 0;
			light = yellow;
			prev = red;
		}
		break;
	}

}