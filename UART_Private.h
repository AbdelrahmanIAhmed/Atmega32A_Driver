/*
 * UART_Functions.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */


#ifndef UART_FUNCTIONS_H_
#define UART_FUNCTIONS_H_


void UART_vidInit(void);
void UART_vidTransmit(u8 DATA);
u8 UART_u8Receive(void);


#define BR 		9600
#define FOSC	8000000
#define MYBR	(FOSC/16/BR-1)

#define	UDR		*((volatile u8 *)0x2C)
#define	UCSRA	*((volatile u8 *)0x2B)
#define	UCSRB	*((volatile u8 *)0x2A)
#define	UBRRL	*((volatile u8 *)0x29)
#define	UBRRH	*((volatile u8 *)0x40)
#define	UCSRC	*((volatile u8 *)0x40)

#endif /* UART_FUNCTIONS_H_ */
