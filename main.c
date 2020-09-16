/*
 * main.c
 *
 *  Created on: Oct 2, 2019
 *      Author: shady
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include <avr/delay.h>
#include "DIO_INT.h"
#include"LCD_INT.h"
#include"UART_INT.h"
#include"UART_CONFG.h"
#include"KeyPad_CONFG.h"

#define CASE_DELAY 2000
u8 Saved_PASS[4] = {'1','2','3','4'};
u8 GET_PASS_CHECK(void);
void READ_DISPLAY_TEMP(void);
/*Not Working Yet*/
void main (void)
{
	u8 ReceivedChar = 0;



	u8 KeyPressed = '@';


	u8 PASS_flag = 0;
	u8 WRONG_PASS_flag = 0;
	u8 Repeat_MENU_flag = 0;
	u8 RESET_PIN = 1 ;


	u8 TEMP_BUTTON_MSG[15]="4 to SHOW TEMP";
	u8 C_PASS_MSG[13]="CORRECT PASS";
	u8 W_PASS_MSG[11]="WRONG PASS";
	u8 TRY_MSG[11]="TRY AGAIN";
	u8 WRONG_ENTRY_MSG[12]= "WRONG ENTRY";
	u8 FAN_SPEED_MSG[17]="+,- FOR FAN SPEED";
	u8 I_FAN_SPEED_MSG[13]="FAN SPEED ++";
	u8 D_FAN_SPEED_MSG[13]="FAN SPEED --";
	u8 OPEN_DOOR_MSG[15]="3 to Open DOOR";
	u8 OPENED_DONE_DOOR_MSG[17]="DOOR IS OPENNING";
	u8 OPENED_NOT_DONE_DOOR_MSG[17]="DOOR IS OPENED";
	u8 CLOSE_DOOR_MSG[16]="2 to close DOOR";
	u8 CLOSED_DONE_DOOR_MSG[16]="DOOR IS CLOSING";
	u8 CLOSED_NOT_DONE_DOOR_MSG[16]="DOOR IS CLOSED";
	u8 ALREADY_MSG[10]="ALREADY!!";
	u8 SPEED_LEVEL_MSG[14] = "SPEED LEVEL: ";
	u8 AUTO_CONTROL_INPUT_MSG[15] = "* EN AUTO CTRL";
	u8 AUTO_CONTROL_MSG[13]="AUTO CONTROL";
	u8 LED_STATE_MSG[10]="LED STATE";
	u8 TOG_LED_STATE_MSG[17] = "5 to TOGGLE LEDs";
	u8 TOGGLING_LEDS_MSG[14]="TOGGLING LEDS";
	u8 SHOW_LED_STATE_MSG[15] = "6 to SHOW LEDs";
	u8 ON_MSG[3]="ON";
	u8 OFF_MSG[4]="OFF";
	u8 SETTINGS_MENU_MSG[9] = "OPTIONS:";
	u8 ENTRY_MSG[17] = "Choose an Option";
	u8 MENU_AGAIN_MSG[16] = "SHOW MENU AGAIN";
	u8 SEL_MSG[17]="1 ->YES ,0 -> NO";
	//Initializations
	//PB7 --> Wrong PASS reset
	DIO_SetPinDirection(PORTB,PIN7,INPUT);
	DIO_SetPinValue(PORTB,PIN7,HIGH);
	//MAIN  MENU INDICATOR
	DIO_SetPinDirection(PORTB,PIN6,OUTPUT);
	DIO_SetPinValue(PORTB,PIN6,LOW);
	LCD_PinsInitialize();
	LCD_Initialize();
	KPD_PinsInitialization();
	UART_INIT();


	READ_DISPLAY_TEMP();
while (1)

	{
		DIO_SetPinValue(PORTB,PIN6,HIGH);

	//Waiting for an Input from KEYPAD
		KeyPressed = '@';
		while(KeyPressed == '@')
			{
				KeyPressed	= KPD_GetPressedKey();
			}

		//KeyPressed = KPD_GetPressedKey();
		if (KeyPressed == '1')
		{
			DIO_SetPinValue(PORTB,PIN6,LOW);
			//Asking for PASSWORD
			do{

				PASS_flag = GET_PASS_CHECK();
				if(PASS_flag == 4)
				{
				LCD_WriteCmd(DISPLAY_CLEAR);
				LCD_GoToXY(0,0);
				LCD_WriteString(C_PASS_MSG);
				_delay_ms(1000);
				//IF PASS was Entered One time Correct this will reset WRONG_PASS_flag(counter)
				WRONG_PASS_flag = 0 ;
				break;
				}
				else
				{
				LCD_WriteCmd(DISPLAY_CLEAR);
				LCD_GoToXY(0,0);
				LCD_WriteString(W_PASS_MSG);
				_delay_ms(1000);
				LCD_WriteCmd(DISPLAY_CLEAR);
				LCD_GoToXY(0,0);

				WRONG_PASS_flag ++;
				if (WRONG_PASS_flag != 3 )
					{
						LCD_WriteString(TRY_MSG);
						_delay_ms(500);
					}
				}
			   }while(WRONG_PASS_flag < 3);

			//IF PASSWORD WAS Entered 3 times PB7 Will return the system to
			//ASKING-for-PASS point
			if(WRONG_PASS_flag > 2 )
			{	//SYS HANGED UNTIL PB7 is PRESSED TO RETURN TO MAIN MENU
				while(RESET_PIN == 1 )
				{
					DIO_GetPinValue(PORTB,PIN7,& RESET_PIN);
				}
			}
			//Display OPtions Menu if PASS IS Correct
			else
			{
				do{
					LCD_WriteCmd(DISPLAY_CLEAR);
					LCD_GoToXY(0,0);
					LCD_WriteString(SETTINGS_MENU_MSG);//OPTIONS:
					LCD_GoToXY(0,1);
					LCD_WriteString(CLOSE_DOOR_MSG);//2
					_delay_ms(3500);//wait 1.5s
/////////////////////////////////////////////////////////////////////
					LCD_WriteCmd(DISPLAY_CLEAR);
					LCD_GoToXY(0,0);
					LCD_WriteString(OPEN_DOOR_MSG);//3
					LCD_GoToXY(0,1);
					LCD_WriteString(TEMP_BUTTON_MSG);//4
					_delay_ms(3500);//wait1.5s
/////////////////////////////////////////////////////////////////////
					LCD_WriteCmd(DISPLAY_CLEAR);
					LCD_GoToXY(0,0);
					LCD_WriteString(TOG_LED_STATE_MSG);//5
					LCD_GoToXY(0,1);
					LCD_WriteString(SHOW_LED_STATE_MSG);//6
					_delay_ms(3500);//wait1.5s
/////////////////////////////////////////////////////////////////////
					LCD_WriteCmd(DISPLAY_CLEAR);
					LCD_GoToXY(0,0);
					LCD_WriteString(FAN_SPEED_MSG);//+,-
					LCD_GoToXY(0,1);
					LCD_WriteString(AUTO_CONTROL_INPUT_MSG);//*
					_delay_ms(3500);//wait1.5s
/////////////////////////////////////////////////////////////////////
					LCD_WriteCmd(DISPLAY_CLEAR);
					LCD_GoToXY(0,0);
					LCD_WriteString(MENU_AGAIN_MSG);//MENU AGAIN ?
					LCD_GoToXY(0,1);
					LCD_WriteString(SEL_MSG);//SEL
/////////////////////////////////////////////////////////////////////
					KeyPressed = '@';
					while(KeyPressed == '@')
					{
						KeyPressed	= KPD_GetPressedKey();
					}
					if (KeyPressed == '1')
					{
						Repeat_MENU_flag = 1;
					}
					else
					{
						Repeat_MENU_flag = 0;
						LCD_WriteCmd(DISPLAY_CLEAR);
						LCD_GoToXY(0,0);
						LCD_WriteString(ENTRY_MSG);
					}

				  }while(Repeat_MENU_flag == 1);

			}


		}
		else if (KeyPressed == '2')
		{//CLOSE the DOOR
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			ReceivedChar = 0;
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);
			//Send USING UART '2' to CLOSE THE DOOR & ENABLE MANUAL CONTROL
			UART_SEND_CHAR_POLLING('2');
			//Receive DOOR STATE
			UART_RECEIVE_CHAR_POLLING(& ReceivedChar);
			if (ReceivedChar == '1')
			{
				//PRINT DOOR IS CLOSING
				LCD_WriteString(CLOSED_DONE_DOOR_MSG);
			}
			else if (ReceivedChar == '0')
			{
				//PRINT DOOR IS CLOSED Already
				LCD_WriteString(CLOSED_NOT_DONE_DOOR_MSG);
				LCD_GoToXY(0,1);
				LCD_WriteString(ALREADY_MSG);
			}
			else{}

			_delay_ms(CASE_DELAY);
		}
		else if (KeyPressed == '3')
		{//OPEN THE DOOR
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			ReceivedChar = 0 ;
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);

			//Send USING UART '3' to CLOSE THE DOOR  & ENABLE MANUAL CONTROL
			UART_SEND_CHAR_POLLING('3');
			//Receive DOOR STATE
			UART_RECEIVE_CHAR_POLLING(& ReceivedChar);
			if (ReceivedChar == '1')
			{
				//PRINT DOOR IS CLOSING
				LCD_WriteString(OPENED_DONE_DOOR_MSG);
			}
			else if (ReceivedChar == '0')
			{
				//PRINT DOOR IS CLOSED Already
				LCD_WriteString(OPENED_NOT_DONE_DOOR_MSG);
				LCD_GoToXY(0,1);
				LCD_WriteString(ALREADY_MSG);
			}
			else{}
			_delay_ms(CASE_DELAY);
		}
		else if(KeyPressed == '4')
		{//SHOW CURRENT TEMPERATURE READING
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';

			READ_DISPLAY_TEMP();

			_delay_ms(CASE_DELAY);

		}
		else if(KeyPressed == '5')
		{//TOGGLE CURRENT LED STATE
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);
			//SENDING 5 to TO turn Auto CONTROL Off then Toggle LEDs & ENABLE MANUAL CONTROL
			UART_SEND_CHAR_POLLING('5');
			LCD_WriteString(TOGGLING_LEDS_MSG);
			_delay_ms(2000);
		}
		else if(KeyPressed == '6')
		{//SHOW LED STATE
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);

			LCD_WriteString(LED_STATE_MSG);
			LCD_GoToXY(0,1);

			ReceivedChar = 0 ;
			//SENDING l to read LED STATE
			UART_SEND_CHAR_POLLING('l');
			UART_RECEIVE_CHAR_POLLING(& ReceivedChar);
			_delay_ms(200);
			if(ReceivedChar == '1')
			{
				LCD_WriteString(ON_MSG);
			}
			else if(ReceivedChar == '0')
			{
				LCD_WriteString(OFF_MSG);
			}
			else{}
			_delay_ms(CASE_DELAY);



		}
		else if(KeyPressed == '+')
		{//INCREASE FAN SPEED
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);
			//SENDING + to turn Auto CONTROL Off then increase Fan SPEED & ENABLE MANUAL CONTROL
			UART_SEND_CHAR_POLLING('+');
			LCD_WriteString(I_FAN_SPEED_MSG);
			UART_RECEIVE_CHAR_POLLING(& ReceivedChar);
			LCD_GoToXY(0,1);
			LCD_WriteString(SPEED_LEVEL_MSG);
			LCD_WriteChar(ReceivedChar);
			_delay_ms(CASE_DELAY);

		}
		else if(KeyPressed == '-')
		{//DECREASE FAN SPEED
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);
			//SENDING - to turn Auto CONTROL Off then increase Fan SPEED & ENABLE MANUAL CONTROL
			UART_SEND_CHAR_POLLING('-');
			LCD_WriteString(D_FAN_SPEED_MSG);
			UART_RECEIVE_CHAR_POLLING(& ReceivedChar);
			LCD_GoToXY(0,1);
			LCD_WriteString(SPEED_LEVEL_MSG);
			LCD_WriteChar(ReceivedChar);
			_delay_ms(CASE_DELAY);

		}
		else if(KeyPressed == '*')
		{//MANUAL CONTROL IS OFF - AUTO CONTROL IS ON
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);
			//SENDING a to EN AUTO Control and disable Manual Control
			UART_SEND_CHAR_POLLING('a');
			LCD_WriteString(AUTO_CONTROL_MSG);
			LCD_GoToXY(0,1);
			LCD_WriteString(ON_MSG);
			_delay_ms(CASE_DELAY);

		}
		else
		{//ENTERD Value no specified
			DIO_SetPinValue(PORTB,PIN6,LOW);
			KeyPressed = '@';
			LCD_WriteCmd(DISPLAY_CLEAR);
			LCD_GoToXY(0,0);
			LCD_WriteString(WRONG_ENTRY_MSG);
			_delay_ms(CASE_DELAY);

		}

	}



}
u8 GET_PASS_CHECK(void)
{
	u8 PASS_flag = 0;
	u8 index = 0;
	u8 Entered_PASS[4];

	u8 KeyPressed = '@';
	u8 PASS_MSG[6]="PASS:";

	LCD_WriteCmd(DISPLAY_CLEAR);
	LCD_GoToXY(0,0);
	LCD_WriteString(PASS_MSG);

	_delay_ms(200);
	LCD_GoToXY(0,1);
	for (index = 0;index < 4 ;index ++)
	{
		while(KeyPressed == '@')
		{
			KeyPressed	= KPD_GetPressedKey();
		}
		Entered_PASS[index] = KeyPressed;
		LCD_WriteChar('*');
		_delay_ms(100);
		KeyPressed = '@';
	}
	for (index = 0;index < 4 ;index ++)
	{
		if (Saved_PASS[index] == Entered_PASS[index])
		{
			PASS_flag ++;
		}
		else{}
	}

return PASS_flag	;
}


void READ_DISPLAY_TEMP(void)
{
	u8 TEMP_MSG[12]="TEMPERATURE";
	u8 ReceivedChar = 0;
	u8 ReceivedData[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	u8 index = 0;
	u8 Receive_flag = 0 ;

	LCD_WriteCmd(DISPLAY_CLEAR);
	LCD_GoToXY(0,0);
	LCD_WriteString(TEMP_MSG);
	LCD_GoToXY(0,1);

		UART_SEND_CHAR_POLLING('t');
	/*REC TEMP read from UART*/
		while(Receive_flag != 2)
		{
			UART_RECEIVE_CHAR_POLLING(& ReceivedChar);
			if (ReceivedChar == '#')
			{
				Receive_flag ++;
			}
			ReceivedData[index]=ReceivedChar;
			index++;
		}
		if (ReceivedData[index-1] == '#')
		{
			ReceivedData[index-1] = 'C';
		}
		else{}
		for (index = 0;index < 9;index++)
		{
			ReceivedData[index] = ReceivedData[index + 1];
		}
		//ReceivedData[8]=' ';

		/*OUTPUT TEMP read on LCD*/
		LCD_WriteArrofChar(ReceivedData,10);

		//LCD_WriteChar(' ');
		//LCD_WriteChar('C');
		_delay_ms(500);


}
