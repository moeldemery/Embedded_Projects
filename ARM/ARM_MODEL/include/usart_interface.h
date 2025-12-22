/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 17 Feb 2020								*
 *******************************************************/


#ifndef 	_USART_INTERFACE_H
#define 	_USART_INTERFACE_H


/********************************************************************************************************
 * Description: This function(API) shall Initialize USART (Initial Configurations)
 * Parameters(Arguments) : void
 * Return: ErrorStatus
********************************************************************************************************/
ErrorStatus USART_EnuInit(void);


/********************************************************************************************************
 * Description: Initialize USART GPIO_Pins (we don't need to set Directions but Modes), Then Enable USART
 * Parameters(Arguments) : void
 * Return: ErrorStatus > Assuming USART1 & USART_Normal_DIO
********************************************************************************************************/
void USART1_Ready(void);


/********************************************************************************************************
 * Description: Receiving Character
 * Parameters(Arguments) : void
 * Return: u8 (Fetch Data Received)
 * Condition: Receiving Buffer should be including Received Data (not empty)
********************************************************************************************************/
u8 USART_voidReceiveData(void);


/********************************************************************************************************
 * Description: Transmitting Character
 * Parameters(Arguments) : u8 (Data will be transferred)
 * Return: void
 * Condition: Transmitting Buffer should be empty to add data that will be transferred
********************************************************************************************************/
void USART_voidSendData(char Copy_u8Data);



/********************************************************************************************************
 * Description: These functions shall describe a frame of data as String (Array of characters) being:
 * 			   -Transmitted >> (from My [M.C] to [Pooty] Screen & user can read it)
 * 			   -Receive >> (user write on pooty  (Data is sent from [pooty] to My [M.C] )
 * Parameters(Arguments) : * p >> Pointer to name of Array (which represents it's address)
 * Return: ErrorStatus
 * Condition: Receiving Buffer should be including Received Data (not empty)
********************************************************************************************************/
ErrorStatus USART_voidSendString(char * p);
ErrorStatus USART_voidReceiveLimitedString(char * p , u8 MessageSize);


/********************************************************************************************************
 * Description: These functions shall describe a frame of data as String (Array of characters) being:
 * 			   -Transmitted >> (from My [M.C] to [Pooty] Screen & user can read it)
 * 			   -Receive >> (user write on pooty  (Data is sent from [pooty] to My [M.C] )
 * 			   Notification function is called as an alarm that an interrupt happened ex: LED_ON(); or Alarm_ON();
 * 	To Avoid Synchronous Functions that will cause CPU to be Stuck, we use Asynchronous functions (By Enabling Interrupts)
 *******************************************************************************************************/

ErrorStatus USART_EnuSendString_Asynch(char *pArrOfChar ,  void(*pFunc)(void)  );
	// in app.c >> USART_EnuSendData_Asynch ("Hey!", LED_ON()); >>Once "Hey!" is sent successfully > Led will be on and notify about it
ErrorStatus USART_EnuReceiveString_Asynch(u8 *pArrOfChar , void( *pFunc )(void) , u8 RxMessageSize  );
	//char Arr_char[50]={0};
	// in app.c >> USART_EnuReceiveData_Asynch (8 ,Arr_char, LED_ON());


/********************************************************************************************************
 * Description: Testing USART1 Program
 *******************************************************************************************************/
void USART1_Testing_App(void);

#endif

