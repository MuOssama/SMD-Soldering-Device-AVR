/*
 * LCD.c

 *
 *  Created on: Aug 24, 2019
 *      Author: Lenovo
 */

#include <avr/delay.h>
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"
/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/
#define LCD_GROUP_DATA GROUPD
#define LCD_GROUP_CONTROL GROUPB
#define LCD_RS_PIN PIN_0
#define LCD_E_PIN PIN_1

#define LCD_HOME 0x02
#define LCD_SET_8FUNCTION 0x38
#define LCD_CLEAR 0x01
#define LCD_DATA_ENTERY 0x06
#define LCD_DISPLAY_ON 0x0C

void LCD_Vinit(void)
{
    /* set DDRA as OUTPUTs pins */
DIO_SetGroupDirection(LCD_GROUP_DATA,0xFF);
/* confguire RS & E as output */
DIO_SetPinDirection(LCD_GROUP_CONTROL , LCD_RS_PIN , OUTPUT);
DIO_SetPinDirection(LCD_GROUP_CONTROL , LCD_E_PIN , OUTPUT);

_delay_ms(30);
LCD_Send_Command(LCD_HOME);
_delay_ms(15);

LCD_Send_Command(LCD_SET_8FUNCTION);
_delay_ms(1);

LCD_Send_Command(LCD_DISPLAY_ON);
_delay_ms(1);

LCD_Send_Command(LCD_CLEAR);
_delay_ms(2);

LCD_Send_Command(LCD_DATA_ENTERY);
_delay_ms(15);

}

void LCD_Send_Command(u8 command)
{
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_RS_PIN , LOW);
    _delay_us(1);
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_E_PIN, HIGH);
    _delay_us(1);
    DIO_SetGroupValue(LCD_GROUP_DATA , command);
    _delay_us(1);
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_E_PIN, LOW);
    _delay_us(5);
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_E_PIN, HIGH);
    _delay_ms(10);
}


void LCD_Send_Data (u8 data)
{
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_RS_PIN , HIGH);
    _delay_us(1);
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_E_PIN, HIGH);
    _delay_us(1);
    DIO_SetGroupValue(LCD_GROUP_DATA , data);
    _delay_us(1);
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_E_PIN, LOW);
    _delay_us(5);
    DIO_SetPinValue(LCD_GROUP_CONTROL , LCD_E_PIN, HIGH);
    _delay_ms(10);
}




void LCD_Send_string(u8 *ptr)
{
    u8 index = 0;
    while(ptr[index]  != '\0')
    {
        LCD_Send_Data(ptr[index]);
        index++;
    }

}

void LCD_Clear(void)
{
    LCD_Send_Command(LCD_CLEAR);
}



void LCD_GOTOXY(u8 raw,u8 col)
{

	switch(raw)
	{
	case 1:      LCD_Send_Command((0x00+col)|(0x80));        break;
	case 2:      LCD_Send_Command((0x40+col)|(0x80));        break;
	default : break;
	}


}


void LCD_WORK (void ){


	u8 arr[16];
	u16 x = ADC_read(0);
	u16 temp = x / 2;


	itoa(temp, arr, 10);


	if (DIO_GetPinValue(GROUPC, PIN_0) == 0
			&& DIO_GetPinValue(GROUPC, PIN_1) == 0) {


	LCD_Clear();
	LCD_GOTOXY(1, 0);
	LCD_Send_string("TEMP= ");
	LCD_GOTOXY(2, 0);
	LCD_Send_string("STATE :");


		LCD_GOTOXY(1, 7);
		LCD_Send_string(arr);
		LCD_GOTOXY(2, 7);
		LCD_Send_string(" WORKING");
		if (temp > 300) {
			DIO_SetPinValue(GROUPC, PIN_7, HIGH);

		} else {
			DIO_SetPinValue(GROUPC, PIN_7, LOW);
		}

	} else {
		LCD_Clear();

		LCD_GOTOXY(1,2);
		LCD_Send_string("SYSTEM  NOT ");
		LCD_GOTOXY(2, 3);
				LCD_Send_string("CONNECTED");

	}

	_delay_ms(1000);

}









