#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


// we have timer 1 2 3 4 5 8



typedef enum {
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
	AFIO,
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
	TIM2,
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




void RCC_voidInit(void);

/**
 *
 * @param Copy_u8PeripheralName
 * @return Error State
 */
u8 RCC_u8EnablePeripheralClock(Peripherals_t Copy_u8PeripheralName);


/**
 *
 * @param Copy_u8PeripheralName
 * @return Error State
 */
u8 RCC_u8DisablePeripheralClock(Peripherals_t Copy_u8PeripheralName);



#endif
