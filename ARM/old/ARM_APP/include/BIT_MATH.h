/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BET (VAR , BIT)			VAR |=  (1 << (BIT))
#define CLR_BET (VAR , BIT)			VAR &= ~(1 << (BIT))
#define TOG_BET (VAR , BIT)			VAR ^=  (1 << (BIT))
#define GET_BET (VAR , BIT)			((VAR >> BIT)) & 0X01
#define ASSIGN_BET (VAR,BIT,VAL)	((VAR & (~(1<<BIT))) | (VAL<<BIT)

#endif
