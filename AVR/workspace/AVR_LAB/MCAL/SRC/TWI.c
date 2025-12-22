/*
 * TWI.c
 *
 *  Created on: 5 Feb 2020
 *      Author: Mohamed
 */


#include "TWI.h"


void TWI_Master_StartCond_blocking(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!GET_BIT(TWCR,TWINT));
}
