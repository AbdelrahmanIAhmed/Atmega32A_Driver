/*
 * Kypad_functioncs.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#include "std_type.h"
#include "DIO_Functions.h"
#include <avr/delay.h>
#include "DIO_reg.h"

#define NOT_PRESSED		0
#define COL_FIN			8
#define ROW_FIN			8
#define ROW_INIT		4
#define COL_INIT		4
#define PORT		PORTD_Idx


const u8 KPD_au8SwitchVal[4][4] =
{
  {
    0x04,
    0x08,
    0x0C,
    0x10 },
  {
    0x03,
    0x07,
    0x0B,
    0x0F },
  {
    0x02,
    0x06,
    0x0A,
    0x0E },
  {
    0x01,
    0x05,
    0x09,
    0x0D }
};
u8 u8GetPressedKey (void)
{


	u8 Loc_u8Coloumn;

	u8 Loc_u8Row;

u8 Pressed_u8button = NOT_PRESSED;

for (Loc_u8Coloumn= 0+ 4 ; Loc_u8Coloumn < 8;Loc_u8Coloumn ++)

{

	DIO_u8setPinValue(PORTD_Idx,Loc_u8Coloumn,0);


	for (Loc_u8Row = 0+ ROW_INIT ; Loc_u8Row <ROW_FIN ;Loc_u8Row ++)

	{

		if  ( DIO_u8getPin(PORTC_Idx,Loc_u8Row ) == 0)

		{


			Pressed_u8button = KPD_au8SwitchVal[Loc_u8Coloumn- COL_INIT][Loc_u8Row - ROW_INIT];



		}

	while (!DIO_u8getPin(PORTC_Idx,Loc_u8Row));
		_delay_ms(10);
	}

	DIO_u8setPinValue(PORTD_Idx,Loc_u8Coloumn,1);

}
return Pressed_u8button;

}
