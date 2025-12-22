/*
 * SysTick.c
 *
 *  Created on: Feb 12, 2020
 *      Author: DELL
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


// System timer Base Address: 0xE000E010
void STK_voidInit(void)
{
	//Enable Interrupt
#if STK_u32_EXCEPTION_ENABLING == ENABLE
	SET_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_TICKINT_PIN);
#elif STK_u32_EXCEPTION_ENABLING == DISABLE
	CLR_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_TICKINT_PIN);
#endif


	//Set Clock : AHB/8
#if STK_u32_CLOCK_SOURCE == AHB
	SET_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_CLKSOURCE_PIN);
#elif STK_u32_CLOCK_SOURCE == AHB_DIV_BY_8
	CLR_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_CLKSOURCE_PIN);
#endif

	//System Disabled
	#if STK_u32_COUNTER_ENABLEING == ENABLE
		SET_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_ENABLE_PIN);
	#elif STK_u32_COUNTER_ENABLEING == DISABLE
		CLR_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_ENABLE_PIN);
	#endif

/*	//Choosing Mode [Timer Operate as Underflow Mode or CTC Mode]
#if STK_u32_RELOAD_Value == ZERO
	SYSTICK->LOAD.FourByteAcess = ZERO;		//UnderFlow Mode (Normal Mode)
#else
	SYSTICK->LOAD.FourByteAcess = STK_u32_RELOAD_Value;		//As if Timer is operating as CTC Mode
#endif*/
}
/**************************************************************************************************/
void STK_voidStart( u32 Copy_u32PreLoadValue )
{
	//Set Preload Value
	SYSTICK->LOAD.FourByteAcess = Copy_u32PreLoadValue;

	//Reset Timer >> WE Enter any Value in Timer Register To Reset the Timer
	SYSTICK->VAL.FourByteAcess = Copy_u32PreLoadValue;

	// Enable Timer >> Once We Enable, Timer will Start Operating
	SET_BIT(SYSTICK->CTRL.FourByteAcess, SYSTICK_CTRL_ENABLE_PIN);

}
/**************************************************************************************************/
// call back function notification function
	static void( *pCallbackFunc )(void) = NULL;

void STK_voidSetCallBack(void (*Copy_PfCallBack)(void))
{
	//Set Call Back (Call Back Function Initialization)
	pCallbackFunc = Copy_PfCallBack;
}
/**************************************************************************************************/
void SysTick_Handler(void)
{
	//Invoke the Call back Function
	if (pCallbackFunc != NULL)
	{
		pCallbackFunc();
	}
}
