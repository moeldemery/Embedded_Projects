/*
 * TTWI.h
 *
 *  Created on: 5 Feb 2020
 *      Author: Mohamed
 */

#ifndef MCAL_INC_TWI_H_
#define MCAL_INC_TWI_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define 		TWBR	 		*((volatile u8 * ) (0x20))

#define 		TWCR	 		*((volatile u8 * ) (0x56))
	#define 	TWINT 			7
	#define 	TWEA 			6
	#define 	TWSTA 			5
	#define 	TWSTO 			4
	#define 	TWWC 			3
	#define 	TWEN 			2

	#define 	TWIE 			0

#define 		TWSR	 		*((volatile u8 * ) (0x21))
	#define 	TWS4 			7
	#define 	TWS3 			6
	#define 	TWS2 			5
	#define 	TWS1 			4
	#define 	TWS0 			3

	#define 	TWPS1 			1
	#define 	TWPS0 			0

#define 		TWDR	 		*((volatile u8 * ) (0x23))
#define 		TWAR	 		*((volatile u8 * ) (0x22))
	#define 	TWA 			1
	#define 	TWGCE 			0

#endif /* MCAL_INC_TWI_H_ */
