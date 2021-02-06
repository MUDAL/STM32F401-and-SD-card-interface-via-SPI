/*
 * systick.h
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

typedef struct
{
	uint32_t start;
	uint32_t ticksToWait;
}systick_t;

extern void SysTick_Init(void);
extern uint32_t SysTick_GetTick(void);
extern void SysTick_DelayMs(uint32_t delayTime);

#endif //_SYSTICK_H_ 
