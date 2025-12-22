/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 7 Feb 2020								*
 *******************************************************/
 
#ifndef  _DIO_PRIVATE_H
#define  _DIO_PRIVATE_H


// typedef struct		//arrangement is important
// {
	// volatile u32 DMA_ISR ;		//u32 to increment by 0x4 (as Step)
	// volatile u32 DMA_IFCR ;
	// volatile u32 DMA_CCR ;	
	// volatile u32 DMA_CNDTR ;
	// volatile u32 DMA_CPAR;
	// volatile u32 DMA_CMAR  ;
// }DMA_REG;

#define DMA_ISR 		*((volatile u32 *)0x40020000)
#define DMA_IFCR 		*((volatile u32 *)0x40020004)
#define DMA_CCR 		*((volatile u32 *)0x40020008)
#define DMA_CNDTR		*((volatile u32 *)0x4002000C)
#define DMA_CPAR 		*((volatile u32 *)0x40020010)
#define DMA_CMAR 		*((volatile u32 *)0x40020014)
















/*
//Register Definition >>	value of GPIOA Base Address is [0x40010800]
#define GPIO_CRL_A		*((volatile u32*)0x40010800) 		//
#define GPIO_CRH_A		*((volatile u32*)0x40010804)		//
#define GPIO_IDR_A		*((volatile u32*)0x40010808)
#define GPIO_ODR_A		*((volatile u32*)0x4001080C)
#define GPIO_BSRR_A		*((volatile u32*)0x40010810)
#define GPIO_BRR_A		*((volatile u32*)0x40010814)		//
#define GPIO_LCKR_A		*((volatile u32*)0x40010818)


//Register Definition >>	value of GPIOB Base Address is [0x40010C00]
#define GPIO_CRL_B		*((volatile u32*)0x40010C00) 		//
#define GPIO_CRH_B		*((volatile u32*)0x40010C04)		//
#define GPIO_IDR_B		*((volatile u32*)0x40010C08)
#define GPIO_ODR_B		*((volatile u32*)0x40010C0C)
#define GPIO_BSRR_B		*((volatile u32*)0x40010C10)
#define GPIO_BRR_B		*((volatile u32*)0x40010C14)		//
#define GPIO_LCKR_B		*((volatile u32*)0x40010C18)


//Register Definition >>	value of GPIOC Base Address is [0x40011000]
#define GPIO_CRL_C		*((volatile u32*)0x40011000) 		//
#define GPIO_CRH_C		*((volatile u32*)0x40011004)		//
#define GPIO_IDR_C		*((volatile u32*)0x40011008)
#define GPIO_ODR_C		*((volatile u32*)0x4001100C)
#define GPIO_BSRR_C		*((volatile u32*)0x40011010)
#define GPIO_BRR_C		*((volatile u32*)0x40011014)		//
#define GPIO_LCKR_C		*((volatile u32*)0x40011018)


//Register Definition >>	value of AFIO Base Address is [0x40010000] ( Alternative function IO )
#define AFIO_EVCR		*((volatile u32*)0x40011000)
#define AFIO_MAPR		*((volatile u32*)0x40011004)
#define AFIO_MAPR		*((volatile u32*)0x40011008)
#define AFIO_MAPR		*((volatile u32*)0x4001100C)
#define AFIO_EXTICR1	*((volatile u32*)0x40011010)
#define AFIO_EXTICR2	*((volatile u32*)0x40011014)
#define AFIO_EXTICR3	*((volatile u32*)0x40011018)
#define AFIO_EXTICR4	*((volatile u32*)0x4001001C)
#define AFIO_MAPR2		*((volatile u32*)0x40010020)*/

#endif
