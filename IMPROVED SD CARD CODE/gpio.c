/*
 * gpio.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */
#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Alternate_Function_Init(GPIO_TypeDef* gpioPort, uint32_t gpioMode, uint8_t gpioAF_Level, uint32_t gpioAF)
{
	gpioPort->MODER |= gpioMode;
	gpioPort->AFR[gpioAF_Level] |= gpioAF;
}

