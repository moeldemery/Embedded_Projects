/********************************************************
 * Author 	: DEMY										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void DMA_Init(void)
{
	DMA_CCH= 0X00007AC2;
	
}

void DMA_Start(u32 Source , u32 Dest , u16 length)
{
	DMA_CNDTR= length;
	DMA_CPAR = Source;
	DMA_CMAR = Dest;
	
}