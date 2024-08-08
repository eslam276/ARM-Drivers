/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 16-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


#include <stdint.h>

#define EXTI_BASE_ADDRESS        0x40013C00U

#define SYSCFG_BASE_ADDRESS      0x40013800U




/************* EXTI Register Definition Sructure **********/

typedef struct
{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
}EXTI_RegDef_t;




/************* SYSCFG Register Definition Sructure **********/

typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t CMPCR;
	volatile uint32_t CFGR;
}SYSCFG_RegDef_t;





/************ EXTI Peripheral Definition *********/

#define EXTI               ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)

/************ SYSCFG Peripheral Definition *********/

#define SYSCFG            ((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)





#endif
