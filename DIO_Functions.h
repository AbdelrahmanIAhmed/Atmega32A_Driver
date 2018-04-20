/*
 * DIO_Functions.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef DIO_FUNCTIONS_H_
#define DIO_FUNCTIONS_H_
/***********************PORTS********************/
#define PORTA_Idx		0
#define PORTB_Idx		1
#define PORTC_Idx		2
#define PORTD_Idx		3

#define PortNumberIdx	3
#define PinNumberIdx	7
#define DIO_u8HIGH		1
#define DIO_u8LOW		0
#define OUTPUT			1
#define	INPUT			0

enum Boolean {
	ERROR,
	OK
}check;

/********************Functions Prototypes*****************/

/*COMMENT: Set Pin Direction */
extern u8 DIO_u8SetPinDirection(u8 , u8 , u8 );

/*COMMENT: Set Port Direction */
extern u8 DIO_u8SetPortDirection(u8 u8PortNBCpy ,u8 PortDirectionCpy);

/*COMMENT: Set Pin Value */
extern u8 DIO_u8setPinValue(u8 u8PortNBCpy, u8 u8PinNBCpy, u8 PinValueCpy);

/*COMMENT: Set Port By Value */
extern u8 DIO_u8setPort(u8 u8PortNBCpy, u8 PortValueCpy);

/*COMMENT: Get a value of a pin in certain Port */
extern u8 DIO_u8getPin (u8 u8PortNBCpy, u8 PinIndexCpy);

/*COMMENT: Get All Port value */
extern u8 DIO_u8getPort(u8 u8PortNBCpy);

#endif /* DIO_FUNCTIONS_H_ */
