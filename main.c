///***************************** islam ****************************************///
///****************************** PWM ****************************************///

#define F_CPU 8000000UL

#include <avr/io.h>
//#include <avr/interrupt.h>
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
#include "uitils/std_types.h"
//////////////////////////////////////////////////////////////
#include "MCAL/DIO/DIO.h"
/////////////////////////////////////////////////////////////
#include "HAL/LCD/LCD.h"
////////////////////////////////////////////////////////////
#include <avr/delay.h>
///////////////////////////////////////////////////////////
#include "MCAL/SPI/SPI.h"
///////////////////////////////////////////////////
#include "MCAL/ADC/ADC.h"
////////////////////////////////////////////////////////////


int main() {

	DIO_SetPinDirection(GROUPC, PIN_0, INPUT);
	DIO_SetPinValue(GROUPC, PIN_0, HIGH);
	DIO_SetPinDirection(GROUPC, PIN_1, INPUT);
	DIO_SetPinValue(GROUPC, PIN_1, HIGH);
	DIO_SetPinDirection(GROUPC, PIN_7, OUTPUT);
	DIO_SetPinDirection(GROUPA, PIN_0, INPUT);
	ADC_init();

	LCD_Vinit();
	LCD_GOTOXY(1, 4);
	LCD_Send_string("WELCOME");
	LCD_GOTOXY(2, 1);
	LCD_Send_string("PROJECT SENSOR ");
	_delay_ms(2000);

	while (1) {

		LCD_WORK( );


	}
}

