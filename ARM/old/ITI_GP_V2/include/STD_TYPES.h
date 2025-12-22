/*
 * STD_TYPES.h
 *
 *  Created on: Jan 2020
 *      Author: Mody Hosny
 */

 #ifndef	STD_TYPES_H_
 #define	STD_TYPES_H_

 //#define NULL 			'\0'					     /* 0 */
 //#define NULL_CHAR 		'\0'						 /* 0 */
 #define NULL	((void *)0xFFFF)			 // or (void *)NULL  /*we set address(0xFFFF)in memory for NULL pointer */
													 // 2 byte address bus or (void *)NULL

 typedef unsigned char 	u8; 						 // 1 byte = 8 bit
 typedef signed char 	s8;							 // 1 byte = 8 bit

 typedef unsigned short int u16;					 // 2 bytes = 16 bit
 typedef signed short int s16;						 // 2 bytes = 16 bit

 typedef unsigned long int u32;						 // 4 bytes = 32 bit
 typedef signed long int s32;						 // 4 bytes = 32 bit

 typedef unsigned long long int u64;				 // 8 bytes = 64 bit
 typedef signed long long int s64;					 // 8 bytes = 64 bit

 typedef float 	f32;								 // 4 bytes = 32 bit
 typedef double f64;								 // 8 bytes = 64 bit

/******************************************************/
/*pointer to function=>for declaration pf x = & fun();*/
/******************************************************/

typedef void(*pf)(void);

/******************************************************************************************
        -> ISR Prototype Definition                                                       *
******************************************************************************************/
 #define ISR(No) void __vector_##No (void) __attribute__ ((signal));\
				 void __vector_##No (void)

/******************************************************/
/* enum function for errors							  */
/******************************************************/
typedef enum
{
	 OK = 103,	///Initial value=0 or whatever
	 NOK,
	 OUT_OF_RANGE,
	 NULL_POINTER
 }ErrorStatus_;

typedef union
{
	struct {
		u32 Bit0:1;	//3ayzhate7gz bit warda bas
		u32 Bit1:1;
		u32 Bit2:1;
		u32 Bit3:1;
		u32 Bit4:1;
		u32 Bit5:1;
		u32 Bit6:1;
		u32 Bit7:1;
		u32 Bit8:1;
		u32 Bit9:1;
		u32 Bit10:1;
		u32 Bit11:1;
		u32 Bit12:1;
		u32 Bit13:1;
		u32 Bit14:1;
		u32 Bit15:1;
		u32 Bit16:1;
		u32 Bit17:1;
		u32 Bit18:1;
		u32 Bit19:1;
		u32 Bit20:1;
		u32 Bit21:1;
		u32 Bit22:1;
		u32 Bit23:1;
		u32 Bit24:1;
		u32 Bit25:1;
		u32 Bit26:1;
		u32 Bit27:1;
		u32 Bit28:1;
		u32 Bit29:1;
		u32 Bit30:1;
		u32 Bit31:1;
	}BitAcess;

	u32 FourByteAcess;		//Full Register Access (1 Register = 4 Bytes = 32 bits
}Register_32;

 #endif /* STD_TYPES */
