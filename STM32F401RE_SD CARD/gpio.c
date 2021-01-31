/*
 * gpio.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */
#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init(void)
{
	GPIOA->MODER |= GPIO_MODER_MODER2_1; //alternate function mode for PA2
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_0 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_2;//Select USART functionality for PA2
	//alternate function mode for PB13,PB14,PB15 and output mode for PB12
	GPIOB->MODER |= (GPIO_MODER_MODE12_0 | GPIO_MODER_MODER13_1 |
									GPIO_MODER_MODER14_1 | GPIO_MODER_MODER15_1);
	//Select SPI2 functionality for PB13(SCK),PB14(MISO),PB15(MOSI)
	GPIOB->AFR[1] |= (GPIO_AFRH_AFSEL13_0 | GPIO_AFRH_AFSEL13_2 |
										GPIO_AFRH_AFSEL14_0 | GPIO_AFRH_AFSEL14_2 |
										GPIO_AFRH_AFSEL15_0 | GPIO_AFRH_AFSEL15_2 );

}
