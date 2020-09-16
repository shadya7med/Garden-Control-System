/*
 * KeyPad_CONFG.h
 *
 *  Created on: Dec 12, 2019
 *      Author: shady
 */

#ifndef KEYPAD_CONFG_H_
#define KEYPAD_CONFG_H_


/*Choose Which port Keypad COLMUNS will be Connected to*/
/*Which PORT*/
/*PORTA	PORTB	PORTC	PORTD*/
#define ColPort PORTA
/*Which PINS*/
/*PIN0	PIN1	PIN2	PIN3	PIN4	PIN5	PIN6	PIN7*/
#define ColPin1 PIN0
#define ColPin2 PIN1
#define ColPin3 PIN2
#define ColPin4 PIN3

/********************************************************/

/*Choose Which port Keypad ROWS will be Connected to*/
/*Which PORT*/
/*PORTA	PORTB	PORTC	PORTD*/
#define RowPort	PORTB
/*Which PINS*/
/*PIN0	PIN1	PIN2	PIN3	PIN4	PIN5	PIN6	PIN7*/
#define RowPin1 PIN0
#define RowPin2 PIN1
#define RowPin3 PIN2
#define RowPin4 PIN3

/*Number of Columns and Rows of the Keypad*/
#define ColsNum 4
#define RowNum 4

/*Keypad Elements Array*/
/*
*'7'				'8'				'9'				/
*'4'				'5'				'6'				*
*'1'				'2'				'3'				-
*'0'				 <				 >				+
*/
//To Change the Buttons Confg refer to KeyPad_FUNC.c

/*Keypad INT */
/*instead of having a new header for just 2 lines*/
void KPD_PinsInitialization();
//Last PressedKey Value remains saved until a new press occurs
//returns the Value of the Key as Char
u8 KPD_GetPressedKey();
#endif /* KEYPAD_CONFG_H_ */
