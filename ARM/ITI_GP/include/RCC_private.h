/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef	_RCC_PRIVATE_H
#define _RCC_PRIVATE_H


typedef struct		//arrangement is important
{
	volatile Register_32 CR	 ;		//u32 to increment by 0x4 (as Step) >>Page
	volatile Register_32 CFGR;
	volatile Register_32 CIR ;
	volatile Register_32 APB2RSTR;
	volatile Register_32 APB1RSTR;
	volatile Register_32 AHBENR ;
	volatile Register_32 APB2ENR;
	volatile Register_32 APB1ENR;
	volatile Register_32 BDCR;
	volatile Register_32 CSR;
}RCC_type;	//>>RCC_Peripheral

#define RCC		((volatile RCC_type*)0x40021000)		// I would like to cast this Base_address as pointer to Struct
//RCC_BASE->CR.FourByteAcess= value
//RCC_BASE->CR.BitAcess.B2. = value

//Busses Types
#define	AHB 				1
#define	APB2				2
#define	APB1				3


//Macros For Bits Of RCC Registers
/****7.3.1 Clock control register (RCC_CR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit	// Peripheral_Register_1Bit_Name
#define RCC_CR_PLLRDY_FLAG			25	// PLLRDY: PLL clock ready flag
#define RCC_CR_PLLON_Bit			24	// PLLON: PLL enable
#define RCC_CR_CSSON_Bit			19	// CSSON: Clock security system enable
#define RCC_CR_HSEBYP_Bit			18	// HSEBYP: External high-speed clock bypass
#define RCC_CR_HSEBYP_FLAG			17	// HSERDY: External high-speed clock ready flag
#define RCC_CR_HSEON_Bit			16	// HSEON: HSE clock enable
#define RCC_CR_HSIRDY_FLAG			1	// HSIRDY: Internal high-speed clock ready flag
#define RCC_CR_HSION_Bit			0	// HSION: Internal high-speed clock enable
/****7.3.2 Clock Configuration register (RCC_CFGR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_CFGR_MCO_Bit2			26	// Microcontroller clock output
#define RCC_CFGR_MCO_Bit1			25
#define RCC_CFGR_MCO_Bit0			24
#define RCC_CFGR_USBPRE_Bit			22	//  USB prescaler
#define RCC_CFGR_PLLMUL_Bit3		21	//  PLL multiplication factor
#define RCC_CFGR_PLLMUL_Bit2		20
#define RCC_CFGR_PLLMUL_Bit1		19
#define RCC_CFGR_PLLMUL_Bit0		18
#define RCC_CFGR_PLLXTPRE_Bit		17 	// HSE divider for PLL entry
#define RCC_CFGR_PLLSRC_Bit			16	// PLL entry clock source
#define RCC_CFGR_ADCPRE_Bit			15	// ADC prescaler
#define RCC_CFGR_ADCPRE_Bit			14
#define RCC_CFGR_PPRE2_Bit2			13	// APB high-speed prescaler (APB2)
#define RCC_CFGR_PPRE2_Bit1			12
#define RCC_CFGR_PPRE2_Bit0			11
#define RCC_CFGR_PPRE1_Bit			10	// APB low-speed prescaler (APB1)
#define RCC_CFGR_PPRE1_Bit			9
#define RCC_CFGR_PPRE1_Bit			8
#define RCC_CFGR_HPRE_Bit3			7	// AHB prescaler
#define RCC_CFGR_HPRE_Bit2			6
#define RCC_CFGR_HPRE_Bit1			5
#define RCC_CFGR_HPRE_Bit0			4
#define RCC_CFGR_SWS_Bit1			3	//System clock switch status
#define RCC_CFGR_SWS_Bit0			2
#define RCC_CFGR_SW_Bit1			1	// System clock switch
#define RCC_CFGR_SW_Bit0			0
/****7.3.3 Clock interrupt register (RCC_CIR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_CIR_CSSC_Bit			23	// Clock security system interrupt clear
#define RCC_CIR_PLLRDYC_Bit			20	// PLL ready interrupt clear
#define RCC_CIR_HSERDYC_Bit			19	// HSE ready interrupt clear
#define RCC_CIR_HSIRDYC_Bit			18	// HSI ready interrupt clear
#define RCC_CIR_LSERDYC_Bit			17	// LSE ready interrupt clear
#define RCC_CIR_LSIRDYC_Bit			16	// LSI ready interrupt clear
#define RCC_CIR_PLLRDYIE_Bit		12	// PLL ready interrupt enable
#define RCC_CIR_HSERDYIE_Bit		11	// HSE ready interrupt enable
#define RCC_CIR_HSIRDYIE_Bit		10	// HSI ready interrupt enable
#define RCC_CIR_LSERDYIE_Bit		9 	// LSE ready interrupt enable
#define RCC_CIR_LSIRDYIE_Bit		8 	// LSI ready interrupt enable
#define RCC_CIR_CSSF_Bit			7 	// Clock security system interrupt flag
#define RCC_CIR_PLLRDYF_Bit			4 	// PLL ready interrupt flag
#define RCC_CIR_HSERDYF_Bit			3 	// HSE ready interrupt flag
#define RCC_CIR_HSIRDYF_Bit			2 	// HSI ready interrupt flag
#define RCC_CIR_LSERDYF_Bit			1 	// LSE ready interrupt flag
#define RCC_CIR_LSIRDYF_Bit			0 	// LSI ready interrupt flag
/****7.3.4 APB2 peripheral reset register (RCC_APB2RSTR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_APB2RSTR_TIM11RST_Bit	21	// TIM11 timer reset
#define RCC_APB2RSTR_TIM10RST_Bit	20	// TIM10 timer reset
#define RCC_APB2RSTR_TIM9RST_Bit	19	// TIM9 timer reset
#define RCC_APB2RSTR_ADC3RST_Bit	15	// ADC3 interface reset
#define RCC_APB2RSTR_USART1RST_Bit	14	// USART1 reset
#define RCC_APB2RSTR_TIM8RST_Bit	13	// TIM8 timer reset
#define RCC_APB2RSTR_SPI1RST_Bit	12	// SPI1 reset
#define RCC_APB2RSTR_TIM1RST_Bit	11	// TIM1 timer reset
#define RCC_APB2RSTR_ADC2RST_Bit	10	// ADC 2 interface reset
#define RCC_APB2RSTR_ADC1RST_Bit	9 	// ADC 1 interface reset
#define RCC_APB2RSTR_IOPCRST_Bit	4 	// IO port C reset
#define RCC_APB2RSTR_IOPBRST_Bit	3 	// IO port B reset
#define RCC_APB2RSTR_IOPARST_Bit	2 	// IO port A reset
#define RCC_APB2RSTR_AFIORST_Bit	0 	// Alternate function IO reset
/****7.3.5 APB1 peripheral reset register (RCC_APB1RSTR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_APB1RSTR_DACRST_Bit		29	// DACRST: DAC interface reset
#define RCC_APB1RSTR_PWRRST_Bit		28	// PWRRST: Power interface reset
#define RCC_APB1RSTR_BKPRST_Bit		27	// BKPRST: Backup interface reset
#define RCC_APB1RSTR_CANRST_Bit		25	// CANRST: CAN reset
#define RCC_APB1RSTR_USBRST_Bit		23	// USBRST: USB reset
#define RCC_APB1RSTR_I2C2RST_Bit	22	// I2C2RST: I2C2 reset
#define RCC_APB1RSTR_I2C1RST_Bit	21	// I2C1RST: I2C1 reset
#define RCC_APB1RSTR_UART5RST_Bit	20	// UART5RST: USART5 reset
#define RCC_APB1RSTR_UART4RST_Bit	19	// UART4RST: USART4 reset
#define RCC_APB1RSTR_USART3RST_Bit	18	// USART3RST: USART3 reset
#define RCC_APB1RSTR_USART2RST_Bit	17	// USART2RST: USART2 reset
#define RCC_APB1RSTR_SPI3RST_Bit	15	// SPI3RST: SPI3 reset
#define RCC_APB1RSTR_SPI2RST_Bit	14	// SPI2RST: SPI2 reset
#define RCC_APB1RSTR_WWDGRST_Bit	11	// WWDGRST: Window watchdog reset
#define RCC_APB1RSTR_TIM14RST_Bit	8	// TIM14RST: TIM14 timer reset
#define RCC_APB1RSTR_TIM13RST_Bit	7 	// TIM14RST: TIM13 timer reset
#define RCC_APB1RSTR_TIM12RST_Bit	6 	// TIM12RST: TIM12 timer reset
#define RCC_APB1RSTR_TIM7RST_Bit	5 	// TIM7RST: TIM7 timer reset
#define RCC_APB1RSTR_TIM6RST_Bit	4 	// TIM6RST: TIM6 timer reset
#define RCC_APB1RSTR_TIM5RST_Bit	3	// TIM5RST: TIM5 timer reset
#define RCC_APB1RSTR_TIM4RST_Bit	2 	// TIM4RST: TIM4 timer reset
#define RCC_APB1RSTR_TIM3RST_Bit	1 	// TIM3RST: TIM3 timer reset
#define RCC_APB1RSTR_TIM2RST_Bit	0 	// TIM2RST: TIM2 timer reset
/****7.3.6 AHB peripheral clock enable register (RCC_AHBENR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_AHBENR_SDIOEN_Bit		10	//SDIOEN: SDIO clock enable
#define RCC_AHBENR_FSMCEN_Bit		8	//FSMCEN: FSMC clock enable
#define RCC_AHBENR_CRCEN_Bit		6	//CRCEN: CRC clock enable
#define RCC_AHBENR_FLITFEN_Bit		4	//FLITFEN: FLITF clock enable
#define RCC_AHBENR_SRAMEN_Bit		2	//SRAMEN: SRAM interface clock enable
#define RCC_AHBENR_DMA2EN_Bit		1	//DMA2EN: DMA2 clock enable
#define RCC_AHBENR_DMA1EN_Bit		0	//DMA1EN: DMA1 clock enable
/****7.3.7 APB2 peripheral clock enable register (RCC_APB2ENR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_APB2ENR_TIM11EN_Bit		21	// TIM11EN: TIM11 timer clock enable
#define RCC_APB2ENR_TIM10EN_Bit		20	// TIM10EN: TIM10 timer clock enable
#define RCC_APB2ENR_TIM9EN_Bit		19	// TIM9EN: TIM9 timer clock enable
#define RCC_APB2ENR_ADC3EN_Bit		15	// ADC3EN: ADC3 interface clock enable
#define RCC_APB2ENR_USART1EN_Bit	14	// USART1EN: USART1 clock enable
#define RCC_APB2ENR_TIM8EN_Bit		13	// TIM8EN: TIM8 Timer clock enable
#define RCC_APB2ENR_SPI1EN_Bit		12	// SPI1EN: SPI1 clock enable
#define RCC_APB2ENR_TIM1EN_Bit		11	// TIM1EN: TIM1 timer clock enable
#define RCC_APB2ENR_ADC2EN_Bit		10	// ADC2EN: ADC 2 interface clock enable
#define RCC_APB2ENR_ADC1EN_Bit		9 	// ADC1EN: ADC 1 interface clock enable
#define RCC_APB2ENR_IOPCEN_Bit		4 	//#IOPCEN: IO port C clock enable
#define RCC_APB2ENR_IOPBEN_Bit		3	//#IOPBEN: IO port B clock enable
#define RCC_APB2ENR_IOPAEN_Bit		2 	//#IOPAEN: IO port A clock enable
#define RCC_APB2ENR_AFIOEN_Bit		0 	// AFIOEN: Alternate function IO clock enable
/****7.3.8 APB1 peripheral clock enable register (RCC_APB1ENR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_APB1ENR_DACEN_Bit		29	// DACEN: DAC interface clock enable
#define RCC_APB1ENR_PWREN_Bit		28	// PWREN: Power interface clock enable
#define RCC_APB1ENR_BKPEN_Bit		27	// BKPEN: Backup interface clock enable
#define RCC_APB1ENR_CANEN_Bit		25	// CANEN: CAN clock enable
#define RCC_APB1ENR_USBEN_Bit		23	// USBEN: USB clock enable
#define RCC_APB1ENR_I2C2EN_Bit		22	// I2C2EN: I2C2 clock enable
#define RCC_APB1ENR_I2C1EN_Bit		21	// I2C1EN: I2C1 clock enable
#define RCC_APB1ENR_UART5EN_Bit		20	// UART5EN: USART5 clock enable
#define RCC_APB1ENR_UART4EN_Bit		19	// UART4EN: USART4 clock enable
#define RCC_APB1ENR_USART3EN_Bit	18	// USART3EN: USART3 clock enable
#define RCC_APB1ENR_USART2EN_Bit	17	// USART2EN: USART2 clock enable
#define RCC_APB1ENR_SPI3EN_Bit		15	// SPI3EN: SPI 3 clock enable
#define RCC_APB1ENR_SPI2EN_Bit		14	// SPI2EN: SPI2 clock enable
#define RCC_APB1ENR_WWDGEN_Bit		11	// WWDGEN: Window watchdog clock enable
#define RCC_APB1ENR_TIM14EN_Bit		8	// TIM14EN: TIM14 timer clock enable
#define RCC_APB1ENR_TIM13EN_Bit		7 	// TIM13EN: TIM13 timer clock enable
#define RCC_APB1ENR_TIM12EN_Bit		6 	// TIM12EN: TIM12 timer clock enable
#define RCC_APB1ENR_TIM7EN_Bit		5 	// TIM7EN: TIM7 timer clock enable
#define RCC_APB1ENR_TIM6EN_Bit		4 	// TIM6EN: TIM6 timer clock enable
#define RCC_APB1ENR_TIM5EN_Bit		3	// TIM5EN: TIM5 timer clock enable
#define RCC_APB1ENR_TIM4EN_Bit		2 	// TIM4EN: TIM4 timer clock enable
#define RCC_APB1ENR_TIM3EN_Bit		1 	// TIM3EN: TIM3 timer clock enable
#define RCC_APB1ENR_TIM2EN_Bit		0 	// TIM2EN: TIM2 timer clock enable
/****7.3.9 Backup domain control register (RCC_BDCR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_BDCR_BDRST_Bit		16 	// BDRST: Backup domain software reset
#define RCC_BDCR_RTCEN_Bit		15 	// RTCEN: RTC clock enable
#define RCC_BDCR_RTCSEL_Bit1	9 	//#RTCSEL[1:0]: RTC clock source selection
#define RCC_BDCR_RTCSEL_Bit0	8 	//#
#define RCC_BDCR_LSEBYP_Bit		2 	// LSEBYP: External low-speed oscillator bypass
#define RCC_BDCR_LSERDY_Bit		1 	// LSERDY: External low-speed oscillator ready
#define RCC_BDCR_LSEON_Bit		0 	// LSEON: External low-speed oscillator enable
/****7.3.10 Control/status register (RCC_CSR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit
#define RCC_CSR_LPWRRSTF_Bit	31	// LPWRRSTF: Low-power reset flag
#define RCC_CSR_WWDGRSTF_Bit	30	// WWDGRSTF: Window watchdog reset flag
#define RCC_CSR_IWDGRSTF_Bit	29	// IWDGRSTF: Independent watchdog reset flag
#define RCC_CSR_SFTRSTF_Bit		28	// SFTRSTF: Software reset flag
#define RCC_CSR_PORRSTF_Bit		27	// PORRSTF: POR/PDR reset flag
#define RCC_CSR_PINRSTF_Bit		26	// PINRSTF: PIN reset flag
#define RCC_CSR_RMVF_Bit		24 	// RMVF: Remove reset flag
#define RCC_CSR_LSIRDY_Bit		1 	// LSIRDY: Internal low-speed oscillator ready
#define RCC_CSR_LSION_Bit		0 	// LSION: Internal low-speed oscillator enable




//Macros For Config.h
#define ENABLE				1
#define DISABLE				2

#define RCC_u8_HSI_SYSCLK	1
#define RCC_u8_HSE_SYSCLK 	2
#define RCC_u8_PLL_SYSCLK 	3


#define SYSCLK				1
#define SYSCLK_DIV_BY_2  	2
#define SYSCLK_DIV_BY_4  	3
#define SYSCLK_DIV_BY_8  	4
#define SYSCLK_DIV_BY_16 	5
#define SYSCLK_DIV_BY_64 	6
#define SYSCLK_DIV_BY_128	7
#define SYSCLK_DIV_BY_256	8
#define SYSCLK_DIV_BY_512	9

#define AHB_CLK 			1
#define AHB_CLK_DIV_BY_2 	2
#define AHB_CLK_DIV_BY_4 	3
#define AHB_CLK_DIV_BY_8 	4
#define AHB_CLK_DIV_BY_16	5

#define AHB_CLK 			1
#define AHB_CLK_DIV_BY_2 	2
#define AHB_CLK_DIV_BY_4 	3
#define AHB_CLK_DIV_BY_8 	4
#define AHB_CLK_DIV_BY_16	5

#define APB2_CLK_DIV_BY_2	1
#define APB2_CLK_DIV_BY_4	2
#define APB2_CLK_DIV_BY_6	3
#define APB2_CLK_DIV_BY_8	4

#define HSI_CLK_DIV_BY_2	1
#define HSE					2

#define NO_CLOCK			1
#define SYSTEM_CLOCK		2
#define HSI_CLK             3
#define HSE_CLK             4
#define PLL_CLK_DIV_BY_1.5  5

#define PLL_INPUTCLK_x2 	1
#define PLL_INPUTCLK_x3		2
#define PLL_INPUTCLK_x4 	3
#define PLL_INPUTCLK_x5 	4
#define PLL_INPUTCLK_x6 	5
#define PLL_INPUTCLK_x7 	6
#define PLL_INPUTCLK_x8 	7
#define PLL_INPUTCLK_x9 	8
#define PLL_INPUTCLK_x10	9
#define PLL_INPUTCLK_x11	10
#define PLL_INPUTCLK_x12	11
#define PLL_INPUTCLK_x13	12
#define PLL_INPUTCLK_x14	13
#define PLL_INPUTCLK_x15	14
#define PLL_INPUTCLK_x16	15
#define PLL_INPUTCLK_x16	16

#define PLL_CLK_DIV_BY_1.5	1
#define PLLCLK            	2













/*Register Definition >>	value of RCC Base Address is [0x40021000]
#define RCC_CR			*((volatile u32*)0x40021000) 		// Page 99 >// 1st register have same value of Base Address (Step is 0x04)
#define RCC_CFGR		*((volatile u32*)0x40021004)		//Two Bits responsible for Input Clock to Prcessor [Mechanical, Electrical]
#define RCC_CIR			*((volatile u32*)0x40021008)
#define RCC_APB2RSTR	*((volatile u32*)0x4002100C)
#define RCC_APB1RSTR	*((volatile u32*)0x40021010)
#define RCC_AHBENR		*((volatile u32*)0x40021014)		// 3 Bits to Enable/Disable Clock of Perepheral
#define RCC_APB2ENR		*((volatile u32*)0x40021018)
#define RCC_APB1ENR		*((volatile u32*)0x4002101C)
#define RCC_BDCR		*((volatile u32*)0x40021020)
#define RCC_CSR			*((volatile u32*)0x40021024)


//-------------------------------------------------------------
//Busses Types
#define	AHB 		1
#define	APB2		2
#define	APB1		3
*/
#endif
