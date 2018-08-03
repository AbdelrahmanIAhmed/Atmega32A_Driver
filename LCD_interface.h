/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*Inialize LCD */
extern void LCD_vidInit(void);

/*Send Command */
extern void LCD_vidSendCommand(u8 u8CmdCpy);

/* send character */
extern void  LCD_vidWriteCharctr(u8 u8DataCpy);

/* send string */
extern void LCD_vidWriteString(u8 * Pu8StringCpy);

#endif /* LCD_INTERFACE_H_ */
