/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 17 Feb 2020								*
 *******************************************************/


#ifndef 	_USART_PRIVATE_H
#define 	_USART_PRIVATE_H

typedef struct		//arrangement is important	//u32 to increment by 0x4 (as Step) >>Page 823
{
	volatile Register_32 SR;		//27.6.1 Status register (USART_SR)
	volatile Register_32 DR;		//27.6.2 Data register (USART_DR)
	volatile Register_32 BRR;		//27.6.3 Baud rate register (USART_BRR)
	volatile Register_32 CR1;		//27.6.4 Control register 1 (USART_CR1)
	volatile Register_32 CR2;		//27.6.5 Control register 2 (USART_CR2)
	volatile Register_32 CR3;		//27.6.6 Control register 3 (USART_CR3)
	volatile Register_32 GTPR;		//27.6.7 Guard time and prescaler register (USART_GTPR)
}USART_type;	//>>RCC_Peripheral

#define USART1		((volatile USART_type*)0x40013800)		// I would like to cast this Base_address as pointer to Struct
#define USART2		((volatile USART_type*)0x40004400)
#define USART3		((volatile USART_type*)0x40004800)
#define USART4		((volatile USART_type*)0x40004C00)
#define USART5		((volatile USART_type*)0x40005000)
//To Access Whole Register: RCC->CR.FourByteAcess   = 0x00010000;
//To Access a Single Bit  : RCC->APB2ENR.BitAcess.Bit2 = 1;


//Macros For Bits Of USART1 Registers
/****27.6.1 Status register (USART_SR)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit	// Peripheral_Register_BitName
#define USART_SR_CTS			9	// CTS: CTS flag						>> CTS status line: (1)Changed (0)didn't change
#define USART_SR_LBD			8	// LBD: LIN break detection flag		>> LIN Break: (1)Detected (0)Not Detected
#define USART_SR_TXE			7	// TXE: Transmit data register empty	>> Data is (0)didn't/(1)did transfer to the shift register
#define USART_SR_TC				6	// TC: Transmission complete			>> Tx is (1)Completed/(0)Not
#define USART_SR_RXNE			5	// RXNE: Read data register not empty	>> (1) Received data is ready to be read / (0)Data is not Received	>> When data is received[RXNE=1] & wasn't read but New data was received, So [ORE=1]
#define USART_SR_IDLE			4	// IDLE: IDLE line detected				>> Idle Line is (1)Detected/(0)Not
#define USART_SR_ORE			3	// ORE: Overrun error					>> set by hardware when the word currently being received in the shift register is ready to be transferred into the RDR register while RXNE=1.
#define USART_SR_NE				2	// NE: Noise error flag					>> set by hardware when noise is detected on a received frame.
#define USART_SR_FE				1	// FE: Framing error					>> set by hardware when a de-synchronization, excessive noise or a break character is detected
#define USART_SR_PE				0	// PE: Parity error						>> set by hardware when a parity error occurs in receiver mode.

/****27.6.2 Data register (USART_DR)*************************************************************/
//#define USART_DR_DR			8:0	//Data value			>> Contains the Received or Transmitted data character.


/****27.6.3 Baud rate register (USART_BRR)*************************************************************/
//#define USART_BRR_DIV_Mantissa			15:4	//DIV_Mantissa: 12 bits define the mantissa of the USART Divider
//#define USART_BRR_DIV_Fraction			3:0		//DIV_Fraction: 4 bits define the fraction of the USART Divider

/****27.6.4 Control register 1 (USART_CR1)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit	// Peripheral_Register_BitName
#define USART_CR1_UE				13	// UE: USART enable  >>  Enable/Disable
#define USART_CR1_M					12	// M: Word length  >>  8/9 Data bits
#define USART_CR1_WAKE				11	// WAKE: Wakeup method >> Idle Line/ Address Mark
#define USART_CR1_PCE				10	// PCE: Parity control enable  >>  Enable/Disable	>When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0
#define USART_CR1_PS				9	// PS: Parity selection  >> (0)Even/(1)Odd Parity
#define USART_CR1_PEIE				8	// PEIE: PE interrupt enable  >>  Disable/Generate Interrupt whenever PE=1[Bit0] in the USART_SR register
#define USART_CR1_TXEIE				7	// TXEIE: TXE interrupt enable  >>  Disable/Generate Interrupt whenever TXE=1[Bit7] in the USART_SR register
#define USART_CR1_TCIE				6	// TCIE: Transmission complete interrupt enable>> Disable/Generate Interrupt whenever TC=1[Bit6] in the USART_SR register
#define USART_CR1_RXNEIE			5	// RXNEIE: RXNE interrupt enable >> Disable/Generate Interrupt whenever ORE=1[Bit3] or RXNE=1[Bit5] in the USART_SR register ( Note that [ORE] Can't be raised without [RXNE] is raised first)
#define USART_CR1_IDLEIE			4	// IDLEIE: IDLE interrupt enable >> Disable/Generate Interrupt whenever IDLE=1[Bit4] in the USART_SR register
#define USART_CR1_TE				3	// TE: Transmitter enable  	 >>  Enable/Disable
#define USART_CR1_RE				2	// RE: Receiver enable >>Receiver is disabled/enabled and begins searching for a start bit
#define USART_CR1_RWU				1	// RWU: Receiver wakeup	>> Active/Mute Mode for Receiver
#define USART_CR1_SBK				0	// SBK: Send break	  >>  Enable/Disable (send Break character)



/****27.6.5 Control register 2 (USART_CR2)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit	// Peripheral_Register_BitName
#define USART_CR2_LINEN				14	// LINEN: LIN mode enable  >>  Enable/Disable
#define USART_CR2_STOP1				13	// STOP: STOP bits >> 1, 0.5, 2, or 1,5 Stop Bits (1.5&2 are mostly used for SmartCard)
#define USART_CR2_STOP0				12	//
#define USART_CR2_CLKEN				11	// CLKEN: Clock enable (For Synchronous Mode) >>  Enable/Disable
#define USART_CR2_CPOL				10	//*CPOL: Clock polarity >> (0)Low/ (1)High value on CK pin outside transmission window.
#define USART_CR2_CPHA				9	//*CPHA: Clock phase  >>   (0)First/(1)Second clock transition is the first data capture edge ((This bit is not available for UART4 & UART5.))
#define USART_CR2_LBCL				8	//*LBCL: Last bit clock pulse >> clock pulse of the last data bit is (0)NotOutput/(1)Output to the CK pin in synchronous mode.
#define USART_CR2_LBDIE				6	// LBDIE: LIN break detection interrupt enable  >>  Disable/Generate Interrupt whenever  LBD=1[Bit8] in the USART_SR register
#define USART_CR2_LBDL				5	// LBDL: lin break detection length >> 10/11 bit bread detection
//#define USART_CR2_ADD			   3:0	// ADD[3:0]: Address of the USART node

///Note: These 3 bits (CPOL, CPHA, LBCL) should not be written while the transmitter is enabled.

/****27.6.6 Control register 3 (USART_CR3)*************************************************************/
///we WRITE DOWN EACH Bit WITH IT'S NUMBER for Access by Bit	// Peripheral_Register_BitName
#define USART_CR3_CTSIE				10	// CTSIE: CTS interrupt enable 		>>  Disable/Generate Interrupt whenever  CTS=1[Bit9] in the USART_SR register
#define USART_CR3_CTSE				9	// CTSE: CTS enable 				>>  Enable/Disable >CTS hardware flow control
#define USART_CR3_RTSE				8	// RTSE: RTS enable					>>  Enable/Disable >RTS hardware flow control
#define USART_CR3_DMAT				7	// DMAT: DMA enable transmitter		>>  Enable/Disable >DMA mode for transmission
#define USART_CR3_DMAR				6	// DMAR: DMA enable receiver 		>>  Enable/Disable >DMA mode for reception
#define USART_CR3_SCEN				5	// SCEN: Smartcard mode enable		>>  Enable/Disable >Smartcard mode.
#define USART_CR3_NACK				4	// NACK: Smartcard NACK enable		>>  Enable/Disable >NACK transmission in case of parity error
#define USART_CR3_HDSEL				3	// HDSEL: Half-duplex selection		>>  Enable/Disable >Half duplex mode (Half-Duplex = Send_OR_Receive in turns)
#define USART_CR3_IRLP				2	// IRLP: IrDA low-power				>>  Enable/Disable >Low-power IrDA mode (if Disabled > Normal Mode)
#define USART_CR3_IREN				1	// IREN: IrDA mode enable			>>  Enable/Disable >IrDA mode
#define USART_CR3_EIE				0	// EIE: Error interrupt enable		>>  Disable/Generate Interrupt whenever[ (DMAR=1[Bit6]in USART_CR3) && (FE=1[Bit1] or ORE=1[Bit3] or NE=1[Bit2] in the USART_SR) ]


/****27.6.7 Guard time and prescaler register (USART_GTPR)*************************************************************/
//#define USART_GTPR_GT			 15:8	// GT[7:0]: Guard time value
//#define USART_GTPR_PSC		  7:0	// PSC[7:0]: Prescaler value (IrDA Low-power mode/Normal IrDA mode/SmartCard Mode)





/* MACROS for Configuration */
#define ENABLED   		1
#define DISABLED 		2

#define Data_8_Bits     1
#define Data_9_Bits     2

#define ODD_PARITY      1
#define EVEN_PARITY     2

#define IDLE_LINE       1
#define ADDRESS_MARK    2

#define ACTIVE_MODE     1
#define MUTE_MODE       2

#define STOP_1_Bit      1
#define STOP_half_Bit   2
#define STOP_2_Bits     3
#define STOP_1half_Bit  4

#define BAUD_9600       1
#define BAUD_115200     2

#define ASYNCHRONOUS    1
#define SYNCHRONOUS     2

#endif
