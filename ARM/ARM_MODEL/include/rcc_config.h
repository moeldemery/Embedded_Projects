#ifndef	_RCC_CONFIG_H
#define _RCC_CONFIG_H


/****Clock control register (RCC_CR)*************************************************************/
//###Note that by Default HSI Will be the Source Clock of the system
/* Options:
 * 	1:ENABLED
 * 	2:DISABLED
 */
//Clocks Initial State
#define HSI_CLK_STATE		DISABLED		// HSION: Internal high-speed clock enable
#define HSE_CLK_STATE		ENABLED		// HSEON: HSE clock enable
#define PLL_CLK_STATE		DISABLED		// PLLON: PLL enable	#Before Switching into PLL, We need to Configure PLL Multiplication Factor

#define HSE_BYPASS_STATE	DISABLED		// HSEBYP: External high-speed clock bypass >Only Enabled in case of Rc_External Clk Source
#define CLOCK_SECURITY		DISABLED		// CSSON: Clock security system enable >>If External Clk Source Failed >> Automatically Switch to Internal RC CLK(HSI)

/*Options:			// to Configure Trimming > we Will be in need for Oscilloscope
 * 1-VALUES			// we Won't configure Calibration because it is Read Only
 */
/*
#define HSI_TRIMMING	  0
*/

/****Clock configuration register (RCC_CFGR)*************************************************************/

/*MCO: M.C clock output >>  Output Signal is Clock of System
 * Options:
 * 	0xx: NO_CLOCK > [001]
 * 	100: SYSTEM_CLOCK (SYSCLK)	//To Test freq(system) & for Clock Cascading>used as Clk_Source for other M.Cs
 * 	101: HSI_CLK
 * 	110: HSE_CLK
 * 	111: DIVISABLE_PLL_CLK		>>>PLL_CLK_DIV_BY_1.5
 */
#define MCO_VALUE	NO_CLOCK

/*******************************************************************
 *  USB prescaler
 * Options:
 * 	0: DIVISABLE_PLL_CLK		>>>PLL_CLK_DIV_BY_1.5
 * 	1: PLL_CLK
 */
#define USP_PRESCALLER	DIVISABLE_PLL_CLK

/*******************************************************************
 *  >>> PLL(multiplication) is Opposite to Prescaller(division)
 *  PLLMUL: PLL multiplication factor >> Caution: The PLL output frequency must not exceed 72 MHz.
 * Options:
 * 	0000: PLL_INPUTCLK_x2
 * 	0001: PLL_INPUTCLK_x3		// PLL_INPUTCLK is: [HSI/2] OR [HSE]
 * 	0010: PLL_INPUTCLK_x4
 * 	0011: PLL_INPUTCLK_x5
 * 	0100: PLL_INPUTCLK_x6
 * 	0101: PLL_INPUTCLK_x7
 * 	0110: PLL_INPUTCLK_x8
 * 	0111: PLL_INPUTCLK_x9
 * 	1000: PLL_INPUTCLK_x10
 * 	1001: PLL_INPUTCLK_x11
 * 	1010: PLL_INPUTCLK_x12
 * 	1011: PLL_INPUTCLK_x13
 * 	1100: PLL_INPUTCLK_x14
 * 	1101: PLL_INPUTCLK_x15
 * 	1111: PLL_INPUTCLK_x16
 */
#define PLL_PRESCALLER	PLL_INPUTCLK_x2

/*******************************************************************
 * [PLLXTPRE: HSE divider for PLL entry]  :  [PLLSRC: PLL entry clock source]
 *	 0x: HSI_CLK_DIV_BY_2	//HSI oscillator clock / 2 selected as PLL input clock
 *	 10: HSE					//HSE oscillator clock selected as PLL input clock
 *	 11: HSE_CLK_DIV_BY_2	//HSE oscillator clock/ 2 selected as PLL input clock
 */
#define PLL_CLK_ENTRY		HSI_CLK_DIV_BY_2

/********************************************************************
 * ADCPRE: ADC Prescaler
 * 	00: APB2_CLK_DIV_BY_2		//PCLK2 = APB2_CLK
 * 	01: APB2_CLK_DIV_BY_4
 * 	10: APB2_CLK_DIV_BY_6
 * 	11: APB2_CLK_DIV_BY_8
 */
#define ADC_PRESCALLER		APB2_CLK_DIV_BY_2


/********************************************************************
 * PPRE2: APB high-speed prescaler (APB2)
 * 0xx: AHB_CLK 				//HCLK = AHB_CLK
 * 100: AHB_CLK_DIV_BY_2
 * 101: AHB_CLK_DIV_BY_4
 * 110: AHB_CLK_DIV_BY_8
 * 111: AHB_CLK_DIV_BY_16
 */
#define APB2_PRESCALLER		AHB_CLK

/********************************************************************
 * PPRE1: APB low-speed prescaler (APB1)
 * 0xx: AHB_CLK 				//HCLK = AHB_CLK
 * 100: AHB_CLK_DIV_BY_2
 * 101: AHB_CLK_DIV_BY_4
 * 110: AHB_CLK_DIV_BY_8
 * 111: AHB_CLK_DIV_BY_16
 */
#define APB1_PRESCALLER		AHB_CLK

/******************************************************************
 * AHB Prescalleder
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
#define AHB_PRESCALLER	1


/********************************************************************
 * SW: System clock switch	>> Choose Source of your System Clock
 * Options:
 *	HSI_SYSCLK
 * 	HSE_SYSCLK
 * 	PLL_SYSCLK
 */
#define SYSCLK_SOURCE		HSE_SYSCLK



/*Clock Sequence:	[#] is Prescaller
 * 			HSI >					#> APB1
 * 			HSE >> SysClock #> AHB >>>
 * HSI/2 >							#> APB2
 * HSE	 >> PLL >
 * HSE/2 >
 * */

#endif
