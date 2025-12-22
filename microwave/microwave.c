
#include "STD_TYPES.h"
#define PORTA 	         *((volatile u8 * ) (0xF80))
#define LATA 	         *((volatile u8 * ) (0xF89))
#define TRISA 	         *((volatile u8 * ) (0xF92))
#define ADCON1 	         *((volatile u8 * ) (0xFC1))
#define CMCON 	         *((volatile u8 * ) (0xFB4))
#define CVRCON 	         *((volatile u8 * ) (0xFB5))

#define PORTB 	         *((volatile u8 * ) (0xF81))
#define LATB 	         *((volatile u8 * ) (0xF8A))
#define TRISB 	         *((volatile u8 * ) (0xF93))
#define INTCON 	         *((volatile u8 * ) (0xFF2))
#define INTCON2 	 *((volatile u8 * ) (0xFF1))
#define INTCON3 	 *((volatile u8 * ) (0xFF0))
#define ADCON1 	         *((volatile u8 * ) (0xFC1))

void main()
{
     TRISA=0;

     while(1)
     {
      PORTA= 1;
     }

}