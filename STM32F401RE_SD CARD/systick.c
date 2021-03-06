/*
 * systick.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#include "stm32f4xx.h"
#include "systick.h"

volatile uint32_t numberOfTicks = 0;

void SysTick_Init(void)
{
	//Systick default clock source = AHB clock / 8 = 2MHz
	SysTick->LOAD = 2000 - 1; //1ms timebase
	SysTick->VAL = 0;
	SysTick->CTRL |= (SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk); //Enable systick interrupt and systick timer
}

uint32_t SysTick_GetTick(void)
{
	return numberOfTicks;
}

void SysTick_Increment(void)
{
	numberOfTicks++;
}

void SysTick_DelayMs(uint32_t delayTime)
{
	uint32_t startTick = numberOfTicks;
	while((numberOfTicks - startTick) < delayTime);
}
