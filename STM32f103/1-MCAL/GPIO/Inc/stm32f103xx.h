#ifndef STM32F103_H
#define STM32F103_H


/**************  Various Memories Base Addresses    *********/

#define FLASH_BASE_ADDRESS        0x08000000UL
#define SRAM_BASE_ADDRESS         0x20000000UL



/**************  AHB Peripheral Base Addresses    *********/


/**************  APB2 Peripheral Base Addresses    *********/

#define GPIOA_BASE_ADDRESS         0x40010800UL
#define GPIOB_BASE_ADDRESS         0x40010C00UL
#define GPIOC_BASE_ADDRESS         0x40011000UL
#define GPIOD_BASE_ADDRESS         0x40011400UL
#define GPIOE_BASE_ADDRESS         0x40011800UL
#define GPIOF_BASE_ADDRESS         0x40011C00UL
#define GPIOG_BASE_ADDRESS         0x40012000UL







/**************  GPIO Peripheral Defination   *********/

#define GPIOA              ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB              ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC              ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD              ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE              ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF              ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG              ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)

/**************  GPIO Register Defination Structure   *********/

typedef struct
{
	volatile uint32_t CR[2]; /*GPIO configuration registers*/
	volatile uint32_t IDR; /*GPIO input data register*/
	volatile uint32_t ODR; /*GPIO output data register*/
	volatile uint32_t BSRR; /*GPIO Bit set reset register*/
	volatile uint32_t BRR; /*GPIO Bit reset register*/
	volatile uint32_t LCKR; /*GPIO lock configuration register*/
	 
}GPIO_RegDef_t;

#endif
