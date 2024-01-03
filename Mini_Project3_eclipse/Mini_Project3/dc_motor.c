 /******************************************************************************
 *
 * Module: DC-Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the Dc Motor driver
 *
 * Author: Abdelrahman Maher
 *
 *******************************************************************************/


#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>
#include "pwm_driver.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

uint8 g_speed;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description : Function to initialize the Dc Motor driver
 *
 */
void DcMotor_init(void)
{
	GPIO_setupPinDirection(PORTB_ID , PIN0_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID , PIN1_ID , PIN_OUTPUT);
	CLEAR_BIT(PORTB,PIN0_ID);
	CLEAR_BIT(PORTB,PIN1_ID);
}

void DcMotor_Rotate (DcMotor_state state , uint8 g_speed)
{
	if(g_speed == 0 || state == stop )
	{
		CLEAR_BIT(PORTB,PIN0_ID);
		CLEAR_BIT(PORTB,PIN1_ID);
	}
	else if (state == clockwise)
	{
		SET_BIT(PORTB,PIN0_ID);
		CLEAR_BIT(PORTB,PIN1_ID);
		PWM_Timer0_Start(g_speed);
	}
	else if (state == anticlockwise)
	{
		CLEAR_BIT(PORTB,PIN0_ID);
		SET_BIT(PORTB,PIN1_ID);
		PWM_Timer0_Start(g_speed);
	}


}



