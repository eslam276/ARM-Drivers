/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: EXTI				**************/
/********************		Version: 1.00			**************/
/********************		Date: 16-10-2023		**************/
/*****************************************************************/
/*****************************************************************/




#include <stdint.h>
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "defines.h"
#include "BIT_MATH.h"

/* Global array of ptr to function to carry callback functions */
static void ( *EXTI_CallBack[16] )(void) = {NULL};


uint8_t EXTI_u8Init(EXTI_Config_t * Copy_stConfig)
{

    uint8_t Local_u8ErrorState = OK ;

    if ( Copy_stConfig != NULL )
    {


        
        /* Set trigger source */

        switch (Copy_stConfig->Trigger_Config)
        {

            case EXTI_RISING_EDGE:
                SET_BIT(EXTI->EXTI_RTSR , Copy_stConfig->EXTI_Num);
                CLR_BIT(EXTI->EXTI_FTSR , Copy_stConfig->EXTI_Num);
                break;

            case EXTI_FALLING_EDGE:
                SET_BIT(EXTI->EXTI_FTSR , Copy_stConfig->EXTI_Num);
                CLR_BIT(EXTI->EXTI_RTSR , Copy_stConfig->EXTI_Num);
                break;

            case EXTI_RISING_FALLING_EDGE:
                SET_BIT(EXTI->EXTI_RTSR , Copy_stConfig->EXTI_Num);
                SET_BIT(EXTI->EXTI_FTSR , Copy_stConfig->EXTI_Num);
                break;
            
            default: Local_u8ErrorState = NOK ;
                break;
        }




        /* Set callback function */

        if (Copy_stConfig->CallBack != NULL)
        {
            EXTI_CallBack[Copy_stConfig->EXTI_Num]= Copy_stConfig->CallBack ;
        }
        else
        {
            Local_u8ErrorState = NULL_PTR_ERR ;
        }
        
        


        /* Set enable state */

        if (Copy_stConfig->Enable_Config == EXTI_ENABLE)
        {
           SET_BIT( EXTI->EXTI_EMR , Copy_stConfig->EXTI_Num);
        }
        else if (Copy_stConfig->Enable_Config == EXTI_DISABLE)
        {
            CLR_BIT( EXTI->EXTI_EMR , Copy_stConfig->EXTI_Num);
        }
        else
        {
            Local_u8ErrorState = NOK ;
        }



    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR ;
    }
    
    
    return Local_u8ErrorState ;
}



uint8_t EXTI_u8SetTriggerSrc(EXTI_Trigger_t Trigger_Config ,EXTI_Number_t Copy_enINTNum )
{
     uint8_t   Local_u8ErrorState = OK ;

    switch (Trigger_Config)
        {

            case EXTI_RISING_EDGE:
                SET_BIT(EXTI->EXTI_RTSR , Copy_enINTNum);
                CLR_BIT(EXTI->EXTI_FTSR , Copy_enINTNum);
                break;

            case EXTI_FALLING_EDGE:
                SET_BIT(EXTI->EXTI_FTSR , Copy_enINTNum);
                CLR_BIT(EXTI->EXTI_RTSR , Copy_enINTNum);
                break;

            case EXTI_RISING_FALLING_EDGE:
                SET_BIT(EXTI->EXTI_RTSR , Copy_enINTNum);
                SET_BIT(EXTI->EXTI_FTSR , Copy_enINTNum);
                break;
            
            default: Local_u8ErrorState = NOK ;
                break;
        }




     return Local_u8ErrorState ;
}










uint8_t EXTI_u8Enable_INT(EXTI_Number_t Copy_enINTNum)
{

    uint8_t   Local_u8ErrorState = OK ;

    if ( Copy_enINTNum <= EXTI_15)
    {
        SET_BIT( EXTI->EXTI_EMR , Copy_enINTNum) ;
    }
    else
    {
        Local_u8ErrorState = NOK ;
    }
    
    
     return Local_u8ErrorState ;
}




uint8_t EXTI_u8Disable_INT(EXTI_Number_t Copy_enINTNum)
{

    uint8_t   Local_u8ErrorState = OK ;

    if ( Copy_enINTNum <= EXTI_15)
    {
        CLR_BIT( EXTI->EXTI_EMR , Copy_enINTNum) ;
    }
    else
    {
        Local_u8ErrorState = NOK ;
    }
    
    
     return Local_u8ErrorState ;

}



uint8_t EXTI_u8GetPendingFlag(EXTI_Number_t Copy_enINTNum,uint8_t* Copy_pValue)
{
    uint8_t   Local_u8ErrorState = OK ;

    if (Copy_pValue != NULL)
    {
        *Copy_pValue =  GET_BIT( EXTI->EXTI_PR , Copy_enINTNum ) ;

    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR ;
    }

    return Local_u8ErrorState ;
    
}



uint8_t EXTI_u8ClearPendingFlag(EXTI_Number_t Copy_enINTNum)
{

     uint8_t   Local_u8ErrorState = OK ;

    if (Copy_enINTNum <= EXTI_15 )
    {
       SET_BIT( EXTI->EXTI_PR , Copy_enINTNum ) ;

    }
    else
    {
        Local_u8ErrorState = NOK ;
    }

    return Local_u8ErrorState ;

}





void EXTI0_IRQHandler(void)
{

	EXTI_u8ClearPendingFlag(EXTI_0);

    if ( EXTI_CallBack[EXTI_0] != NULL )
    {
        EXTI_CallBack[EXTI_0]();
    }
    
	
}
void EXTI1_IRQHandler(void)
{
	EXTI_u8ClearPendingFlag(EXTI_1);
	 if ( EXTI_CallBack[EXTI_1] != NULL )
    {
        EXTI_CallBack[EXTI_1]();
    }
}
void EXTI2_IRQHandler(void)
{
	EXTI_u8ClearPendingFlag(EXTI_2);
	 if ( EXTI_CallBack[EXTI_2] != NULL )
    {
        EXTI_CallBack[EXTI_2]();
    }
}
void EXTI3_IRQHandler(void)
{
	EXTI_u8ClearPendingFlag(EXTI_3);
	 if ( EXTI_CallBack[EXTI_3] != NULL )
    {
        EXTI_CallBack[EXTI_3]();
    }
}
void EXTI4_IRQHandler(void)
{
	EXTI_u8ClearPendingFlag(EXTI_4);
	if ( EXTI_CallBack[EXTI_4] != NULL )
    {
        EXTI_CallBack[EXTI_4]();
    }
}
void EXTI9_5_IRQHandler(void)
{
	if(((EXTI->EXTI_PR)>>EXTI_5 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_5);
		if ( EXTI_CallBack[EXTI_5] != NULL )
        {
            EXTI_CallBack[EXTI_5]();
        }

	}
	if(((EXTI->EXTI_PR)>>EXTI_6 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_6);
		if ( EXTI_CallBack[EXTI_6] != NULL )
        {
            EXTI_CallBack[EXTI_6]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_7 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_7);
		if ( EXTI_CallBack[EXTI_7] != NULL )
        {
            EXTI_CallBack[EXTI_7]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_8 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_8);
		if ( EXTI_CallBack[EXTI_8] != NULL )
        {
            EXTI_CallBack[EXTI_8]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_9 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_9);
		if ( EXTI_CallBack[EXTI_9] != NULL )
        {
            EXTI_CallBack[EXTI_9]();
        }
	}
}



void EXTI15_10_IRQHandler(void)
{
	if(((EXTI->EXTI_PR)>>EXTI_10 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_10);
		if ( EXTI_CallBack[EXTI_10] != NULL )
        {
            EXTI_CallBack[EXTI_10]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_11 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_11);
		if ( EXTI_CallBack[EXTI_11] != NULL )
        {
            EXTI_CallBack[EXTI_11]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_12 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_12);
		if ( EXTI_CallBack[EXTI_12] != NULL )
        {
            EXTI_CallBack[EXTI_12]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_13 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_13);
		if ( EXTI_CallBack[EXTI_13] != NULL )
        {
            EXTI_CallBack[EXTI_13]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_14 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_14);
		if ( EXTI_CallBack[EXTI_14] != NULL )
        {
            EXTI_CallBack[EXTI_14]();
        }
	}
	if(((EXTI->EXTI_PR)>>EXTI_15 & 1) == 1)
	{
		EXTI_u8ClearPendingFlag(EXTI_15);
		if ( EXTI_CallBack[EXTI_15] != NULL )
        {
            EXTI_CallBack[EXTI_15]();
        }
	}
}

