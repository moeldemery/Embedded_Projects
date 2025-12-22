/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#include "STD_TYPES.h"
#include "Bit_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


//This Function apply clock on Processor
void RCC_voidInit(void)
{
	//NOTE THAT by default PLL 72 MHz is operating as Initial Value (As Per Kareem)
	//1-Check on the Config.h File if HSI or HSE or PLL are ENABLED/Disabled

#if RCC_u8_HSI_CLK_STATE == ENABLE
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_HSION_Bit);
#elif RCC_u8_HSI_CLK_STATE == DISABLE
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_HSION_Bit);
#endif

	#if RCC_u8_HSE_CLK_STATE == ENABLE
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEON_Bit); 		//OR >> RCC->CR.BitAcess.Bit16 = 1; Not Sure that Register will Note the change
#elif RCC_u8_HSE_CLK_STATE == DISABLE
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEON_Bit);
#endif

#if RCC_u8_PLL_CLK_STATE == ENABLE
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_PLLON_Bit);
#elif RCC_u8_PLL_CLK_STATE == DISABLE
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_PLLON_Bit);
#endif


	//2-Choose System Clock [HSI or HSE or PLL]#Before Switching into PLL, We need to Configure PLL Multiplication Factor
#if RCC_u8_SYSCLK_SOURCE == RCC_u8_HSI_SYSCLK
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_HSION_Bit);
#elif RCC_u8_SYSCLK_SOURCE == RCC_u8_HSE_SYSCLK
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEON_Bit);
#elif RCC_u8_SYSCLK_SOURCE == RCC_u8_PLL_SYSCLK
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_PLLON_Bit);
#endif

	//3-We Need to Configure AHB, APB1, APB2 Prescaler

}







//This API shall Enable the Clock on Certain Peripheral
ErrorStatus_ RCC_enueripheralCLKState(u8 Copy_u8PeripheralNb , u8 Copy_u8State)	//ex I want [ GPIOA_CLK Peripheral , Enabled/Disabled ]
{
	ErrorStatus_ Local_enuReturnState = 103;
	if(Copy_u8State != (RCC_u8_PERIPHERAL_CLK_ENABLED || RCC_u8_PERIPHERAL_CLK_DISABLED))
		{
		Local_enuReturnState = OUT_OF_RANGE;
		}
	else
	{
		switch(Copy_u8PeripheralNb)
		{
			case RCC_GPIOA_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit2 = Copy_u8State;	break;
			case RCC_GPIOB_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit3 = Copy_u8State;	break;
			case RCC_GPIOC_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit4 = Copy_u8State;	break;
			case RCC_DMA_PERIPHERAL:	RCC->AHBENR.BitAcess.Bit0  = Copy_u8State;	break;
			//case
			//case	UART
			default: Local_enuReturnState = OUT_OF_RANGE;	break;
		}
	}
	return Local_enuReturnState;
}


























//This Function apply clock on Processor
void RCC_SystemCLKInit(void)
{
		//HSE Enable with no Bypass
	//PLL Disabled & HSI Disabled
	//CSS Disabled
	//SysClk = HSE = 8MHz = ABH = APB1 = APB2
	RCC->CR.FourByteAcess   = 0x00010000;
	RCC->CFGR.FourByteAcess = 0x00000001;
}



/*
//This API shall Enable the Clock on Certain Peripheral
void RCC_voidEnableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral)
{
	switch (Copy_u8Bus)
	{
		case AHB  : SET_BIT(RCC_AHBENR  , Copy_u8Peripheral);	break;
		case APB2 : SET_BIT(RCC_APB2ENR , Copy_u8Peripheral);	break;
		case APB1 : SET_BIT(RCC_APB1ENR , Copy_u8Peripheral);	break;
		default : //No Thing	break;
	}
}

//This API shall Disable the Clock on Certain Peripheral
void RCC_voidDisableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral)
{
		switch (Copy_u8Bus)
	{
		case AHB  : CLR_BIT(RCC_AHBENR  , Copy_u8Peripheral);	break;
		case APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8Peripheral);	break;
		case APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8Peripheral);	break;
		default : //No Thing	break;
	}
}

//This Function apply clock on Processor
void RCC_SystemCLKInit(void)
{
		//HSE Enable with no Bypass
	//PLL Disabled & HSI Disabled
	//CSS Disabled
	//SysClk = HSE = 8MHz = ABH = APB1 = APB2
	RCC_CR 	 = 0x00010000;
	RCC_CFGR = 0x00000001;
}
*/
