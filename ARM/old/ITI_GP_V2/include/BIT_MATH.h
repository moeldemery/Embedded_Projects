/*
 * BIT_MATH.H
 *
 *  Created on: Jan 2020
 *      Author: Mody Hosny
 */


 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_

 // Bit operations	# >> Most Used
 #define SET_BIT(VAR,BIT_NUMBER)			(VAR) |= 	(1<<(BIT_NUMBER))  //# assign the desired bit  with 1 (or the VAR with 1)
 #define CLR_BIT(VAR,BIT_NUMBER)			(VAR) &=~	(1<<(BIT_NUMBER))  //# and 0 with the desired bit to clr(set to 0)
 #define TOGGLE_BIT(VAR,BIT_NUMBER)			(VAR) ^= 	(1<<(BIT_NUMBER))  //# (bitwise exclusive or [^]) with the desired bit to toggle from 0 to 1 and from 1 to 0
 #define ASSIGN_BIT(VAR,BIT_NUMBER,VALUE)	(VAR) = 	((VAR&(~(1<<BIT_NUMBER)))|(VALUE << BIT_NUMBER))  // CLR the desired bit then assign the desired value
 #define GET_BIT(VAR,BIT_NUMBER) 			((VAR>> BIT_NUMBER)&(0x01))   //# Move the desired bit to the first bit then anding it with 1 to make sure if it's 1 or 0

#define ASSIGN_NIBBLE_VALUE(REG,PIN,VAL)	REG = ( (REG & (~(0xF << PIN*4))) | (VAL << PIN*4) )

 //Concatenation ( if you have separate numbers and would like to combine all of them into one number ex:8 bits of Register
 #define 	CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0)	CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
 #define	CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)	0b##B7##B6##B5##B4##B3##B2##B1##B0
 /*CONC_HELP > is to delay the combination of bits of Register one step until the bits are numbers
 (it means that if bits value are Macros, They will be numbers first by preprocessor then combined)*/




/******************************************************************************************************/
/******************************************************************************************************/
 // REG operations
 #define SET_REG(REG) 						(REG) =  (0xff)  			// Assign the desired reg  with 1 (or the reg with 1)
 #define CLR_REG(REG)  						(REG) =  (0x00)				// and 0 with the desired reg to clr(set to 0)
 #define TOGGLE_REG(REG) 					(REG) ^= (0xff)				// (bitwise exclusive or [^]) with the desired reg to toggle from 0 to 1 and from 1 to 0
 #define ASSIGN_REG(REG,VALUE)   			(REG) =  (VALUE)			// ASSIGN a new value to the reg
 #define EDIT_REG(REG,VALUE)   				(REG) |= (VALUE)			// ASSIGN a new value to the reg

 // REG_LOW_NIBLE operations
 #define GET_LOW_NIBLE(REG) 				((REG) &  (0x0f))							// GET the bits value at the LOW NIBLE of the reg
 #define CLR_LOW_NIBLE(REG) 				((REG) &= (0xf0))							// and 0 with the LOW NIBLE of the reg to clr(set to 0)
 #define SET_LOW_NIBLE(REG)  				((REG) |= (0x0f))							// assign the LOW NIBLE of the reg  with 1 (or the reg with 1)
 #define TOGGLE_LOW_NIBLE(REG) 				((REG) ^= (0x0f))							// (bitwise exclusive or [^]) with the LOW NIBLE of the reg to toggle from 0 to 1 and from 1 to 0
 #define ASSGIN_LOW_NIBLE(REG,VALUE) 		(REG)   = ((REG & 0xf0)|(VALUE & 0x0f))		// ASSIGN a new value to the LOW NIBLE of the reg


 // REG_HIGH_NIBLE operations
 #define GET_HIGH_NIBLE(REG) 				((REG >> 4) & 0x0f)							// GET the bits value at the HIGH NIBLE of the reg
 #define CLR_HIGH_NIBLE(REG) 				((REG) &= (0x0f))							// and 0 with the HIGH NIBLE of the reg to clr(set to 0)
 #define SET_HIGH_NIBLE(REG) 				((REG) |= (0xf0))							// assign the HIGH NIBLE of the reg  with 1 (or the reg with 1)
 #define TOGGLE_HIGH_NIBLE(REG) 			((REG) ^= (0xf0))							// (bitwise exclusive or [^]) with the HIGH NIBLE of the reg to toggle from 0 to 1 and from 1 to 0
 #define ASSIGN_HIGH_NIBLE(REG,VALUE) 		(REG)   = ((REG) & (0x0f)) | ((VALUE)<<4)	// ASSIGN a new value to the HIGH NIBLE of the reg

 #endif	/* BIT_MATH_H_ */
