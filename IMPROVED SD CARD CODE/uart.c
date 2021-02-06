#include "stm32f4xx.h"                  // Device header
#include "uart.h"

void UART_Init(USART_TypeDef* uartPort, uint16_t baud, uint8_t dmaMode, uint8_t uartMode)
{
	uartPort->CR1 |= USART_CR1_UE;
	//Default: Word length = 8 bits, 1 Start bit, 1 Stop bit
	uartPort->CR3 |= dmaMode; 
	uartPort->BRR = baud; 
  uartPort->CR1 |= uartMode;
}

void UART_TransmitString(USART_TypeDef* uartPort, char* pString)
{
	int i = 0;
	while (pString[i] != '\0'){
		while ((uartPort->SR & USART_SR_TXE) != USART_SR_TXE);
		uartPort->DR = pString[i];
		i++;
	}
}

