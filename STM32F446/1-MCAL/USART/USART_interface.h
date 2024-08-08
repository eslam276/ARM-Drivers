/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-11-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include <stdint.h>



#define F_COLCK                   16000000UL
#define USART1_BAUD_RATE         (uint32_t)9600


typedef enum
{
    USART_1 =0 ,
	USART_2 ,
	USART_3 ,
	UART_4  ,
	UART_5  ,
	USART_6

}USART_NUM_t ;


typedef enum
{
    RX,
    TX,
    RX_TX

}USART_Mode_t;



typedef enum 
{
    OVER16,
    OVER8

}USART_Sampling_t ;



typedef enum 
{
    EIGHT,
    NINE

}USART_WordLength_t ;



typedef enum 
{
    PARITY_DISABLED,
    PARITY_ENABLED

}USART_Parity_t ;


typedef enum 
{
    RXINT_DISABLE ,
    RXINT_ENABLE 

}USART_RXINT_t;


typedef struct 
{

    USART_NUM_t  USART_Num ;
    USART_Parity_t Parity ;
    USART_WordLength_t Word ;
    USART_Sampling_t OverSampling ;
    USART_Mode_t Mode ;
    USART_RXINT_t RX_INT ;



}USART_Cnfg_t;


uint8_t  USART_u8Init( USART_Cnfg_t * Copy_psCnfg );
uint8_t  USART_u8ReceiveCharSynch     ( USART_NUM_t Copy_USARTindex , uint8_t * Copy_pu8DataChar  );
void     USART_voidTransmitCharSynch     ( USART_NUM_t Copy_USARTindex , uint8_t  Copy_u8DataChar  ) ;

#endif