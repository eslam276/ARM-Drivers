/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-11-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define  USART_SR_RXNE          5
#define  USART_SR_TC            6

#define  USART_SR_RXNE_DOWN_MASK 0b0
#define  USART_SR_TC_MASK        0b0



#define CR1_OVER8           15
#define CR1_WORDLENGTH      12
#define CR1_PCE             10
#define CR1_TE              3
#define CR1_RE              2


#define  USART_BAUD_RATE_ACCESS       4
#define  USART_MAX_FRAC               1500
#define  USART_FRACTION               0
#define  USART_MANTISSA               1

#define  USART_CR1_UE           13





#endif