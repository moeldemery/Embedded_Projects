#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

typedef unsigned char                   u8 ;
typedef unsigned short int              u16;
typedef unsigned int                    u32;

typedef signed char                     s8 ;
typedef signed short int                s16;
typedef signed int                      s32;

typedef float                           f32;
typedef double                          d64;

typedef enum 
{
        OK = 0,
        NOKAY = 4,
        OUTOFRANGE = 8
}Error_status;

#endif //__STD_TYPES_H__