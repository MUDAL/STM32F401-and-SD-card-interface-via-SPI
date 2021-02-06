/*
 * spi.c
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */
#include "stm32f4xx.h"
#include "spi.h"

void SPI_Init(SPI_TypeDef* spiPort, uint32_t spiConfig)
{
	spiPort->CR1 |= spiConfig;
}

void SPI_SendOneByte(SPI_TypeDef* spiPort, uint8_t* data)
{
	while ((spiPort->SR & SPI_SR_TXE) != SPI_SR_TXE); //wait for transmit buffer to be empty
	spiPort->DR = *data;
}

void SPI_SendMultipleBytes(SPI_TypeDef* spiPort, uint8_t* buffer, uint16_t length)
{
	for (uint16_t i = 0; i < length; i++)
	{
		while ((spiPort->SR & SPI_SR_TXE) != SPI_SR_TXE); //wait for transmit buffer to be empty
		spiPort->DR = buffer[i];
	}
}

uint8_t SPI_ReceiveOneByte(SPI_TypeDef* spiPort)
{
	while ((spiPort->SR & SPI_SR_RXNE) != SPI_SR_RXNE); //wait for receive buffer to contain data
	return spiPort->DR;
}

void SPI_SendReceive(SPI_TypeDef* spiPort, uint8_t* TxData, uint8_t* RxData)
{
	while ((spiPort->SR & SPI_SR_TXE) != SPI_SR_TXE); //wait for transmit buffer to be empty
	spiPort->DR = *TxData;
	while ((spiPort->SR & SPI_SR_RXNE) != SPI_SR_RXNE); //wait for receive buffer to contain data
	*RxData = spiPort->DR;

}

void SPI_SlaveSelect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin)
{
	nssGpioPort->ODR &= ~nssGpioPin;
}

void SPI_SlaveDeselect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin)
{
	nssGpioPort->ODR |= nssGpioPin;
}




