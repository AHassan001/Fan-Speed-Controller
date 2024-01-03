/*
 * Mini_Project3.c
 *
 *  Created on: Oct 6, 2022
 *      Author: amahe
 */
#include "adc.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "lcd.h"
#include "avr/io.h" /* To use the SREG Register */


int main(void)
{
	uint8 temp =0;

	SREG  |= (1<<7);
	ADC_ConfigType Adc_Config = {INTERNAL_VREF,D_FACTOR_8};

	ADC_init( &Adc_Config);
	LCD_init();
	DcMotor_init();


	LCD_displayStringRowColumn(0, 2, "FAN is ");
	LCD_displayStringRowColumn(1, 2, "Temp =    C ");

	while(1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(1,9);

		if (temp>=100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}


		 if (temp < 30)
		 {
			DcMotor_Rotate(stop, 0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
		 }
		 else if (temp >= 30 && temp < 60)
		 {
			DcMotor_Rotate(clockwise, 25);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		 }
		 else if (temp >= 60 && temp < 90)
		 {
			DcMotor_Rotate(clockwise, 50);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		 }
		 else if (temp >= 90 && temp < 120)
		 {
			DcMotor_Rotate(clockwise, 75);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		 }
		 else if(temp >= 120)
		 {
			DcMotor_Rotate(clockwise, 100);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		 }

	}
}
