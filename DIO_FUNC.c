/*
 * DIO_FUNC.c
 *
 *  Created on: Sep 24, 2019
 *      Author: shady
 *      DIO functions for ATMEGA 32
 *      Version 1.0
 */
#include"STD_TYPES.h"
#include "BIT_CALC.h"
#include"DIO_REG.h"
#include "DIO_INT.h"

/*********************************/
/******PINS Functions*****/
/*Func 1 : Set Pins Direction either OUTPUT or INPUT
 *for any PIN from PIN0 --OR--> 0 to PIN7 --OR--> 7
 *at any PORT from PORTA --OR--> 0 to PORTD --OR--> 3*/

u8 DIO_SetPinDirection(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy,u8 u8_PinDirectionCopy)
{
	u8 u8_ErrorState;
	if (((u8_PortIDCopy >= PORTA)&&(u8_PortIDCopy <= PORTD))&&((u8_PinNumberCopy >= PIN0)&&(u8_PinNumberCopy <= PIN7))&&((u8_PinDirectionCopy >= INPUT  )&&(u8_PinDirectionCopy <= OUTPUT )))
	{/*Function Inputs Error check*/
		u8_ErrorState =ErrorStateOK ;
		/*Setting Pins Direction*/
		if (u8_PinDirectionCopy == OUTPUT)
		{
			switch(u8_PortIDCopy)
			{
				case PORTA : 	SET_BIT(DDRA_register,u8_PinNumberCopy);	break;
				case PORTB :	SET_BIT(DDRB_register,u8_PinNumberCopy);	break;
				case PORTC :	SET_BIT(DDRC_register,u8_PinNumberCopy);	break;
				case PORTD :	SET_BIT(DDRD_register,u8_PinNumberCopy);	break;
			}

		}
		else if (u8_PinDirectionCopy == INPUT)
		{
			switch(u8_PortIDCopy)
					{
						case PORTA :	CLR_BIT(DDRA_register,u8_PinNumberCopy);	break;
						case PORTB :	CLR_BIT(DDRB_register,u8_PinNumberCopy);	break;
						case PORTC :	CLR_BIT(DDRC_register,u8_PinNumberCopy);	break;
						case PORTD :	CLR_BIT(DDRD_register,u8_PinNumberCopy);	break;
					}
		}
	}
	else
	{
		u8_ErrorState = ErrorStateNOK ;
	}
return u8_ErrorState ;

}


/*********************************/


/*Func 2 : Set Pins values either HIGH or LOW
 *for any PIN from PIN0 --OR--> 0 to PIN7 --OR--> 7
 *at any PORT from PORTA --OR--> 0 to PORTD --OR--> 3*/

u8 DIO_SetPinValue(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy,u8 u8_PinValueCopy)
{
	u8 u8_ErrorState;
	if (((u8_PortIDCopy >= PORTA)&&(u8_PortIDCopy <= PORTD))&&((u8_PinNumberCopy >= PIN0)&&(u8_PinNumberCopy <= PIN7))&&((u8_PinValueCopy >= LOW  )&&(u8_PinValueCopy <= HIGH )))
		{/*Function Inputs Error check*/
		u8_ErrorState = ErrorStateOK;
		/*Setting PINS Value*/
		if (u8_PinValueCopy == HIGH)
				{
					switch(u8_PortIDCopy)
					{
						case PORTA : 	SET_BIT(PORTA_register,u8_PinNumberCopy);	break;
						case PORTB :	SET_BIT(PORTB_register,u8_PinNumberCopy);	break;
						case PORTC :	SET_BIT(PORTC_register,u8_PinNumberCopy);	break;
						case PORTD :	SET_BIT(PORTD_register,u8_PinNumberCopy);	break;
					}

				}
				else if (u8_PinValueCopy == LOW)
				{
					switch(u8_PortIDCopy)
							{
								case PORTA :	CLR_BIT(PORTA_register,u8_PinNumberCopy);	break;
								case PORTB :	CLR_BIT(PORTB_register,u8_PinNumberCopy);	break;
								case PORTC :	CLR_BIT(PORTC_register,u8_PinNumberCopy);	break;
								case PORTD :	CLR_BIT(PORTD_register,u8_PinNumberCopy);	break;
							}
				}





		}
	else
	{
		u8_ErrorState = ErrorStateNOK;
	}




return u8_ErrorState;
}


/*********************************/



/*Func 3: Get Pins values
 *for any PIN from PIN0 --OR--> 0 to PIN7 --OR--> 7
 *at any PORT from PORTA --OR--> 0 to PORTD --OR--> 3*/

u8 DIO_GetPinValue(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy,u8* u8_PinValueCopy)
{
	//u8 u8_PinValueCopy;
	u8 u8_ErrorState;
	if (((u8_PortIDCopy >= PORTA)&&(u8_PortIDCopy <= PORTD))&&((u8_PinNumberCopy >= PIN0)&&(u8_PinNumberCopy <= PIN7)))
	{/*Function Inputs Error check*/
		u8_ErrorState =ErrorStateOK ;
		/*Getting Pins Value*/

			switch(u8_PortIDCopy)
			{
				case PORTA : 	(*u8_PinValueCopy) = GET_BIT(PINA_register,u8_PinNumberCopy);	break;
				case PORTB :	(*u8_PinValueCopy) = GET_BIT(PINB_register,u8_PinNumberCopy);	break;
				case PORTC :	(*u8_PinValueCopy) = GET_BIT(PINA_register,u8_PinNumberCopy);	break;
				case PORTD :	(*u8_PinValueCopy) = GET_BIT(PINA_register,u8_PinNumberCopy);	break;
			}

	}
	else
	{
		u8_ErrorState = ErrorStateNOK ;
	}
return u8_ErrorState  ;

}


/*********************************/

/*Func 4 : toggle Pins values
 *for any PIN from PIN0 --OR--> 0 to PIN7 --OR--> 7
 *at any PORT from PORTA --OR--> 0 to PORTD --OR--> 3*/

u8 DIO_TogPinValue(u8 u8_PortIDCopy ,u8 u8_PinNumberCopy)
{
	u8 u8_ErrorState;


	if (((u8_PortIDCopy >= PORTA)&&(u8_PortIDCopy <= PORTD))&&((u8_PinNumberCopy >= PIN0)&&(u8_PinNumberCopy <= PIN7)))
	{/*Function Inputs Error check*/
		u8_ErrorState =ErrorStateOK ;
		/*Toggle Pins Value*/

			switch(u8_PortIDCopy)
			{
				case PORTA : 	 TOG_BIT(PORTA_register,u8_PinNumberCopy);	break;
				case PORTB :	 TOG_BIT(PORTB_register,u8_PinNumberCopy);	break;
				case PORTC :	 TOG_BIT(PORTC_register,u8_PinNumberCopy);	break;
				case PORTD :	 TOG_BIT(PORTD_register,u8_PinNumberCopy);	break;
			}


	}
	else
	{
		u8_ErrorState = ErrorStateNOK ;
	}
return u8_ErrorState ;

}

/******************************************************/
/**********PORT Functions*****/
/*Func 1 : Set PORT Direction from PORT_INPUT --> 0x00 -All port PINS are INPUTS
 *to PORT_OUTPUT -- > 0xFF - All port PINs are OUTPUTs-
 *for any PORT from PORTA --OR--> 0 to PORTD --OR--> 3
 *PS : Note : NOISE on non-PULLED Input PINS */



u8 DIO_SetPortDirection(u8 u8_PortIDCopy,u8 u8_PortDirectionCopy)
{
	u8 u8_ErrorState;
	if ((u8_PortIDCopy >= PORTA) && (u8_PortIDCopy <= PORTD)&& (u8_PortDirectionCopy >= PORT_INPUT) && (u8_PortDirectionCopy <= PORT_OUTPUT))
		{/*Error Check */
			u8_ErrorState = ErrorStateOK;
		 /*Setting PORT Direction*/
			switch(u8_PortIDCopy)
			{
			case PORTA :	DDRA_register = u8_PortDirectionCopy ; 	break;
			case PORTB :	DDRB_register = u8_PortDirectionCopy ;	break;
			case PORTC :	DDRC_register = u8_PortDirectionCopy ;	break;
			case PORTD : 	DDRD_register = u8_PortDirectionCopy ;	break;
			}
		}
	else
	{
		u8_ErrorState = ErrorStateNOK;
	}

	return u8_ErrorState ;
}




/*******************/

/*Func 2 : Set PORT value form PORT_LOW --> 0x00 - All port PINS are LOW
 *to PORT_HIGH -->  0xFF - All port PINS are HIGH -
 *for any PORT from PORTA --OR--> 0 to PORTD --OR--> 3
 *Note : NOISE on non-PULLED Input PINS*/

u8 DIO_SetPortValue(u8 u8_PortIDCopy,u8 u8_PortValueCopy)
{
	u8 u8_ErrorState;
	if ((u8_PortIDCopy >= PORTA) && (u8_PortIDCopy <= PORTD)&& (u8_PortValueCopy >= PORT_LOW) && (u8_PortValueCopy <= PORT_HIGH))
		{/*Error Check */
			u8_ErrorState = ErrorStateOK;
		/* Setting PORT Value*/
			switch(u8_PortIDCopy)
			{
			case PORTA :	PORTA_register = u8_PortValueCopy ; 	break;
			case PORTB :	PORTB_register = u8_PortValueCopy ;		break;
			case PORTC :	PORTC_register = u8_PortValueCopy ;		break;
			case PORTD : 	PORTD_register = u8_PortValueCopy ;		break;
			}
		}
	else
	{
		u8_ErrorState = ErrorStateNOK;
	}

	return u8_ErrorState ;
}

/*******************/
