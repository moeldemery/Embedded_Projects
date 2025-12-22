
#ifndef 	_NVIC_CONFIG_H
#define 	_NVIC_CONFIG_H


/****4.4.5 Application interrupt and reset control register (SCB_AIRCR) >>STM-Programming DataSheets:Page 134************************************/

/*Options:		NVIC_Init_Split_GroupSub_Priorities
 *	1- BitsNo_4Group_0Sub		//16Groups_1Subs
 *	2- BitsNo_3Group_1Sub		//8Groups_2Subs
 *	3- BitsNo_2Group_2Sub		//4Groups_4Subs
 *	4- BitsNo_1Group_3Sub		//2Groups_8Subs
 *	5- BitsNo_0Group_4Sub		//1Group_16Subs		>>In this Case Nested Interrupt is Disabled Because all Peripherals are in one Group
 */
#define Priority_4BitsDesign		BitsNo_2Group_2Sub



#endif
