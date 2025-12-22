/*
 * INT_program.c
 *
 *  Created on: 11 Jan 2020
 *      Author: Mohamed
 */


#include "../INC/INT_interface.h"

void INT_Void_ExternalIntInit(u8 Copy_u8_ChannelNo)
{
	SET_BIT(SREG_REG,7);			//enable general interrupt
	SET_BIT(MCUCR_REG,0);			//any logical change

	switch (Copy_u8_ChannelNo)
	{
		case EXT_INT_0:
		{
			SET_BIT(GICR_REG,EXT_INT_0);	//enable external interrupt 0
			//SEI();
			break;
		}
		case EXT_INT_1:
		{
			SET_BIT(GICR_REG,EXT_INT_1);	//enable external interrupt 1
			break;
		}
		case EXT_INT_2:
		{
			SET_BIT(GICR_REG,EXT_INT_2);	//enable external interrupt 2
			break;
		}
		default:
		{

			break;
		}

	}
}



