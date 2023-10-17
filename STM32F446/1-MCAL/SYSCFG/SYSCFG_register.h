/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: SYSCFG				**************/
/********************		Version: 1.00			**************/
/********************		Date: 16-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef SYSCFG_REGISTER_H_
#define SYSCFG_REGISTER_H_


#include <stdint.h>



#define SYSCFG_BASE_ADDRESS      0x40013800U


/************* SYSCFG Register Definition Sructure **********/

typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
    volatile uint32_t RESERVED1[2];
	volatile uint32_t CMPCR;
    volatile uint32_t RESERVED2[2];
	volatile uint32_t CFGR;
}SYSCFG_RegDef_t;



/************ SYSCFG Peripheral Definition *********/

#define SYSCFG            ((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)





#endif