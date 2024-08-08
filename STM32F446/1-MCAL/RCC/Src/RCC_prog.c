/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: RCC_prog.c		    *******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#include <stdint.h>
#include "BIT_MATH.h"
#include "library/STM32F446.h"
#include "defines.h"

#include "Inc/RCC_interface.h"
#include "RCC_priv.h"

uint8_t RCC_Set_CLK_Status(RCC_ClkType_t Copy_enClkType,RCC_ClkStatus_t Copy_enClkStatus)
{
	 RCC_ClkType_t RCC_enSystemClk;
	 uint8_t Local_enError = OK;
     uint32_t Local_u32TimeoutCounter = 0;
	   RCC_enSystemClk = (RCC_SYS_CLK_STATUSMASK & RCC->CFGR)>>2 ; /*Get the system clock*/
	   if (Copy_enClkStatus == ON)
	   {
		   switch(Copy_enClkType)
		   {
		   case PLL :
		   {
			   SET_BIT(RCC->CR,CR_PLLON) ;  /*enable PLL clock*/
			   while((GET_BIT(RCC->CR,CR_PLLRDY) != 1) && Local_u32TimeoutCounter <= RCC_CLKTIMEOUT)    /*Waiting enable flag*/
			   {
				   Local_u32TimeoutCounter++;
			   }
		   }break;
		   case HSE :
		   {
			   SET_BIT(RCC->CR,CR_HSEON) ;  /*enable HSE clock*/
			   while((GET_BIT(RCC->CR,CR_HSERDY) != 1) && Local_u32TimeoutCounter <= RCC_CLKTIMEOUT)    /*Waiting enable flag*/
			   {
				   Local_u32TimeoutCounter++;
			   }
		   }break;
		   case HSI :
		   {
			   SET_BIT(RCC->CR,CR_HSION) ;  /*enable HSI clock*/
			   while((GET_BIT(RCC->CR,CR_HSIRDY) != 1) && Local_u32TimeoutCounter <= RCC_CLKTIMEOUT)    /*Waiting enable flag*/
			   {
				   Local_u32TimeoutCounter++;
			   }
		   }break;
		   }
	   }
	   else if (Copy_enClkStatus == OFF)
	   {
		   switch (Copy_enClkType)
		   {
		   case PLL :
		   {
			   if(RCC_enSystemClk != PLL)
			   {
				   CLR_BIT(RCC->CR,CR_PLLON) ;  /*Disable PLL clock*/
			   }
			   else
			   {
				   Local_enError = CLK_DisableFail; /* PLL is the system clock can't be disabled*/
			   }
		   }break;
		   case HSI :
		   {
		   if(RCC_enSystemClk != HSI)
		   {
			   CLR_BIT(RCC->CR,CR_HSION) ;  /*Disable HSI clock*/
		   }
		   else
		   {
			   Local_enError = CLK_DisableFail; /* HSI is the system clock can't be disabled*/
		   }
		   }break;
		   case HSE :
		   {
			   if(RCC_enSystemClk != HSE)
			   {
				   CLR_BIT(RCC->CR,CR_HSEON) ;  /*Disable HSE clock*/
			   }
			   else
			   {
				   Local_enError = CLK_DisableFail; /* HSE is the system clock can't be disabled*/
			   }
		   }
		   }
	   }

  if(Local_u32TimeoutCounter >= RCC_CLKTIMEOUT)
  {
	   Local_enError = CLK_EnableTimeout ;
  }

return Local_enError;
}

void RCC_Set_SysClk(RCC_SysClkType_t Copy_enClkType)
{
	RCC->CFGR &= RCC_SYS_CLK_STATUSMASK;
	RCC->CFGR |= Copy_enClkType;
}

uint8_t RCC_ClkCfg(const RCC_ClkCf_t* Copy_stClkCfg)
{
	uint8_t Local_u8ErrorStatu = OK;
	if(Copy_stClkCfg != NULL)
	{
       if((Copy_stClkCfg->PLLDiv_Factor > PLLMULL_FACTOR_MAX) || (Copy_stClkCfg->PLLDiv_Factor > PLLMULL_FACTOR_MIN)
    		  || (Copy_stClkCfg->PLLInputDiv_Factor < 2))
       {
    	   Local_u8ErrorStatu = CLK_CFG_ERR;
       }
       else
       {
           RCC->PLLCFGR &= PLLMULL_FACTOR_MASK;
           RCC->PLLCFGR |= Copy_stClkCfg->PLLMull_Factor <<6;

           RCC->PLLCFGR &= PLLINPUT_DIVFACTOR_MASK;
           RCC->PLLCFGR |= Copy_stClkCfg->PLLInputDiv_Factor;

           RCC->PLLCFGR &= PLLDIVFACTOT_MASK;
           RCC->PLLCFGR |= Copy_stClkCfg->PLLDiv_Factor <<16;

           RCC->PLLCFGR &= ~(1 << PLLCFGR_PLLSRC);
           RCC->PLLCFGR |= Copy_stClkCfg->Clk_Src << PLLCFGR_PLLSRC;
       }
	}
	else
	{
		Local_u8ErrorStatu = NULL_PTR_ERR;
	}
	return Local_u8ErrorStatu;
}

void RCC_AHB1ResetClk(RCC_AHB1ENR_t Copy_enPeripheral)
{
	if((Copy_enPeripheral != AHB1_BKPSRAM) && (Copy_enPeripheral != AHB1_OTGHSULPI))
	{
		RCC->AHB1RSTR |= (1 << Copy_enPeripheral);
	}
	else
	{
		/*Do nothing*/
	}
}
void RCC_AHB2ResetClk(RCC_AHB2ENR_t Copy_enPeripheral)
{
	RCC->AHB2RSTR |= (1 << Copy_enPeripheral);
}
void RCC_AHB3ResetClk(RCC_AHB3ENR_t Copy_enPeripheral)
{
	RCC->AHB3RSTR |= (1 << Copy_enPeripheral);
}
void RCC_APB1ResetClk(RCC_APB1ENR_t Copy_enPeripheral)
{
	RCC->APB1RSTR |= (1 << Copy_enPeripheral);
}
void RCC_APB2ResetClk(RCC_APB2ENR_t Copy_enPeripheral)
{
	RCC->APB2RSTR |= (1 << Copy_enPeripheral);
}
void RCC_AHB1EnableClk(RCC_AHB1ENR_t Copy_enPeripheral)
{
     RCC->AHB1ENR |= (1 << Copy_enPeripheral);
}
void RCC_AHBD1isableClk(RCC_AHB1ENR_t Copy_enPeripheral)
{
	RCC->AHB1ENR &= ~(1 << Copy_enPeripheral);
}
void RCC_AHB2EnableClk(RCC_AHB2ENR_t Copy_enPeripheral)
{
    RCC->AHB2ENR |= (1 << Copy_enPeripheral);
}
void RCC_AHB2DisableClk(RCC_AHB2ENR_t Copy_enPeripheral)
{
	RCC->AHB2ENR &= ~(1 << Copy_enPeripheral);
}
void RCC_AHB3EnableClk(RCC_AHB3ENR_t Copy_enPeripheral)
{
	RCC->AHB3ENR |= (1 << Copy_enPeripheral);
}
void RCC_AHB3DisableClk(RCC_AHB3ENR_t Copy_enPeripheral)
{
	RCC->AHB3ENR &= ~(1 << Copy_enPeripheral);
}
void RCC_APB1Enable(RCC_APB1ENR_t Copy_enPeripheral)
{
	RCC->APB1ENR |= (1 << Copy_enPeripheral);
}
void RCC_APB1Disable(RCC_APB1ENR_t Copy_enPeripheral)
{
	RCC->APB1ENR &= ~(1 << Copy_enPeripheral);
}
void RCC_APB2Enable(RCC_APB2ENR_t Copy_enPeripheral)
{
	RCC->APB2ENR |= (1 << Copy_enPeripheral);
}
void RCC_APB2Disable(RCC_APB2ENR_t Copy_enPeripheral)
{
	RCC->APB2ENR &= ~(1 << Copy_enPeripheral);
}
