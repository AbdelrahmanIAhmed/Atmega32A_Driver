/*
 * SPI_Functions.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "std_type.h"
#include "DIO_utilites.h"
#include "DIO_reg.h"
#include "DIO_Functions.h"
#include "SPI_private.h"

void SPI_vidInit(u8 u8Mode)
{
 if(u8Mode == MASTER)
 {

	set_bit(DDRB,4);
	set_bit(DDRB,5);
	set_bit(DDRB,7);
	clr_bit(DDRB,6);

	set_bit(SPCR,2);
	set_bit(SPCR,6);
	set_bit(SPCR,4);
	set_bit(SPCR,0);
 }
 else if (u8Mode == SLAVE)
 {
	clr_bit(DDRB,4);
	clr_bit(DDRB,5);
	clr_bit(DDRB,7);
	set_bit(DDRB,6);

	set_bit(SPCR,2);
	set_bit(SPCR,6);
	clr_bit(SPCR,4);
	set_bit(SPCR,0);
 }
 return;
}


u8 SPI_u8Tranceiver(u8 u8Data)
{
	SPDR = u8Data;
	while (get_bit(SPSR,7)==0); // check status flag
	return SPDR;
}
