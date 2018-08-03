/*
 * Interrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "DIO_reg.h"
#include "std_type.h"
#include "DIO_utilites.h"
#include <avr/interrupt.h>
//#define F_CPU 800000ul
#include <avr/delay.h>
#include "Interrupt.h"

void Init_Inturrupt0(void)
{
	MCUCR|=0x02;
	GICR|= 0x40;
	GIFR =1;
	}
void Enable_Global_Inturrpt(void)
{
	SREG |= 0x80;
	}
/*
void vidIntTimer0(void)
{
	TCCR0= 0b10000101;
	set_bit(TIMSK,0);
	set_bit(TIFR,0);
}*/
