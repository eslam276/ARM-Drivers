/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: GPIO				**************/
/********************		Version: 1.00			**************/
/********************		Date: 31-8-2023			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include <stdint.h>




/**
 * @brief 
 * 
 * @Port_t enum
 * 
 */
typedef enum
{
    PORTA = 0 ,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG,
    PORTH,
    

}Port_t;






/**
 * @brief 
 * @Pin_Value_t enum
 * 
 */

typedef enum
{
    LOW = 0 ,
    HIGH,
    

}Pin_Value_t ;







/**
 * @brief 
 * @Pin_t enum
 * 
 */

typedef enum
{
    PIN0 = 0 ,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
    

}Pin_t;






typedef enum
{
    INPUT = 0 ,
    OUTPUT,
    ALTERNATIVE_FUNCTION ,
    ANALOG,
    

}Mode_t ;



typedef enum
{
    LOW_ = 0 ,
    MEDUIM,
    FAST ,
    HIGH_,
    

}OutputSpeed_t ;




typedef enum
{
    PUSH_PULL = 0 ,
    OPEN_DRAIN,
    

}OutputType_t ;



typedef enum
{
    NO_PULL = 0 ,
    PULL_UP,
    PULL_DOWN,
    

}PullUpDown_t ;






typedef enum
{
    AF0 = 0 ,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15,
    

}AltFunc_t ;



























typedef struct 
{
    
    Port_t Port ;
    Pin_t PinNum ;
    Mode_t Mode ;
    OutputSpeed_t Speed ;
    OutputType_t  OutputType ;
    PullUpDown_t PullType ;
    AltFunc_t AltFunc ;

}GPIO_PIN_CFG_t;




uint8_t GPIO_u8PinInit (const GPIO_PIN_CFG_t* PinCFG );

uint8_t GPIO_u8SetPinValue (Port_t Port , Pin_t PinNum , Pin_Value_t Value );


uint8_t GPIO_u8TogglePinValue (Port_t Port , Pin_t PinNum );


uint8_t GPIO_u8ReadPinValue (Port_t Port , Pin_t PinNum , uint8_t * Value );




#endif