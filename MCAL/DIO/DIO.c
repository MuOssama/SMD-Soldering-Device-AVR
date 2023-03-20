/*
 * DIO.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Lenovo
 */

#include "DIO_REG.h"
#include "../../uitils/BIT_MATH.h"
#include "DIO.h"

void DIO_SetPinDirection(u8 GropuIDcopy, u8 PinIDcopy, u8 DirId)
{
    if (DirId == INPUT)
    {
        switch (GropuIDcopy)
        {
        case GROUPA:
            CLR_BIT(DDRA_Register, PinIDcopy);
            break;
        case GROUPB:
            CLR_BIT(DDRB_Register, PinIDcopy);
            break;
        case GROUPC:
            CLR_BIT(DDRC_Register, PinIDcopy);
            break;
        case GROUPD:
            CLR_BIT(DDRD_Register, PinIDcopy);
            break;
        }
    }
    else if (DirId == OUTPUT)
    {
        switch (GropuIDcopy)
        {
        case GROUPA:
            SET_BIT(DDRA_Register, PinIDcopy);
            break;
        case GROUPB:
            SET_BIT(DDRB_Register, PinIDcopy);
            break;
        case GROUPC:
            SET_BIT(DDRC_Register, PinIDcopy);
            break;
        case GROUPD:
            SET_BIT(DDRD_Register, PinIDcopy);
            break;
        }
    }
    else
    {

    }
}

void DIO_SetPinValue(u8 GropuIDcopy, u8 PinIDcopy, u8 ValueId)
{
    if (ValueId == LOW)
    {
        switch (GropuIDcopy)
        {
        case GROUPA:
            CLR_BIT(PORTA_Register, PinIDcopy);
            break;
        case GROUPB:
            CLR_BIT(PORTB_Register, PinIDcopy);
            break;
        case GROUPC:
            CLR_BIT(PORTC_Register, PinIDcopy);
            break;
        case GROUPD:
            CLR_BIT(PORTD_Register, PinIDcopy);
            break;
        }
    }
    else if (ValueId == HIGH)
    {
        switch (GropuIDcopy)
        {
        case GROUPA:
            SET_BIT(PORTA_Register, PinIDcopy);
            break;
        case GROUPB:
            SET_BIT(PORTB_Register, PinIDcopy);
            break;
        case GROUPC:
            SET_BIT(PORTC_Register, PinIDcopy);
            break;
        case GROUPD:
            SET_BIT(PORTD_Register, PinIDcopy);
            break;
        }
    }
}

u8 DIO_GetPinValue(u8 GropuIDcopy, u8 PinIDcopy)
{
    u8 result = 0xFF;
    switch (GropuIDcopy)
    {
    case GROUPA:
        result = GET_BIT(PINA_Register, PinIDcopy);
        break;
    case GROUPB:
        result = GET_BIT(PINB_Register, PinIDcopy);
        break;
    case GROUPC:
        result = GET_BIT(PINC_Register, PinIDcopy);
        break;
    case GROUPD:
        result = GET_BIT(PIND_Register, PinIDcopy);
        break;
    }
    return result;
}

void DIO_SetGroupDirection(u8 GropuIDcopy, u8 DirID)
{
    switch (GropuIDcopy)
    {
    case GROUPA:
        DDRA_Register = DirID;
        break;
    case GROUPB:
        DDRB_Register = DirID;
        break;
    case GROUPC:
        DDRC_Register = DirID;
        break;
    case GROUPD:
        DDRD_Register = DirID;
        break;
    }
}

void DIO_SetGroupValue(u8 GropuIDcopy, u8 valueID)
{

    switch (GropuIDcopy)
    {
    case GROUPA:
        PORTA_Register = valueID;
        break;
    case GROUPB:
        PORTB_Register = valueID;
        break;
    case GROUPC:
        PORTC_Register = valueID;
        break;
    case GROUPD:
        PORTD_Register = valueID;
        break;
    }
}


void DIO_TogPin(u8 GropuIDcopy, u8 PinIDcopy) {
	switch (GropuIDcopy) {
	case GROUPA:
		PORTA_Register ^= (1 << PinIDcopy);
		break;
	case GROUPB:
		PORTB_Register ^= (1 << PinIDcopy);
		break;
	case GROUPC:
		PORTC_Register ^= (1 << PinIDcopy);
		break;
	case GROUPD:
		PORTD_Register ^= (1 << PinIDcopy);
		break;
	}
}
