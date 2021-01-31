/*
 * spi2.h
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#ifndef INC_SPI2_H_
#define INC_SPI2_H_

extern void SPI2_Init(void);
extern void SPI2_SendOneByte(uint8_t* data);
extern void SPI2_SendMultipleBytes(uint8_t* buffer, uint16_t length);
extern uint8_t SPI2_ReceiveOneByte(void);
extern void SPI2_SendReceive(uint8_t* TxData, uint8_t* RxData);
extern void SPI2_SlaveSelect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin);
extern void SPI2_SlaveDeselect(GPIO_TypeDef* nssGpioPort, uint32_t nssGpioPin);

#endif /* INC_SPI2_H_ */
