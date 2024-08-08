/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: SCB				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/




#ifndef SCB_REGIISTER_H
#define SCB_REGIISTER_H

#include <stdint.h>


#define SCB_BASE_ADDRESS          0xE000E008UL



/************* SCB Register Defination structure **************/

typedef struct
{
	volatile uint32_t ACTLR;
	         uint32_t Reserved_0[829];
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCRS;
	volatile uint32_t CFSR; /*Banked Register*/
	volatile uint32_t HFSR;
             uint32_t Reserved_1;
	volatile uint32_t MMAR;
	volatile uint32_t BFAR;
	volatile uint32_t AFSR;
	
}SCB_RegDef_t;




#define SCB                  ((SCB_RegDef_t *)SCB_BASE_ADDRESS)




#endif
