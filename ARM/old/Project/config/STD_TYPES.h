/************************************************************/
/* Author  :Amin                                            */
/* Version :v1.0                                            */
/* Date    :31 Jan 2020                                     */
/************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
  #define NULL  		  '\0'
//#define NULL_CHAR   '\0'
//#define NULL ((void*)0xFFFF)

typedef signed   char s8 ;
typedef unsigned char u8 ;

typedef signed   short int s16 ;
typedef unsigned short int u16 ;

typedef signed   long int s32 ;
typedef unsigned long int u32 ;

typedef signed   long long int s64 ;
typedef unsigned long long int u64 ;

typedef float  f32 ;
typedef double f64 ;

typedef enum Error 
{
	OK=0   		 	  ,
	NOKAY=1  		  ,
	OUTOFRANGE=2	  ,
	NULL_POINTER=3
		
}Error_state ;

#define ISR(NUM) void __vector_##NUM (void) __attribute__((signal));\
				 void __vector_##NUM (void)

typedef union
{
    struct
	{
		u32 Bit0 :1;
		u32 Bit1 :1;
		u32 Bit2 :1;
		u32 Bit3 :1;
		u32 Bit4 :1;
		u32 Bit5 :1;
		u32 Bit6 :1;
		u32 Bit7 :1;
		u32 Bit8 :1;
		u32 Bit9 :1;
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
	}Bit_access;
	u32 FourByteAccess;
}Reg_32Access;
#endif

