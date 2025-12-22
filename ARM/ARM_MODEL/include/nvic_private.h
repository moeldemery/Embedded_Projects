/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 7 Feb 2020								*
 *******************************************************/
 
#ifndef  _DIO_PRIVATE_H
#define  _DIO_PRIVATE_H

//>>By default all of them are Group Zero Priority Zero >> I am Depending on H>W
//NVIC Controls 60 External Interrupts in ARM_Cortex_M3, Where > x=0 [0~31] OR x=1 [32~60]External Interrupts

/*Interrupt set-enable registers (NVIC_ISERx) >> Base Address is [0xE000E100]  */
#define NVIC_ISER0		*((volatile u32*)0xE000E100) 		//1: Enable  ,  0:No Effect >> Faster as less assembly code
#define NVIC_ISER1		*((volatile u32*)0xE000E104)		//STM-Programming DataSheet: Page 105 & 125

/*Interrupt clear-enable registers (NVIC_ICERx) >> Base Address is [0xE000E180]*/
#define NVIC_ICER0		*((volatile u32*)0xE000E180)		//1: Disable  ,  0:No Effect
#define NVIC_ICER1		*((volatile u32*)0xE000E184)

/*Interrupt set-pending registers (NVIC_ISPRx) >> Base Address is [0xE000E200]*/
#define NVIC_ISPR0		*((volatile u32*)0xE000E200) 		//1: Set Pending Flag  ,  0:No Effect
#define NVIC_ISPR1		*((volatile u32*)0xE000E204)		//

/*Interrupt clear-pending registers (NVIC_ICPRx) >> Base Address is [0xE000E280]*/
#define NVIC_ICPR0		*((volatile u32*)0xE000E280)		//1: Clear Pending Flag  ,  0:No Effect
#define NVIC_ICPR1		*((volatile u32*)0xE000E284)		//

/*Interrupt active bit registers (NVIC_IABRx) >> Base Address is [0xE000E280]*/
#define NVIC_IABR0		*((volatile u32*)0xE000E280)	//The IABR0-IABR2 registers indicate which interrupts are active.
#define NVIC_IABR1		*((volatile u32*)0xE000E280)

/*Application interrupt and reset control register (SCB_AIRCR) >> Base Address is [0xE000ED0C]*/
#define SCB_AIRCR		*((volatile u32*)0xE000ED0C)		//(PriorityDesign)STM-Programming DataSheet: Page 135

/*Interrupt priority registers (NVIC_IPRx) >> Base Address is [0xE000E400]*/
#define NVIC_IPR		  ((volatile u8*)0xE000E400)		//(PriorityValue)Interrupt priority registers (NVIC_IPRx)		//STM-Programming DataSheet: Page 125
//Instead of #define SCB_IPRx		*((volatile u32*)0xE000E400) >> Because we want to Access it as byte Access


/* [NVIC_IPR] Register is used to Write Down the S.W Priority as (Group or Sub-Priorities) for one of 240 External Peripherals (Only 60 in ARM Cortex-M3)
 * we write the Interrupt Priority value in 8 bits & that's why we access using Byte Access (only write in four bits in ARM Cortex-M3)>> Lower 4Bits are Zeros
 * ex: NVIC_voidSetIntPriority(37, 0b 1100 0000);	>>Set USART1 S.W Priority as:
 * 		-Group 0 Sub 12[in case 0 bits Group [] and 4 bits for Sub[1100]	>>when all peripherals are in one Group, No Nested Interrupts will happen
 * 		-Group 1 Sub 4 [in case 1 bits Group [1] and 3 bits for Sub[100]
 * 		-Group 3 Sub 0 [in case 2 bits Group [11] and 2 bits for Sub[00]
 * 		-Group 6 Sub 0 [in case 3 bits Group [110] and 1 bits for Sub[0]
 * 		-Group 12 Sub0 [in case 4 bits Group [1100] and 0 bits for Sub[]
 *
 * # we Can Split Bits for Group&Sub-Priorities by Using [SCB_AIRCR] Register >> Ex: SCB_AIRCR = 0x05FA0#00;
 * Note that: >>[05FA]> is a Password(VectKey) to write in this register
 * 			  >>By Controlling [#] we Control Splitting >>where: 0Bit >1 option, 1Bit>2 options, 2Bits>4 options, 3Bits>8, 4Bits>16 options
 * 0b011 = 0x3	> [0] Bits for Group-Priority & [4] Bits for Sub-Priority
 * 0b100 = 0x0	> [1] Bits for Group-Priority & [3] Bits for Sub-Priority
 * 0b101 = 0x5	> [2] Bits for Group-Priority & [2] Bits for Sub-Priority
 * 0b110 = 0x6	> [3] Bits for Group-Priority & [1] Bits for Sub-Priority
 * 0b111 = 0x7	> [4] Bits for Group-Priority & [0] Bits for Sub-Priority
 */






#endif
