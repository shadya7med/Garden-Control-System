/*
 * LCD_CONFG.h
 *
 *  Created on: Sep 28, 2019
 *      Author: shady
 */

#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#include"DIO_INT.h"


/*to declare PINS and PORTS connected to the LCD 16X2 Module*/

#define DataPort PORTC
#define ControlPort PORTD
#define RS 	PIN5
#define RW	PIN6
#define EN 	PIN7
#define DisplayLineLength 16



#endif /* LCD_CONFG_H_ */
