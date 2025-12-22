/************************************************************/
/* Author  :Amin                                            */
/* Version :v1.0                                            */
/* Date    :31 Jan 2020                                     */
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "RCC_Privt.h"
#include "RCC_Config.h"

/*this API shall enable the clk on certian peripheral*/
void RCC_vidEnableClock(u8 copy_u8Bus,u8 copy_u8peripheral)
{
	switch(copy_u8Bus)
	{
		case 0:
			SET_BIT(RCC_ABHENR,copy_u8peripheral); break;
		case 1:
			SET_BIT(RCC_APB1ENR,copy_u8peripheral); break;
		case 2:
			SET_BIT(RCC_APB2ENR,copy_u8peripheral); break;
		default : /*Nothing*/ break;
	}
}
/*this API shall disable the clk on certian peripheral*/
void RCC_vidDisableClock(u8 copy_u8Bus,u8 copy_u8peripheral)
{
	switch(copy_u8Bus)
	{
		case 0:
			CLR_BIT(RCC_ABHENR,copy_u8peripheral); break;
		case 1:
			CLR_BIT(RCC_APB1ENR,copy_u8peripheral); break;
		case 2:
			CLR_BIT(RCC_APB2ENR,copy_u8peripheral); break;
		default : /*Nothing*/ break;
	}
}
/*this API shall enable the clk on Processor*/
void RCC_vidSystemClkInit(void)
{
	/*HSE enable with no bypass*/
	/*PLL Disable HSI Diabled*/
	/*CSS Disabled*/
	/*syclk = HSE = 8MHZ = AHB = APB1 = APB2*/
	RCC_CR  =0x00010000;
	RCC_CFGR=0x00000001;
}