/*
 * LED.h
 *
 *  Created on: 15 Jan 2020
 *      Author: Mohamed
 */

#ifndef HAL_INC_LED_H_
#define HAL_INC_LED_H_

#include "../UTILITIES/STD_TYPES.h"
#include "../UTILITIES/BIT_MATH.h"
#include "../MCAL/INC/DIO_driver.h"

void LED1_On(void);
void LED1_Off(void);
void LED1_Toggle(void);
void LED2_On(void);
void LED2_Off(void);

#endif /* HAL_INC_LED_H_ */
