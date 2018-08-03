/*
 * TIMER_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/* Interrupt Registers*/
#define SREG	*((u8 *)0x5F)
#define MCUCR	*((u8 *)0x55)
#define GICR	*((u8 *)0x5B)
#define GIFR	*((u8 *)0x5A)

/* TIMER0 Registers */
#define TCNT0	*((u8 *)0x52)
#define TCCR0	*((u8 *)0x53)
#define TIMSK	*((u8 *)0x59)
#define TIFR	*((u8 *)0x58)
#define OCR0 	*((u8 *)0x5C)

/*TIMER1A Registers */
#define TCCR1A	*((u8 *)0x4F)
#define TCCR1B	*((u8 *)0x4E)
#define	OCR1	*((u16 *)0x4A)
#define ICR1	*((u16 *)0x46)


/*************************************/
/************PROTOTYPES**************/
/************************************/
extern void vidIntTimer0_CTC(u16 u16val);
extern void vidIntTimer0(void);
void Timer_vidPWM(u8 u8DutyCycle);
extern void vidInitTimer1_PWM(void);
#endif /* TIMER_PRIVATE_H_ */
