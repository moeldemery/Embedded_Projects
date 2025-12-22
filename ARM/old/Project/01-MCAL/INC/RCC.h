/*
	Name: 			RCC.h
	Copyright: 		v1
	Author: 		mohamed eldemery
	Date: 			31/01/20 12:22
	Description: 	
*/

#ifndef _RCC_H
#define _RCC_H

#define RCC_BASE_ADD	 	0x40021000

#define RCC_CR				*((volatile u32*) (RCC_BASE_ADD + 0x00))
#define RCC_CFGR			*((volatile u32*) (RCC_BASE_ADD + 0x04))
#define RCC_CIR				*((volatile u32*) (RCC_BASE_ADD + 0x08))
#define RCC_APB2RSTR		*((volatile u32*) (RCC_BASE_ADD + 0x0C))
#define RCC_APB1RSTR		*((volatile u32*) (RCC_BASE_ADD + 0x10))
#define RCC_AHBENR			*((volatile u32*) (RCC_BASE_ADD + 0x14))
#define RCC_APB2ENR			*((volatile u32*) (RCC_BASE_ADD + 0x18))
#define RCC_APB1ENR			*((volatile u32*) (RCC_BASE_ADD + 0x1C))
#define RCC_BDCR			*((volatile u32*) (RCC_BASE_ADD + 0x20))

/* this API shall enable the clock on certain peripheral */
void RCC_void_EnableClock(u8 Copy_u8_peripheral);

/*this API shall disable the clock on certain peripheral*/
void RCC_void_DisableClock(u8 Copy_u8_peripheral);

/*this API shall initialize the clock on certain peripheral*/
void RCC_void_ClkInit(u8 Copy_u8_peripheral);

#endif	//_RCC_H
