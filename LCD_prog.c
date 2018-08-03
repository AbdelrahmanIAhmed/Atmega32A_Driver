/*
 * LCD_prog.c
 *
 *  Created on: 20/4/2018
 *      Author: Abdelrahman Ahmed
 *      LCD 16 * 2 Functions
 */
#include "std_type.h"
#include "DIO_Functions.h"
#include "DIO_Functions.h"
#include <avr/delay.h>


/*Inialize LCD */
void LCD_vidInit(void)
{
	  _delay_ms(100);
	/* Clear Display */
	LCD_vidSendCommand(0b0000001);

	/* Return Home  */
	LCD_vidSendCommand(0b00000010);

	/* Entry Mode Set  */
	LCD_vidSendCommand(0b00000110);

	/* Display ON OFF Control */
	 LCD_vidSendCommand(0b00001100);

	 /* Function Set  */
	LCD_vidSendCommand(0b00111000);
}
/*Send Command */
void LCD_vidSendCommand(u8 u8CmdCpy)
{
	/* SET RS to Instruction Mood */
DIO_u8setPinValue(PORTA_Idx,0,DIO_u8LOW);

	/* Read Write bit is set to LOW */
DIO_u8setPinValue(PORTA_Idx, 1 ,DIO_u8LOW);

	/* SET Enable bit to HIGH*/
DIO_u8setPinValue(PORTA_Idx, 2 ,DIO_u8HIGH);

	/* send command to Data BUS */
DIO_u8setPort(PORTD_Idx,u8CmdCpy);

	/* SET Enable bit to LOW*/
DIO_u8setPinValue(PORTA_Idx, 2 ,DIO_u8LOW);

	/* delay function here */
	_delay_ms(5);

	/* SET Enable bit to HIGH*/
DIO_u8setPinValue(PORTA_Idx, 2 ,DIO_u8HIGH);
	/*  delay function here */
	_delay_ms(10);
}

void  LCD_vidWriteCharctr(u8 u8DataCpy)
{
	/* SET RS to Data Mood */
	DIO_u8setPinValue(PORTA_Idx,0,DIO_u8HIGH);

	/* Read Write bit is set to LOW */
	DIO_u8setPinValue(PORTA_Idx, 1 ,DIO_u8LOW);

	/* SET Enable bit to HIGH*/
	DIO_u8setPinValue(PORTA_Idx, 2 ,DIO_u8HIGH);

	/* send command to Data BUS */
	DIO_u8setPort(PORTD_Idx,u8DataCpy);

	/* SET Enable bit to LOW*/
	DIO_u8setPinValue(PORTA_Idx, 2 ,DIO_u8LOW);

		/*  delay function here */
	 _delay_ms(5);

		/* SET Enable bit to HIGH*/
	DIO_u8setPinValue(PORTA_Idx, 2 ,DIO_u8HIGH);

		/*  delay function here */
	 _delay_ms(10);

}

void LCD_vidWriteString(u8 * Pu8StringCpy)
{
	u8 u8Indx = 0;

	while (Pu8StringCpy[u8Indx] !=0)
	{
		 LCD_vidWriteCharctr(Pu8StringCpy[u8Indx]);

		 u8Indx ++;
		 /*  delay function here */
		 _delay_ms(2);
	}

}
void LCD_vidShiftData(u32 count)
{	u32 i;
	for (i= 0; i< count ; i++)
	{
	LCD_vidSendCommand(0b00011000);
	}
	return;
	}
