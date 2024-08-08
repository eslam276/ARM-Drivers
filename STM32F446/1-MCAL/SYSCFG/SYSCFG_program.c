/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: SYSCFG				**************/
/********************		Version: 1.00			**************/
/********************		Date: 16-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#include <stdint.h>
#include "SYSCFG_interface.h"
#include "SYSCFG_register.h"
#include "SYSCFG_private.h"

#include "defines.h"
#include "BIT_MATH.h"




uint8_t SYSCFG_u8SetLine(SYSCFG_Line_t Copy_enLineValue, SYSCFG_Port_t Copy_u8enPortValue)
{
	uint8_t Local_u8Error_Status = OK;
	if(Copy_enLineValue <= LINE_15 && Copy_enLineValue >= LINE_0)
	{
		if(Copy_u8enPortValue >= PA && Copy_u8enPortValue <= PH)
		{
             uint8_t Local_u8RegNum = Copy_enLineValue / REG_ACCESS;
             uint8_t Local_u8BitNum = Copy_enLineValue % BIT_ACCESS;

            /* Clear the required 4 bits */
             SYSCFG->EXTICR[Local_u8RegNum] &= ( ~ ( 0b1111 << Local_u8BitNum ));
             SYSCFG->EXTICR[Local_u8RegNum] |= Copy_u8enPortValue << (Local_u8BitNum *BIT_ACCESS);
		}
		else
		{
			Local_u8Error_Status = NOK;
		}
	}
	else
	{
		Local_u8Error_Status = NOK;
	}
	return Local_u8Error_Status;
}
