/*
 * KAYPAD.h
 *
 *  Created on: Sep 24, 2021
 *      Author: eslam gamal
 */

#ifndef HAL_KAYPAD_KAYPAD_H_
#define HAL_KAYPAD_KAYPAD_H_



#include "../../MCAL/DIO/DIO.h"


#define KEY_PAD_GROUP     GROUPD
#define ROW_NO            4
#define COL_NO            4

u8 Get_key_pad_pressed( );

#endif /* HAL_KAYPAD_KAYPAD_H_ */
