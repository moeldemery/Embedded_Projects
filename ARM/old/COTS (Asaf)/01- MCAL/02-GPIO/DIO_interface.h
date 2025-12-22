/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_DIO_INTERFACE_H
#define 	_DIO_INTERFACE_H


#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7
#define DIO_PIN8		8
#define DIO_PIN9		9
#define DIO_PIN10		10
#define DIO_PIN11		11
#define DIO_PIN12		12
#define DIO_PIN13		13
#define DIO_PIN14		14
#define DIO_PIN15		15
#define DIO_PIN16		16
#define DIO_PIN17		17
#define DIO_PIN18		18
#define DIO_PIN19		19
#define DIO_PIN20		20
#define DIO_PIN21		21
#define DIO_PIN22		22
#define DIO_PIN23		23
#define DIO_PIN24		24
#define DIO_PIN25		25
#define DIO_PIN26		26
#define DIO_PIN27		27
#define DIO_PIN28		28
#define DIO_PIN29		29
#define DIO_PIN30		30
#define DIO_PIN31		31
#define DIO_PIN32		45		//32
#define DIO_PIN33		46		//33
#define DIO_PIN34		47		//34


#define DIO_OUT_2M_PP	X
#define DIO_OUT_2M_OD	X
#define DIO_OUT_2M_AFPP	X
#define DIO_OUT_2M_AFOD

#define DIO_OUT_10M_PP
#define DIO_OUT_10M_OD
#define DIO_OUT_10M_AFPP
#define DIO_OUT_10M_AFOD

#define DIO_OUT_50M_PP
#define DIO_OUT_50M_OD
#define DIO_OUT_50M_AFPP
#define DIO_OUT_50M_AFOD

#define DIO_IN_ANALOG
#define DIO_IN_FLOATING
#define DIO_IN_PULL_UP
#define DIO_IN_PULL_DOWN

#define DIO_HIGH	1
#define DIO_LOW		0
/*************************************************************************************/

void DIO_voidInitialize(void);
void DIO_SetPinValue (u8 Copy_u8PinNo , u8 Copy_u8PinValue);
void DIO_GetPinValue (u8 Copy_u8PinNo);




















/************************************************************/
/* Description: This function shall set						*/
/*				direction for I/O pins 						*/
/************************************************************/
void DIO_voidInitialize(void);

/************************************************************/
/* Description : Set the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)]
 * 			 [Copy_u8PinValue -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 *
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUT_OF_RANGE/NULL_POINTER].
 * */
/************************************************************/
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PinIdx, u8 Copy_u8PinVal);

/************************************************************/
/* Description : Get the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)]
 * 			 [* Copy_Pu8PinValue used to receive the pin value 0/1]
 *
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUT_OF_RANGE/NULL_POINTER].
 * */
/************************************************************/
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PinIdx, u8 *Copy_Pu8PinVal);

#endif