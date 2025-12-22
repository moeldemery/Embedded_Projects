/*
 * RCC_Prog.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Amin
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "RCC_Privat.h"
#include "RCC_Config.h"

void RCC_vidInit(void)
{

#if(EXTERNAL_HIGH_SPEED_CLK==ENABLE)
	SET_BIT(RCC->CR.FourByteAccess,HSEON);//enable HSE
#elif(EXTERNAL_HIGH_SPEED_CLK==DISABLE)
	CLR_BIT(RCC->CR.FourByteAccess,HSEON);//disable HSE
#endif
#if(PHASE_LOCKED_LOOP_PLL==ENABLE)
	SET_BIT(RCC->CR.FourByteAccess,PLLON);//enable PLL
#elif(PHASE_LOCKED_LOOP_PLL==DISABLE)
	CLR_BIT(RCC->CR.FourByteAccess,PLLON);//disable PLL
#endif
/*1-APB1,APB2,AHBprescaler*/
/*2-PLL multiplication factor*/
/*3-choose system clk*/
#if(CLK_SYSTEM_SCR==HSI)

}
Error_state RCC_EnuPeripheralClkState(u8 copy_u8PeripheralNum,u8 copy_u8State)
{
	Error_state Local_enuReturnState=OK;
	if(copy_u8State==RCC_U8_PERIHERAL_CLK_ENABLE  || copy_u8State==RCC_U8_PERIHERAL_CLK_DISABLE)
	{
		switch(copy_u8PeripheralNum)

			{
				case RCC_GPIOA_PERIHERAL:RCC->APB2ENR.Bit_access.Bit2=copy_u8State;break;
				case RCC_GPIOB_PERIHERAL:RCC->APB2ENR.Bit_access.Bit3=copy_u8State;break;
				case RCC_GPIOC_PERIHERAL:RCC->APB2ENR.Bit_access.Bit4=copy_u8State;break;
				default :Local_enuReturnState=OUTOFRANGE;
			}
	}
	else
	{
		Local_enuReturnState=OUTOFRANGE;
	}

	return Local_enuReturnState;

}
