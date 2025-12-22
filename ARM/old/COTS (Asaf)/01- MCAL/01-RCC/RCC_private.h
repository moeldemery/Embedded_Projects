/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/*Register Definition >>	value of RCC Base Address is [0x40021000]*/
#define RCC_CR			*((volatile u32*)0x40021000) 		// Page 99 >// 1st register have same value of Base Address (Step is 0x04)
#define RCC_CFGR		*((volatile u32*)0x40021004)		//Two bits responsible for Input Clock to Prcessor [Mechanical, Electrical]
#define RCC_CIR			*((volatile u32*)0x40021008)
#define RCC_APB2RSTR	*((volatile u32*)0x4002100C)
#define RCC_APB1RSTR	*((volatile u32*)0x40021010)
#define RCC_AHBENR		*((volatile u32*)0x40021014)		// 3 bits to Enable/Disable Clock of Perepheral
#define RCC_APB2ENR		*((volatile u32*)0x40021018)
#define RCC_APB1ENR		*((volatile u32*)0x4002101C)
#define RCC_BDCR		*((volatile u32*)0x40021020)
#define RCC_CSR			*((volatile u32*)0x40021024)


/**************************************************************************/
/*Busses Types*/
#define	AHB 		1
#define	APB2		2
#define	APB1		3

#endif