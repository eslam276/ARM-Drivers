#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_



#define RCC_START_ADDRESS   0x40021000

#define RCC_CR  		    *((volatile u32*) (RCC_START_ADDRESS + 0x00) )     /* Clock Control Register                */
#define RCC_CR_PLLRDY		25
#define RCC_CR_PLLON		24
#define RCC_CR_CSSON		19
#define RCC_CR_HSEBYP		18
#define RCC_CR_HSERDY       17
#define RCC_CR_HSEON		16
#define RCC_CR_HSITRIM		3
#define RCC_CR_HSIRDY		1
#define RCC_CR_HSION		0



#define RCC_CFGR  		    *((volatile u32*) (RCC_START_ADDRESS + 0x04) )     /* Clock Configuration Register          */
#define RCC_CFGR_MCO		24
#define RCC_CFGR_PLLMUL		18
#define RCC_CFGR_PLLXTPRE   17
#define RCC_CFGR_PLLSRC     16
#define RCC_CFGR_ADCPRE		14
#define RCC_CFGR_PPRE2		11
#define RCC_CFGR_PPRE1		8
#define RCC_CFGR_HPRE		4
#define RCC_CFGR_SWS		2
#define RCC_CFGR_SW			0


#define RCC_CIR  		    *((volatile u32*) (RCC_START_ADDRESS + 0x08) )     /* Clock Interrupt Register              */
#define RCC_APB2RSTR  		*((volatile u32*) (RCC_START_ADDRESS + 0x0C) )     /* APB2 Peripheral Reset Register        */
#define RCC_APB1RSTR  		*((volatile u32*) (RCC_START_ADDRESS + 0x10) )     /* APB1 Peripheral Reset Register        */

#define RCC_AHBENR  		*((volatile u32*) (RCC_START_ADDRESS + 0x14) )     /* AHB Peripheral Clock Enable Register  */


// no timer 6 7 9 10 11 12 13 14



#define RCC_APB2ENR  		*((volatile u32*) (RCC_START_ADDRESS + 0x18) )     /* APB2 Peripheral Clock Enable Register */

#define RCC_APB1ENR  		*((volatile u32*) (RCC_START_ADDRESS + 0x1C) )     /* APB1 Peripheral Clock Enable Register */


#define RCC_BDCR  		    *((volatile u32*) (RCC_START_ADDRESS + 0x20) )     /* Backup Domain Control Register        */
#define RCC_CSR  		    *((volatile u32*) (RCC_START_ADDRESS + 0x24) )     /* Control/status Register               */


#endif


/*
#define RCC_CR_HSICAL_7		15
#define RCC_CR_HSICAL_6		14
#define RCC_CR_HSICAL_5		13
#define RCC_CR_HSICAL_4		12
#define RCC_CR_HSICAL_3		11
#define RCC_CR_HSICAL_2		10
#define RCC_CR_HSICAL_1		9
#define RCC_CR_HSICAL_0		8
#define RCC_CR_HSITRIM_4	7
#define RCC_CR_HSITRIM_3	6
#define RCC_CR_HSITRIM_2	5
#define RCC_CR_HSITRIM_1	4
#define RCC_CR_HSITRIM_0	3
*/
