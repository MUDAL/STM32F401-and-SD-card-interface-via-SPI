/*
 * gpio.h
 *
 *  Created on: 30 Jan 2021
 *      Author: OLAOLUWA
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

enum Gpio
{
	GPIO_AF_REG_LOW = 0,
	GPIO_AF_REG_HIGH
};

extern void GPIO_Alternate_Function_Init(GPIO_TypeDef* gpioPort, uint32_t gpioMode, 
														uint8_t gpioAF_Level, uint32_t gpioAF);

#endif /* INC_GPIO_H_ */
