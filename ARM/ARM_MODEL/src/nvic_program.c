/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
/* NVIC Controls External Peripherals(60 one in ARM Cortex M3) that can be used as Source of Interrupt Triggering ISR [ex:USART1_IRQHandler()] */
void NVIC_voidEnableInt (u8 Copy_u8Idx)
{
	if( Copy_u8Idx<=31)			//if(Copy_u8Idx>0 && Copy_u8Idx<=31) >> Not u8 is unsigned (it will be always > 0)
	{
		NVIC_ISER0 = (1<<Copy_u8Idx);		//Note that in NVIC we write Values Directly without using OR >> To be faster(less steps in assemply language)
	}
	else if( Copy_u8Idx<=59)		//else if(Copy_u8Idx>=32 && Copy_u8Idx<=59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC_ISER1 = (1<<Copy_u8Idx);
	}
}
void NVIC_voidDisableInt(u8 Copy_u8Idx)
{
	if( Copy_u8Idx<=31)			//if(Copy_u8Idx>0 && Copy_u8Idx<=31) >> Not u8 is unsigned (it will be always > 0)
	{
		NVIC_ICER0 = (1<<Copy_u8Idx);
	}
	else if( Copy_u8Idx<=59)		//else if(Copy_u8Idx>=32 && Copy_u8Idx<=59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC_ICER1 = (1<<Copy_u8Idx);
	}
}
/**************************************************************************/
void NVIC_voidSetPendingFlag(u8 Copy_u8Idx)
{
	if( Copy_u8Idx<=31)			//if(Copy_u8Idx>0 && Copy_u8Idx<=31) >> Not u8 is unsigned (it will be always > 0)
	{
		NVIC_ISPR0 = (1<<Copy_u8Idx);
	}
	else if( Copy_u8Idx<=59)		//else if(Copy_u8Idx>=32 && Copy_u8Idx<=59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC_ISPR1 = (1<<Copy_u8Idx);
	}
}
/**************************************************************************/
void NVIC_voidClrPendingFlag(u8 Copy_u8Idx)
{
	if( Copy_u8Idx<=31)			//if(Copy_u8Idx>0 && Copy_u8Idx<=31) >> Not u8 is unsigned (it will be always > 0)
	{
		NVIC_ICPR0 = (1<<Copy_u8Idx);
	}
	else if( Copy_u8Idx<=59)		//else if(Copy_u8Idx>=32 && Copy_u8Idx<=59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC_ICPR1 = (1<<Copy_u8Idx);
	}
}
/**************************************************************************/
ErrorStatus NVIC_Init_Split_GroupSub_Priorities(u8 Copy_u8Priority_4BitsDesign)		//SCB = System Control Block >>4 bits To Adjust Group Settings (ex: How many Groups and sub-Groups you want )
{										// STM-Programming Data sheet: page 135	 >>SCB_AIRCR = 0x05FA0#00;	[#] is used to design no. of Groups Or Subs Bits
	u8 Local_u8Error = OK;
	switch(Priority_4BitsDesign)//SCB_AIRCR = 0x05FA0#00;
	{
	case BitsNo_4Group_0Sub:	SCB_AIRCR = 0x05FA0300;		break;
	case BitsNo_3Group_1Sub:	SCB_AIRCR = 0x05FA0000;		break;
	case BitsNo_2Group_2Sub:	SCB_AIRCR = 0x05FA0500;		break;
	case BitsNo_1Group_3Sub:	SCB_AIRCR = 0x05FA0600;		break;
	case BitsNo_0Group_4Sub:	SCB_AIRCR = 0x05FA0700;		break;
	default :	Local_u8Error = OUT_OF_RANGE;				break;
	}
	return Local_u8Error;
}


/**************************************************************************/	//u8 Means that number is Positive >> No need to check if it is less than Zero
/*0b011 = 0x3	> [0] Bits for Group-Priority & [4] Bits for Sub-Priority			> Group: 0 ~ 1    & Sub: 0 ~ 15
* 0b100 = 0x0	> [1] Bits for Group-Priority & [3] Bits for Sub-Priority			> Group: 0 ~ 2    & Sub: 0 ~ 8
* 0b101 = 0x5	> [2] Bits for Group-Priority & [2] Bits for Sub-Priority	OPTIONS > Group: 0 ~ 4    & Sub: 0 ~ 4
* 0b110 = 0x6	> [3] Bits for Group-Priority & [1] Bits for Sub-Priority			> Group: 0 ~ 8    & Sub: 0 ~ 2
* 0b111 = 0x7	> [4] Bits for Group-Priority & [0] Bits for Sub-Priority			> Group: 0 ~ 15   & Sub: 0 ~ 1
*/
ErrorStatus NVIC_voidSetIntPriority (u8 Copy_u8Peripheral, u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority)		//Set a Priority of a Certain External Peripheral (as Group-Priority and Sub-Priority)
{
	u8 Copy_u8Priority;
	u8 Local_u8Error = OK;

	switch (SCB_AIRCR)
	{
	case 0x05FA0300:if(Copy_u8GroupPriority>1 || Copy_u8SubPriority>15)	{Local_u8Error = OUT_OF_RANGE;}		break;
	case 0x05FA0000:if(Copy_u8GroupPriority>2 || Copy_u8SubPriority>8)	{Local_u8Error = OUT_OF_RANGE;}		break;
	case 0x05FA0500:if(Copy_u8GroupPriority>4 || Copy_u8SubPriority>4)	{Local_u8Error = OUT_OF_RANGE;}		break;
	case 0x05FA0600:if(Copy_u8GroupPriority>8 || Copy_u8SubPriority>2)	{Local_u8Error = OUT_OF_RANGE;}		break;
	case 0x05FA0700:if(Copy_u8GroupPriority>15|| Copy_u8SubPriority>1)	{Local_u8Error = OUT_OF_RANGE;}		break;
	default:
		//Copy_u8Priority = 0b[Copy_u8GroupPriority][Copy_u8SubPriority][0000];
		Copy_u8Priority= Copy_u8GroupPriority;		//Wrong Value> ????????? >>BiTMath and BitMasking
		NVIC_IPR[Copy_u8Peripheral]= Copy_u8Priority;		//Note that: *P=P[0] & *(P+2)= P[2]
	}
	return Local_u8Error;
}

