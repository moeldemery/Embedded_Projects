#ifndef  RCC_CONFIG_H
#define  RCC_CONFIG_H
/*********************************CR_Register************************************/
/*options:
 * 1.ENABLE
 * 2.DISABLE
 * */
#define INTERNAL_HIGH_SPEED_CLK				ENABLE
#define EXTERNAL_HIGH_SPEED_CLK				ENABLE
#define PHASE_LOCKED_LOOP_PLL				ENABLE
#define CLK_SECURITY_SYSTEM					DISABLE     /*Clock security system*/
#define EXT_HIGH_CLK_BYPASS					DISABLE     /*external 4-16 MHz oscillator*/
/*********************************CFGR_Register************************************/
/*options:choose system clk source
 * 1.HSI
 * 2.HSE
 * 3.PLL
 */
#define CLK_SYSTEM_SCR						HSI
/*option:
 * 1.SYSCLK_NO_DIV
 * 2.SYSCLK_BY_2
 * 3.SYSCLK_BY_4
 * 4.SYSCLK_BY_8
 * 5.SYSCLK_BY_16
 * 6.SYSCLK_BY_64
 * 7.SYSCLK_BY_128
 * 8.SYSCLK_BY_256
 * 9.SYSCLK_BY_512
 */
#define FOUR_PIN_AHB_PRESCALER              SYSCLK_BY_2
/*option:
 * 1.HCLK_NO_DIV
 * 2.HCLK_BY_2
 * 3.HCLK_BY_4
 * 4.HCLK_BY_8
 * 5.HCLK_BY_16
 */
#define THREE_PIN_APB1_PRESCALER			HCLK_NO_DIV
#define THREE_PIN_APB2_PRESCALER			HCLK_NO_DIV
/*option:
 * 1.PCLK2_BY_2
 * 2.PCLK2_BY_4
 * 3.PCLK2_BY_8
 * 4.PCLK2_BY_16
 */
#define TWO_PIN_ADC_PRESCALER
/*option:
 * 1.HSI_CLK_BY_2_IPNUT_CLK
 * 2.HSE_CLK_INPUT_CLK
 * */
#define PLL_SCR            					HSI_CLK_BY_2_IPNUT_CLK
/*option:
 * 1.HSE_NOT_DIVIDED
 * 2.HSE_DIVIDED_BY_2
 */
#define HSE_DIVIDER_FOR_PLL_ENTRY           HSE_NOT_DIVIDED
/*option:
 * 1.CLK_X_2
 * 2.CLK_X_3
 * 3.CLK_X_4
 * 4.CLK_X_5
 * 5.CLK_X_6
 * 6.CLK_X_7
 * 7.CLK_X_8
 * 8.CLK_X_9
 * 9.CLK_X_10
 * 10.CLK_X_11
 * 11.CLK_X_12
 * 12.CLK_X_13
 * 13.CLK_X_14
 * 14.CLK_X_15
 * 15.CLK_X_16
 */
#define FOUR_PIN_PLL_MULTI_FACTOR			CLK_X_2

#endif
