/*
	Name: 			DIO.h
	Copyright: 		v1
	Author: 		mohamed eldemery
	Date: 			07/02/20 06:22
	Description: 	
*/
#include "DIO.h"

void DIO_void_Init(void)
{
	/*config all pins output pp(pushpull) 2mhz */
	
	DIO_CRL_A= 0x22222222;
	DIO_CRL_B= 0x22222222;
	DIO_CRL_C= 0x22200000;
	DIO_CRH_A= 0x22222222;
	DIO_CRH_B= 0x22222222;
	DIO_CRH_C= 0x22200000;
}
void DIO_void_SetPinValue(u8 Copy_u8_PinNo, u8 Copy_u8_PinValue)
{
	u8 Local_u8_PortNo = Copy_u8_PinNo/16;
	u8 Local_u8_PinNo  = Copy_u8_PinNo%16;
	switch(Local_u8_PortNo):
	{
		case 0:	{ASSIGN_BIT(DIO_ODR_A,Local_u8_PinNo,Copy_u8_PinValue);break;}
		case 1:	{ASSIGN_BIT(DIO_ODR_B,Local_u8_PinNo,Copy_u8_PinValue);break;}
		case 2:	{ASSIGN_BIT(DIO_ODR_B,Local_u8_PinNo,Copy_u8_PinValue);break;}
	}
}
u8	 DIO_u8_GetPinValue(u8 Copy_u8_PinNo)
{
	
}

