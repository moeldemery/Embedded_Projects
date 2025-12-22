/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_RCC_INTERFACE_H___
#define 	_RCC_INTERFACE_H___

/*Macro for Enabling and Disabling Peripherals CLKs*/
#define RCC_u8_PERIPHERAL_CLK_ENABLED		1
#define RCC_u8_PERIPHERAL_CLK_DISABLED		2

/*Marco for Peripheralsin ARM-CortexM*/
#define RCC_GPIOA_PERIPHERAL				1
#define RCC_GPIOB_PERIPHERAL				2
#define RCC_GPIOC_PERIPHERAL				3
//
#define RCC_DMA_PERIPHERAL					0
//#define RCC_SPI_PERIPHERAL				5


/*Prototypes For Functions of RCC*/

//This Function apply clock on Processor
void RCC_voidInit(void);

//This API shall Enable the Clock on Certain Peripheral
ErrorStatus_ RCC_enueripheralCLKState(u8 Copy_u8PeripheralNb , u8 Copy_u8State);		//note that If M.C has no of peripheral more that 256 > we use u16


/*
//This API shall Enable the Clock on Certain Peripheral
void RCC_voidEnableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral);

//This API shall Disable the Clock on Certain Peripheral
void RCC_voidDisableClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral);

//This Function apply clock on Processor
void RCC_SystemCLKInit(void);
*/
void RCC_SystemCLKInit(void);
#endif
