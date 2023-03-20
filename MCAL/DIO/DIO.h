/*
 * DIO.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../uitils/STD_TYPES.h"


#define GROUPA 0
#define GROUPB 1
#define GROUPC 2
#define GROUPD 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

void DIO_SetPinDirection(u8 GropuIDcopy, u8 PinIDcopy, u8 DirId);
void DIO_SetPinValue(u8 GropuIDcopy, u8 PinIDcopy, u8 ValueId);
u8 DIO_GetPinValue(u8 GropuIDcopy, u8 PinIDcopy);

void DIO_SetGroupDirection(u8 GropuIDcopy , u8 DirID);
void DIO_SetGroupValue(u8 GropuIDcopy , u8 valueID);

void DIO_TogPin(u8 GropuIDcopy, u8 PinIDcopy);

#endif /* MCAL_DIO_DIO_H_ */
