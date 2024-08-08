/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: KPD_program.c		    *******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#include <stdint.h>

#include "GPIO_interface.h"

#include "KPD_cfg.h"
#include "KPD_interface.h"



void KPD_PinInint(void)
{

	/* ROWS CFG  A --> 4,5,6,7    INPUT PULLED_UP  */

	GPIO_PinConfig_t A4 = { .Port = PORTA , .PinNum = PIN4 , .Mode = INPUT , .Input = PULLUP_PULLDOWN  } ;
	GPIO_PinConfig_t A5 = { .Port = PORTA , .PinNum = PIN5 , .Mode = INPUT , .Input = PULLUP_PULLDOWN  } ;
	GPIO_PinConfig_t A6 = { .Port = PORTA , .PinNum = PIN6 , .Mode = INPUT , .Input = PULLUP_PULLDOWN  } ;
	GPIO_PinConfig_t A7 = { .Port = PORTA , .PinNum = PIN7 , .Mode = INPUT , .Input = PULLUP_PULLDOWN  } ;

	/* Coulmns CFG B->  11 ,10 ,1,0   OUT   HIGH */

	GPIO_PinConfig_t B11 = { .Port = PORTB , .PinNum = PIN11 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B10 = { .Port = PORTB , .PinNum = PIN10 , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B1  = { .Port = PORTB , .PinNum = PIN1  , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;
	GPIO_PinConfig_t B0  = { .Port = PORTB , .PinNum = PIN0  , .Mode = OUTPUT_SPEED_2M , .Output = OUTPUT_PUSH_PULL  } ;


	GPIO_u8PinInit(&A4);
	GPIO_u8PinInit(&A5 );
	GPIO_u8PinInit(&A6);
	GPIO_u8PinInit(&A7 );

	GPIO_u8PinInit(&B11);
	GPIO_u8PinInit(&B10);
	GPIO_u8PinInit(&B1);
	GPIO_u8PinInit(&B0); 


	GPIO_u8SetPinValue(PORTB,PIN0,PIN_HIGH);
	GPIO_u8SetPinValue(PORTB,PIN1,PIN_HIGH);
	GPIO_u8SetPinValue(PORTB,PIN10,PIN_HIGH);
	GPIO_u8SetPinValue(PORTB,PIN11,PIN_HIGH);


	GPIO_u8SetPinValue(PORTA,PIN4,PIN_HIGH);
	GPIO_u8SetPinValue(PORTA,PIN5,PIN_HIGH);
	GPIO_u8SetPinValue(PORTA,PIN6,PIN_HIGH);
	GPIO_u8SetPinValue(PORTA,PIN7,PIN_HIGH);

}






/*required All row pins are input pulledup, all colum pins are output high*/
uint8_t KPD_u8GetPressedKey(void)
{
	uint8_t Local_u8PressedKey = KPD_u8NO_Pressed_KEY_VAL;
	uint8_t Local_u8RowCounter;
	uint8_t Local_u8ColCounter;
	uint8_t Local_u8KeyState;
	static uint8_t Local_u8ColArr[KPD_u8COL_NUM] = {KPD_u8COL1_PIN, KPD_u8COL2_PIN, KPD_u8COL3_PIN, KPD_u8COL4_PIN};
	static uint8_t Local_u8ROWArr[KPD_u8ROW_NUM] = {KPD_u8ROW1_PIN, KPD_u8ROW2_PIN, KPD_u8ROW3_PIN, KPD_u8ROW4_PIN};
	static uint8_t Local_u8KPDArr[KPD_u8ROW_NUM][KPD_u8COL_NUM] = KPD_u8BUTTON_ARR;

	/*Activate column pins and read the rows*/
	for(Local_u8ColCounter = 0; Local_u8ColCounter < KPD_u8COL_NUM; Local_u8ColCounter++)
	{
		/*Activate Current Colulum*/
		GPIO_u8SetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter],PIN_LOW);

		for(Local_u8RowCounter = 0; Local_u8RowCounter < KPD_u8ROW_NUM; Local_u8RowCounter++)
		{
			/*Readt the current row*/
			GPIO_u8SetPinValue(KPD_u8ROW_PORT,  Local_u8ROWArr[Local_u8RowCounter],&Local_u8KeyState);

			/*if current row is low, button is pressed*/
			if(Local_u8KeyState == PIN_LOW)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];
				/*wait until key is released*/
				while(Local_u8KeyState == PIN_LOW)
				{
					GPIO_u8ReadPinValue(KPD_u8ROW_PORT, Local_u8ROWArr[Local_u8RowCounter], &Local_u8KeyState);
				}

				return Local_u8PressedKey;
			}

		}
		/*Deactivate the current column*/
		GPIO_u8SetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter],PIN_HIGH);

	}
	return Local_u8PressedKey;
}
