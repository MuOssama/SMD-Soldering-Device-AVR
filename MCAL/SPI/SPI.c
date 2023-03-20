#include "SPI.h"
/****************************
 function return type : void
 init the master --> SPCR
 *****************************/
void init_master(void)
{
	/*
	 setting the output of SPI pins
	 */
	SPI_DDR |= ((1 << SPI_SS) | (1 << SPI_SCK) | (1 << SPI_MOSI));
	/*
	 SET BIT 4 TO BECOME A MSTER (MSTR)
	 SET BIT 2 TO ENABLE THE SPI (SPE)
	 frequancy 125k
	 */
	SPCR |= ((1 << 6) | (1 << 4) | (1 << 1));
}

u8 transfer_BLOCK(u8 data)
{
	SPDR = data;
	while (!(SPSR & (1 << 7))); // waiting 8 clocks
	return SPDR;
}

void init_slave(void)
{
	SPI_DDR = (1 << SPI_MISO);
	SPCR = (1 << SPE);
}
/*
 return data register of spi
 */

