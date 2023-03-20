/*
 * ADC.c
 *
 *  Created on: Oct 9, 2021
 *      Author: 20101
 */
#include<avr/io.h>
#include "../../UITILS/BIT_MATH.h"
#include"../DIO/DIO.h"
#include"../../UITILS/STD_TYPES.h"
#include "ADC.h"

#define ADCD *((volatile u16*)(0x24))

void ADC_init( )
{
	ADMUX |= (1 << 6);
	ADMUX &= ~(1 << 7);
	ADMUX &= ~(1 << 5);
	ADCSRA &= ~(1 << 0);
	ADCSRA |= (1 << 1);
	ADCSRA |= (1 << 2);
	ADCSRA |= (1 << 7);
}

u16 ADC_read(u8 channel)
{
	if (channel <= 7) {
		ADMUX &= 0XE0;
		ADMUX |= channel;
		ADCSRA |= (1 << 6);
		while (GET_BIT(ADCSRA,4) != 1) {

		}
		ADCSRA |= (1 << 4);
	}
	return ADCD;
}
