/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: NVIC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef NVIC_REGISTER_H_
#define NVIC_REGISTER_H_

#include<stdint.h>



#define NVIC_BASE_ADDRESS         0xE000E100UL




/*************   NVIC Register Defination structure *********/

typedef struct
{
	volatile uint32_t SETENA[8];
	         uint32_t Resreved_0[24];
	volatile uint32_t CLRENA[8];
	         uint32_t Resreved_1[24];
	volatile uint32_t SETPEND[8];
	         uint32_t Resreved_2[24];
    volatile uint32_t CLRPEND[8];
             uint32_t Resreved_3[24];
	volatile uint32_t ACTIVE[8];
	         uint32_t Resreved_4[24];
	volatile uint8_t IPR[240];
	         uint32_t Resreved_5[644];
	volatile uint32_t STIR ;


    
}NVIC_RegDef_t;




#define NVIC                ((NVIC_RegDef_t *)NVIC_BASE_ADDRESS)







#endif