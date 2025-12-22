/********************************************************
 * Author 	: Mody										*
 * Version	: V01										*
 * Data		: 17 Feb 2020								*
 *******************************************************/


#ifndef 	_USART_CONFIG_H
#define 	_USART_CONFIG_H

/****27.6.4 Control register 1 (USART_CR1)*************************************************************/
/*Options:
 * 1-ENABLED
 * 2-DISABLED
 */
#define USART_ENABLEING		DISABLED		// USART enable 			> [USART_CR1_UE]	# Once we Enable, USART Starts Operation
#define TE_ENABLING			ENABLED			// Enable Transmitting		> [USART_CR1_TE]
#define RE_ENABLING			ENABLED			// Enable Receiving			> [USART_CR1_RE]

#define TXE_INT				DISABLED		// TXE interrupt enable 	> [USART_CR1_TXEIE]						// Frame(character) of Data is Sent
#define TRx_COMPLT_INT		DISABLED		// Transmission complete interrupt enabled 	> [USART_CR1_TCIE]	// whole message is sent(all frames) & TXE is raised
#define RXNE_INT			DISABLED		// RXNE interrupt enable	> [USART_CR1_RXNEIE]

#define Parity_CONTROL		ENABLED			// Parity control enable 	> [USART_CR1_PCE]
#define PE_INT				DISABLED		// PE interrupt enable 		> [USART_CR1_PEIE]
#define SENDING_BREAK		DISABLED		// Send Break				> [USART_CR1_SBK]			// if Enabled > Error Frame Interrupt will take place
#define IDLE_INT			DISABLED		// IDLE interrupt enable	> [USART_CR1_IDLEIE]


/*Options:	Word length(Length of Frame) > [USART_CR1_M]
 * 1-Data_8_Bits
 * 2-Data_9_Bits
 */
#define WORD_LENGTH		Data_9_Bits		//I will choose 9bits of Data, but will enable Parity(1 bit)>>So a Total of 8Bits of Data

/*Options:	Parity selection > [USART_CR1_PS]
 * 1-ODD_PARITY
 * 2-EVEN_PARITY
 */
#define Parity_Selection	ODD_PARITY


/*Options:	Wakeup method > [USART_CR1_WAKE]
 * 1-IDLE_LINE
 * 2-ADDRESS_MARK
 */
#define WakeUp_METHOD	IDLE_LINE


/*Options:  Receiver wakeup > [USART_CR1_RWU]
 * 1-ACTIVE_MODE
 * 2-MUTE_MODE
 */
#define WakeUp_RECEIVER		ACTIVE_MODE


/****27.6.5 Control register 2 (USART_CR2)*************************************************************/
/*Options: STOP_BIT > [USART_CR2_STOP1/0]
 * 1-STOP_1_Bit
 * 2-STOP_half_Bit		0.5_StopBit
 * 3-STOP_2_Bits
 * 4-STOP_1half_Bit		1.5_StopBit
 */
#define STOP_BIT		STOP_1_Bit		// Stop Bits

/*Options:
 * 1-SYNCHRONOUS	(Clock Enabled)
 * 2-ASYNCHRONOUS	(Clock Disabled >> Default setting)
 */
#define USART_Mode		ASYNCHRONOUS		// connected M.Cs have Same clk(Freq_sys) or Not			> [USART_CR2_CLKEN]


/****27.6.6 Control register 3 (USART_CR3)*************************************************************/
/*Options:
 * 1-ENABLED
 * 2-DISABLED
 */
#define ERROR_INT		DISABLED			// Error interrupt enable		>[USART_CR3_EIE]

/****27.6.7 Guard time and prescaler register (USART_GTPR)*************************************************************/
//#define USART_GTPR_GT			 15:8	// Guard time value
//#define USART_GTPR_PSC		  7:0	// Prescaler value (IrDA Low-power mode/Normal IrDA mode/SmartCard Mode)

/*Options:
 * 1-BAUD_9600
 * 2-BAUD_115200
 */
#define BAUD_RATE		BAUD_9600		// Baud Rate Desired


#endif
