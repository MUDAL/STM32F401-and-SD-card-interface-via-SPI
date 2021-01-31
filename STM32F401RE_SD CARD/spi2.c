/*
 * spi2.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */
#include "stm32f4xx.h"
#include "spi2.h"

void SPI2_Init(void)
{
	//serial clock baud rate = 64 hence SPI clock output = 16MHz / 64 = 0.25MHz or 250kHz
	//enable software slave management
	//enable internal slave select
	//enable master mode
	//enable SPI
	SPI2->CR1 |= (SPI_CR1_BR_0 | SPI_CR1_BR_2 | SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_MSTR | SPI_CR1_SPE);
}

void SPI2_SendOneByte(uint8_t* data)
{
	while ((SPI2->SR & SPI_SR_TXE) != SPI_SR_TXE); //wait for transmit buffer to be empty
	SPI2->DR = *data;
}

void SPI2_SendMultipleBytes(uint8_t* buffer, uint16_t length)
{
	for (uint16_t i = 0; i < length; i++)
	{
		while ((SPI2->SR & SPI_SR_TXE) != SPI_SR_TXE); //wait for transmit buffer to be empty
		SPI2->DR = buffer[i];
	}
}

uint8_t SPI2_ReceiveOneByte(void)
{
	while ((SPI2->SR & SPI_SR_RXNE) != SPI_SR_RXNE); //wait for receive buffer to contain data
	return SPI2->DR;
}

void SPI2_SendReceive(uint8_t* TxData, uint8_t* RxData)
{
	while ((SPI2->SR & SPI_SR_TXE) != SPI_SR_TXE); //wait for transmit buffer to be empty
	SPI2->DR = *TxData;
	while ((SPI2->SR & SPI_SR_RXNE) != SPI_SR_RXNE); //wait for receive buffer to contain data
	*RxData = SPI2->DR;

}

void SPI2_SlaveSelect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin)
{
	nssGpioPort->ODR &= ~nssGpioPin;
}

void SPI2_SlaveDeselect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin)
{
	nssGpioPort->ODR |= nssGpioPin;
}




