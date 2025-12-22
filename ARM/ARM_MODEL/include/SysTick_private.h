#ifndef	_SYSTICK_PRIVATE_H
#define _SYSTICK_PRIVATE_H


typedef struct		//arrangement is important
{
	volatile Register_32 CTRL;		//u32 to increment by 0x4 (as Step) >>Page
	volatile Register_32 LOAD;
	volatile Register_32 VAL;
	volatile Register_32 CALIB;
}SYSTICK_type;	//>>RCC_Peripheral

#define SYSTICK		((volatile SYSTICK_type*)0xE000E010)		// I would like to cast this Base_address as pointer to Struct
//RCC_BASE->CR.FourByteAcess= value
//RCC_BASE->CR.BitAcess.B2. = value

//Macros For Pins Of SYSTICK Registers
/****SysTick control and status register (STK_CTRL)*************************************************************/
///we WRITE DOWN EACH BIT WITH IT'S NUMBER for Access by Bit
#define SYSTICK_CTRL_COUNTFLAG_PIN		16
#define SYSTICK_CTRL_CLKSOURCE_PIN		2
#define SYSTICK_CTRL_TICKINT_PIN		1
#define SYSTICK_CTRL_ENABLE_PIN			0

/****SysTick reload value register (STK_LOAD)*************************************************************/




//Macros For Config.h
#define ENABLE		1
#define DISABLE		2

#define ZERO		0x00000000

#define AHB_DIV_BY_8	1
#define AHB				2

#endif
