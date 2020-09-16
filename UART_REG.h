/*
 * UART_REG.h
 *
 *  Created on: Dec 8, 2019
 *      Author: shady
 */

#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR_register		(*(volatile u8 *)0x2C)
#define UCSRA_register		(*(volatile u8 *)0x2B)
#define UCSRB_register		(*(volatile u8 *)0x2A)
#define UCSRC_register		(*(volatile u8 *)0x40)
#define UBRRL_register		(*(volatile u8 *)0x29)
#define UBRRH_register		(*(volatile u8 *)0x40)

#endif /* UART_REG_H_ */
