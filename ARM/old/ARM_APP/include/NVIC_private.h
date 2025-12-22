/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 7 Feb 2020								*
 *******************************************************/
 
#ifndef  _DIO_PRIVATE_H
#define  _DIO_PRIVATE_H

/*Register Definition >>	value of ISERX Base Address is [0xE000E100]*/

#define NVIC_ISER0		*((volatile u32*)0xE000E100) 		
#define NVIC_ISER1		*((volatile u32*)0xE000E104)
 	
#define NVIC_ICER0		*((volatile u32*)0xE000E180) 	
#define NVIC_ICER1		*((volatile u32*)0xE000E184) 	

#define NVIC_ISPR0		*((volatile u32*)0xE000E200) 		
#define NVIC_ISPR1		*((volatile u32*)0xE000E204)
 	
#define NVIC_ICPR0		*((volatile u32*)0xE000E280) 	
#define NVIC_ICPR1		*((volatile u32*)0xE000E284) 

#endif /*_DIO_PRIVATE_H*/