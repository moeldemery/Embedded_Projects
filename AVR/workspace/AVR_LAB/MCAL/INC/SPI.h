/*
 * SPI.h
 *
 *  Created on: 27 Jan 2020
 *      Author: Mohamed
 */

#ifndef MCAL_INC_SPI_H_
#define MCAL_INC_SPI_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define 		SPCR	 		*((volatile u8 * ) (0x2D))
	#define 	SPIE 			7
	#define 	SPE 			6
	#define 	DORD 			5
	#define 	MSTR 			4
	#define 	CPOL 			3
	#define 	CPHA 			2
	#define 	SPR1 			1
	#define 	SPR0 			0

#define 		SPSR 			*((volatile u8 * ) (0x2E))
	#define 	SPIF 			7
	#define 	WCOL 			6
	#define 	SPI2X 			0

#define 		SPDR 			*((volatile u8 * ) (0x2F))


typedef enum {SPI_DISABLE,	SPI_EN} SPI_enable_t ;
typedef enum {SPI_SLAVE	,	SPI_MASTER} SPI_M_S_t ;
typedef enum {SPI_MSB_FIRST,SPI_LSB_FIRST} SPI_Data_Order_t ;
typedef enum {SPI_LEADING_EDGE_RISING,SPI_LEADING_EDGE_FALLING} SPI_Clk_Polarity_t ;
typedef enum {SPI_LEADING_EDGE_SAMPLING,SPI_LEADING_EDGE_SETUP} SPI_Clk_Phase_t ;
typedef enum {SPI_F_2,SPI_F_4,SPI_F_8,SPI_F_16,SPI_F_32,SPI_F_64,SPI_F_128} SPI_Clk_Rate_t ;
typedef enum {SPI_INT_DISABLE,SPI_INT_EN} SPI_Int_enable_t ;

typedef struct
{
	SPI_enable_t			SPI_Enable;
	SPI_M_S_t			 	SPI_M_S;
	SPI_Data_Order_t     	SPI_Data_Order;
	SPI_Clk_Polarity_t   	SPI_Clk_Polarity;
	SPI_Clk_Phase_t      	SPI_Clk_Phase;
	SPI_Clk_Rate_t       	SPI_Clk_Rate;
	SPI_Int_enable_t     	SPI_Int_enable;
}SPI_config_t;


void SPI_Init(void);
u8 	 SPI_TXRX (u8 tx_data);
void SPI_TX_String(u8 * Copy_p_tx_data);
void SPI_TX_Buffer(u8 * Copy_p_tx_data , u8 size);

#endif /* MCAL_INC_SPI_H_ */
