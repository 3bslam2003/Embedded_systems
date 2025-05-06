#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"





void RCC_init(void)
{
#if 	RCC_CLK_Type == RCC_HSI
			SET_BIT(RCC->CR,RCC_HSION);
#elif 	RCC_CLK_Type == RCC_HSE
			SET_BIT(RCC->CR,RCC_HSEON);
		#if 	RCC_BYPASS_STATE ==RCC_BYPASS_disable
					CLR_BIT(RCC->CR,RCC_HSEBYP);
		#elif	RCC_BYPASS_STATE ==RCC_BYPASS_enable	
					SET_BIT(RCC->CR,RCC_HSEBYP);
#endif
 #endif
#if     RCC_CSS_STATE==RCC_CSS_enable
			SET_BIT(RCC->CR,RCC_CSSON);
#elif	RCC_CSS_STATE==RCC_CSS_disable
			CLR_BIT(RCC->CR,RCC_CSSON); 
#endif
			
#if 	RCC_MCO2_STATE   == RCC_MCO2_HSI
			RCC->CFGR&=MCO2_MASK;
			RCC->CFGR|=RCC_MCO2_HSI;
#elif	RCC_MCO2_STATE   == RCC_MCO2_SYSCLK
			RCC->CFGR1&=MCO2_MASK;
			RCC->CFGR1|=RCC_MCO2_SYSCLK;
#elif	RCC_MCO2_STATE   == RCC_MCO2_PLLI2S
			RCC->CFGR1&=MCO2_MASK;
			RCC->CFGR1|=RCC_MCO2_PLLI2S;
#elif	RCC_MCO2_STATE   == RCC_MCO2_HSE
			RCC->CFGR1&=MCO2_MASK;
			RCC->CFGR1|=RCC_MCO2_HSE;
#endif

#if     RCC_MCO2_PRE_STATE == RCC_MCO2_PRE_ND
			RCC->CFGR&=MCO2_PRE_MASK;
			RCC->CFGR|=RCC_MCO2_PRE_ND;
#endif
			
			/*
options:
	1-RCC_MCO1_HSI  0
	2-RCC_MCO1_LSE  1
	3-RCC_MCO1_HSE  2
	4-RCC_MCO1_PLL  3
*/

#if		RCC_MCO1_STATE   == RCC_MCO1_HSI
			RCC->CFGR&=MCO1_MASK ;
			RCC->CFGR|=RCC_MCO1_HSI;
#elif	RCC_MCO1_STATE   == RCC_MCO1_LSE		
			RCC->CFGR1&=MCO1_MASK ;
			RCC->CFGR1|=RCC_MCO1_LSE;
#elif	RCC_MCO1_STATE   == RCC_MCO1_HSE		
			RCC->CFGR1&=MCO1_MASK ;
			RCC->CFGR1|=RCC_MCO1_HSE;			
#elif	RCC_MCO1_STATE   == RCC_MCO1_PLL		
			RCC->CFGR1&=MCO1_MASK ;
			RCC->CFGR1|=RCC_MCO1_PLL;			
#endif			



#if RCC_MCO1_PRE_STATE == RCC_MCO1_PRE_ND
			RCC->CFGR&=MCO1_PRE_MASK ;
			RCC->CFGR|=RCC_MCO1_PRE_ND;
			
#endif

RCC->CFGR&=RCC_SW_MASK ;
RCC->CFGR|=RCC_MCO1_PRE_ND;
			
			
}		


void RCC_clockenable(u32 copy_busid , u32 copy_peripheralid)
{
	switch(copy_busid)
	{
		case AHB1:
		SET_BIT(RCC->AHB1ENR,copy_peripheralid);break;
		case AHB2:
		SET_BIT(RCC->AHB2ENR,copy_peripheralid);break;
		case APB1:
		SET_BIT(RCC->APB1ENR,copy_peripheralid);break;
		case APB2:
		SET_BIT(RCC->APB2ENR,copy_peripheralid);break;
		default:

		break;
	}
}
void RCC_clickdisable(u32 copy_busid , u32 copy_peripheralid)
{
		switch(copy_busid)
	{
		case AHB1:
		CLR_BIT(RCC->AHB1ENR,copy_peripheralid);break;
		case AHB2:
		CLR_BIT(RCC->AHB2ENR,copy_peripheralid);break;
		case APB1:
		CLR_BIT(RCC->APB1ENR,copy_peripheralid);break;
		case APB2:
		CLR_BIT(RCC->APB2ENR,copy_peripheralid);break;
		default:

		break;
	}
}
