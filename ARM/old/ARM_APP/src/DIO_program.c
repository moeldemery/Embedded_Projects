/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidInitialize(void)
{
	/*Configure all pins output PP 2M */
	DIO_CRL_A = 0x22222222;		//>> 01 for pp Mode & 00 for input [0x2 = 0b0010] 
	DIO_CRL_B = 0x22222222;
	DIO_CRH_A = 0x22222222;
	DIO_CRH_B = 0x22222222;
	DIO_CRH_C = 0x22200000;
}

void DIO_SetPinValue (u8 Copy_u8PinNo , u8 Copy_u8PinValue)
{
	u8 Local_u8PortNum = Copy_u8PinNo / 16 ;
	u8 Local_u8PinNum  = Copy_u8PinNo % 16 ;
	
	switch (Local_u8PortNum)
	{
		case 0: ASSIGN_BIT(DIO_ODA_A , Local_u8PinNum , Copy_u8PinValue);	break;
		case 1: ASSIGN_BIT(DIO_ODA_B , Local_u8PinNum , Copy_u8PinValue);	break;
		case 2: ASSIGN_BIT(DIO_ODA_C , Local_u8PinNum , Copy_u8PinValue);	break;
	}
}
u8 DIO_GetPinValue (u8 Copy_u8PinNo)
{
	u8 Local_u8PortNum = Copy_u8PinNo / 16 ;
	u8 Local_u8PinNum  = Copy_u8PinNo % 16 ;
	u8 Local_u8Result;
	
	switch (Local_u8PortNum)
	{
		case 0: Local_u8Result = GET_BIT(DIO_ODA_A , Local_u8PinNum );	break;
		case 1: Local_u8Result = GET_BIT(DIO_ODA_B , Local_u8PinNum );	break;
		case 2: Local_u8Result = GET_BIT(DIO_ODA_C , Local_u8PinNum );	break;
	}
	return Local_u8Result;
}
