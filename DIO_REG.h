/*
 * DIO_REG.h
 *
 *  Created on: Sep 24, 2019
 *      Author: shady
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_
/*PORTA*/
#define DDRA_register (*(volatile u8 *)0x3A)
#define PORTA_register (*(volatile u8 *)0x3B)
#define PINA_register (*(volatile u8 *)0x39)
/******/
/*PORTB*/
#define DDRB_register (*(volatile u8 *)0x37)
#define PORTB_register (*(volatile u8 *)0x38)
#define PINB_register (*(volatile u8 *)0x36)
/******/
/*PORTC*/
#define DDRC_register (*(volatile u8 *)0x34)
#define PORTC_register (*(volatile u8 *)0x35)
#define PINC_register (*(volatile u8 *)0x33)
/******/
/*PORTD*/
#define DDRD_register (*(volatile u8 *)0x31)
#define PORTD_register (*(volatile u8 *)0x32)
#define PIND_register (*(volatile u8 *)0x30)
/******/
#endif /* DIO_REG_H_ */
