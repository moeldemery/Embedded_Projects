/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 7 Feb 2020								*
 *******************************************************/
 
#ifndef  _DIO_PRIVATE_H
#define  _DIO_PRIVATE_H

/*Register Definition >>	value of GPIOA Base Address is [0x40010800]*/
#define GPIO_CRL_A		*((volatile u32*)0x40010800) 		//
#define GPIO_CRH_A		*((volatile u32*)0x40010804)		//
#define GPIO_IDR_A		*((volatile u32*)0x40010808)
#define GPIO_ODR_A		*((volatile u32*)0x4001080C)
#define GPIO_BSR_A		*((volatile u32*)0x40010810)
#define GPIO_BRR_A		*((volatile u32*)0x40010814)		//
#define GPIO_LCK_A		*((volatile u32*)0x40010818)


/*Register Definition >>	value of GPIOB Base Address is [0x40010C00]*/
#define GPIO_CRL_B		*((volatile u32*)0x40010C00) 		//
#define GPIO_CRH_B		*((volatile u32*)0x40010C04)		//
#define GPIO_IDR_B		*((volatile u32*)0x40010C08)
#define GPIO_ODR_B		*((volatile u32*)0x40010C0C)
#define GPIO_BSR_B		*((volatile u32*)0x40010C10)
#define GPIO_BRR_B		*((volatile u32*)0x40010C14)		//
#define GPIO_LCK_B		*((volatile u32*)0x40010C18)


/*Register Definition >>	value of GPIOC Base Address is [0x40011000]*/
#define GPIO_CRL_C		*((volatile u32*)0x40011000) 		//
#define GPIO_CRH_C		*((volatile u32*)0x40011004)		//
#define GPIO_IDR_C		*((volatile u32*)0x40011008)
#define GPIO_ODR_C		*((volatile u32*)0x4001100C)
#define GPIO_BSR_C		*((volatile u32*)0x40011010)
#define GPIO_BRR_C		*((volatile u32*)0x40011014)		//
#define GPIO_LCK_C		*((volatile u32*)0x40011018)


/*Register Definition >>	value of AFIO Base Address is [0x40010000] ( Alternative function IO*/
/*#define AFIO_EVCR		*((volatile u32*)0x40011000)
#define AFIO_MAPR		*((volatile u32*)0x40011004)
#define AFIO_MAPR		*((volatile u32*)0x40011008)
#define AFIO_MAPR		*((volatile u32*)0x4001100C)
#define AFIO_EXTICR1	*((volatile u32*)0x40011010)
#define AFIO_EXTICR2	*((volatile u32*)0x40011014)
#define AFIO_EXTICR3	*((volatile u32*)0x40011018)
#define AFIO_EXTICR4	*((volatile u32*)0x4001001C)
#define AFIO_MAPR2		*((volatile u32*)0x40010020)*/

#endif