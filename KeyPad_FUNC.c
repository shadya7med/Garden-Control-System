/*
 * KeyPad_FUNC.c
 *
 *  Created on: Dec 12, 2019
 *      Author: shady
 */
#include"BIT_CALC.h"
#include"STD_TYPES.h"
#include"DIO_INT.h"

#include"KeyPad_CONFG.h"
#include"util/delay.h"

u8 PinsArr[RowNum][ColsNum] ={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'0','<','>','+'}};


void KPD_PinsInitialization()
{	/*Colunms connected to PORTA and the first 4Pins are output*/
		DIO_SetPinDirection(ColPort,ColPin1,OUTPUT);
		DIO_SetPinDirection(ColPort,ColPin2,OUTPUT);
		DIO_SetPinDirection(ColPort,ColPin3,OUTPUT);
		DIO_SetPinDirection(ColPort,ColPin4,OUTPUT);
		/*Write D1 to the Columns*/
		DIO_SetPinValue(ColPort,ColPin1,HIGH);
		DIO_SetPinValue(ColPort,ColPin2,HIGH);
		DIO_SetPinValue(ColPort,ColPin3,HIGH);
		DIO_SetPinValue(ColPort,ColPin4,HIGH);
		/**********************************************************/
		/*Rows connected to PORTB and the first 4Pins are inputs*/
		DIO_SetPinDirection(RowPort,RowPin1,INPUT);
		DIO_SetPinDirection(RowPort,RowPin2,INPUT);
		DIO_SetPinDirection(RowPort,RowPin3,INPUT);
		DIO_SetPinDirection(RowPort,RowPin4,INPUT);
		/*Pulling up to PORTB first 4 Pins*/
		DIO_SetPinValue(RowPort,RowPin1,HIGH);
		DIO_SetPinValue(RowPort,RowPin2,HIGH);
		DIO_SetPinValue(RowPort,RowPin3,HIGH);
		DIO_SetPinValue(RowPort,RowPin4,HIGH);

}

u8 KPD_GetPressedKey()
{
	u8 u8_ColIndex,u8_RowIndex;
	u8 u8_PinValue = 1;
	//Last PressedKey Value remains saved until a new press occurs
	u8 u8_PressedKeyValue = '@';
	for(u8_ColIndex =0;u8_ColIndex < ColsNum;u8_ColIndex++)
			{
				DIO_SetPinValue(ColPort, u8_ColIndex,LOW);
				for (u8_RowIndex = 0;u8_RowIndex < RowNum; u8_RowIndex ++)
				{
					//DIO_GetPinValue(RowPort,u8_RowIndex,& u8_PinValue);

					DIO_GetPinValue(RowPort,u8_RowIndex,& u8_PinValue);
					if (u8_PinValue == 0)
					{
						while(u8_PinValue == 0)
						{
							DIO_GetPinValue(RowPort,u8_RowIndex,& u8_PinValue);
						}
						(u8_PressedKeyValue) = PinsArr[u8_RowIndex][u8_ColIndex];

						_delay_ms(20);

					}
					else{
						//u8_PressedKeyValue = '@';
					}
				}
				//DIO_SetPortValue(ColPort, PORT_HIGH);
				DIO_SetPinValue(ColPort, u8_ColIndex,HIGH);
			}


return u8_PressedKeyValue ;
}
