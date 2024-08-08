/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: DMA				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/



#ifndef DMA_REGISTER_H
#define DMA_REGISTER_H

#include <stdint.h>



/*********************  DMA Register Definition Structure   *********************/
#define DMA1_BASE_ADRESS		 0x40026000U
#define DMA2_BASE_ADRESS		 0x40026400U

typedef enum
{
	SCR,
	SNDTR,
	SPAR,
	SM0AR,
	SM1AR,
	SFCR,


}DMA_Stream_Reg_T;

typedef struct
{
	volatile uint32_t ISR[2];
	volatile uint32_t IFCR[2];
	volatile uint32_t STR[8][6];

}DMA_RegDef_T;

#define DMA1					((DMA_RegDef_T *)DMA1_BASE_ADRESS)
#define DMA2					((DMA_RegDef_T *)DMA2_BASE_ADRESS)




#endif