#ifndef RCC_PRIVAT_H
#define RCC_PRIVAT_H
/****************************REGISTERS************************************/
typedef struct
{
	Reg_32Access CR;
	Reg_32Access CFGR;
	Reg_32Access CIR;
	Reg_32Access APB2RSTR;
	Reg_32Access APB1RSTR;
	Reg_32Access AHBENR;
	Reg_32Access APB2ENR;
	Reg_32Access APB1ENR;
	Reg_32Access BDCR;
	Reg_32Access CSR;
}RCC_type;

#define RCC  ((volatile RCC_type*)(0x40021000))

/*************************REGISTER_BITS**********************************/
/*RCC_CR_bits*/
#define HSION                   0
#define HSIRDY                  1
#define HSEON                   16
#define HSERDY                  17
#define HSEBYP					18
#define CSSON   				19
#define PLLON                  24
#define PLLRDY					25
/*RCC_CFGR_bits*/
#define OTGFSPRE                22
/************************************************************************/
#define ENABLE     				1
#define DISABLE    				0

#define HSI						1
#define HSE						2
#define PLL						3

#define SYSCLK_NO_DIV 			1
#define SYSCLK_BY_2   			2
#define SYSCLK_BY_4   			3
#define SYSCLK_BY_8   			4
#define SYSCLK_BY_16  			5
#define SYSCLK_BY_64  			6
#define SYSCLK_BY_128 			7
#define SYSCLK_BY_256 			8
#define SYSCLK_BY_512 			9

#define HCLK_NO_DIV				1
#define HCLK_BY_2   			2
#define HCLK_BY_4   			3
#define HCLK_BY_8   			4
#define HCLK_BY_16				5

#define PCLK2_BY_2  			1
#define PCLK2_BY_4  			2
#define PCLK2_BY_8  			3
#define PCLK2_BY_16 			4

#define HSI_CLK_BY_2_IPNUT_CLK  1
#define HSE_CLK_INPUT_CLK       2

#define HSE_NOT_DIVIDED 		1
#define HSE_DIVIDED_BY_2		2

#define CLK_X_2  				0000
#define CLK_X_3                 0001
#define CLK_X_4                 0010
#define CLK_X_5                 0011
#define CLK_X_6                 0100
#define CLK_X_7                 0101
#define CLK_X_8                 0110
#define CLK_X_9                 0111
#define CLK_X_10                1000
#define CLK_X_11                1001
#define CLK_X_12                1010
#define CLK_X_13                1011
#define CLK_X_14                1100
#define CLK_X_15                1101
#define CLK_X_16                1110
#define CLK_X_16                1111

#endif
