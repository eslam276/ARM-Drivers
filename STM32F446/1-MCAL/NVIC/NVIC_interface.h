/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: NVIC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include <stdint.h> 



typedef enum
{
	WWDG=0,
	PVD,
	TAMP_STAMP,
	RTC_WKUP,
	FLASH,
	RCC_INT,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	CAN1_TX,
	CAN1_RX0,
	CAN1_RX1,
	CAN1_SCE,
	EXTI9_5,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	USART3,
	EXTI15_,
	RTC_Alarm,
	OTG_FS_WKUP,
	TIM8_BRK_TIM12,
	TIM8_UP_TIM13,
	TIM8_TRG_COM_TIM14,
	TIM8_CC,
	DMA1_Stream7,
	FMC,
	SDIO,
	TIM5,
	SPI3,
	UART4,
	UART5,
	TIM6_DAC,
	TIM7,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	CAN2_TX=73,
	CAN2_RX0,
	CAN2_RX1,
	CAN2_SCE,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	OTG_HS_EP1_OUT,
	OTG_HS_EP1_IN,
	OTG_HS_WKUP,
	OTG_HS,
	DCMI,
	FPU=81,
	SPI4=84,
	SAI1=87,
	SAI2=91,
	QuadSPI ,
	HDMI_CEC,
	SPDIF_Rx,
	FMPI2C1,
	FMPI2C1_error
    
}INTReq_Num_t;





typedef enum
{
	NOT_ACTIVE=0,
	ACTIVE,

}ActiveFlagStatus_t;





void INT_Enable(INTReq_Num_t IREQ_Num);
void INT_Disable(INTReq_Num_t IREQ_Num);
void SetPendingFlag(INTReq_Num_t IREQ_Num);
void CLRPendingFlag(INTReq_Num_t IREQ_Num);

ActiveFlagStatus_t GetActiveFlag(INTReq_Num_t IREQ_Num);

void NVIC_voidSetIRQPriority (INTReq_Num_t IREQ_Num , uint8_t Priority);






#endif