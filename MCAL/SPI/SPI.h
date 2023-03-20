
#ifndef SPI_H_
#define SPI_H_

#define F_CPU 8000000UL
#include "avr\io.h"
#include "avr\delay.h"
#include "../../uitils/std_types.h"

#define SPI_DDR    DDRB
#define SPI_SS		4
#define SPI_MOSI	5
#define SPI_MISO	6
#define SPI_SCK		7

/****************************
 function return type : void
 init the master --> SPCR
 *****************************/
void init_master  (void);
u8 transfer_BLOCK (u8 data);
void init_slave   (void);
/*
 return data register of spi
 */

#endif /* SPI_H_ */
