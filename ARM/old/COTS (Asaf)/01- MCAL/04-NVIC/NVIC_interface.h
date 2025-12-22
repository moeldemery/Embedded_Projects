/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_NVIC_INTERFACE_H
#define 	_NVIC_INTERFACE_H

/*DEFINES init*/


/*************************************************************************************/


/************************************************************/
/* Description : Set the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)]
 * 			 [Copy_u8PinValue -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 *
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUT_OF_RANGE/NULL_POINTER].
 * */
/************************************************************/
void NVIC_voidEnableInt	(u8 Copy_u8Idx);
void NVIC_voidDisableInt(u8 Copy_u8Idx);

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx);
void NVIC_voidClrPendingFlag(u8 Copy_u8Idx);





#endif //NVIC_INTERFACE