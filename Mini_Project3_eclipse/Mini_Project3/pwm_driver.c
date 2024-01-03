/*
 * pwm_driver.c
 *
 *  Created on: Oct 7, 2022
 *      Author: amahe
 */
#include "pwm_driver.h"
#include <avr/io.h>

void PWM_Timer0_Start (uint8 duty_cycle)
{

	TCNT0 = 0;

	if (duty_cycle == 25)
	{
		OCR0 = 63;
	}
	else if (duty_cycle == 50)
	{
		OCR0 = 127 ;
	}
	else if (duty_cycle == 75)
	{
		OCR0 = 191;
	}
	else if (duty_cycle == 100)
	{
		OCR0  = 255;
	}
	DDRB  |= (1<<PB3);

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
