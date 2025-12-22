

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "USART.h"

 void USART_void_Init(void)
 {


	 USART1->BRR=0x340; //9600 boud

	 SET_BIT(USART1->CR1, 13);	//UE 			enable usart
	 CLR_BIT(USART1->CR1, 12);	//Word length 	1 Start bit, 8 Data bits, n Stop bit
	 CLR_BIT(USART1->CR1, 10);	//PCE 			Parity control disabled
	 CLR_BIT(USART1->CR1, 8);	//PEIE 			Parity interrupt disabled
	 CLR_BIT(USART1->CR1, 7);	//TXEIE 		TXE interrupt disabled
	 CLR_BIT(USART1->CR1, 6);	//TCIE 			Transmission complete interrupt disabled
	 CLR_BIT(USART1->CR1, 5);	//RXNE 			RXNE interrupt disabled
 }

 void USART_void_tx(u8 Copy_datatx)
 {
	 USART1->DR = Copy_datatx;

 }
