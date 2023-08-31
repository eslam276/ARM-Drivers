

#ifndef STM32F446_H
#define STM32F446_H


#include <stdint.h>


/****************************  Various memory base addresses   *******************/

#define FLASH_BASE_ADDRESS      0x08000000UL

#define SRAM_BASE_ADDRESS       0x20000000UL






/****************************  AHB1 periphral base addresses   *******************/


#define GPIOA_BASE_ADDRESS          0x40020000UL
#define GPIOB_BASE_ADDRESS          0x40020400UL
#define GPIOC_BASE_ADDRESS          0x40020800UL
#define GPIOD_BASE_ADDRESS          0x40020C00UL
#define GPIOE_BASE_ADDRESS          0x40021000UL
#define GPIOF_BASE_ADDRESS          0x40021400UL
#define GPIOG_BASE_ADDRESS          0x40021800UL
#define GPIOH_BASE_ADDRESS          0x40021C00UL

#define RCC_BASE_ADDRESS            0x40023800UL






/****************************  AHB2 periphral base addresses   *******************/




/****************************  AHB3 periphral base addresses   *******************/





/****************************  APB1 periphral base addresses   *******************/





/****************************  APB2 periphral base addresses   *******************/










/****************************  GPIO Register Definintion Structure   *******************/



typedef struct 
{

    volatile uint32_t  MODER ;                                  /* GPIO port mode register  */
    volatile uint32_t  OTYPER ;                                 /* GPIO port output type register */
    volatile uint32_t  OSPEEDER ;                               /* GPIO port output speed register */
    volatile uint32_t  PUPDR ;                                  /* GPIO port pull-up/pull-down register*/
    volatile uint32_t  IDR ;                                    /* GPIO port input data register  */
    volatile uint32_t  ODR ;                                    /* GPIO port output data register */
    volatile uint32_t  BSRR ;                                   /* GPIO port bit set/reset register */
    volatile uint32_t  LCKR ;                                   /* GPIO port configuration lock register */
    volatile uint32_t  AFRL[2] ;                                /* GPIO alternate function  register */
                                  


}GPIO_REG_t;





/****************************  GPIO Periphral Definintions    *******************/

#define GPIOA               ((GPIO_REG_t*) GPIOA_BASE_ADDRESS)
#define GPIOB               ((GPIO_REG_t*) GPIOB_BASE_ADDRESS)
#define GPIOC               ((GPIO_REG_t*) GPIOC_BASE_ADDRESS)
#define GPIOD               ((GPIO_REG_t*) GPIOD_BASE_ADDRESS)
#define GPIOE               ((GPIO_REG_t*) GPIOE_BASE_ADDRESS)
#define GPIOF               ((GPIO_REG_t*) GPIOF_BASE_ADDRESS)
#define GPIOG               ((GPIO_REG_t*) GPIOG_BASE_ADDRESS)
#define GPIOH               ((GPIO_REG_t*) GPIOH_BASE_ADDRESS)




















#endif
