/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: KPD_program.c		    *******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#include "std_types.h"

#include "DIO_interface.h"

#include "KPD_cfg.h"
#include "KPD_interface.h"
#include "KPD_private.h"

/*required All row pins are input pulledup, all colum pins are output high*/
uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8PressedKey = KPD_u8NO_Pressed_KEY_VAL;
	uint8 Local_u8RowCounter;
	uint8 Local_u8ColCounter;
	uint8 Local_u8KeyState;
	static uint8 Local_u8ColArr[KPD_u8COL_NUM] = {KPD_u8COL1_PIN, KPD_u8COL2_PIN, KPD_u8COL3_PIN, KPD_u8COL4_PIN};
	static uint8 Local_u8ROWArr[KPD_u8ROW_NUM] = {KPD_u8ROW1_PIN, KPD_u8ROW2_PIN, KPD_u8ROW3_PIN, KPD_u8ROW4_PIN};
	static uint8 Local_u8KPDArr[KPD_u8ROW_NUM][KPD_u8COL_NUM] = KPD_u8BUTTON_ARR;

	/*Activate column pins and read the rows*/
	for(Local_u8ColCounter = 0; Local_u8ColCounter < KPD_u8COL_NUM; Local_u8ColCounter++)
	{
		/*Activate Current Colulum*/
		DIO_u8SetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter], DIO_u8PIN_LOW);
		for(Local_u8RowCounter = 0; Local_u8RowCounter < KPD_u8ROW_NUM; Local_u8RowCounter++)
		{
			/*Readt the current row*/
			DIO_u8GetPinValue(KPD_u8ROW_PORT, Local_u8ROWArr[Local_u8RowCounter], &Local_u8KeyState);

			/*if current row is low, button is pressed*/
			if(Local_u8KeyState == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];
				/*wait until key is released*/
				while(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_u8ROW_PORT, Local_u8ROWArr[Local_u8RowCounter], &Local_u8KeyState);
				}

				return Local_u8PressedKey;
			}

		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter], DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
