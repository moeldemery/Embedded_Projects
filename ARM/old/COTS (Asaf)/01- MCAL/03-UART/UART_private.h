/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/*Register Definition >>	value of UART1 Base Address is [0x40013800]*/
#define USART_SR		*((volatile u32*)0x40013800)
#define USART_DR		*((volatile u32*)0x40013804)
#define USART_BRR		*((volatile u32*)0x40013808)
#define USART_CR1		*((volatile u32*)0x4001380C)
#define USART_CR2		*((volatile u32*)0x40013810)
#define USART_CR3		*((volatile u32*)0x40013814)
#define USART_GTPR		*((volatile u32*)0x40013818)


#endif