

#include <stdint.h>
#include "GPIO_interface.h"
#include "BIT_MATH.h"









 
static uint8_t ARR[10] = {0b00111111,0b00110000,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};





void SSD_PinInit(void)
{
    GPIO_PinConfig_t A11 = { .Port = PORTA , .PinNum = PIN11 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t A8  = { .Port = PORTA , .PinNum = PIN8  , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
    GPIO_PinConfig_t A12 = { .Port = PORTA , .PinNum = PIN12 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t A15 = { .Port = PORTA , .PinNum = PIN15 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;

    GPIO_PinConfig_t B3  = { .Port = PORTB , .PinNum = PIN3  , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B8  = { .Port = PORTB , .PinNum = PIN8  , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B9  = { .Port = PORTB , .PinNum = PIN9  , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B12 = { .Port = PORTB , .PinNum = PIN12 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B13 = { .Port = PORTB , .PinNum = PIN13 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B14 = { .Port = PORTB , .PinNum = PIN14 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B15 = { .Port = PORTB , .PinNum = PIN15 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;


	GPIO_u8PinInit(&A11);
	GPIO_u8PinInit(&A8 );
    GPIO_u8PinInit(&A12);
	GPIO_u8PinInit(&A15);

    GPIO_u8PinInit(&B3);
	GPIO_u8PinInit(&B8);
	GPIO_u8PinInit(&B9);
	GPIO_u8PinInit(&B12);
	GPIO_u8PinInit(&B13);
	GPIO_u8PinInit(&B14);
	GPIO_u8PinInit(&B15);
}




void SSD1_ON(void)
{
    GPIO_u8SetPinValue(PORTB , PIN8 , PIN_HIGH);
}
void SSD2_ON(void)
{
    GPIO_u8SetPinValue(PORTB , PIN9 , PIN_HIGH);
}
void SSD3_ON(void)
{
    GPIO_u8SetPinValue(PORTB , PIN3 , PIN_HIGH);
}







void SSD1_OFF(void)
{
    GPIO_u8SetPinValue(PORTB , PIN8 , PIN_LOW);
}
void SSD2_OFF(void)
{
    GPIO_u8SetPinValue(PORTB , PIN9 , PIN_LOW);
}

void SSD3_OFF(void)
{
    GPIO_u8SetPinValue(PORTB , PIN3 , PIN_LOW);
}


void SSD_SendNumber(uint8_t Number )
{
    GPIO_u8SetPinValue(PORTA , PIN11 , ( GET_BIT(ARR[Number] , 0) ) );
    GPIO_u8SetPinValue(PORTA , PIN8  , ( GET_BIT(ARR[Number] , 1) ) );
    GPIO_u8SetPinValue(PORTB , PIN15 , ( GET_BIT(ARR[Number] , 2) ) );
    GPIO_u8SetPinValue(PORTB , PIN14 , ( GET_BIT(ARR[Number] , 3) ) );
    GPIO_u8SetPinValue(PORTB , PIN13 , ( GET_BIT(ARR[Number] , 4) ) );
    GPIO_u8SetPinValue(PORTB , PIN12 , ( GET_BIT(ARR[Number] , 5) ) );
    GPIO_u8SetPinValue(PORTA , PIN12 , ( GET_BIT(ARR[Number] , 6) ) );
}
