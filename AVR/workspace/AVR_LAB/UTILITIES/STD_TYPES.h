/********************************************/
/*Auther	: mohamed Eldemery				*/
/*Version	: V01							*/
/*Date		: 31 DEC 2019					*/
/********************************************/

#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__


#define NULL 				((void * ) 0xFFFF)

typedef unsigned char		u8 ;
typedef unsigned short int	u16;
typedef unsigned int		u32;

typedef signed char			s8 ;
typedef signed short int	s16;
typedef signed int			s32;

typedef float				f32;
typedef double				d64;

#ifndef F_CPU
#define F_CPU 12000000LU
#endif

#define HIGH 0xFF
#define LOW	 0x00

typedef enum 
{
	OK = 0,
	NOKAY = 4,
	OUTOFRANGE = 8,
	NULLPOINTER = 12
}Error_status;

#define ISR(no) void __vector_##no (void)  __attribute__ ((signal)); \
		void __vector_##no (void)


#endif //__STD_TYPES_H__
