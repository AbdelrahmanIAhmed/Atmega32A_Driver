/*
 * DIO_Functions.c]
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdelrahman Ahmed
 */
#include "std_type.h"
#include "DIO_utilites.h"
#include "DIO_reg.h"
#include "DIO_Functions.h"

static volatile  u8 * u8PortsReg [] = {& PORTA,& PORTB, &PORTC, & PORTD};
static volatile  u8 * u8DirectionReg [] = {& DDRA,& DDRB,& DDRC, & DDRD};
static volatile  u8 * u8PinsReg [] = {& PINA,& PINB,& PINC,& PIND};

/************************************************************************************/
extern u8 DIO_u8SetPinDirection(u8 u8PortNBCpy, u8 u8PinNBCpy, u8 PinDirectionCpy)
{

	if (u8PortNBCpy > PortNumberIdx)
	{
		return check = ERROR;
	}
	else
	{
		if	(PinDirectionCpy==DIO_u8HIGH )

			{

	//assign_bit(*u8DirectionReg[u8PortNBCpy], u8PinNBCpy, DIO_u8HIGH);
	//*u8DirectionReg[u8PortNBCpy] = ((~(1<< u8PinNBCpy)) & (*u8DirectionReg[u8PortNBCpy])) | (DIO_u8HIGH<<u8PinNBCpy);
	set_bit(* u8DirectionReg[u8PortNBCpy],u8PortNBCpy);

		return check = OK;
			}
	  else
	  	  	{
		  	//  assign_bit(* u8DirectionReg[u8PortNBCpy], u8PinNBCpy, DIO_u8LOW);
		  	  	 clr_bit(* u8DirectionReg[u8PortNBCpy],u8PortNBCpy);
		  	  return check = OK;
	  	  	}

	}
}
/*********************************************************************************/
extern u8 DIO_u8SetPortDirection(u8 u8PortNBCpy ,u8 PortDirectionCpy)
{
	if ( u8PortNBCpy > PortNumberIdx )
	{
		 check = ERROR;
	}
	else
	{
	if ( PortDirectionCpy == DIO_u8HIGH)
	{
		set_reg(* u8DirectionReg[u8PortNBCpy]);
		 check = OK;
	}

	if (PortDirectionCpy == DIO_u8LOW)
	{
		clr_reg(* u8DirectionReg[u8PortNBCpy]);
		 check = OK;
	}
	}
	return check;
}

/*********************************************************************************/
extern u8 DIO_u8setPinValue(u8 u8PortNBCpy, u8 u8PinNBCpy, u8 PinValueCpy)
{
	if ( u8PortNBCpy > PortNumberIdx )
		{
			 check = ERROR;
		}
	else
		{
		 if (PinValueCpy == DIO_u8HIGH )
		 {

		set_bit(* u8PortsReg [u8PortNBCpy] ,  u8PinNBCpy);
		check = OK;
	}
		 else// (PinValueCpy == DIO_u8LOW )
	{
		clr_bit(* u8PortsReg [u8PortNBCpy] ,  u8PinNBCpy);
		check = OK;
	}
		}
	return check;
}
/**********************************************************************************/
extern u8 DIO_u8setPort(u8 u8PortNBCpy, u8 PortValueCpy)
{
	if ( u8PortNBCpy > PortNumberIdx )
			{
				 check = ERROR;
			}
	else {
		if (PortValueCpy!= DIO_u8LOW)

			{
			assign_reg(*u8PortsReg [u8PortNBCpy],PortValueCpy);
			check = OK;
			}

		else
			{
			clr_reg(*u8PortsReg [u8PortNBCpy]);
			check = OK;
			}
			}
	return check;
}
/******************************************************************************/
extern u8 DIO_u8getPin(u8 u8PortNBCpy, u8 PinIndexCpy)
/* u8 DIO_u8getPin(u8 u8PortNBCpy, u8 PinIndexCpy, u* value)*/
{
	if ( u8PortNBCpy > PortNumberIdx )
				{
					 check = ERROR;
				}
	else
	{
		check = OK;
	}

	return get_bit(*u8PinsReg[u8PortNBCpy],PinIndexCpy);
}
/*******************************************************************************/
extern u8 DIO_u8getPort(u8 u8PortNBCpy)
{
	return  * u8PinsReg [u8PortNBCpy];
}
/******************************************************************************/
