/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*This API shall Enable the Clock on Certain Peripheral*/
void RCC_voidEnableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral)
{
	switch (Copy_u8Bus)
	{
		case AHB  : SET_BIT(RCC_AHBENR  , Copy_u8Peripheral);	break;
		case APB2 : SET_BIT(RCC_APB2ENR , Copy_u8Peripheral);	break;
		case APB1 : SET_BIT(RCC_APB1ENR , Copy_u8Peripheral);	break;
		default : /*No Thing*/	break;
	}
}

/*This API shall Disable the Clock on Certain Peripheral*/
void RCC_voidDisableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral)
{
		switch (Copy_u8Bus)
	{
		case AHB  : CLR_BIT(RCC_AHBENR  , Copy_u8Peripheral);	break;
		case APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8Peripheral);	break;
		case APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8Peripheral);	break;
		default : /*No Thing*/	break;
	}
}

/*This Function apply clock on Processor*/
void RCC_SystemCLKInit(void)
{
		/*HSE Enable with no Bypass*/
	/*PLL Disabled & HSI Disabled*/
	/*CSS Disabled*/
	/*SysClk = HSE = 8MHz = ABH = APB1 = APB2*/
	RCC_CR 	 = 0x00010000;
	RCC_CFGR = 0x00000001;
}
