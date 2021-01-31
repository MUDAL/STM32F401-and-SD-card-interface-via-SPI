/*
 * usart2.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#include "stm32f4xx.h"
#include "usart2.h"

void USART2_Init(uint16_t baud)
{
	USART2->CR1 |= USART_CR1_UE; //Enable USART
	//Default: Word length = 8 bits, 1 Start bit, 1 Stop bit
	USART2->BRR = baud;
	USART2->CR1 |= USART_CR1_TE; //send idle frame as first transmission
}

void USART2_TransmitString(char* pData)
{
	uint32_t i = 0;
	while (*(pData + i) != '\0')
	{
		while ((USART2->SR & USART_SR_TXE) == 0x00);//wait for TXE bit to be set
		USART2->DR = *(pData + i);
		i++;
	}
}
