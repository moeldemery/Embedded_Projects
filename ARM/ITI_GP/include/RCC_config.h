#ifndef	_RCC_CONFIG_H
#define _RCC_CONFIG_H


/****Clock control register (RCC_CR)*************************************************************/
//###Note that by Default HSI Will be the Source Clock of the system

/* Options:
 * 1:ENABLE
 * 2:DISABLE
 */
//Clocks Initial State
#define RCC_u8_HSI_CLK_STATE	ENABLE
#define RCC_u8_HSE_CLK_STATE	ENABLE
#define RCC_u8_PLL_CLK_STATE	ENABLE

//Want to use ByPass [in case of Rc_External Clk Source] or don't
#define RCC_HSE_BYPASS_STATE	DISABLE		//we Enable it for RC-External Clock Source only

//Macro for Clock Security System	>>If External Clk Source Failed >> Automatically Switch to Internal RC CLK(HSI)
#define RCC_u8_CSS				DISABLE

/*Options:			// to Configure Trimming > we Will be in need for Oscilloscope
 * 1-VALUES			// we Won't configure Calibration because it is Read Only
 */
/*
#define HSI_TRIMMING	  0
*/
/****Clock configuration register (RCC_CFGR)*************************************************************/

/*SW: System clock switch
 * Options:
 * 		RCC_u8_HSI_SYSCLK
 * 		RCC_u8_HSE_SYSCLK
 * 		RCC_u8_PLL_SYSCLK
 */
#define RCC_u8_SYSCLK_SOURCE		RCC_u8_HSI_SYSCLK

/*AHB Prescalleder
 * 0xxx: SYSCLK 		not divided
 * 1000: SYSCLK_DIV_BY_2
 * 1001: SYSCLK_DIV_BY_4
 * 1010: SYSCLK_DIV_BY_8
 * 1011: SYSCLK_DIV_BY_16
 * 1100: SYSCLK_DIV_BY_64
 * 1101: SYSCLK_DIV_BY_128
 * 1110: SYSCLK_DIV_BY_256
 * 1111: SYSCLK_DIV_BY_512
 */
#define RCC_u8_AHB_PRESCALLER	1

/*PPRE1: APB low-speed prescaler (APB1)
 * 0xx: AHB_CLK 				//HCLK = AHB_CLK
 * 100: AHB_CLK_DIV_BY_2
 * 101: AHB_CLK_DIV_BY_4
 * 110: AHB_CLK_DIV_BY_8
 * 111: AHB_CLK_DIV_BY_16
 */
#define RCC_u8_PPRE1_PRESCALLER	1

/*PPRE2: APB high-speed prescaler (APB2)
 * 0xx: AHB_CLK 				//HCLK = AHB_CLK
 * 100: AHB_CLK_DIV_BY_2
 * 101: AHB_CLK_DIV_BY_4
 * 110: AHB_CLK_DIV_BY_8
 * 111: AHB_CLK_DIV_BY_16
 */
#define RCC_u8_PPRE2_PRESCALLER	1

/*ADCPRE: ADC prescaler
 * 00: APB2_CLK_DIV_BY_2		//PCLK2 = APB2_CLK
 * 01: APB2_CLK_DIV_BY_4
 * 10: APB2_CLK_DIV_BY_6
 * 11: APB2_CLK_DIV_BY_8
 */
#define RCC_u8_ADCPRE_PRESCALLER	1

/*APLLSRC: PLL entry clock source
 * 0: HSI_CLK_DIV_BY_2			//HSI oscillator clock / 2 selected as PLL input clock
 * 1: HSE						//HSE oscillator clock selected as PLL input clock
 */
#define RCC_u8_APLLSRC_PRESCALLER	1


/* MCO: Microcontroller clock output >>  Output Signal is Clock of System
 * Options:
 * 0xx: NO_CLOCK > [001]
 * 100: SYSTEM_CLOCK (SYSCLK)
 * 101: HSI_CLK
 * 110: HSE_CLK
 * 111: PLL_CLK_DIV_BY_1.5
 */
#define MCO_VALUE	NO_CLOCK

/* PLLMUL: PLL multiplication factor >> Caution: The PLL output frequency must not exceed 72 MHz.
 * Options:
 * 0000: PLL_INPUTCLK_x2
 * 0001: PLL_INPUTCLK_x3		// PLL_INPUTCLK is: [HSI/2] OR [HSE]
 * 0010: PLL_INPUTCLK_x4
 * 0011: PLL_INPUTCLK_x5
 * 0100: PLL_INPUTCLK_x6
 * 0101: PLL_INPUTCLK_x7
 * 0110: PLL_INPUTCLK_x8
 * 0111: PLL_INPUTCLK_x9
 * 1000: PLL_INPUTCLK_x10
 * 1001: PLL_INPUTCLK_x11
 * 1010: PLL_INPUTCLK_x12
 * 1011: PLL_INPUTCLK_x13
 * 1100: PLL_INPUTCLK_x14
 * 1101: PLL_INPUTCLK_x15
 * 1110: PLL_INPUTCLK_x16
 * 1111: PLL_INPUTCLK_x16
 */
#define PLL_VALUE	PLL_INPUTCLK_x2

/* USB prescaler
 * Options:
 * 0: PLL_CLK_DIV_BY_1.5
 * 1: PLLCLK
 */
#define USP_PRESCALLER	PLLCLK
/*
 * Options:
 * 1-VALUES
 */





#endif
