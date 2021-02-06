/*
 * spi.h
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#ifndef _SPI_H_
#define _SPI_H_

extern void SPI_Init(SPI_TypeDef* spiPort, uint32_t spiConfig);
extern void SPI_SendOneByte(SPI_TypeDef* spiPort, uint8_t* data);
extern void SPI_SendMultipleBytes(SPI_TypeDef* spiPort, uint8_t* buffer, uint16_t length);
extern uint8_t SPI_ReceiveOneByte(SPI_TypeDef* spiPort);
extern void SPI_SendReceive(SPI_TypeDef* spiPort, uint8_t* TxData, uint8_t* RxData);
extern void SPI_SlaveSelect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin);
extern void SPI_SlaveDeselect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin);

#endif //_SPI_H_ 
