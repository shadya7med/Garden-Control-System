/*
 * UART_FUNC.c
 *
 *  Created on: Dec 8, 2019
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"UART_REG.h"
#include"UART_INT.h"
#include"UART_CONFG.h"

void UART_INIT(void)
{

	/*UART Initialization*/

	//PD0 -- > RXD ,, PD1 -- > TXD >>>> UART will overwrite the GPIO functions for the PINS
		/*SETTING BUAD RATE --> 9600 at Fosc = 8MHz*/
		UBRRH_register = (u8)(UBRR >> 8) ;
		UBRRL_register = (u8)UBRR ;

		//UCSRC_register = 0b10000110;//CS --> 8bits,Async
		UCSRC_register = (u8)1 << 7 |UART_MODE_SELECT << 6|UART_PARITY_MODE << 4|UART_STOP_BIT_MODE <<3 |UART_CHAR_SIZE << 1|(u8)0;
		//UCSRB_register = 0b00011000;//No Interrupt ,RX & TX is enabled
		UCSRB_register = UART_RX_COMPLETE_INT_STATE << 7|UART_TX_COMPLETE_INT_STATE << 6|UART_UDR_EMPTY_INT_STATE << 5|UART_RX_STATE << 4|UART_TX_STATE << 3|(u8)0;


}

void UART_SEND_CHAR_POLLING(u8 u8_SentData)
{

	while(GET_BIT(UCSRA_register,UDRE) == 0 );//wait until TX Buffer is empty
	UDR_register = u8_SentData ;

}

void UART_RECEIVE_CHAR_POLLING(u8 * u8_ReceivedData)
{
	while(GET_BIT(UCSRA_register,RXC) == 0);//wait until RX buffer has unread data and then read it
	*(u8_ReceivedData) = UDR_register;


}
