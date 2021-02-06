/*
 * uart.h
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#ifndef _UART_H_
#define _UART_H_

enum Baud
{
	BAUD_9600 = 0x683,
	BAUD_115200 = 0x8B
};

extern void UART_Init(USART_TypeDef* uartPort, uint16_t baud, uint8_t dmaMode, uint8_t uartMode);
extern void UART_TransmitString(USART_TypeDef* uartPort,char* pString);

#endif //_UART_H_ 
