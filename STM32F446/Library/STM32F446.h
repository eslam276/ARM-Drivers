

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






/**************  RCC Register Defination Structure   *********/


typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                   */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                               */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                             */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                 */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                           */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                           */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                           */
  uint32_t      RESERVED0;     		/*!< Reserved, 0x1C                                                */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                           */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                           */
  uint32_t      RESERVED1[2];  		/*!< Reserved, 0x28-0x2C                                           */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                           */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                           */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                           */
  uint32_t      RESERVED2;     		/*!< Reserved, 0x3C                                                */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                    */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                    */
  uint32_t      RESERVED3[2];  		/*!< Reserved, 0x48-0x4C                                           */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register,  */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register,  */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register,  */
  uint32_t      RESERVED4;     		/*!< Reserved, 0x5C                                                */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register,  */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register,  */
  uint32_t      RESERVED5[2];  		/*!< Reserved, 0x68-0x6C                                           */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                           */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                          */
  uint32_t      RESERVED6[2];  		/*!< Reserved, 0x78-0x7C                                           */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,                */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                            */
  volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                            */
  volatile uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                  */
  volatile uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                             */
  volatile uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,                */
} RCC_RegDef_t;

#define RCC                 ((RCC_RegDef_t*)RCC_BASE_ADDRESS)









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
    volatile uint32_t  AFR[2] ;                                /* GPIO alternate function  register */
                                  


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
