#include "stm32f4xx.h"                  // Device header
#include "gpio.h"
#include "uart.h"

void Serial_Init(void)
{
	GPIO_Alternate_Function_Init(GPIOA,GPIO_MODER_MODER2_1,GPIO_AF_REG_LOW, 
																GPIO_AFRL_AFSEL2_0 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_2); 
  UART_Init(USART2,BAUD_115200,0,USART_CR1_TE);
}

void Serial_Transmit(char* pData)
{
	UART_TransmitString(USART2,pData);
}