/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: RCC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 27-8-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

typedef enum
{
	ON,
	OFF
}status_t;


typedef enum
{
	HSE,
	HSI,
	PLL
}CLK_t;


typedef enum
{
	devided_by_2,
	Not_Devided
}HSE_Config_t;


typedef enum
{
	/* For cfg parameter */
	IN_X_2,
	IN_X_3,
	IN_X_4,
	IN_X_5,
	IN_X_6,
	IN_X_7,
	IN_X_8,
	IN_X_9,
	IN_X_10,
	IN_X_11,
	IN_X_12,
	IN_X_13,
	IN_X_14,
	IN_X_15,
	IN_X_16,

	/* for PLL_SRC parameter */

	HSI_devided_by2,
	HSE_

}PLL_Config_t;


typedef enum 
{
	/*AHB peripherals, 11 total*/
	DMA1,
	DMA2,
	SRAM,
	RES1,
	FLITF,
	RES2,
	CRCE,
	RES3,
	FSMC,
	RES4,
	SDIO,
	/*APB2 peripherals, 22 in total*/
	AFIO=0,
	RES5,
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART1,
	ADC3,
	RES6,
	RES7,
	RES8,
	TIM9,
	TIM10,
	TIM11,
	/*APB1 peripherals, 30 total*/
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	RES9,
	RES10,
	WATCHDOG,
	RES11,
	RES12,
	SPI2,
	SPI3,
	RES13,
	USART2,
	USART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	USB,
	RES14,
	CAN,
	RES15,
	BKP,
	PWR,
	DAC
}Peripherals_t;



uint8_t RCC_u8SetClkStatus(CLK_t Cpoy_Clock , status_t Copy_Status);

void RCC_voidSetSystemClock(CLK_t Cpoy_Clock);


/* can be written only when PLL is disabled */
void RCC_voidHSEConfig(HSE_Config_t Copy_Cfg);


/* can be written only when PLL is disabled */
void RCC_voidPLLConfig(PLL_Config_t Copy_Cfg , PLL_Config_t Copy_PLLSRC);


void RCC_voidAHBEnable(Peripherals_t Copy_Periphral);
void RCC_voidAHBDisble(Peripherals_t Copy_Periphral);


void RCC_voidAPB1Enable(Peripherals_t Copy_Periphral);
void RCC_voidAPB1Disble(Peripherals_t Copy_Periphral);



void RCC_voidAPB2Enable(Peripherals_t Copy_Periphral);
void RCC_voidAPB2Disble(Peripherals_t Copy_Periphral);


#endif
















