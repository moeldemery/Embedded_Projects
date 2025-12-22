/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 31 Jan 2020								*
 *******************************************************/
 
#ifndef 	_DIO_INTERFACE_H
#define 	_DIO_INTERFACE_H


/*Macro For Pin Number*/					//www.Vector E Learning . com
#define DIO_u8_PIN0			0		//A0
#define DIO_u8_PIN1			1		//A1
#define DIO_u8_PIN2			2		//A2
#define DIO_u8_PIN3			3		//A3
#define DIO_u8_PIN4			4		//A4
#define DIO_u8_PIN5			5		//A5
#define DIO_u8_PIN6			6		//A6
#define DIO_u8_PIN7			7		//A7
#define DIO_u8_PIN8			8		//A8
#define DIO_u8_PIN9			9		//A9
#define DIO_u8_PIN10		10		//A10
#define DIO_u8_PIN11		11		//A11
#define DIO_u8_PIN12		12		//A12
#define DIO_u8_PIN13		13		//A13
#define DIO_u8_PIN14		14		//A14
#define DIO_u8_PIN15		15		//A15

#define DIO_u8_PIN16		16		//B0
#define DIO_u8_PIN17		17		//B1
#define DIO_u8_PIN18		18		//B2
#define DIO_u8_PIN19		19		//B3
#define DIO_u8_PIN20		20		//B4
#define DIO_u8_PIN21		21		//B5
#define DIO_u8_PIN22		22		//B6
#define DIO_u8_PIN23		23		//B7
#define DIO_u8_PIN24		24		//B8
#define DIO_u8_PIN25		25		//B9
#define DIO_u8_PIN26		26		//B10
#define DIO_u8_PIN27		27		//B11
#define DIO_u8_PIN28		28		//B12
#define DIO_u8_PIN29		29		//B13
#define DIO_u8_PIN30		30		//B14
#define DIO_u8_PIN31		31		//B15

//Because PORTC is consisting of three H.W Pins only > PIN_no: 13, 14, 15 >>>45%16 = 13 , 46%16 = 13 , 47%16 = 15
#define DIO_u8_PIN32		45		//C0 >32	//Actively LOW Green Led inside ARM chip(Not External Pin)>> Apply Low to activate
#define DIO_u8_PIN33		46		//C1 >33
#define DIO_u8_PIN34		47		//C2 >34

/*Macro For High Value and Low Value*/
#define		DIO_u8_HIGH		1
#define		DIO_u8_LOW		0

/* Macro For Pin Modes (16 Mode for each Pin) */
#define DIO_u8_INPUT_ANALOG		0b0000
#define DIO_u8_INPUT_FLOATING	0b0100
#define DIO_u8_INPUT_PULLUP		0b1000
#define DIO_u8_INPUT_PULLDOWN	0b1100		/*Take note that it is Reserved (Will be specified later by ODR)*/

// Macro for OutPut Direction = 10 MHz Speed
#define DIO_u8_OUTPUT_10M_PP	0b0001		//Push Pull Mode
#define DIO_u8_OUTPUT_10M_OD	0b0101		//Open Drain
#define DIO_u8_OUTPUT_10M_AFPP	0b1001		//Alternative Function PushPull
#define DIO_u8_OUTPUT_10M_AFOD	0b1101		//Alternative Function OD

// Macro for OutPut Direction = 2 MHz Speed
#define DIO_u8_OUTPUT_2M_PP		0b0010
#define DIO_u8_OUTPUT_2M_OD		0b0110
#define DIO_u8_OUTPUT_2M_AFPP	0b1010
#define DIO_u8_OUTPUT_2M_AFOD	0b1110

// Macro for OutPut Direction = 50 MHz Speed
#define DIO_u8_OUTPUT_50M_PP	0b0011
#define DIO_u8_OUTPUT_50M_OD	0b0111
#define DIO_u8_OUTPUT_50M_AFPP	0b1011
#define DIO_u8_OUTPUT_50M_AFOD	0b1111




ErrorStatus DIO_enuInit(void);

//to Set each pin Mode (Direction [in/out put] + Mode [Pullup/down - OpenDrain
ErrorStatus DIO_enuSetPinMode (u8 Copy_u8PinNb , u8 Copy_u8PinMode);

ErrorStatus DIO_enuSetPinValue(u8 Copy_u8PinNb , u8 Copy_u8Value);

ErrorStatus DIO_enuGetPinValue(u8 Copy_u8PinNb , u8 *Copy_ReturnValue);

void ledToggle_Pin32(void);

ErrorStatus ledToggle_Pinx(u8 Pin_No);

#endif
