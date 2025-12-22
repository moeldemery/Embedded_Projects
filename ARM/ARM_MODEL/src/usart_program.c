/*
 * USART_program.c
 *
 *  Created on: Feb 17, 2020
 *      Author: DELL
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"



/********************************************************************************************************
 * Description: This function(API) shall Initialize USART (Initial Configurations)
 * Parameters(Arguments) : void
 * Return: ErrorStatus
********************************************************************************************************/
ErrorStatus USART_EnuInit(void)
{
	ErrorStatus Local_Error = OK ;

	RCC_enueripheralCLKState(RCC_USART1_PERIPHERAL,ENABLE);		// Enable USART1 Clock
	NVIC_voidEnableInt(VT_USART1);								// Enable NVIC Interrupts for USART1


	/****27.6.4 Control register 1 (USART_CR1)*************************************************************/
#if USART_ENABLEING == ENABLED		// USART enable
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_UE);
#elif USART_ENABLEING == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_UE);
#else
	Local_Error = NOK;
#endif

#if TE_ENABLING == ENABLED		// Enable Transmitting
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_TE);
#elif TE_ENABLING == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_TE);
#else
	Local_Error = NOK;
#endif

#if RE_ENABLING == ENABLED		// Enable Receiving and begins searching for a start bit
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_RE);
#elif RE_ENABLING == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_RE);
#else
	Local_Error = NOK;
#endif

#if TXE_INT == ENABLED		// TXE(Empty transferring Buffer) interrupt enable > Now I can Send Data
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_TXEIE);
#elif TXE_INT == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_TXEIE);
#else
	Local_Error = NOK;
#endif

#if TRx_COMPLT_INT == ENABLED		// Transmission complete interrupt enabled > Now I can Send Data
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_TCIE);
#elif TRx_COMPLT_INT == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_TCIE);
#else
	Local_Error = NOK;
#endif

#if RXNE_INT == ENABLED		// RXNE interrupt enable > Now I can Read data Received (when Receiving Buffer is not Empty)
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_RXNEIE);
#elif RXNE_INT == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_RXNEIE);
#else
	Local_Error = NOK;
#endif

#if WORD_LENGTH == Data_8_Bits		// Word length(Length of Frame)
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_M);
#elif WORD_LENGTH == Data_9_Bits
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_M);
#else
	Local_Error = NOK;		//I will choose 9Bits (8DataBits + 1 ParityBit)>By enabling parity check
#endif


#if Parity_CONTROL == ENABLED		// Parity control(check) enable
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_PCE);
#elif Parity_CONTROL == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_PCE);
#else
	Local_Error = NOK;
#endif

#if Parity_Selection == ODD_PARITY		// Parity selection
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_PS);
#elif Parity_Selection == EVEN_PARITY
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_PS);
#else
	Local_Error = NOK;
#endif

#if PE_INT == ENABLED		// PE interrupt enable
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_PEIE);
#elif PE_INT == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_PEIE);
#else
	Local_Error = NOK;
#endif




#if WakeUp_METHOD == IDLE_LINE		// Wakeup method
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_WAKE);
#elif WakeUp_METHOD == ADDRESS_MARK
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_WAKE);
#else
	Local_Error = NOK;
#endif

#if IDLE_INT == ENABLED		// IDLE interrupt enable
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_IDLEIE);
#elif IDLE_INT == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_IDLEIE);
#else
	Local_Error = NOK;
#endif

#if WakeUp_RECEIVER == ACTIVE_MODE		// Receiver wakeup
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_RWU);
#elif WakeUp_RECEIVER == MUTE_MODE
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_RWU);
#else
	Local_Error = NOK;
#endif

#if SENDING_BREAK == ENABLED		// Send Break
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_SBK);
#elif SENDING_BREAK == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR1_SBK);
#else
	Local_Error = NOK;
#endif

	/****27.6.5 Control register 2 (USART_CR2)*************************************************************/
#if STOP_BIT == STOP_1_Bit		// STOP_BIT
	CLR_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP1);
	CLR_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP0);
#elif STOP_BIT == STOP_half_Bit
	CLR_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP1);
	SET_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP0);
#elif STOP_BIT == STOP_2_Bits
	SET_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP1);
	CLR_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP0);
#elif STOP_BIT == STOP_1half_Bit
	SET_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP1);
	SET_BIT(USART1->CR2.FourByteAcess, USART_CR2_STOP0);
#else
	Local_Error = NOK;
#endif


#if USART_Mode == SYNCHRONOUS		// Error interrupt enable
	SET_BIT(USART1->CR2.FourByteAcess, USART_CR2_CLKEN);
#elif USART_Mode == ASYNCHRONOUS
	CLR_BIT(USART1->CR2.FourByteAcess, USART_CR2_CLKEN);
#else
	Local_Error = NOK;
#endif

	/****27.6.6 Control register 3 (USART_CR3)*************************************************************/
#if ERROR_INT == ENABLED		// Error interrupt enable
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR3_EIE);
#elif ERROR_INT == DISABLED
	CLR_BIT(USART1->CR1.FourByteAcess, USART_CR3_EIE);
#else
	Local_Error = NOK;
#endif

	/****27.6.7 Guard time and prescaler register (USART_GTPR)*************************************************************/
	 /* Set baud rate = 9600 Bps
	   * USARTDIV = Fck / (16 * baud_rate_desired)			//Fck is Clock of APB2 >>FOR USART1 >>Rcc is 8MHz
	   *          = 8000000 / (16 * 9600) = 52.083
	   *
	   * DIV_Fraction = 16 * 0.083 = 1.328 = 1 = 0x1		//8 or 16_OverSamplings (to have accurate reading not affected by noise)
	   * DIV_Mantissa = 0d52 = 0x34
	   *
	   * Baud Rate    = 0x341
	   *
	   * #when Receiving Data (Asynchronous mode = Different Clocks) we Use OverSampling Technique to discriminate between Valid Data & Noise
	   * OverSampling by 8 > Offers Higher Speed but less Tolerance of Clock Deviation OR  OverSampling by 16 > Vice Versa*/

#if BAUD_RATE == BAUD_9600		// Baud Rate Desired
	USART1->BRR.FourByteAcess = 0x341;
#elif BAUD_RATE == BAUD_115200
	USART1->BRR.FourByteAcess = 0x15;
#else
	Local_Error = NOK;
#endif


	return Local_Error;
}



/********************************************************************************************************
 * Description: Initialize USART GPIO_Pins (we don't need to set Directions but Modes), Then Enable USART
 * Parameters(Arguments) : void
 * Return: ErrorStatus > Assuming USART1 & USART_Normal_DIO
********************************************************************************************************/
void USART1_Ready(void)		// Initialize USART_GPIO_Pins Then Enable It
{
  /* First: Initialize USART1_GPIO_Pins */
	/*
	 * Normal_DIO :USART1_TX>[PA9] & USART1_RX>[PA10] / Alternative_DIO: USART1_TX>[PB6] & USART1_RX>[PB7] >>> Page 180
	 * Note that We don't need to Set Directions of PA9,10 Pins because It will be Set automatically by USART
	 * But we Need to Set Pins_Mode and Enable Clock of Peripheral
	 */

		//First we Enable Clock for PortA
		RCC_enueripheralCLKState(RCC_GPIOA_PERIPHERAL,ENABLE);

		// Set H.W Pin USART1_TX>[PA9] >> as OutPut Direction , 2 MHz Speed, Push Pull Mode
		DIO_enuSetPinMode(DIO_u8_PIN9 , DIO_u8_OUTPUT_2M_PP);

		// Set H.W Pin USART1_RX>[PA10] >> as InPut Direction , Pull down Mode
		DIO_enuSetPinMode(DIO_u8_PIN10 , DIO_u8_INPUT_PULLDOWN);

  /* Second: USART Enable > USART is Ready Now */
	SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_UE);
}



/********************************************************************************************************
 * Description: Receiving Character
 * Parameters(Arguments) : void
 * Return: u8 (Fetch Data Received)
 * Condition: Receiving Buffer should be including Received Data (not empty)
********************************************************************************************************/
u8 USART_voidReceiveData(void)
{
	/*Once Receive Buffer is not Empty, I can read(fetch)Data Received >Can't read data from empty R_Buffer*/
	while ((GET_BIT(USART1->SR.FourByteAcess,USART_SR_RXNE))==0);	//(Waiting for data to be received)

	/*Once (UCSRA_RXC=1) >> Now you can fetch data from R_Buffer(full now) & read it */
	return USART1->DR.FourByteAcess;
}


/********************************************************************************************************
 * Description: Transmitting Character
 * Parameters(Arguments) : u8 (Data will be transferred)
 * Return: void
 * Condition: Transmitting Buffer should be empty to add data that will be transferred
********************************************************************************************************/
void USART_voidSendData(char Copy_u8Data)
{
	/*Once Transmitting Buffer is empty, I can transmit New Data >Can't put data in full T_Buffer)*/
	while ((GET_BIT(USART1->SR.FourByteAcess,USART_SR_TXE))==0);		//(Wait until transmit buffer is empty)

	/*Once (UCSRA_UDRE=1) >> Now you can write new Data in T_Buffer(empty now) to be transmitted */
	USART1->DR.FourByteAcess = Copy_u8Data;
}



/********************************************************************************************************
 * Description: These functions shall describe a frame of data as String (Array of characters) being:
 * 			   -Transmitted >> (from My [M.C] to [Pooty] Screen & user can read it)
 * 			   -Receive >> (user write on pooty  (Data is sent from [pooty] to My [M.C] )
 * Parameters(Arguments) : * p >> Pointer to name of Array (which represents it's address)
 * Return: ErrorStatus
 * Condition: Receiving Buffer should be including Received Data (not empty)
********************************************************************************************************/
ErrorStatus USART_voidSendString(char * p)
{
	ErrorStatus Local_Error= OK;
		if(p == NULL)
		{
			Local_Error = NULL_POINTER;
		}
		else
		{
			while(*p != '\0')			//Because last character in a string is null '\0'
			{
				USART_voidSendData(*p);
				p++;
			}
		}
		return Local_Error;
}

/***********************************************************************/
/*Now user will write on pooty screen, It will send it to My M.C(AVR)*/
ErrorStatus USART_voidReceiveLimitedString(char * p , u8 MessageSize) // we can choose to return ErrorStatus or void
{
	u8 i;
	ErrorStatus Local_Error= OK;
		if(p == NULL)
		{
			Local_Error = NULL_POINTER;
		}
		else
		{
			for (i=0 ; i <= MessageSize ; i++)		///Pooty can only send string up to (MessageSize) ex: 5 characters from user
			{

				*p = USART_voidReceiveData();	//p[i] = USART_voidReceiveData();
				p++;
			}
		}
		return Local_Error;
}


/********************************************************************************************************
 * Description: These functions shall describe a frame of data as String (Array of characters) being:
 * 			   -Transmitted >> (from My [M.C] to [Pooty] Screen & user can read it)
 * 			   -Receive >> (user write on pooty  (Data is sent from [pooty] to My [M.C] )
 * 			   Notification function is called as an alarm that an interrupt happened ex: LED_ON(); or Alarm_ON();
 * 	To Avoid Synchronous Functions that will cause CPU to be Stuck, we use Asynchronous functions (By Enabling Interrupts)
 *******************************************************************************************************/

/**********************************************************************************************/
/***************If we want to use Complete_Transmission interrupt******************************/
/*Global Variables*/
	/*Transmitted String Array*/
	/*const*/ static char *TransmetedString= NULL;		//we will always deal with string as [constant] & [static]>file scope (use in this file only to avoid multiple definition and Linker Error)
	/*Transmission callback notification function*/
	static void( *pTxCallbackFunc )(void) = NULL;		//pointer to function with void input and return void
	/*Transmission index*/
	static u8 TxIndex;
ErrorStatus USART_EnuSendString_Asynch(/*const*/ char *pArrOfChar ,  void( *pFunc )(void)  )		// in app.c >> USART_EnuSendData_Asynch ("Hey!", LED_ON() );
{												// *p is a pointer to array of char [string]
												// *pFunc is a pointer to function
	ErrorStatus Local_Error= OK;
	if( (pArrOfChar == NULL) || (pFunc == NULL) )
	{
		Local_Error = NULL_POINTER;
	}
	else
	{
		/*Transmitted string Initialization */
		TransmetedString = pArrOfChar;

		/*Callback Initialization*/
		pTxCallbackFunc = pFunc;

		/*Array Index Initialization*/
		TxIndex = 0;

		/*Enable Interrupt (TXE_INT == Enabled), when Transferring Buffer is empty > we Can Send new Data*/
		SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_TXEIE);
/* Now processor will be doing other tasks normally but Once (USART_SR_TXE=1)[Tx Data Register empty flag is raised] ,USART1_Handler will be triggered  */

		/*Enable Interrupt (TRx_COMPLT_INT == Enabled), when Transmission is Completed (whole message is Sent) */
		SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_TCIE);
	}
return Local_Error;
}

/**********************************************************************************************/
/***************If we want to use receive_complete interrupt******************************/


//Receiving String Array
static u8 *ReceivedString= NULL;		//we will always deal with string as [const] & [static]>file scope (use in this file only)
//Receiving call back function notification function
static void( *pRxCallbackFunc )(void) = NULL;
//Receiving Index
static u8 RxIndex;
//Received message size >> If I want to Receive limited String (Specify it's max limit user can send to me)
static u8 RxMessageLength ;


ErrorStatus USART_EnuReceiveString_Asynch(u8 *pArrOfChar , void( *pFunc )(void) , u8 RxMessageSize  )
{												// *p is a pointer to array of char [string]

	ErrorStatus Local_Error= OK;
	if( (pArrOfChar == NULL) || (pFunc == NULL) )
	{
		Local_Error = NULL_POINTER;
	}
	else
	{
		/*Received string(ArrOfChar) Initialization */
		ReceivedString = pArrOfChar;

		/*RxCallback Initialization*/
		pRxCallbackFunc = pFunc;

		/*Array Index Initialization*/
		RxIndex = 0;

		/*Message Size Initialization*/
		RxMessageLength = RxMessageSize;


		/*Enable Interrupt (RXNE_INT == Enabled), when Receiving Buffer is Not_Empty(Received Data) > we Can Fetch and Read this Data Received*/
		SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_RXNEIE);
/* Now processor will be doing other tasks normally but Once (USART_SR_RXNE=1)[Rx Data Register Not-empty flag is raised] ,USART1_Handler will be triggered  */

		/*Enable Parity Error Interrupt (PE_INT == Enabled) >> processor will be doing other tasks normally until [USART_SR_PE ==1]*/
		SET_BIT(USART1->CR1.FourByteAcess, USART_CR1_PEIE);

		/*Enable Frame Error Interrupt (ERROR_INT == Enabled) >> processor will be doing other tasks normally until [USART_SR_FE ==1]*/
		SET_BIT(USART1->CR1.FourByteAcess, USART_CR3_EIE);
	}
	return Local_Error;
}

/**********************************************************************************************/
/*************ISR Function in case of Interrupts>>>USART1_IRQHandler****************************/
void USART1_IRQHandler(void)		//Condition: NVIC must be Enabled > in Vector Table is 37 for USART1 >>STM RegisterDataSheet Page:204
{
/*Note that I will not use [else if()] >> Because More than one Error may Happen at same time, I want to double check all of them without skipping any
 *  error checking (even if it took longer time and not_Predictable Response time (Because I am having only one Handler(ISR) for all USART_Interrupts*/

/*************************************************/
	// When (flag is raised that Receiving Buffer is not Empty) >> Now I Can fetch and read Data Received
	//Condition: (RXNE_INT == Enabled)
	if (GET_BIT(USART1->SR.FourByteAcess, USART_SR_RXNE)==1)				//Or  if((USART1->SR & USART_SR_RXNE) == USART_SR_RXNE)
	{
		/* RXNE_INT Declaration */
		DIO_enuSetPinValue(DIO_u8_PIN2 , DIO_u8_HIGH);		//PA2

		//if (ReceivedString[RxIndex] != '\0')	// If still receiving Data = Not end of frame yet
		//Receive the current Element
			ReceivedString[RxIndex]= USART1->DR.FourByteAcess;

		//Index Increment
			RxIndex++;

			if (RxIndex == RxMessageLength || ReceivedString[RxIndex] == '\0')			//If user inputs are exceeding Specified Length or frame is ended
			{
				// Clear Flag
				CLR_BIT(USART1->SR.FourByteAcess, USART_SR_RXNE);

				//Invoke the Rx callback notification function
				pRxCallbackFunc();
			}

	}

/*************************************************/
	//Condition: (TXE_INT == Enabled)
	if (GET_BIT(USART1->SR.FourByteAcess, USART_SR_TXE)==1 )		//Once a frame(Character) of data is Sent
	{
		/* TXE_INT Declaration */
		DIO_enuSetPinValue(DIO_u8_PIN3 , DIO_u8_HIGH);		//PA3		>>TxE_INT



		if (TransmetedString[TxIndex] != '\0')	// Check for end-of-line condition
		{
			/*Send the current Element*/
			USART1->DR.FourByteAcess = TransmetedString[TxIndex];	//OR > UDR = *TransmetedString;

			/*Index Increment*/
			TxIndex ++;
		}
		else			// else if (TransmetedString[TxIndex] == '\0')	>>	if last character of Frame
		{
			/* Clear Flag */
			CLR_BIT(USART1->SR.FourByteAcess, USART_SR_TXE);
			/*Invoke the notification callback function (any Notification to the user that an interrupt happened ex: LED_ON();*/
			//pTxCallbackFunc();		//I don't need to use call back function for each Frame of Data Sent
		}
	}

/*************************************************/
	//Condition: (TRx_COMPLT_INT == Enabled)
	if (GET_BIT(USART1->SR.FourByteAcess, USART_SR_TC)==1)		// whole message is sent(all frames) & TXE is raised but no more data to send
	{
		/* Declare a notification message or function(Turn led On) Or Both */
		USART_voidSendString("Transmission is complete and message is sent");
		DIO_enuSetPinValue(DIO_u8_PIN4 , DIO_u8_HIGH);		//PA4

			/* Clear Flag */
			CLR_BIT(USART1->SR.FourByteAcess, USART_SR_TC );
			/*Invoke the notification callback function (any Notification to the user that an interrupt happened ex: LED_ON();*/
			pTxCallbackFunc();			// when whole message is Sent, I want a notification message
	}

/*************************************************/
		//when parity check & Interrupt are Both enabled, and we received a frame(character) of Data with parity Error, This
	if (GET_BIT(USART1->SR.FourByteAcess, USART_SR_PE)==1)		//OR > if((USART1->SR & USART_SR_PE) == USART_SR_PE)
	{
		/* Declare parity error */
		USART_voidSendString("Parity Error");
		DIO_enuSetPinValue(DIO_u8_PIN6 , DIO_u8_HIGH);		//PA6


		/* Clearing Error By Receiving any other value*/
		while(GET_BIT(USART1->SR.FourByteAcess, USART_SR_RXNE)==0)					//while((USART1->SR & USART_SR_RXNE) != USART_SR_RXNE)
		    {
		      /* Wait for RXNE flag to be set */
		    }

		    /* Read data register to clear parity error */
		    USART1->DR.FourByteAcess;												// It is mentioned in Reference manual how to Clear Parity Error


	}
/*************************************************/
	static const char FrameError[] = "Frame Error";	//Esm el array hwa 3nwanha

		//when Error Interrupt is Enabled and an Error happen in Data Frame Transmitted
	if (GET_BIT(USART1->SR.FourByteAcess, USART_SR_FE)==1)
	{
		/* Declare Frame error */
		USART_voidSendString(FrameError);
		DIO_enuSetPinValue(DIO_u8_PIN7 , DIO_u8_HIGH);	//PA7

		/* Clearing Error By Receiving any other value*/
		while(GET_BIT(USART1->SR.FourByteAcess, USART_SR_RXNE)==0)					//while((USART1->SR & USART_SR_RXNE) != USART_SR_RXNE)
			{
			  /* Wait for RXNE flag to be set */
			}

			/* Read data register to clear parity error */
			USART1->DR;
	}
}






/********************************************************************************************************
*********************************************************************************************************
 * Description: Testing USART1 Program
 ********************************************************************************************************
********************************************************************************************************/
typedef enum		// Sequential Flags
{
  USART1_IDLE,
  USART1_WAIT_FOR_NAME,
  USART1_ASK_FOR_Command,
  USART1_WAIT_FOR_COMMAND,
  USART1_WAIT_FOR_RESPONCE,

} USART1_StateType;

static USART1_StateType currentState = USART1_IDLE;		//Set Initial Value (Flag)


//USART1 messages to be transmitted (Expressed as Arrays)
static const char ask_for_name[]       = "What is your name?";
static const char Name_OF_USER_Arr[20] = {0};
static const char hi[]                 = "Hi,";
static const char ask_for_command[]    = "Kindly choose Action: [turn_on / turn_off] [green_led / red_led]";
static const char turn_on_green_led[]  = "turn_on green_led";
static const char turn_on_red_led[]    = "turn_on red_led";
static const char turn_off_green_led[] = "turn_off green_led";
static const char turn_off_red_led[]   = "turn_off red_led";
static const char done[]               = "Done";
static const char wrong_command[]      = "Wrong Command";
static const char parity_error[]       = "Parity Error";


void USART1_Testing_App(void)
{
	/* Reset USART1 state */
	currentState = USART1_IDLE;

  switch (currentState)
  {
    case USART1_IDLE:

    	/* Go to next state */
      currentState = USART1_WAIT_FOR_NAME;

      /* Transmit data */
      //USART_EnuSendString_Asynch("Hello Customer" ,ledToggle_Pin32 );
      USART_EnuSendString_Asynch(ask_for_name ,ledToggle_Pin32 );


      break;

    case USART1_WAIT_FOR_NAME:
    	USART_EnuReceiveString_Asynch(Name_OF_USER_Arr, ledToggle_Pin32, 15);	// I will Receive a max of 15 characters from Customer and store them in Buffer [Name_OF_USER]

        /* Go to next state */
        currentState = USART1_ASK_FOR_Command;
      break;

    case USART1_ASK_FOR_Command:
      /* Transmit data */
    	USART_EnuSendString_Asynch(ask_for_command ,ledToggle_Pin32 );

      /* Go to next state */
      currentState = USART1_WAIT_FOR_COMMAND;
      break;


    case USART1_WAIT_FOR_COMMAND:
    	break;
  }
}



/***********************************************************************************************************************************/
/*ErrorStatus USARTx_Ready(u8 Copy_USART, u8 Copy_ConnectionPins)
{
	ErrorStatus Local_Error = OK ;

	switch(Copy_USART)
	{
	case USART1:
		if (Copy_ConnectionPins == Normal_DIO)				// Normal_DIO :USART1_TX>[PA9] & USART1_RX>[PA10]  >> Page 180
		{

		}
		else if (Copy_ConnectionPins == Alternative_DIO)	// Alternative_DIO: USART1_TX>[PB6] & USART1_RX>[PB7] >> Page 180
		{

		}
		else
			Local_Error = NOK;
	break;
	}
	return Local_Error;
}
*/
