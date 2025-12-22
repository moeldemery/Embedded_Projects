/************************************************************/
/* Author  :Amin                                            */
/* Version :v1.0                                            */
/* Date    :31 Jan 2020                                     */
/************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
/*this API shall enable the clk on certian peripheral*/
void RCC_vidEnableClock(u8 copy_u8Bus,u8 copy_u8peripheral)
/*this API shall disable the clk on certian peripheral*/
void RCC_vidDisableClock(u8 copy_u8Bus,u8 copy_u8peripheral);
/*this API shall enable the clk on Processor*/
void RCC_vidSystemClkInit(void);



#endif