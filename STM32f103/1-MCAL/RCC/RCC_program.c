/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: RCC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 27-8-2023			**************/
/*****************************************************************/
/*****************************************************************/

#include <stdint.h>

#include "BIT_MATH.h"
#include "defines.h"

#include "RCC_interface.h"
#include "RCC_register.h"
#include "RCC_private.h"
#include "RCC_config.h"



uint8_t RCC_u8SetClkStatus(CLK_t Cpoy_Clock , status_t Copy_Status)
{
	uint8_t Local_u8ErrorState = OK ;
	uint32_t Local_u32Time = TIME_OUT ;

	switch (Cpoy_Clock)
	{

	case HSE:

		if (Copy_Status == ON)
		{
			/* Enable HSE */
			SET_BIT(RCC->RCC_CR,RCC_CR_HSEON);

			/* Wait until HSE is Ready or Timeout */
			while ( ( (GET_BIT(RCC->RCC_CR,RCC_CR_HSERDY)) == 0 )  && (Local_u32Time > 0) )
			{
				Local_u32Time--;
			}

			if (Local_u32Time == 0 )
			{
				Local_u8ErrorState =  TIMEOUT_ERR ;
			}
			else
			{
				
			}
			
		}
		else if (Copy_Status == OFF)
		{
			/* Disable HSE */
			CLR_BIT(RCC->RCC_CR,RCC_CR_HSEON);
		}
		
		
		break;


	case HSI:
		if (Copy_Status == ON)
		{
			/* Enable HSI */
			SET_BIT(RCC->RCC_CR,RCC_CR_HSION);

			/* Wait until HSI is ready or Timeout */
			while ( ( (GET_BIT(RCC->RCC_CR,RCC_CR_HSIRDY)) == 0 )  && (Local_u32Time > 0) )
			{
				Local_u32Time--;
			}

			if (Local_u32Time == 0 )
			{
				Local_u8ErrorState =  TIMEOUT_ERR ;
			}
			else
			{
				
			}
			
		}
		else if (Copy_Status == OFF)
		{
			/* Disable HSI */
			CLR_BIT(RCC->RCC_CR,RCC_CR_HSION);
		}
		break;


	case PLL:
		if (Copy_Status == ON)
		{
			/* Enable PLL */
			SET_BIT(RCC->RCC_CR,RCC_CR_PLLON);

			/* Wait ubtil PLL is ready or timeout */
			while ( ( (GET_BIT(RCC->RCC_CR,RCC_CR_PLLRDY)) == 0 )  && (Local_u32Time > 0) )
			{
				Local_u32Time--;
			}

			if (Local_u32Time == 0 )
			{
				Local_u8ErrorState =  TIMEOUT_ERR ;
			}
			else
			{
				
			}
			
			
			
		}
		else if (Copy_Status == OFF)
		{
			/* Disable PLL */
			CLR_BIT(RCC->RCC_CR,RCC_CR_PLLON);
		}
		break;
	
	
	default:
		break;
	}


	return Local_u8ErrorState ;
}






void RCC_voidSetSystemClock(CLK_t Cpoy_Clock)
{

	switch (Cpoy_Clock)
	{
	case HSI:
		CLR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW0);
		CLR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW1);
		break;
	case HSE:
		SET_BIT(RCC->RCC_CFGR,RCC_CFGR_SW0);
		CLR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW1);
		break;
	case PLL:
		CLR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW0);
		SET_BIT(RCC->RCC_CFGR,RCC_CFGR_SW1);
		break;
	
	default:
		break;
	}

}


void RCC_voidHSEConfig(HSE_Config_t Copy_Cfg)
{

	if (Copy_Cfg == devided_by_2)
	{
		SET_BIT(RCC->RCC_CFGR,RCC_CFGR_PLLXTPRE);
	}
	else if (Copy_Cfg == Not_Devided)
	{
		CLR_BIT(RCC->RCC_CFGR,RCC_CFGR_PLLXTPRE);
	}
	
	
}

void RCC_voidPLLConfig(PLL_Config_t Copy_Cfg , PLL_Config_t Copy_PLLSRC)
{
	/* Clear the cfg bits in the register 18 , 19 , 20 , 21 */

	CLR_BIT(RCC->RCC_CFGR,18);
	CLR_BIT(RCC->RCC_CFGR,19);
	CLR_BIT(RCC->RCC_CFGR,20);
	CLR_BIT(RCC->RCC_CFGR,21);

	/* set the cfg value in the register */

	RCC->RCC_CFGR |= ( Copy_Cfg << 18 );


	/* select PLL source */

	if (Copy_PLLSRC == HSI_devided_by2)
	{
		CLR_BIT(RCC->RCC_CFGR,RCC_CFGR_PLLSRC);
	}
	else if (Copy_PLLSRC == HSE_)
	{
		SET_BIT(RCC->RCC_CFGR,RCC_CFGR_PLLSRC);
	}
	
	

}




void RCC_voidAHBEnable(Peripherals_t Copy_Periphral)
{
	SET_BIT(RCC->RCC_AHBENR,Copy_Periphral);
}
void RCC_voidAHBDisble(Peripherals_t Copy_Periphral)
{
	CLR_BIT(RCC->RCC_AHBENR,Copy_Periphral);
}


void RCC_voidAPB1Enable(Peripherals_t Copy_Periphral)
{
	SET_BIT(RCC->RCC_APB1ENR,Copy_Periphral);
}
void RCC_voidAPB1Disble(Peripherals_t Copy_Periphral)
{
	CLR_BIT(RCC->RCC_APB1ENR,Copy_Periphral);
}



void RCC_voidAPB2Enable(Peripherals_t Copy_Periphral)
{
	SET_BIT(RCC->RCC_APB2ENR,Copy_Periphral);
}
void RCC_voidAPB2Disble(Peripherals_t Copy_Periphral)
{
	CLR_BIT(RCC->RCC_APB2ENR,Copy_Periphral);
}



