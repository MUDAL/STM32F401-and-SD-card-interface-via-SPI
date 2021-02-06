/*
 * clock.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */


#include "stm32f4xx.h"                  // Device header
#include "clock.h"

void Clocks_Init(void)
{
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN); //Enable GPIO A, B and C  clock
	RCC->APB1ENR |= (RCC_APB1ENR_SPI2EN | RCC_APB1ENR_USART2EN);//enable SPI2, USART2 clock
}
