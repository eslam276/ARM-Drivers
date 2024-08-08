/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 16-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#include <stdint.h>
#include "EXTI_register.h"


typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_FALLING_EDGE

}EXTI_Trigger_t;

typedef enum
{
	EXTI_ENABLE,
	EXTI_DISABLE
}EXTI_Enable_t;

typedef enum
{
	EXTI_0,
	EXTI_1,
	EXTI_2,
	EXTI_3,
	EXTI_4,
	EXTI_5,
	EXTI_6,
	EXTI_7,
	EXTI_8,
	EXTI_9,
	EXTI_10,
	EXTI_11,
	EXTI_12,
	EXTI_13,
	EXTI_14,
	EXTI_15
}EXTI_Number_t;

typedef struct
{
	EXTI_Trigger_t Trigger_Config;
	EXTI_Enable_t  Enable_Config;
	EXTI_Number_t  EXTI_Num;
	void (*CallBack)(void);

}EXTI_Config_t;

uint8_t EXTI_u8Init(EXTI_Config_t * Copy_stConfig);
uint8_t EXTI_u8Enable_INT(EXTI_Number_t Copy_enINTNum);
uint8_t EXTI_u8Disable_INT(EXTI_Number_t Copy_enINTNum);
uint8_t EXTI_u8GetPendingFlag(EXTI_Number_t Copy_enINTNum,uint8_t* Copy_pValue);
uint8_t EXTI_u8ClearPendingFlag(EXTI_Number_t Copy_enINTNum);
uint8_t EXTI_u8SetTriggerSrc(EXTI_Trigger_t Trigger_Config ,EXTI_Number_t Copy_enINTNum );



#endif
