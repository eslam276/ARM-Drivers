/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-11-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_



#include <stdint.h>


#define USART1_u32_BASE_ADDRESS                                	0x40011000U
#define USART2_u32_BASE_ADDRESS                                	0x40004400U
#define USART3_u32_BASE_ADDRESS                                	0x40004800U
#define UART4_u32_BASE_ADDRESS                                	0x40004C00U
#define UART5_u32_BASE_ADDRESS                                	0x40005000U
#define USART6_u32_BASE_ADDRESS                                	0x40011400U



typedef	struct
{
	volatile uint32_t SR    ;
	volatile uint32_t DR    ;
	volatile uint32_t BRR   ;
	volatile uint32_t CR1   ;
	volatile uint32_t CR2   ;
	volatile uint32_t CR3   ;
	volatile uint32_t GTPR  ;

} USART_REG ;



#define  USART1                     ( (  USART_REG *) USART1_u32_BASE_ADDRESS )
#define  USART2                     ( (  USART_REG *) USART2_u32_BASE_ADDRESS )
#define  USART3                     ( (  USART_REG *) USART3_u32_BASE_ADDRESS )
#define  UART4                     	( (  USART_REG *) UART4_u32_BASE_ADDRESS  )
#define  UART5                     	( (  USART_REG *) UART5_u32_BASE_ADDRESS  )
#define  USART6                     ( (  USART_REG *) USART6_u32_BASE_ADDRESS )




#endif