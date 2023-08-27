#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_register.h"
#include "RCC_private.h"
#include "RCC_config.h"

/* we want to initialize clock source */
void RCC_voidInit(void) {

	RCC_CR = 0;
	RCC_CFGR = 0;

/* Enabling or Disabling the clock sources */
#if RCC_HSI_EN == ENABLE
	SET_BIT(RCC_CR, RCC_CR_HSION);
	while ((GET_BIT(RCC_CR, RCC_CR_HSIRDY)) == 0)
		;
#else
	CLR_BIT(RCC_CR, RCC_CR_HSION);
#endif

#if RCC_HSE_EN == ENABLE
	SET_BIT(RCC_CR, RCC_CR_HSEON);
	while ((GET_BIT(RCC_CR, RCC_CR_HSERDY)) == 0)
		;
#else
	CLR_BIT(RCC_CR, RCC_CR_HSEON);
#endif

#if RCC_PLL_EN == ENABLE
	SET_BIT(RCC_CR, RCC_CR_PLLON);
	while( (GET_BIT(RCC_CR, RCC_CR_PLLRDY)) == 0);
#else
	CLR_BIT(RCC_CR, RCC_CR_PLLON);
#endif

/* Applying the user defined trim value */
	if (RCC_TRIMMING_VALUE < 32)
		RCC_CR |= (RCC_TRIMMING_VALUE << RCC_CR_HSITRIM);

/* Enabling Bypass if HSE is RC */
#if RC_HSE_BYPASS == ENABLE
	SET_BIT(RCC_CR,RCC_CR_HSEBYP);
#elif RC_HSE_BYPASS == DISABLE
	CLR_BIT(RCC_CR, RCC_CR_HSEBYP);
#endif

/* Enabling Clock Security */
#if RCC_CSS_ENABLE == ENABLE
	SET_BIT(RCC_CR, RCC_CR_CSSON);
#elif RCC_CSS_ENABLE == DISABLE
	CLR_BIT(RCC_CR, RCC_CR_CSSON);
#endif

/* Selecting the user defined system clock */
RCC_CFGR |= (RCC_SYSTEM_CLOCK - 5) << RCC_CFGR_SW;

/* Applying the user defined AHB prescalar */
RCC_CFGR |= RCC_AHB_PRESCALAR << RCC_CFGR_HPRE;

/* Applying the user defined APB1 prescalar */
if ( RCC_APB1_PRESCALAR == NONE)
	RCC_CFGR |= RCC_APB1_PRESCALAR << RCC_CFGR_PPRE1;
else
	RCC_CFGR |= (RCC_APB1_PRESCALAR - 4) << RCC_CFGR_PPRE1;

/* Applying the user defined APB2 prescalar */
if ( RCC_APB2_PRESCALAR == NONE)
	RCC_CFGR |= RCC_APB2_PRESCALAR << RCC_CFGR_PPRE2;
else
	RCC_CFGR |= (RCC_APB2_PRESCALAR - 4) << RCC_CFGR_PPRE2;

/* Applying the user defined ADC prescalar */
RCC_CFGR |= (RCC_ADC_PRESCALAR - 8) << RCC_CFGR_ADCPRE;

/* Selecting the user defined PLL Source */
RCC_CFGR |= RCC_PLL_SRC << RCC_CFGR_PLLSRC;

/* Applying prescalar to HSE when selected as PLL source, if any */
RCC_CFGR |= RCC_PLL_HSE_DIV << RCC_CFGR_PLLXTPRE;

/* Applying the PPL multiplication factor */
RCC_CFGR |= RCC_PLL_MUL << RCC_CFGR_PLLMUL;

/* Selecting the microcontroller output clock source, if any */
RCC_CFGR |= RCC_MCO_SRC << RCC_CFGR_MCO;
}

u8 RCC_u8EnablePeripheralClock(Peripherals_t Copy_u8PeripheralName) {

	u8 Local_u8ErrorState = OK;

	if (Copy_u8PeripheralName < 11)
		SET_BIT(RCC_AHBENR, Copy_u8PeripheralName);
	else if (Copy_u8PeripheralName >= 11 && Copy_u8PeripheralName < 33)
		SET_BIT(RCC_APB2ENR, (Copy_u8PeripheralName - 11));
	else if (Copy_u8PeripheralName >= 33 && Copy_u8PeripheralName < 63)
		SET_BIT(RCC_APB1ENR, (Copy_u8PeripheralName - 33));
	else
		Local_u8ErrorState = NOOK;

	return Local_u8ErrorState;

}

u8 RCC_u8DisablePeripheralClock(Peripherals_t Copy_u8PeripheralName) {

	u8 Local_u8ErrorState = OK;

	if (Copy_u8PeripheralName < 11)
		CLR_BIT(RCC_AHBENR, Copy_u8PeripheralName);
	else if (Copy_u8PeripheralName >= 11 && Copy_u8PeripheralName < 33)
		CLR_BIT(RCC_APB2ENR, (Copy_u8PeripheralName - 11));
	else if (Copy_u8PeripheralName >= 33 && Copy_u8PeripheralName < 63)
		CLR_BIT(RCC_APB1ENR, (Copy_u8PeripheralName - 33));
	else
		Local_u8ErrorState = NOOK;

	return Local_u8ErrorState;

}

/*
 u8 RCC_u8EnablePeripheralClock(u8 Copy_u8Bus, u8 Copy_u8PeripheralCode) {

 u8 Local_u8ErrorState = OK;

 switch(Copy_u8Bus){

 case(RCC_AHB_BUS): 	SET_BIT(RCC_AHBENR, Copy_u8PeripheralCode);
 break;

 case(RCC_APB1_BUS):	SET_BIT(RCC_APB1ENR, Copy_u8PeripheralCode);
 break;

 case(RCC_APB2_BUS):	SET_BIT(RCC_APB2ENR, Copy_u8PeripheralCode);
 break;

 default:			Local_u8ErrorState = NOOK;

 }

 return Local_u8ErrorState;


 }



 u8 RCC_u8DisablePeripheralClock(u8 Copy_u8Bus, u8 Copy_u8PeripheralCode) {

 u8 Local_u8ErrorState = OK;

 switch (Copy_u8Bus) {

 case (RCC_AHB_BUS):
 CLR_BIT(RCC_AHBENR, Copy_u8PeripheralCode);
 break;

 case (RCC_APB1_BUS):
 CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralCode);
 break;

 case (RCC_APB2_BUS):
 CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralCode);
 break;

 default:
 Local_u8ErrorState = NOOK;

 }

 return Local_u8ErrorState;
 }

 */
