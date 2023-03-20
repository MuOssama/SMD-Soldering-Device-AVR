/*
 * KAYPAD.c
 *
 *  Created on: Sep 24, 2021
 *      Author: eslam gamal
 */

#include "../../uitils/std_types.h"

#include "../../MCAL/DIO/DIO.h"
#include "KAYPAD.h"

#include "avr/delay.h"

u8 key_pad_arr[4][4] = { { 1, 2, 3, 'A' }, { 4, 5, 6, 'B' }, { 7, 8, 9, 'C' }, {
		'*', 0, '#', 'D' }

};

u8 Get_key_pad_pressed() {
	while (1) {
		for (u8 i = 0; i < ROW_NO; i++) {
			DIO_SetGroupDirection(KEY_PAD_GROUP, (0b00010000) << i);
			DIO_SetGroupValue(KEY_PAD_GROUP, (~((0b00010000) << i)));
			_delay_ms(50);

			for (u8 y = 0; y < COL_NO; y++) {
				if (DIO_GetPinValue(KEY_PAD_GROUP, y) == 0)
					return key_pad_arr[i][y];
			}

		}

	}

}

