#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*

options :
	1-RCC_HSI   0
	2-RCC_HSE   1
	3-RCC_PLL   2




*/

#define RCC_CLK_Type  RCC_HSI

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

options :
	1-RCC_CSS_enable     1
	2-RCC_CSS_disable

*/


#define RCC_CSS_STATE    RCC_CSS_enable

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*

options:
	1-RCC_BYPASS_enable  1
	2-RCC_BYPASS_disable 0
*/
#define RCC_BYPASS_STATE  RCC_BYPASS_disable

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
options:
	1-RCC_MCO2_SYSCLK  0
	2-RCC_MCO2_PLLI2S  1
	3-RCC_MCO2_HSE     2
	3-RCC_MCO2_HSI     3
*/


#define RCC_MCO2_STATE     RCC_MCO2_HSI

/*

options:
	1-RCC_MCO2_PRE_ND 0
	2-RCC_MCO2_PRE_2  4
	3-RCC_MCO2_PRE_3  5
	4-RCC_MCO2_PRE_4  6
	5-RCC_MCO2_PRE_5  7 
*/
#define RCC_MCO2_PRE_STATE  RCC_MCO2_PRE_ND



/*
options:
	1-RCC_MCO1_HSI  0
	2-RCC_MCO1_LSE  1
	3-RCC_MCO1_HSE  2
	3-RCC_MCO1_PLL  3
*/


#define RCC_MCO1_STATE     RCC_MCO1_HSI

/*

options:
	1-RCC_MCO1_PRE_ND 0
	2-RCC_MCO1_PRE_2  4
	3-RCC_MCO1_PRE_3  5
	4-RCC_MCO1_PRE_4  6
	5-RCC_MCO1_PRE_5  7 
*/
#define RCC_MCO1_PRE_STATE   RCC_MCO1_PRE_ND


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
