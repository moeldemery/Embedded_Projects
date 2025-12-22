/*
 * main.c
 *
 *  Created on: Feb 10, 2020
 *      Author: DELL
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"

	// USART 1 & Normal_DIO [No Re-mapping]

#define MAX_BUFFER_LENGTH	   ((u32) 200u)


int main(void)
{
	RCC_SystemCLKInit();////SysClk = HSE = 8MHz = ABH = APB1 = APB2

	//To Toggle Pin32 (Green Led)
	RCC_enueripheralCLKState(RCC_GPIOC_PERIPHERAL,ENABLE);		// RCC_voidEnableClock(2,4);	>> I/O port C clock enable [RCC_APB2ENR_IOPCEN] > Page 145
	DIO_enuSetPinMode(DIO_u8_PIN32 , DIO_u8_OUTPUT_2M_PP);
	DIO_enuSetPinValue(DIO_u8_PIN32 , DIO_u8_LOW);	//Actively LOW Green Led inside ARM chip(Not External Pin)>> Apply Low to activate

	USART_EnuInit();		//Enable RCC_USART1 & Enable NVIC & Initialize USART with Configured Settings

	USART1_Ready();

/*Set Modes*/
	DIO_enuSetPinMode(DIO_u8_PIN7 , DIO_u8_OUTPUT_2M_PP);		//PA7
	DIO_enuSetPinMode(DIO_u8_PIN6 , DIO_u8_OUTPUT_2M_PP);		//PA6
	DIO_enuSetPinMode(DIO_u8_PIN5 , DIO_u8_OUTPUT_2M_PP);		//PA5
	DIO_enuSetPinMode(DIO_u8_PIN4 , DIO_u8_OUTPUT_2M_PP);		//PA4
	DIO_enuSetPinMode(DIO_u8_PIN3 , DIO_u8_OUTPUT_2M_PP);		//PA3
	DIO_enuSetPinMode(DIO_u8_PIN2 , DIO_u8_OUTPUT_2M_PP);		//PA2


	/*	// Indicating Leds
	DIO_enuSetPinValue(DIO_u8_PIN7 , DIO_u8_HIGH);		//PA7		>>frame error
	DIO_enuSetPinValue(DIO_u8_PIN6 , DIO_u8_HIGH);		//PA6		>>Parity error
	DIO_enuSetPinValue(DIO_u8_PIN5 , DIO_u8_HIGH);		//PA5
	DIO_enuSetPinValue(DIO_u8_PIN4 , DIO_u8_HIGH);		//PA4		>>TC_INt
	DIO_enuSetPinValue(DIO_u8_PIN3 , DIO_u8_HIGH);		//PA3		>>TxE_INT
	DIO_enuSetPinValue(DIO_u8_PIN2 , DIO_u8_HIGH);		//PA2		>>RxNE_INT*/

	static const char hi[]= "Hi,";
	char Arr[MAX_BUFFER_LENGTH]={0};		// array of 200u characters > initialized as zero

/*
 	 // A) Sending and Receiving Character
		USART_voidSendData('A');
		USART_voidReceiveData();
*/
/*
 	 // B) Sending and Receiving String = Array of Characters (Synchronous=Pooling)
		USART_voidSendString(hi);
		USART_voidSendString(" SUNNY ! ");
		USART_voidReceiveLimitedString(Arr , 20);
*/
/*
 	 // C) Sending and Receiving String = Array of Characters (Asynchronous)
		USART_EnuSendString_Asynch(hi , ledToggle_Pin32);				//Send data in Buffer[hi] and Turn led32 off
		USART_EnuReceiveString_Asynch(Arr, ledToggle_Pin32, 15);		// user can enter a max of 15 characters that will be stored in Arr & Led32 will toggle once Receiving data
*/
	while(1)
	{
		//USART1_Testing_App();
	}
}


