/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: DMA				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/


#ifndef DMA_INETRFACE_H
#define DMA_INETRFACE_H

#include <stdint.h>

#include "DMA_register.h"
#include "DMA_private.h"

typedef enum
{
    DMA_1 = 0 ,
    DMA_2,
}DMA_NUM_t;



typedef enum 
{
    CHANNEL0 = 0 ,
    CHANNEL1,
    CHANNEL2,
    CHANNEL3,
    CHANNEL4,
    CHANNEL5,
    CHANNEL6,
    CHANNEL7

}DMA_Channel_t;



typedef enum
{
	STREAM0 = 0,
	STREAM1,
	STREAM2,
	STREAM3,
	STREAM4,
	STREAM5,
	STREAM6,
	STREAM7

}DMA_StreamNum_t;

typedef enum
{
    LOW = 0 ,
    MEDIUM,
    HIGH ,
    VERY_HIGH

}DMA_PriorityLevel_t;

typedef enum 
{
    FIXED = 0,
    INCREMENT 

}DMA_Increment_t;



typedef enum
{
	BYTE = 0 ,
	HALF_WORD,
	WORD

}DMA_IncSize_t;




typedef enum
{
	PERIPH_TO_MEM = 0 ,
	MEM_TO_PERIPH,
	MEM_TO_MEM

}DMA_TransferDirection_t;


typedef enum
{
    DISABLED = 0 ,
    ENABLED 

}DMA_IntEnable_t ;


typedef enum 
{
    DIRECT_MODE = 0 ,
    FIFO_MODE

}DMA_TransferMode_t;



typedef enum
{
	QUART = 0,
	HALF,
	THREE_QUART,
	FULL

}DMA_FIFOThresh_t;




typedef struct
{
	DMA_NUM_t DMA_NUM;

	DMA_Increment_t MemIncMode;
	DMA_Increment_t PerIncMode;

	DMA_IncSize_t MemIncSize;
	DMA_IncSize_t PerIncSize;

	 // DMA_SrcDestMode SrcDestMode;
	DMA_TransferDirection_t TransferMode;

	DMA_StreamNum_t StreamNum;
	DMA_Channel_t ChannelNum;
	DMA_PriorityLevel_t PriorityLevel;

	DMA_FIFOThresh_t FIFOThresh;

	DMA_IntEnable_t InterruptEnable;

	void (*CallBackFunc)(void);

}DMA_Cnfg_T;


uint8_t DMA_u8Init(DMA_Cnfg_T* DMA_Cnfg);

uint8_t DMA_u8StartTransfer(DMA_Cnfg_T *DMA_Cnfg,uint32_t *Copy_pu32SrcAddress , uint32_t *Copy_pu32DestAddress , uint16_t Copy_u32DataSize);


#endif