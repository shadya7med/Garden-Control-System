/*
 * UART_INT.h
 *
 *  Created on: Dec 8, 2019
 *      Author: shady
 */

#ifndef UART_INT_H_
#define UART_INT_H_

/*UCSRA_register pins*/
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0
/***************************/
/*UCSRB_register pins*/
#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0
/***************************/
/*UCSRC_register pins*/
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0
/***************************/
/*UBRRL_register pins*/
#define URSEL	7

/***************************/

#define UBRR  						(u16)51
#define ASYNCH_MODE					(u8)0
#define SYNCH_MODE					(u8)1
#define DISABLED_PARITY				0b00
#define EVEN_PARITY					0b10
#define ODD_PARITY					0b11
#define ONE_STOP_BIT				(u8)0
#define	TWO_STOP_BIT				(u8)1
#define	_5_BIT						0b00
#define	_6_BIT						0b01
#define	_7_BIT						0b10
#define	_8_BIT						0b11
#define _9_BIT						0b11

#define UART_RX_COMPLETE_INT_DIS	(u8)0
#define UART_RX_COMPLETE_INT_EN		(u8)1

#define UART_TX_COMPLETE_INT_DIS	(u8)0
#define UART_TX_COMPLETE_INT_EN		(u8)1


#define UART_UDR_EMPTY_INT_DIS		(u8)0
#define UART_UDR_EMPTY_INT__EN		(u8)1

#define UART_RXDIS					(u8)0
#define UART_RXEN					(u8)1

#define UART_TXDIS					(u8)0
#define UART_TXEN					(u8)1

/****************************/
/*UART Functions*/
void UART_INIT(void);

void UART_SEND_CHAR_POLLING(u8 u8_SentData);
void UART_RECEIVE_CHAR_POLLING(u8* u8_ReceivedData);

#endif /* UART_INT_H_ */
