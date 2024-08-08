/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "GPIO_interface.h"
#include "RCC_interface.h"

int main(void)
{
	RCC_APB2Enable(APB2_IOPA);
	RCC_APB2Enable(APB2_IOPB);
	GPIO_PinConfig_t LedPin={
			.Mode = OUTPUT_SPEED_2M,
			.Port = PORTA,
			.PinNum = PIN2,
			.Output = OUTPUT_PUSH_PULL
	};
	GPIO_PinConfig_t SwitchPin={
			.Mode = INPUT,
			.Port = PORTB,
			.PinNum = PIN0,
			.Input = FLOATING
	};
	GPIO_u8PinInit(&LedPin);
	GPIO_u8PinInit(&SwitchPin);
	uint8_t Local_u8SwitchState;

    /* Loop forever */

	for(;;)
	{
		GPIO_u8ReadPinValue(PORTB, PIN0, &Local_u8SwitchState);
		while(Local_u8SwitchState == 1)
		{
			GPIO_u8ReadPinValue(PORTB, PIN0, &Local_u8SwitchState);
		}
		GPIO_u8SetPinValue(PORTA, PIN2, PIN_HIGH);


	}
}
