/*
 * BTN.h
 *
 *  Created on: 15 Jan 2020
 *      Author: Mohamed
 */

#ifndef HAL_INC_BTN_H_
#define HAL_INC_BTN_H_

#include "../UTILITIES/STD_TYPES.h"
#include "../UTILITIES/BIT_MATH.h"
#include "../MCAL/INC/DIO_driver.h"

u8 BTN0_GetValue(void);
u8 BTN1_GetValue(void);
u8 BTN2_GetValue(void);

#endif /* HAL_INC_BTN_H_ */
