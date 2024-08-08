/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: SYSCFG				**************/
/********************		Version: 1.00			**************/
/********************		Date: 16-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_


#include <stdint.h>



typedef enum
{
	LINE_0,
	LINE_1,
	LINE_2,
	LINE_3,
	LINE_4,
	LINE_5,
	LINE_6,
	LINE_7,
	LINE_8,
	LINE_9,
	LINE_10,
	LINE_11,
	LINE_12,
	LINE_13,
	LINE_14,
	LINE_15
}SYSCFG_Line_t;

typedef enum
{
	PA,
	PB,
	PC,
	PD,
	PE,
	PF,
	PG,
	PH
}SYSCFG_Port_t;

uint8_t SYSCFG_u8SetLine(SYSCFG_Line_t Copy_enLineValue, SYSCFG_Port_t Copy_u8enPortValue);




#endif