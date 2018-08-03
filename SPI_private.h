/*
 * SPI_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define	SPCR	*((u8 *)0x2D)
#define	SPSR	*((u8 *)0x2E)
#define	SPDR	*((u8 *)0x2F)

#define MASTER	1
#define	SLAVE	0

/* Prototypes */
void SPI_vidInit(u8 u8Mode);
u8 SPI_u8Tranceiver(u8 u8Data);

#endif /* SPI_PRIVATE_H_ */
