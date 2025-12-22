/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 7 Feb 2020								*
 *******************************************************/
 
#ifndef  _DIO_PRIVATE_H
#define  _DIO_PRIVATE_H


typedef struct		//arrangement is important
{
	volatile u32 CRL ;		//u32 to increment by 0x4 (as Step)
	volatile u32 CRH ;
	volatile u32 IDR ;
	volatile u32 ODR ;
	volatile u32 BSRRR;
	volatile u32 BRR ;
	volatile u32 LCKRR;
}GPIO_REG;



//Casting as pointer to Structure (to be informed that I am pointing to an address)
			//Note that : *(0x1234).CRH == GPIO->CRH
#define GPIOA		((volatile GPIO_REG*)0x40010800)		// I would like to cast this address as pointer to Struct
#define GPIOB		((volatile GPIO_REG*)0x40010C00)
#define GPIOC		((volatile GPIO_REG*)0x40011000)

/********************************************************************************************
 *****************************ALternative Functions*****************************************/
typedef struct		//arrangement is important
{
	volatile u32 EVCR	;		//u32 to increment by 0x4 (as Step)
	volatile u32 MAPR	;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 Reserved;		//Reserved Area
	volatile u32 MAPR2	;
}AFIO_REG;



// value of AFIO Base Address is [0x40010000] ( Alternative function IO )
#define AFIO		((volatile GPIO_REG*)0x40011000)

















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
#define AFIO_EXTICR1	*((volatile u32*)0x40011008)
#define AFIO_EXTICR2	*((volatile u32*)0x4001100C)
#define AFIO_EXTICR3	*((volatile u32*)0x40011010)
#define AFIO_EXTICR4	*((volatile u32*)0x40011014)
#define Reserved		*((volatile u32*)0x40011018)
#define AFIO_MAPR2		*((volatile u32*)0x4001101C)


#endif
