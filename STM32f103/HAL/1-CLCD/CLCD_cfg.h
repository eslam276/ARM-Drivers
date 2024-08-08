/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: CLCD_CFG.h			*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef CLCD_CFG_H_
#define CLCD_CFG_H_

#include "GPIO_interface.h"

/*Please choose which port to connect ctrl pins: RS, RW, E
 * options:  1- DIO_u8PORTA
 * 			 2- DIO_u8PORTB
 * 			 3- DIO_u8PORTC
 * 			 4- DIO_u8PORTD
 * 	*/

/*Configure the operation mode, options: 1- EIGHT_BIT_MODE
 * 										 2- FOUR_BIT_MODE	*/

#define CLCD_OP_MODE			FOUR_BIT_MODE

/*cofigure if the RW pin is controlled or not, options: 1- ENABLED
 * 														2- DISABLED */
#define CLCD_RW_CTRL_EN			DISABLED

#define CLCD_CTRL_PORT			PORTA

#define CLCD_RS_PIN				PIN11
#define CLCD_E_PIN				PIN8

#if CLCD_RW_CTRL_EN	== ENABLED
#define CLCD_RW_PIN				DIO_u8PIN0
#endif

#define CLCD_DATA_PORT			PORTB

#if CLCD_OP_MODE ==  FOUR_BIT_MODE

#define CLCD_D4_PIN				PIN15
#define CLCD_D5_PIN				PIN14
#define CLCD_D6_PIN				PIN13
#define CLCD_D7_PIN				PIN12
#endif


#endif
