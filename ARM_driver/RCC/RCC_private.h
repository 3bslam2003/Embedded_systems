
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
#define RCC_SW_MASK  0xFFFFFFFC
#define MCO2_MASK  0x3FFFFFFF
#define MCO2_PRE_MASK  0xFFFFFF1F

#define MCO1_PRE_MASK  0xFFFFFF0F

#define MCO1_MASK    0xFFFFFFCF


#define RCC_CSSON  19
#define RCC_HSEBYP 18
#define RCC_HSEON  16
#define RCC_HSION  0




#define RCC_CSSC    23
#define RCC_HSERDYC 19
#define RCC_HSIRDYC 18
#define RCC_HSERDYIE 11
#define RCC_HSIRDYIE 10
#define RCC_HSERDYF  3
#define RCC_HSIRDYF  2




#define RCC_base_adress   0x40023800


typedef struct
{
	u32  CR;
	u32  PLLCFGR;
	u32  CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
 	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved7;
	u32 Reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 Reserved9;
	u32 Reserved10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 Reserved11;
	u32 Reserved12;
	u32 BDCR;
	u32 CSR;
	u32 Reserved13;
	u32 Reserved14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 Reserved15;
	u32 DCKCFGR;
	
}RCC_memory_map;


#define RCC   ((RCC_memory_map*)(RCC_base_adress))




#endif
