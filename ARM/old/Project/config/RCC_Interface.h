#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*macros for enable and disable peripheral clks*/
#define  RCC_U8_PERIHERAL_CLK_ENABLE    1
#define  RCC_U8_PERIHERAL_CLK_DISABLE   0

/*macros for peripheral */
#define  RCC_GPIOA_PERIHERAL            0
#define  RCC_GPIOB_PERIHERAL            1
#define  RCC_GPIOC_PERIHERAL            2

/******************************Functions**********************************/
void RCC_vidInit(void);
Error_state RCC_EnuPeripheralClkState(u8 copy_u8PeripheralNum,u8 copy_u8State);
#endif
