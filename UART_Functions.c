/*
 * UART_Functions.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "std_type.h"
#include "DIO_utilites.h"
#include "DIO_reg.h"
#include "DIO_Functions.h"
#include "UART_Private.h"


void UART_vidInit(void)
{
	set_bit(UCSRB,4); // Receive Enable.
	set_bit(UCSRB,5); // USRAT Data register Interrupt Enable
	UBRRL= MYBR;
	UBRRH=0;
}
void UART_vidTransmit(u8 DATA)
{
	while (get_bit(UCSRA,5)==0); // check if the buffer has data
	UDR=DATA;

}
u8 UART_u8Receive(void)
{
 /*This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is empty*/
	while(get_bit(UCSRA,7)==0);
	return UDR;
}
