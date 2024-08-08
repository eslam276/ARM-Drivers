/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: NVIC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/


#include <stdint.h>
#include "NVIC_interface.h"
#include "NVIC_reg.h"
#include "NVIC_private.h"






void INT_Enable(INTReq_Num_t IREQ_Num)

{
    uint8_t RegNum ;
    uint8_t BitNum ;

    RegNum = IREQ_Num / REG_DIVISION_FACTOR ;
    BitNum = IREQ_Num % REG_DIVISION_FACTOR ;


    NVIC->SETENA[RegNum] &= (1<< BitNum);
}











void INT_Disable(INTReq_Num_t IREQ_Num)
{
    uint8_t RegNum ;
    uint8_t BitNum ;

    RegNum = IREQ_Num / REG_DIVISION_FACTOR ;
    BitNum = IREQ_Num % REG_DIVISION_FACTOR ;


    NVIC->CLRENA[RegNum] &= (1<< BitNum);
}


void SetPendingFlag(INTReq_Num_t IREQ_Num)
{
    uint8_t RegNum ;
    uint8_t BitNum ;

    RegNum = IREQ_Num / REG_DIVISION_FACTOR ;
    BitNum = IREQ_Num % REG_DIVISION_FACTOR ;


    NVIC->SETPEND[RegNum] &= (1<< BitNum);
}



void CLRPendingFlag(INTReq_Num_t IREQ_Num)
{
    uint8_t RegNum ;
    uint8_t BitNum ;

    RegNum = IREQ_Num / REG_DIVISION_FACTOR ;
    BitNum = IREQ_Num % REG_DIVISION_FACTOR ;


    NVIC->CLRPEND[RegNum] &= (1<< BitNum);
}



ActiveFlagStatus_t GetActiveFlag(INTReq_Num_t IREQ_Num)
{
    uint8_t RegNum ;
    uint8_t BitNum ;

    uint8_t FlagStatus ;

    RegNum = IREQ_Num / REG_DIVISION_FACTOR ;
    BitNum = IREQ_Num % REG_DIVISION_FACTOR ;


    if ( (  (NVIC->ACTIVE[RegNum] >> BitNum) & 1 )  ==  0  )
    {
        FlagStatus = NOT_ACTIVE ;
    }
    else
    {
        FlagStatus = NOT_ACTIVE ;
    }
    
    return FlagStatus ;
}



void NVIC_voidSetIRQPriority (INTReq_Num_t IREQ_Num , uint8_t Priority)
{
    NVIC->IPR[IREQ_Num] = Priority << IPR_SHIFT ;
}
   
