/*
 * DIO_INT.h
 *
 *  Created on: Sep 24, 2019
 *      Author: shady
 */
#ifndef _DIO_INT_H_
#define _DIO_INT_H_

/*PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*PIN Values*/
#define HIGH 1
#define LOW 0
/*PIN Directions*/
#define INPUT 0
#define OUTPUT	1

/********************************/

/*PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/*PORT Values*/
#define PORT_HIGH  0xFF
#define PORT_LOW	0x00
/*PORT directions*/
#define PORT_OUTPUT	0xFF
#define	PORT_INPUT	0x00

/*************************************/

/*DIO Function Prototypes*/
/*PINS Functions*/
u8 DIO_SetPinDirection(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy,u8 u8_PinDirectionCopy);

u8 DIO_SetPinValue(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy,u8 u8_PinValueCopy);

u8 DIO_GetPinValue(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy,u8* u8_PinValueCopy);

u8 DIO_TogPinValue(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy);

/********************/

/*PORT Functions */

u8 DIO_SetPortDirection(u8 u8_PortIDCopy,u8 u8_PortDirectionCopy);
u8 DIO_SetPortValue(u8 u8_PortIDCopy,u8 u8_PortValueCopy);

#endif /*_DIO_INT_H_*/
