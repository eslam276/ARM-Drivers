


#include <stdint.h>
#include "defines.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"


static   USART_REG* USART_Index[6]={USART1,USART2,USART3,UART4,UART5,USART6};

uint8_t  USART_u8Init( USART_Cnfg_t * Copy_psCnfg )
{
   uint8_t Local_u8ErrorState = OK ;

   if (Copy_psCnfg != NULL)
   {

        /* Set Oversampling */
        CLR_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_OVER8);
        USART_Index[Copy_psCnfg->USART_Num]->CR1 |= Copy_psCnfg->OverSampling << CR1_OVER8 ;

        /* Select the wordlength  */
        CLR_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_WORDLENGTH);
        USART_Index[Copy_psCnfg->USART_Num]->CR1 |= Copy_psCnfg->Word << CR1_WORDLENGTH ;


        /* Set parity status  */
        CLR_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_PCE);
        USART_Index[Copy_psCnfg->USART_Num]->CR1 |= Copy_psCnfg->Parity << CR1_PCE ;



        /* Set RX TX state */

        switch (Copy_psCnfg->Mode)
        {
        case RX :
            CLR_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_TE);
            SET_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_RE);
            break;
        case TX :
            CLR_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_RE);
            SET_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_TE);
            break;
        case RX_TX :
            SET_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_RE);
            SET_BIT( USART_Index[Copy_psCnfg->USART_Num]->CR1  , CR1_TE);
            break;
        
        default:
            break;
        }




        /* Baudrate configurations */

		uint8_t Local_u8OverSampling ;
		if (Copy_psCnfg->OverSampling == OVER8 )
		{
			Local_u8OverSampling=8;
		}
		else
		{
			Local_u8OverSampling=16;
		}
		uint64_t Local_u64Mantissa = ( F_COLCK ) / ( (Local_u8OverSampling) * USART1_BAUD_RATE ) ;
		uint64_t Local_u64Fraction = ( ( ( F_COLCK * 100 ) / ( (Local_u8OverSampling) * USART1_BAUD_RATE )  ) % 100 ) * (Local_u8OverSampling) ;

		if( Local_u64Fraction > USART_MAX_FRAC )
		{
			Local_u64Mantissa += USART_MANTISSA ;
			Local_u64Fraction  = USART_FRACTION ;
		}
		USART_Index[Copy_psCnfg->USART_Num] -> BRR = ( Local_u64Mantissa << USART_BAUD_RATE_ACCESS  ) | ( Local_u64Fraction / 100 ) ;
		


        
        /* Enable USART */
		SET_BIT ( USART_Index[Copy_psCnfg->USART_Num] -> CR1 , USART_CR1_UE );
	



   }
   else
   {
        Local_u8ErrorState = NULL_PTR_ERR ;
   }
   
   

   return Local_u8ErrorState ;
    
}



uint8_t  USART_u8ReceiveCharSynch     ( USART_NUM_t Copy_USARTindex , uint8_t * Copy_pu8DataChar  )
{
	uint8_t Local_u8ErrorState = OK ;
	if ( Copy_pu8DataChar != NULL )
	{
		CLR_BIT( USART_Index[Copy_USARTindex] -> SR , USART_SR_RXNE );
	    while ( USART_SR_RXNE_DOWN_MASK == GET_BIT ( USART_Index[Copy_USARTindex] -> SR , USART_SR_RXNE ) )  ;
	    *Copy_pu8DataChar = ( USART_Index[Copy_USARTindex] -> DR )  ;
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}
	return Local_u8ErrorState ;
}





void  USART_voidTransmitCharSynch     ( USART_NUM_t Copy_USARTindex , uint8_t  Copy_u8DataChar  )
{
	
		USART_Index[Copy_USARTindex] -> DR = Copy_u8DataChar ;
		while ( USART_SR_TC_MASK == GET_BIT( USART_Index[Copy_USARTindex] -> SR , USART_SR_TC ) )  ;
		CLR_BIT( USART_Index[Copy_USARTindex] -> SR , USART_SR_TC );
	
}