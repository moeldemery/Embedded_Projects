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

//This API shall Enable the Clock on Certain Peripheral
ErrorStatus RCC_enueripheralCLKState(u8 Copy_u8PeripheralNb , u8 Copy_u8State)	//ex I want [ GPIOA_CLK Peripheral , Enabled/Disabled ]
{
	ErrorStatus Local_enuReturnState = OK;
	if(Copy_u8State != (RCC_u8_PERIPHERAL_CLK_ENABLED || RCC_u8_PERIPHERAL_CLK_DISABLED))
		{
		Local_enuReturnState = OUT_OF_RANGE;
		}
	else
	{
		switch(Copy_u8PeripheralNb)		//STM-Register DataSheet page: 145
		{
			case RCC_GPIOA_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit2 = Copy_u8State;	break;		//SET/
			case RCC_GPIOB_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit3 = Copy_u8State;	break;
			case RCC_GPIOC_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit4 = Copy_u8State;	break;

			case RCC_DMA1_PERIPHERAL:	RCC->AHBENR.BitAcess.Bit0  = Copy_u8State;	break;
			case RCC_USART1_PERIPHERAL:	RCC->APB2ENR.BitAcess.Bit14= Copy_u8State;	break;

			//case
			//case	UART
			default: Local_enuReturnState = OUT_OF_RANGE;	break;
		}
	}
	return Local_enuReturnState;
}
/*Note that:
 *  [RCC->AHBENR.BitAcess.Bit0 = Copy_u8State;] == [SET_BIT(RCC->AHBENR.ByteAccess, Bit0)]  ==  [SET_BIT(RCC->AHBENR.ByteAccess, RCC_AHBENR_DMA1EN_Bit)]*/




//This Function(API) apply clock on Processor
ErrorStatus RCC_SystemCLKInit(void)
{
	ErrorStatus Local_Error= OK;

	//NOTE THAT by default PLL 72 MHz is operating as Initial Value (As Per Kareem)
	//1-Check on the Config.h File if HSI or HSE or PLL are ENABLEDD/Disabled
//###Note that by Default HSI Will be the Source Clock of the system


/****Clock control register (RCC_CR)*************************************************************/
#if HSI_CLK_STATE == ENABLED
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_HSION_Bit);
#elif HSI_CLK_STATE == DISABLED
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_HSION_Bit);
#else
	Local_Error = NOK;
#endif
/**************************************/
#if HSE_CLK_STATE == ENABLED		//Note that my H.w Crystal produces 8MHz >> So Clock of HSE is 8MHz
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEON_Bit); 		//OR >> RCC->CR.BitAcess.Bit16 = 1; Not Sure that Register will Note the change
#elif HSE_CLK_STATE == DISABLED
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEON_Bit);
#else
	Local_Error = NOK;
#endif
/**************************************/

#if PLL_CLK_STATE == ENABLED
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_PLLON_Bit);
#elif PLL_CLK_STATE == DISABLED
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_PLLON_Bit);
#else
	Local_Error = NOK;
#endif
/**************************************/

#if HSE_BYPASS_STATE == ENABLED
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEBYP_Bit);
#elif HSE_BYPASS_STATE == DISABLED
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_HSEBYP_Bit);
#else
	Local_Error = NOK;
#endif
/**************************************/

#if CLOCK_SECURITY == ENABLED
	SET_BIT(RCC->CR.FourByteAcess,RCC_CR_CSSON_Bit);
#elif CLOCK_SECURITY == DISABLED
	CLR_BIT(RCC->CR.FourByteAcess,RCC_CR_CSSON_Bit);
#else
	Local_Error = NOK;
#endif


/****Clock configuration register (RCC_CFGR)*************************************************************/
#if MCO_VALUE == NO_CLOCK
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit2);
#elif MCO_VALUE == SYSTEM_CLOCK
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit2);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit0);
#elif MCO_VALUE == HSI_CLK
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit2);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit0);
#elif MCO_VALUE == HSE_CLK
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit2);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit0);
#elif MCO_VALUE == DIVISABLE_PLL_CLK		//>>PLL_CLK_DIV_BY_1.5
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit2);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_MCO_Bit0);
#else
	Local_Error = NOK;
#endif
/**************************************/


#if USP_PRESCALLER == DIVISABLE_PLL_CLK	//>>>PLL_CLK_DIV_BY_1.5
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_USBPRE_Bit);
#elif USP_PRESCALLER == PLL_CLK
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_USBPRE_Bit);
#else
	Local_Error = NOK;
#endif
/**************************************/


#if PLL_PRESCALLER == PLL_INPUTCLK_x2
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x3
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x4
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x5
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x6
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x7
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x8
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x9
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x10
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x11
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x12
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x13
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x14
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x15
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#elif PLL_PRESCALLER == PLL_INPUTCLK_x16
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit3);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit2);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit1);
		SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLMUL_Bit0);
#else
		Local_Error = NOK;
#endif
/**************************************/


#if PLL_CLK_ENTRY == HSI_CLK_DIV_BY_2
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLSRC_Bit);
#elif PLL_CLK_ENTRY == HSE
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLSRC_Bit);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLXTPRE_Bit);
#elif PLL_CLK_ENTRY == HSE_CLK_DIV_BY_2
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLSRC_Bit);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PLLXTPRE_Bit);
#else
	Local_Error = NOK;
#endif
/**************************************/


#if ADC_PRESCALLER == APB2_CLK_DIV_BY_2
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit0);
#elif ADC_PRESCALLER == APB2_CLK_DIV_BY_4
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit0);
#elif ADC_PRESCALLER == APB2_CLK_DIV_BY_6
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit0);
#elif ADC_PRESCALLER == APB2_CLK_DIV_BY_8
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_ADCPRE_Bit0);
#else
	Local_Error = NOK;
#endif
/**************************************/

#if APB2_PRESCALLER == AHB_CLK
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit2);
#elif APB2_PRESCALLER == AHB_CLK_DIV_BY_2
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit2);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit0);
#elif APB2_PRESCALLER == AHB_CLK_DIV_BY_4
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit2);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit0);
#elif APB2_PRESCALLER == AHB_CLK_DIV_BY_8
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit2);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit0);
#elif APB2_PRESCALLER == AHB_CLK_DIV_BY_16
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit2);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE2_Bit0);
#else
	Local_Error = NOK;
#endif
/**************************************/

#if APB1_PRESCALLER == AHB_CLK
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit2);
#elif APB1_PRESCALLER == AHB_CLK_DIV_BY_2
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit2);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit0);
#elif APB1_PRESCALLER == AHB_CLK_DIV_BY_4
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit2);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit0);
#elif APB1_PRESCALLER == AHB_CLK_DIV_BY_8
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit2);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit0);
#elif APB1_PRESCALLER == AHB_CLK_DIV_BY_16
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit2);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_PPRE1_Bit0);
#else
	Local_Error = NOK;
#endif
/**************************************/

#if AHB_PRESCALLER == SYSCLK
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_HPRE_Bit2);//Bits 7= 0
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_2
	RCC->CFGR.FourByteAcess |= 0x80		//Bits 7:4 >> 0b1000 = 0x8
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_4
	RCC->CFGR.FourByteAcess |= 0x90		//Bits 7:4 >> 0b1001 = 0x9
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_8
	RCC->CFGR.FourByteAcess |= 0xA0		//Bits 7:4 >> 0b1010 = 0xA
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_16
	RCC->CFGR.FourByteAcess |= 0xB0		//Bits 7:4 >> 0b1011 = 0xB
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_64
	RCC->CFGR.FourByteAcess |= 0xC0		//Bits 7:4 >> 0b1100 = 0xC
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_128
	RCC->CFGR.FourByteAcess |= 0xD0		//Bits 7:4 >> 0b1101 = 0xD
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_256
	RCC->CFGR.FourByteAcess |= 0xE0		//Bits 7:4 >> 0b1110 = 0xE
#elif AHB_PRESCALLER == AHB_CLK_DIV_BY_512
	RCC->CFGR.FourByteAcess |= 0xF0		//Bits 7:4 >> 0b1111 = 0xF
#else
	Local_Error = NOK;
#endif
/**************************************/


	//Choose System Clock [HSI or HSE or PLL]#Before Switching into PLL, We need to Configure PLL Multiplication Factor
#if SYSCLK_SOURCE == HSI_SYSCLK
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_SW_Bit1);
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_SW_Bit0);
#elif SYSCLK_SOURCE == HSE_SYSCLK
	CLR_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_SW_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_SW_Bit0);
#elif SYSCLK_SOURCE == PLL_SYSCLK
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_SW_Bit1);
	SET_BIT(RCC->CFGR.FourByteAcess,RCC_CFGR_SW_Bit0);
#else
	Local_Error = NOK;
#endif
/**************************************/

	return Local_Error;
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
