/*
 * Timer_private.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#include "std_type.h"
#include "DIO_reg.h"
#include "DIO_utilites.h"
#include "DIO_Functions.h"
#include "TIMER_private.h"
extern void vidIntTimer0_CTC(u16 u16val)

{
	//set_bit(TCCR0,3);
	//clr_bit(TCCR0,7);
	TCCR0 =0b00001001;
	set_bit(TIMSK,1);
	set_bit(TIFR,1);
	set_reg_val(OCR0,u16val);
}

extern void vidIntTimer0(void)
{
	TCCR0= 0b10000101;
	set_bit(TIMSK,0);
	set_bit(TIFR,0);
}
void Timer_vidPWM(u8 u8DutyCycle)
{
	TCCR0= 0b01101101;
	set_bit(DDRB,3); // OC0
	OCR0=u8DutyCycle;
}
void vidInitTimer1_PWM(void)
{
	set_bit(TCCR1A,1);
	set_bit(TCCR1A,7);
//	assign_reg(TCCR1A,0b10000010);
	set_bit(TCCR1B,1);
	set_bit(TCCR1B,3);
	set_bit(TCCR1A,4);
	//assign_reg(TCCR1B,0b00011010);
}

void vidInitTimer1_PWM_ICU(void)
{
	 Enable_Global_Inturrpt();
	 TCCR1A= 0b00000000;
	 TCCR1B =0b01000001;
	 /* Enable Preipheral int */
	 set_bit(TIMSK,5);
	 clr_bit(DDRC,6);
	 set_bit(TIMSK,2);
}




