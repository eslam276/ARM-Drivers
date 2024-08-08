#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#include <stdint.h>

typedef enum
{
	HSI=0,
	HSE,
	PLL
}RCC_ClkType_t;

typedef enum
{
	ON=0,
	OFF
}RCC_ClkStatus_t;

typedef enum
{
    HSI_SYS=0,
	HSE_SYS,
	PLLP_SYS,
	PLL_R
}RCC_SysClkType_t;

/*Control register Bits*/
#define CR_HSION        0u
#define CR_HSIRDY       1u
#define CR_HSEON        16u
#define CR_HSERDY       17u
#define CR_PLLON        24u
#define CR_PLLRDY       25u
/*PLL configuration register PLL source bit*/
#define PLLCFGR_PLLSRC  22u

typedef enum
{
	AHB1_GPIOA=0,
	AHB1_GPIOB,
	AHB1_GPIOC,
	AHB1_GPIOD,
	AHB1_GPIOE,
	AHB1_GPIOF,
	AHB1_GPIOG,
    AHB1_GPIOH,
	AHB1_CRC=12,
	AHB1_FLITF=15,
	AHB1_SRAM1=16,
	AHB1_SRAM2=17,
	AHB1_BKPSRAM=18,
	AHB1_DMA1=21,
	AHB1_DMA2=22,
	AHB1_OTGHS=29,
	AHB1_OTGHSULPI=30
}RCC_AHB1ENR_t;

typedef enum
{
	AHB2_DCMI=0,
	AHB2_OTGFS=7
}RCC_AHB2ENR_t;

typedef enum
{
	AHB3_FMC=0,
	AHB3_QSPI
}RCC_AHB3ENR_t;

typedef enum
{
	APB1_TIM2=0,
	APB1_TIM3,
	APB1_TIM4,
	APB1_TIM5,
	APB1_TIM6,
	APB1_TIM7,
	APB1_TIM12,
	APB1_TIM13,
	APB1_TIM14,
	APB1_WWDG=11,
	APB1_SPI2=14,
	APB1_SPI3,
	APB1_SPDIFRX,
	APB1_USART2,
	APB1_USART3,
	APB1_UART4,
	APB1_UART5,
	APB1_I2C1,
	APB1_I2C2,
	APB1_I2C3,
	APB1_FMPI2C1,
	APB1_CAN1,
	APB1_CAN2,
	APB1_CEC,
	APB1_PWR,
	APB1_DAC
}RCC_APB1ENR_t;

typedef enum
{
	APB2_TIM1=0,
	APB2_TIM8,
	APB2_USART1=4,
	APB2_USART6=5,
	APB2_ADC1=8,
	APB2_ADC2,
	APB2_ADC3,
	APB2_SDIO,
	APB2_SPI1,
	APB2_SPI4,
	APB2_SYSCFG,
	APB2_TIM9=16,
	APB2_TIM10,
	APB2_TIM11,
	APB2_SAI1=22,
	APB2_SAI2

}RCC_APB2ENR_t;



typedef struct
{
	uint16_t PLLMull_Factor;
	uint8_t  PLLDiv_Factor;
	uint8_t  PLLInputDiv_Factor;
	RCC_ClkType_t  Clk_Src;
}RCC_ClkCf_t;

uint8_t RCC_Set_CLK_Status(RCC_ClkType_t Copy_enClkType,RCC_ClkStatus_t Copy_enClkStatus);
void RCC_Set_SysClk(RCC_SysClkType_t Copy_enClkType);
uint8_t RCC_ClkCfg(const RCC_ClkCf_t* Copy_stClkCfg);

void RCC_AHB1ResetClk(RCC_AHB1ENR_t Copy_enPeripheral);
void RCC_AHB2ResetClk(RCC_AHB2ENR_t Copy_enPeripheral);
void RCC_AHB3ResetClk(RCC_AHB3ENR_t Copy_enPeripheral);
void RCC_APB1ResetClk(RCC_APB1ENR_t Copy_enPeripheral);
void RCC_APB2ResetClk(RCC_APB2ENR_t Copy_enPeripheral);

void RCC_AHB1EnableClk(RCC_AHB1ENR_t Copy_enPeripheral);
void RCC_AHBD1isableClk(RCC_AHB1ENR_t Copy_enPeripheral);
void RCC_AHB2EnableClk(RCC_AHB2ENR_t Copy_enPeripheral);
void RCC_AHB2DisableClk(RCC_AHB2ENR_t Copy_enPeripheral);
void RCC_AHB3EnableClk(RCC_AHB3ENR_t Copy_enPeripheral);
void RCC_AHB3DisableClk(RCC_AHB3ENR_t Copy_enPeripheral);
void RCC_APB1Enable(RCC_APB1ENR_t Copy_enPeripheral);
void RCC_APB1Disable(RCC_APB1ENR_t Copy_enPeripheral);
void RCC_APB2Enable(RCC_APB2ENR_t Copy_enPeripheral);
void RCC_APB2Disable(RCC_APB2ENR_t Copy_enPeripheral);

#endif
