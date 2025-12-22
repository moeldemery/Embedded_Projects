/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_RCC_INTERFACE_H
#define 	_RCC_INTERFACE_H

/*This API shall Enable the Clock on Certain Peripheral*/
void RCC_voidEnableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral);

/*This API shall Disable the Clock on Certain Peripheral*/
void RCC_voidDisableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral);

/*This Function apply clock on Processor*/
void RCC_SystemCLKInit(void);


#endif