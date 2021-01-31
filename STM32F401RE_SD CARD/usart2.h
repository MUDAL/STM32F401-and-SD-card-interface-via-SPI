/*
 * usart2.h
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#ifndef INC_USART2_H_
#define INC_USART2_H_

enum Baud
{
	BAUD_9600 = 0x683,
	BAUD_115200 = 0x8B
};

extern void USART2_Init(uint16_t baud);
extern void USART2_TransmitString(char* pData);

#endif /* INC_USART2_H_ */
