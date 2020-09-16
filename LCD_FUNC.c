/*
 * LCD_FUNC.c
 *
 *  Created on: Sep 26, 2019
 *      Author: shady
 */
#include"STD_TYPES.h"
#include<avr/delay.h>
#include<string.h>
#include"DIO_INT.h"
#include"LCD_CONFG.h"
#include"LCD_INT.h"




/*16X2 LCD functions:
 * 1.LCD_PinsInitialize : for making uC connected PINS to the LCD module as Output using DIO driver\
 * 2.LCD_Initialize : Initializing LCD display using a sequence of commands as specified in LCD data sheet
 * 3.LCD_WriteCmd: to Write a Command on LCD Module List using 8-bit commands ,List of commands explained in data sheet and in LCD_INT.h
 * 4.LCD_WriteChar: to Write a Character on LCD Module using 8-bit corresponding to each character
 * 5.LCD_WriteString: to Write a String ended with '\0' EX : "NAME"
 * 6.LCD_WriteArrofChar : to Write a String or Array of Chars not ended with '\0'
 * 7.LCD_GoToXY : to Move to any place on LCD from 0 to 15 on 2 Rows 0,1
 * 8.LCD_Sep_DisResult: to seperate -u16 Max- number , convert it to CHAR and display these characters
 * NOTE :when using LCD_Sep_DisResult numbers must not start with 0 Ex : 500 not 0500
 * 9.LCD_SepResult: Like Func 8 but without displaying on LCD 16X2 module*/

u8 LCD_PinsInitialize()
{
	u8 ErrorState;

	if ((ControlPort >= PORTA) && (ControlPort <= PORTD) && (DataPort >= PORTA) && (DataPort <= PORTD) && (EN >= PIN0) && (EN <= PIN7)&& (RS >= PIN0) && (RS <= PIN7)&& (RW >= PIN0) && (RW <= PIN7))
		{
			ErrorState = ErrorStateOK;

			DIO_SetPinDirection(ControlPort,EN,OUTPUT);
			DIO_SetPinDirection(ControlPort,RS,OUTPUT);
			DIO_SetPinDirection(ControlPort,RW,OUTPUT);

			DIO_SetPortDirection(DataPort,PORT_OUTPUT);

		}
	else {
			ErrorState = ErrorStateNOK;



	}





	return ErrorState;

}



void LCD_Initialize (void)
{

	_delay_ms(40);
	LCD_WriteCmd(FUNCTION_SET);
	_delay_ms(1);
	LCD_WriteCmd(DISPLAY_CONTROL_ON);
	_delay_ms(1);
	LCD_WriteCmd(DISPLAY_CLEAR);
	_delay_ms(3);
	LCD_WriteCmd(ENTRY_MODE);

	_delay_ms(1);



}


void LCD_WriteCmd(u8 u8_CmdCopy)
{
	DIO_SetPinValue(ControlPort,EN,LOW);
	DIO_SetPinValue(ControlPort,RS,LOW);
	DIO_SetPinValue(ControlPort,RW,LOW);

	DIO_SetPortValue(DataPort,u8_CmdCopy);

	DIO_SetPinValue(ControlPort,EN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(ControlPort,EN,LOW);


}



void LCD_WriteChar(u8 u8_DataCopy)
{
	DIO_SetPinValue(ControlPort,EN,LOW);
	DIO_SetPinValue(ControlPort,RS,HIGH);
	DIO_SetPinValue(ControlPort,RW,LOW);

	DIO_SetPortValue(DataPort,u8_DataCopy);

	DIO_SetPinValue(ControlPort,EN,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(ControlPort,EN,LOW);


}








void LCD_WriteString(u8 * u8_StringCopy)
{
	u8 index;


	for (index = 0 ;index < ((u16)strlen (u8_StringCopy));index++)
	{

		LCD_WriteChar(u8_StringCopy[index]);


	}


}



void LCD_WriteArrofChar(u8 * u8_ArrofChar ,u8 u8_ArrayLength)
{
	u8 index;


	for (index = 0 ;index < u8_ArrayLength;index++)
	{

		LCD_WriteChar(u8_ArrofChar[index]);


	}


}



u8 LCD_GoToXY(u8 u8_XValue,u8 u8_YValue)
{
	u8 ErrorState;

	if ((u8_XValue >= 0) && (u8_XValue <= 15) && (u8_YValue >= 0) && (u8_YValue <= 1))
	{
		ErrorState = ErrorStateOK ;
		switch (u8_YValue)
		{
			case 0 :LCD_WriteCmd(128 + u8_XValue); 	break;
			case 1 :LCD_WriteCmd(192 + u8_XValue); 	break;
		}
	}
	else
	{
		ErrorState = ErrorStateNOK ;
	}

	return ErrorState ;

}


void LCD_Sep_DisResult(u16 u16_result)
{
	u8 ResArr[5],index = 0 ;


		ResArr[0] =(u8) (u16_result /(u16)10000);
		u16_result = u16_result -( (u16) ResArr[0] * (u16) 10000) ;

		ResArr[1] = (u8)(u16_result /(u16)1000);
		u16_result = u16_result - ((u16)ResArr[1] * (u16) 1000) ;

		ResArr[2]  = (u8)(u16_result /(u16)100 ) ;
		u16_result = u16_result - ((u16)ResArr[2] * (u16) 100) ;

		ResArr[3] = (u8)(u16_result /(u16)10) ;
		u16_result = u16_result -((u16)ResArr[3] * (u16)10);

		ResArr[4] = (u8)u16_result ;


		/*converting INT to CHAR*/
		for (index =0 ;index < 5;index++)
			{
				ResArr[index] += '0';
			}



		LCD_WriteArrofChar((ResArr ),(5));





}


void LCD_SepResult(u16 u16_result,u8 *ResSepArr)
{
	u8 ResArr[5],index = 0 ;


		ResArr[0] =(u8) (u16_result /(u16)10000);
		u16_result = u16_result -( (u16) ResArr[0] * (u16) 10000) ;

		ResArr[1] = (u8)(u16_result /(u16)1000);
		u16_result = u16_result - ((u16)ResArr[1] * (u16) 1000) ;

		ResArr[2]  = (u8)(u16_result /(u16)100 ) ;
		u16_result = u16_result - ((u16)ResArr[2] * (u16) 100) ;

		ResArr[3] = (u8)(u16_result /(u16)10) ;
		u16_result = u16_result -((u16)ResArr[3] * (u16)10);

		ResArr[4] = (u8)u16_result ;



		/*converting INT to CHAR*/
		for (index =0 ;index < 5;index++)
			{
				ResArr[index] += '0';
			}

		for (index =0;index < 5;index++)
		ResSepArr[index] = ResArr[index] ;


}
