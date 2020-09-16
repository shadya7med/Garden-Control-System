/*
 * LCD_INT.h
 *
 *  Created on: Sep 26, 2019
 *      Author: shady
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


/*Commands Description*/
/* N-->0--> 1 LINE , 1--> 2 Lines
 * F-->0--> 5*7 dots character,1-->5*10 dots character
 * D-->0-->Display OFF ,1--> Display ON
 * C-->0-->Cursor OFF ,1-->Cursor ON
 * B-->0-->Blinking OFF ,1-->Blinking ON
 * S/C-->0-->Cursor ,1-->Screen
 * R/L-->0-->Shift Left,1-->Shift right
 */
/*LCD Commands Values*/
/*RS & RW --> 00*/
#define FUNCTION_SET 0b00111000//0011NF00
#define DISPLAY_CONTROL_ON 0b00001100//00001DCB
#define DISPLAY_CLEAR 0b00000001//00000001
#define ENTRY_MODE 0b00000110//000001 I/D SH
#define RETURN_HOME 0b00000010//00000010
#define DISPLAY_SHIFT 0b0001000//0001 S/C R/L 00
#define SET_CGRAM_ADDRESS 0b01000000//01 AC5 AC4 AC3 AC2 AC1 AC0
#define SET_DDRAM_ADDRESS 0b10000000//1 AC6 AC5 AC4 AC3 AC2 AC1 AC0

/*RS&RW-->01*/
#define READ_BF 0b10000000//BF AC6 AC5 AC4 AC3 AC2 AC1 AC0


/*LCD Functions Prototype*/
//refter to LCD_CONFIG.h for LCD pins connections
u8 LCD_PinsInitialize();
void LCD_Initialize(void);

void LCD_WriteCmd(u8 u8_CmdCopy);

void LCD_WriteChar(u8 u8_DataCopy);
void LCD_WriteString(u8 * u8_StringCopy);
void LCD_WriteArrofChar(u8 * u8_ArrofChar,u8 u8_ArrayLength);

u8 LCD_GoToXY (u8 , u8);

void LCD_Sep_DisResult(u16 u16_result);

void LCD_SepResult(u16 u16_result,u8 *ResSepArr);

#endif /* LCD_INT_H_ */
