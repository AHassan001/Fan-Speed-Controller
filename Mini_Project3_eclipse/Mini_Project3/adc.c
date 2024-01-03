/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* reference voltage configuration */
	switch (Config_Ptr ->ref_volt){
	case 0:
		ADMUX &= ~(1<<REFS1);
		ADMUX &= ~(1<<REFS0);
		break;
	case 1:
		ADMUX |= (1<<REFS1);
		ADMUX &= ~(1<<REFS0);
		break;
	case 3:
		ADMUX |= (1<<REFS1) | (1<<REFS0);
		break;
	}


	/* prescaler configuration */
	switch (Config_Ptr -> prescaler){
	case 1:
		ADCSRA |= (1<<ADPS0);
		ADCSRA &= ~(1<<ADPS1);
		ADCSRA &= ~(1<<ADPS2);

		break;
	case 2:
		ADCSRA |= (1<<ADPS1);
		ADCSRA &= ~(1<<ADPS0);
		ADCSRA &= ~(1<<ADPS2);

		break;
	case 3:
		ADCSRA |= (1<<ADPS0);
		ADCSRA |= (1<<ADPS1);
		ADCSRA &= ~(1<<ADPS2);

		break;
	case 4:
		ADCSRA |= (1<<ADPS2);
		ADCSRA &= ~(1<<ADPS1);
		ADCSRA &= ~(1<<ADPS0);

		break;
	case 5:
		ADCSRA |= (1<<ADPS0);
		ADCSRA |= (1<<ADPS2);
		ADCSRA &= ~(1<<ADPS1);

		break;
	case 6:
		ADCSRA |= (1<<ADPS1);
		ADCSRA |= (1<<ADPS2);
		ADCSRA &= ~(1<<ADPS0);

		break;
	case 7:
		ADCSRA |= (1<<ADPS0);
		ADCSRA |= (1<<ADPS1);
		ADCSRA |= (1<<ADPS2);
		break;
	}

}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
