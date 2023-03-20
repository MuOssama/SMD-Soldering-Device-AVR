/*
 * BIT_MATH.h
 *
 *  Created on: Sep 17, 2021
 *      Author: eslam gamal
 */

#ifndef UITILS_BIT_MATH_H_
#define UITILS_BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) |= (1<<(BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1<<(BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^= (1<<(BITNO))
#define GET_BIT(VAR,BITNO)  (((VAR) >> (BITNO)) & 0x01)

#endif /* UITILS_BIT_MATH_H_ */
