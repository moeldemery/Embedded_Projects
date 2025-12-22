/*
	Name: 			RCC.h
	Copyright: 		v1
	Author: 		mohamed eldemery
	Date: 			31/01/20 12:22
	Description:
*/


/* this API shall enable the clock on certain peripheral */
void RCC_void_EnableClock(u8 Copy_u8_bus ,u8 Copy_u8_peripheral)
{
    switch (Copy_u8_bus):
    {
        case 0 :{SET_BIT(RCC_AHBENR,Copy_u8_peripheral) ; break;}
        case 1 :{SET_BIT(RCC_APB1ENR,Copy_u8_peripheral); break;}
        case 2 :{SET_BIT(RCC_APB2ENR,Copy_u8_peripheral); break;}
        default:{/*NOTHING*/        break;}
    }

}

/*this API shall disable the clock on certain peripheral*/
void RCC_void_DisableClock(u8 Copy_u8_peripheral)
{

}

/*this API apply clock on processor */
void RCC_void_ClkInit(u8 Copy_u8_peripheral)
{
    /*HSE enable with no BYPASS*/
    /*PLL , HSI , CSS DISABLE*/
    /*SYSCLK = HSE = 8MHZ = APH = APB1=APB2*/
    RCC_CF   = 0x00010000;
    RCC_CFGR = 0x00000001;
}

#endif	//_RCC_H
