/*
	Name: 			DIO.h
	Copyright: 		v1
	Author: 		mohamed eldemery
	Date: 			07/02/20 06:22
	Description: 	
*/

#ifndef _DIO_H
#define _DIO_H

#define DIO_BASE_ADD	 	0x40010800

#define DIO_CRL_A 	*((volatile U32*)DIO_BASE_ADD + 0x00)
#define DIO_CRH_A 	*((volatile U32*)DIO_BASE_ADD + 0x04)
#define DIO_IDR_A 	*((volatile U32*)DIO_BASE_ADD + 0x08)
#define DIO_ODR_A 	*((volatile U32*)DIO_BASE_ADD + 0x0C)


#define DIO_PIN_0 0 	
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4 
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_PIN_8 8 	
#define DIO_PIN_9 9
#define DIO_PIN_10 10
#define DIO_PIN_11 11
#define DIO_PIN_12 12
#define DIO_PIN_13 13
#define DIO_PIN_14 14
#define DIO_PIN_15 15

#define DIO_PIN_ 	
#define DIO_PIN_
#define DIO_PIN_
#define DIO_PIN_
#define DIO_PIN_
#define DIO_PIN_
#define DIO_PIN_
#define DIO_PIN_


#define DIO_OUT_2M_PP
#define DIO_OUT_2M_OD
#define DIO_OUT_2M_AFPP
#define DIO_OUT_2M_AFOD
#define DIO_OUT_10M_PP
#define DIO_OUT_10M_OD
#define DIO_OUT_10M_AFPP
#define DIO_OUT_10M_AFOD
#define DIO_OUT_50M_PP
#define DIO_OUT_50M_OD
#define DIO_OUT_50M_AFPP
#define DIO_OUT_50M_AFOD

#define DIO_IN_ANALOGE
#define DIO_IN_FLOATING
#define DIO_IN_PULL_UP
#define DIO_IN_PULL_DOWN

#define DIO_LOW		0x00
#define DIO_HIGH	0x01

void DIO_void_Init(void);
void DIO_void_SetPinValue(u8 Copy_u8_PinNo, u8 Copy_u8_PinValue);
u8	 DIO_u8_GetPinValue(u8 Copy_u8_PinNo);

#endif //_DIO_H
