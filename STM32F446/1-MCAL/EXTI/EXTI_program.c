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


static void (* EXTI_voidCallback[23] )(void) = {NULL};


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
                break;
            case EXTI_FALLING_EDGE:
                SET_BIT(EXTI->EXTI_FTSR , Copy_stConfig->EXTI_Num);
                break;
            case EXTI_RISING_FALLING_EDGE:
                SET_BIT(EXTI->EXTI_RTSR , Copy_stConfig->EXTI_Num);
                SET_BIT(EXTI->EXTI_FTSR , Copy_stConfig->EXTI_Num);
                break;
            
            default:
                break;
        }




        /* Set callback function */

        if (Copy_stConfig->CallBack != NULL)
        {
            EXTI_voidCallback[Copy_stConfig->EXTI_Num]= Copy_stConfig->CallBack ;
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



    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR ;
    }
    
    
    return Local_u8ErrorState ;
}











uint8_t EXTI_u8Enable_INT(EXTI_Number_t Copy_enINTNum)
{

    uint8_t   Local_u8ErrorState = OK ;

    if ( Copy_enINTNum <= EXTI_22)
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

    if ( Copy_enINTNum <= EXTI_22)
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

    if (Copy_enINTNum <= EXTI_22 )
    {
       SET_BIT( EXTI->EXTI_PR , Copy_enINTNum ) ;

    }
    else
    {
        Local_u8ErrorState = NOK ;
    }

    return Local_u8ErrorState ;

}
