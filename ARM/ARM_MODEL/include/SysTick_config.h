#ifndef	_SYSTICK_CONFIG_H
#define _SYSTICK_CONFIG_H


/****4.5.1 SysTick control and status register (STK_CTRL)*************************************************************/
//###Note that by Default HSI Will be the Source Clock of the system

/* CLKSOURCE: Clock source selection Options:
 * 0: AHB_DIV_BY_8
 * 1: AHB
 */
#define STK_u32_CLOCK_SOURCE	AHB_DIV_BY_8

/* Options:
 * 1:ENABLE
 * 0:DISABLE
 */
//TICKINT: SysTick exception request enable ((Enable Internal Interrupts to be Triggered by SysTick))
#define STK_u32_EXCEPTION_ENABLING	ENABLE

//ENABLE: Counter enable
#define STK_u32_COUNTER_ENABLEING	DISABLE

/****SysTick reload value register (STK_LOAD)*************************************************************/


 /* To Set PreLoad Initial Value Options:
  * ZERO >> UnderFlow Mode
  * 0bxxx (any Value) >> CTC Mode >> we are using Timer as CTC Mode
  */
#define	STK_u32_RELOAD_Value	ZERO


#endif
