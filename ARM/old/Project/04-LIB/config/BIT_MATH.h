/************************************************************/
/* Author  :Amin                                            */
/* Version :v1.0                                            */
/* Date    :31 Jan 2020                                     */
/************************************************************/

#ifndef BIT_MATH
#define BIT_MATH

#define 	SET_BIT(REG,BIT_NO)	    				(  REG |=  (1<<(BIT_NO)) )
#define 	CLR_BIT(REG,BIT_NO)						(  REG &= ~(1<<(BIT_NO)) )
#define 	TOGGLE_BIT(REG,BIT_NO)					(  REG ^=  (1<<(BIT_NO)) )
#define 	GET_BIT(REG,BIT_NO)						( (REG >> (BIT_NO))&1    )
#define     ASSIGN_NIBBLE_VALUE(REG,PIN,Val)		(  REG = ((REG&(~(0xF<<PIN*4)))|(VAL<<PIN*4)))
#define 	ASSIGN_BIT(REG,BIT,Val)                 (  REG)

#endif
