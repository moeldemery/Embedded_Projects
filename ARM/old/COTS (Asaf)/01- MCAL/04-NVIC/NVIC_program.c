/********************************************************
 * Author 	: Demery										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#include "../04- LIB/STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/*THIS FUNCTION USED TO ENABLE THE SELECTED INTRRUPT*/

void NVIC_voidEnableInt	(u8 Copy_u8Idx)
{
	if(Copy_u8Idx >= 0 && Copy_u8Idx <= 31)  		//fisrt check is redundance 
	{
		NVIC_ISER0 = (1<< Copy_u8Idx);
	}
	else if(Copy_u8Idx >= 32 && Copy_u8Idx <=59)	//since it is elseif first check is redundance
	{
		Copy_u8Idx -= 32;
		NVIC_ISER1 = (1<< Copy_u8Idx);
	}
		
}

void NVIC_voidDisableInt(u8 Copy_u8Idx)
{
	if(Copy_u8Idx >= 0 && Copy_u8Idx <= 31)  		//fisrt check is redundance 
	{
		NVIC_ICER0 = (1<< Copy_u8Idx);
	}
	else if(Copy_u8Idx >= 32 && Copy_u8Idx <=59)	//since it is elseif first check is redundance
	{
		Copy_u8Idx -= 32;
		NVIC_ICER1 = (1<< Copy_u8Idx);
	}
}

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx)
{
	if(Copy_u8Idx >= 0 && Copy_u8Idx <= 31)  		//fisrt check is redundance 
	{
		NVIC_ISPR0 = (1<< Copy_u8Idx);
	}
	else if(Copy_u8Idx >= 32 && Copy_u8Idx <=59)	//since it is elseif first check is redundance
	{
		Copy_u8Idx -= 32;
		NVIC_ISPR1 = (1<< Copy_u8Idx);
	}
}
void NVIC_voidClrPendingFlag(u8 Copy_u8Idx)
{
	if(Copy_u8Idx >= 0 && Copy_u8Idx <= 31)  		//fisrt check is redundance 
	{
		NVIC_ICPR0 = (1<< Copy_u8Idx);
	}
	else if(Copy_u8Idx >= 32 && Copy_u8Idx <=59)	//since it is elseif first check is redundance
	{
		Copy_u8Idx -= 32;
		NVIC_ICPR1 = (1<< Copy_u8Idx);
	}
}
