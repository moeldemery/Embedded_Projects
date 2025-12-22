/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_NVIC_INTERFACE_H
#define 	_NVIC_INTERFACE_H

void NVIC_voidEnableInt (u8 Copy_u8Idx);
void NVIC_voidDisableInt(u8 Copy_u8Idx);

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx);
void NVIC_voidClrPendingFlag(u8 Copy_u8Idx);

ErrorStatus NVIC_Init_Split_GroupSub_Priorities(u8 Copy_u8Priority_4BitsDesign);
ErrorStatus NVIC_voidSetIntPriority (u8 Copy_u8Peripheral, u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority);

//Macros For Config.h

#define ENABLE				1
#define DISABLE				2

#define BitsNo_4Group_0Sub		1
#define BitsNo_3Group_1Sub		2
#define BitsNo_2Group_2Sub		3
#define BitsNo_1Group_3Sub		4
#define BitsNo_0Group_4Sub		5

/*	# Vector Table # STM_Register DataSheet Page: 197	*/
//NVIC Controls 60 External Peripherals whose addresses are recorded in Vector Table>> Here number is important  because it represents corresponding ISR (Handler value)
#define VT_WWDG				0		// Window watchdog interrupt
#define VT_RCC 				5		// RCC global interrupt
#define VT_EXTI0			6		// EXTI Line0 interrupt
#define VT_EXTI1			7		// EXTI Line1 interrupt
#define VT_EXTI2			8
#define VT_EXTI3			9
#define VT_EXTI4			10
#define VT_DMA1_Channel1 	11		// DMA1 Channel1 global interrupt
#define VT_DMA1_Channel2 	12
#define VT_DMA1_Channel3 	13
#define VT_DMA1_Channel4 	14
#define VT_DMA1_Channel5 	15
#define VT_DMA1_Channel6 	16
#define VT_DMA1_Channel7	17
#define VT_ADC1_2		 	18		// ADC1 and ADC2 global interrupt
#define VT_CAN_RX1 			21		// CAN RX1 interrupt
#define VT_CAN_SCE		 	22		// CAN SCE interrupt
#define VT_TIM1_CC 			34		// TIM1 Capture Compare interrupt
#define VT_I2C1_EV			31		// I2C1 event interrupt
#define VT_I2C1_ER			32		// I2C1 error interrupt
#define VT_SPI1				35		// SPI1 global interrupt
#define VT_SPI2 			36		// SPI2 global interrupt
#define VT_USART1			37		// USART1 global interrupt
#define VT_USART2			38		//
#define VT_USART3			39		//
//
//so on..

#endif
