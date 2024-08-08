/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: GPIO				**************/
/********************		Version: 1.00			**************/
/********************		Date: 31-8-2023			**************/
/*****************************************************************/
/*****************************************************************/


#include <stdint.h>
#include <Library/STM32F446.h>
#include <Library/BIT_MATH.h>
#include <Library/defines.h>

#include "Inc/GPIO_private.h"
#include "Inc/GPIO_interface.h"



static GPIO_REG_t* GPIOPort[GPIO_PERIPHRAL_NUM] = { GPIOA , GPIOB , GPIOC , GPIOD , GPIOE , GPIOF , GPIOG , GPIOH };





/*===============================================================================================================*/
/********************************************************************************************
 * @fn  GPIO_u8PinInit
 * @brief the function initialises the GPIO pin according to the input parameters
 * 
 * @param[in] PinCFG : The initializations values of the pin
 * @retval ErrorStatus
 * @return uint8_t 
 *********************************************************************************************
 */
/*===============================================================================================================*/


uint8_t GPIO_u8PinInit (const GPIO_PIN_CFG_t* PinCFG )
{
    uint8_t Local_u8ErrorState = OK ;

    if (PinCFG != NULL)
    {

        /* You should check All Variables */
       if ((PinCFG->Port <= PORTH) && (PinCFG->PinNum <= PIN15))
       {
            /* Selsect GPIO mode : Input , Output , Analog , Alternate Function */
            (GPIOPort[PinCFG->Port]->MODER) &= ~(MODER_MASK << ((PinCFG->PinNum) * MODER_PIN_ACCESS)); /* Clear the mode bits*/
            (GPIOPort[PinCFG->Port]->MODER) |=  ( (PinCFG->Mode) << (PinCFG->PinNum) * MODER_PIN_ACCESS );

            /* Select GPIO pull state : Pullup , pulldown , no pull */
            (GPIOPort[PinCFG->Port]->PUPDR) &= ~(PUPDR_MASK << ((PinCFG->PinNum) * PUPDR_PIN_ACCESS));
            (GPIOPort[PinCFG->Port]->PUPDR) |=  ( (PinCFG->PullType) << (PinCFG->PinNum) * PUPDR_PIN_ACCESS );


            /* Select output type and output speed in case of general purpose output or alternate function */
            if ((PinCFG->Mode == OUTPUT) || (PinCFG->Mode == ALTERNATIVE_FUNCTION))
            {
                /* select output type : Push pull , op(en drain  */
                 (GPIOPort[PinCFG->Port]->OTYPER) &= ~( OTYPER_MASK << (PinCFG->PinNum));
                 (GPIOPort[PinCFG->Port]->OTYPER) |=  ( (PinCFG->OutputType)  << (PinCFG->PinNum) );

                /* Select output speed : Low Meduim High Fast */
                  (GPIOPort[PinCFG->Port]->OSPEEDER) &= ~(OSPEEDER_MASK << ((PinCFG->PinNum) * OSPEEDER_PIN_ACCESS)); 
                  (GPIOPort[PinCFG->Port]->OSPEEDER) |=  ((PinCFG->Speed) << ((PinCFG->PinNum) * OSPEEDER_PIN_ACCESS));
            
                /* Select the pin alternative function */
                if ((PinCFG->Mode == ALTERNATIVE_FUNCTION))
                {
                    uint8_t Local_u8RegNum = (PinCFG->PinNum) / AFR_PIN_SHIFTING ;
                    uint8_t Local_u8BitNum = (PinCFG->PinNum) % AFR_PIN_SHIFTING ;

                    (GPIOPort[PinCFG->Port]->AFR[Local_u8RegNum]) &= ~(AFR_MASK << (Local_u8BitNum * AFR_PIN_ACCESS) );
                    (GPIOPort[PinCFG->Port]->AFR[Local_u8RegNum]) |=  (( PinCFG->AltFunc) << (Local_u8BitNum * AFR_PIN_ACCESS) );
                    
                }
                
            }

            





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














/*===============================================================================================================*/
/********************************************************************************************
 * @fn  GPIO_u8SetPinValue
 * @brief the function set the GPIO pin value according to the input parameters
 * 
 * @param[in] Port :    the port num of required pin , get options @Port_t enum 
 * @param[in] PINNUM :  the pin which we want to set it's value , grt options @Pin_t enum
 * @param[in] Value : the value we want to set to the pin , grt options @Pin_Value_t enum
 * @retval ErrorStatus
 * @return uint8_t 
 *********************************************************************************************
 */
/*===============================================================================================================*/


uint8_t GPIO_u8SetPinValue (Port_t Port , Pin_t PinNum , Pin_Value_t Value )
{
    uint8_t Local_u8ErrorState = OK ;

    if ((Port <= PORTH) && (PinNum <= PIN15))
    {
        if (Value == LOW)
        {
            GPIOPort[Port]->ODR &= ~(1<<PinNum) ;
            /* GPIOPort[Port]->BSRR = 1<< 16 + PinNum ; */
        }
        else if (Value == HIGH)
        {
            GPIOPort[Port]->ODR |= (1<<PinNum) ;
            /* GPIOPort[Port]->BSRR = 1<<  PinNum ; */
        }
        else
        {
            Local_u8ErrorState = NOK ;
        }
        
    }
    else
    {
        Local_u8ErrorState = NOK ;
    }
    





    return Local_u8ErrorState ;

}






uint8_t GPIO_u8TogglePinValue (Port_t Port , Pin_t PinNum )
{
    uint8_t Local_u8ErrorState = OK ;

    if ((Port < PORTH) && (PinNum < PIN15))
    {
        TOG_BIT(GPIOPort[Port]->ODR,PinNum);
    }
    else
    {
        Local_u8ErrorState = NOK ;
    }
    



    return Local_u8ErrorState ;

}


uint8_t GPIO_u8ReadPinValue (Port_t Port , Pin_t PinNum , uint8_t * Value )
{
    uint8_t Local_u8ErrorState = OK ;

    if ((Port < PORTH) && (PinNum < PIN15))
    {
        if (Value != NULL)
        {
            *Value = GET_BIT(GPIOPort[Port]->IDR,PinNum);
        }
        else
        {
            Local_u8ErrorState = NULL_PTR_ERR ;
        }
        
        
    }
    else
    {
        Local_u8ErrorState = NOK ;
    }
    



    return Local_u8ErrorState ;
}

