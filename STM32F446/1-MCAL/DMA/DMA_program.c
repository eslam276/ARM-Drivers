

#include <stdint.h>
#include "defines.h"

#include "DMA_register.h"
#include "DMA_private.h"
#include "DMA_interface.h"


static DMA_RegDef_T *DMA_Arr[2] = {DMA1 , DMA2};
static DMA_Status DMA_StatusArr[2] ;
static void (*GeneralCallBackFun[DMA_TYPE_NUM*DMA_STREAM_NUM])(void) = {NULL};


uint8_t DMA_u8Init(DMA_Cnfg_T* DMA_Cnfg)
{
    uint8_t Local_u8ErrorState = OK ;

    if (DMA_Cnfg != NULL)
    {
        /* Channel Selction */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_CHSEL_MASK << DMA_CHSEL_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->ChannelNum << DMA_CHSEL_SHIFT) ;

        /* Set priority level */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_PL_MASK << DMA_PL_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->PriorityLevel << DMA_PL_SHIFT) ;

        /* Set Memory data size  */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_MSIZE_MASK << DMA_MSIZE_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->MemIncSize << DMA_MSIZE_SHIFT) ;


        /* Set Periphral data size  */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_PSIZE_MASK << DMA_PSIZE_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->PerIncSize << DMA_PSIZE_SHIFT) ;

        /* Set Memory Increment mode  */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_MINC_MASK << DMA_MINC_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->MemIncMode << DMA_MINC_SHIFT) ;


        /* Set Periphral Increment mode  */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_PINC_MASK << DMA_PINC_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->PerIncMode << DMA_PINC_SHIFT) ;


        if(DMA_Cnfg->TransferMode == FIFO_MODE)
		{
			/* Disable direct mode*/
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SFCR] |= (1 << DMA_DMDIS_SHIFT);

			
			/* Set FIFO threshold*/
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_FTH_MASK);
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->FIFOThresh);



		}



        /*Set Callback function */
		if(DMA_Cnfg->DMA_NUM == DMA_1)
		{
			GeneralCallBackFun[DMA_Cnfg->StreamNum] = DMA_Cnfg->CallBackFunc;

		}
		else if(DMA_Cnfg->DMA_NUM == DMA_2)
		{
			GeneralCallBackFun[(DMA_Cnfg->StreamNum)+DMA_STREAM_NUM] = DMA_Cnfg->CallBackFunc;

		}


        /* Set Interrupt status */
        /* Set Periphral Increment mode  */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_TCIE_MASK << DMA_TCIE_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->InterruptEnable << DMA_TCIE_SHIFT) ;


        /* DMA is IDLE*/
		DMA_StatusArr[DMA_Cnfg->DMA_NUM] = DMA_IS_IDLE;

    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR ;
    }
    
    

   
    return Local_u8ErrorState ;
}







uint8_t DMA_u8StartTransfer(DMA_Cnfg_T *DMA_Cnfg,uint32_t *Copy_pu32SrcAddress , uint32_t *Copy_pu32DestAddress , uint16_t Copy_u32DataSize)
{
    uint8_t Local_u8ErrorState = OK;

	if((DMA_Cnfg != NULL) && (Copy_pu32DestAddress != NULL) && (Copy_pu32SrcAddress != NULL) && (DMA_StatusArr[DMA_Cnfg->DMA_NUM] != DMA_IS_BUSY))
	{
        /* DMA is in busy state*/
		DMA_StatusArr[DMA_Cnfg->DMA_NUM] = DMA_IS_BUSY;


        /* Set Data transfer direction  */
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] &= ~(DMA_DIR_MASK << DMA_DIR_SHIFT) ;
        DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= (DMA_Cnfg->TransferMode << DMA_DIR_SHIFT) ;
 

        if (DMA_Cnfg->TransferMode == MEM_TO_PERIPH)
		{
			/* Set memory as source address*/
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SM0AR] = (uint32_t)Copy_pu32SrcAddress;

			/* Set peripheral as destination address*/
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SPAR]  = (uint32_t)Copy_pu32DestAddress;

		}

		else
		{
			/* Set peripheral as source address*/
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SPAR]  = (uint32_t)Copy_pu32SrcAddress;

			/* Set memory as destination address*/
			DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SM0AR] = (uint32_t)Copy_pu32DestAddress;

		}

		/* Set data size*/
		DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SNDTR] = 	Copy_u32DataSize;

		/*Clear interrupt status registers*/
		DMA_Arr[DMA_Cnfg->DMA_NUM]->ISR[0] = 0x00000000;
		DMA_Arr[DMA_Cnfg->DMA_NUM]->ISR[1] = 0x00000000;

		/*Enable Stream*/
		DMA_Arr[DMA_Cnfg->DMA_NUM]->STR[DMA_Cnfg->StreamNum][SCR] |= 1;


    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR ;
    }

    return Local_u8ErrorState ;    
}








void DMA1_Stream0_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[0] = 0xffffffff;

	GeneralCallBackFun[STREAM0]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;
}

void DMA1_Stream1_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM1]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;

}
void DMA1_Stream2_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM2]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;
}
void DMA1_Stream3_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM3]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;

}
void DMA1_Stream4_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM4]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;
}
void DMA1_Stream5_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM5]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;
}
void DMA1_Stream6_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM6]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;
}

void DMA1_Stream7_IRQHandler(void)
{
	/*Clear Flag*/
	DMA1->IFCR[1] = 0xffffffff;


	/* Call Callback Function*/
	GeneralCallBackFun[STREAM7]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_1] = DMA_IS_IDLE;
}

void DMA2_Stream0_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[(STREAM0 + DMA_STREAM_NUM)]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}
void DMA2_Stream1_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM1 + DMA_STREAM_NUM]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}
void DMA2_Stream2_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM2 + DMA_STREAM_NUM]();

	/* DMA is in IDLE state*/
	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}
void DMA2_Stream3_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[0] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM3 + DMA_STREAM_NUM]();

	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}
void DMA2_Stream4_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM4 + DMA_STREAM_NUM]();

	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}

void DMA2_Stream5_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM5 + DMA_STREAM_NUM]();

	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}
void DMA2_Stream6_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM6 + DMA_STREAM_NUM]();

	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}

void DMA2_Stream7_IRQHandler(void)
{
	/*Clear Flag*/
	DMA2->IFCR[1] = 0xffffffff;

	/* Call Callback Function*/
	GeneralCallBackFun[STREAM7 + DMA_STREAM_NUM]();

	DMA_StatusArr[DMA_2] = DMA_IS_IDLE;
}
