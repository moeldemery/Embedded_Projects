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


//ErrorStatus DIO_enuInit(void);

//to Set each pin Mode (Direction [in/out put] + Mode [Pullup/down - OpenDrain
ErrorStatus DIO_enuSetPinMode (u8 Copy_u8PinNb , u8 Copy_u8PinMode)
{
	ErrorStatus Local_enuReturnState= OK;
	/*Check PIN Number within the Range*/
	if ( Copy_u8PinNb <= DIO_u8_PIN34 )/*  &&[Copy_u8PinNb >= DIO_u8_PIN0] */ //Note that anyway (number will never be less than Zero because it is u32> Unsigned Variable)
	{
		u8 Local_u8PortNb = Copy_u8PinNb / 16;			//ex: Pin16 > PortA , Pin20> PortB >> 12/16=0 , 20/16=1 , 31/16=2
		u8 Local_u8PinNb  = Copy_u8PinNb % 16;			//	12%16=12 , 20%16=4 , 31%16=16 , 45%16=13


		switch (Local_u8PortNb)
		{
			case 0://PORTA
				/*Checking of Customer wants PullUp Or PullDown Input Modes >> we will store that in ODR Register*/
				if (Copy_u8PinMode == DIO_u8_INPUT_PULLUP)
				{
					SET_BIT(GPIOA ->ODR , Local_u8PinNb);
				}
				else if(Copy_u8PinMode == DIO_u8_INPUT_PULLDOWN)
				{
					CLR_BIT(GPIOA ->ODR , Local_u8PinNb);
				}
				/*Setting Mode of PIN*/
				if(Local_u8PinNb <=7)
				{
					ASSIGN_NIBBLE_VALUE(GPIOA->CRL , Local_u8PinNb , Copy_u8PinMode);
				}
				else if(Local_u8PinNb <=15)
				{
					Local_u8PinNb -= 8;
					ASSIGN_NIBBLE_VALUE(GPIOA->CRH , Local_u8PinNb , Copy_u8PinMode);
				}
				break;

				/*********************************************************************/
			case 1://PORTB
			/*Checking of Customer wants PullUp Or PullDown Input Modes >> we will store that in ODR Register*/
			if (Copy_u8PinMode == DIO_u8_INPUT_PULLUP)
			{
				SET_BIT(GPIOB ->ODR , Local_u8PinNb);
			}
			else if(Copy_u8PinMode == DIO_u8_INPUT_PULLDOWN)
			{
				CLR_BIT(GPIOB ->ODR , Local_u8PinNb);
			}
			/*Setting Mode of PIN*/
			if(Local_u8PinNb <=7)
			{
				ASSIGN_NIBBLE_VALUE(GPIOB->CRL , Local_u8PinNb , Copy_u8PinMode);
			}
			else if(Local_u8PinNb <=15)
			{
				Local_u8PinNb -= 8;
				ASSIGN_NIBBLE_VALUE(GPIOB->CRH , Local_u8PinNb , Copy_u8PinMode);
			}
			break;

			case 2://PORTC
				/*Checking of Customer wants PullUp Or PullDown Input Modes >> we will store that in ODR Register*/
				if (Copy_u8PinMode == DIO_u8_INPUT_PULLUP)
				{
					SET_BIT(GPIOC ->ODR , Local_u8PinNb);
				}
				else if(Copy_u8PinMode == DIO_u8_INPUT_PULLDOWN)
				{
					CLR_BIT(GPIOC ->ODR , Local_u8PinNb);
				}
				/*Setting Mode of PIN*/
//				if(Local_u8PinNb <=7)		>>> We don't need it in PortC
//					{
//						ASSIGN_NIBBLE_VALUE(GPIOC->CRL , Local_u8PinNb , Copy_u8PinMode);
//					}
				if(Local_u8PinNb <=15 && Local_u8PinNb >=13)
					{
						Local_u8PinNb -= 8;
						ASSIGN_NIBBLE_VALUE(GPIOC->CRH , Local_u8PinNb , Copy_u8PinMode);
					}
					else
					{
						Local_enuReturnState = OUT_OF_RANGE;
					}
					break;
		}

	/*	//Check if [0 =< PIN Number < 15] >> GPIOA
		if (Copy_u8PinNb <= DIO_u8_PIN15)
		{
			//GPIOA
		}
		else if (Copy_u8PinNb > DIO_u8_PIN15  && Copy_u8PinNb <= DIO_u8_PIN31)
		{
			//GPIOB
		}
		else if (Copy_u8PinNb > DIO_u8_PIN31  && Copy_u8PinNb <= DIO_u8_PIN31)*/
	}
	else
	{
		Local_enuReturnState = OUT_OF_RANGE;
	}
	return Local_enuReturnState;
}

/**********************************************************************************************************************/

ErrorStatus DIO_enuSetPinValue(u8 Copy_u8PinNb , u8 Copy_u8Value)
{
	ErrorStatus Local_enuReturnState = OK;
	if (Copy_u8PinNb <= DIO_u8_PIN34   &&   ((Copy_u8Value == DIO_u8_HIGH) || (Copy_u8Value == DIO_u8_LOW )))
	{
		u8 Local_u8PortNb = Copy_u8PinNb / 16;
		u8 Local_u8PinNb  = Copy_u8PinNb % 16;
		switch (Local_u8PortNb)
		{
			case 0:
				if(Copy_u8Value == DIO_u8_HIGH)
				{
					SET_BIT(GPIOA->ODR , Local_u8PinNb);
				}
				else			// if (Copy_u8Value == DIO_u8_LOW)
				{
					CLR_BIT(GPIOA->ODR , Local_u8PinNb);
				}
			break;

			case 1:
				if(Copy_u8Value == DIO_u8_HIGH)
				{
					SET_BIT(GPIOB->ODR , Local_u8PinNb);
				}
				else
				{
					CLR_BIT(GPIOB->ODR , Local_u8PinNb);
				}
			break;

			case 2:
				if (Local_u8PinNb >= 13 && Local_u8PinNb <= 15)
				{
					if(Copy_u8Value == DIO_u8_HIGH)
					{
						SET_BIT(GPIOC->ODR , Local_u8PinNb);
					}
					else
					{
						CLR_BIT(GPIOC->ODR , Local_u8PinNb);
					}
				}
				else
				{
					Local_enuReturnState = OUT_OF_RANGE;
				}
			break;
		}
	}
	else
	{
		Local_enuReturnState = OUT_OF_RANGE;
	}
	return Local_enuReturnState;
}
/**********************************************************************************************************************/
ErrorStatus DIO_enuGetPinValue(u8 Copy_u8PinNb , u8 *Copy_ReturnValue)
{
	ErrorStatus Local_enuReturnState = OK;
	if(Copy_ReturnValue == NULL)
	{
		Local_enuReturnState = NULL_POINTER;
	}
	else if (Copy_u8PinNb > DIO_u8_PIN34)
	{
		Local_enuReturnState = OUT_OF_RANGE;
	}
	else		// if(Copy_u8PinNb <= DIO_u8_PIN34)
	{
		u8 Local_u8PortNb = Copy_u8PinNb / 16;
		u8 Local_u8PinNb  = Copy_u8PinNb % 16;
		switch (Local_u8PortNb)
		{
			case 0:	*Copy_ReturnValue = GET_BIT(GPIOA->IDR , Local_u8PinNb);	break;
			case 1:	*Copy_ReturnValue = GET_BIT(GPIOB->IDR , Local_u8PinNb);	break;
			case 2:	*Copy_ReturnValue = GET_BIT(GPIOC->IDR , Local_u8PinNb);	break;
		}
	}
	return Local_enuReturnState;
}

/**********************************************************************************************************************/

void ledToggle_Pin32(void)
{
	static int i = 0;
	switch(i)
	{
	case 0:	DIO_enuSetPinValue(DIO_u8_PIN32 , DIO_u8_HIGH);		i=1;	break;
	case 1:	DIO_enuSetPinValue(DIO_u8_PIN32 , DIO_u8_LOW);		i=0;	break;
	}
}

/**********************************************************************************************************************/

ErrorStatus ledToggle_Pinx(u8 Pin_No)		//Example :	ledToggle_Pinx(DIO_u8_PIN0)		~	ledToggle_Pinx(DIO_u8_PIN34)
{
	ErrorStatus Local_Error = OK;

  if(Pin_No <32 || Pin_No==45 || Pin_No==46 || Pin_No==47)		//45,46,47 for C0,C1&C2
	  {
		static int i = 0;
		switch(i)
			{
			case 0:	DIO_enuSetPinValue(DIO_u8_PIN32 , DIO_u8_HIGH);		i=1;	break;
			case 1:	DIO_enuSetPinValue(DIO_u8_PIN32 , DIO_u8_LOW);		i=0;	break;
			}
	  }
  else
	  {
	  Local_Error = OUT_OF_RANGE;
	  }

  return Local_Error;
}




/*

void DIO_voidInitialize(void)
{
	//Configure all pins output PP 2M
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
}*/
