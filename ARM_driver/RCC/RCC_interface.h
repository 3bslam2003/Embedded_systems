#ifndef  RCC_INTERFACE_H_
#define  RCC_INTERFACE_H_


#define RCC_HSI   0
#define RCC_HSE   1
#define RCC_PLL   2




#define RCC_CSS_enable     1
#define RCC_CSS_disable    0

#define RCC_BYPASS_enable  1
#define RCC_BYPASS_disable 1


#define RCC_MCO2_SYSCLK  0
#define RCC_MCO2_PLLI2S  0x40000000
#define RCC_MCO2_HSE     0x80000000
#define RCC_MCO2_HSI    0xC0000000

#define RCC_MCO2_PRE_ND 0
#define RCC_MCO2_PRE_2  4
#define RCC_MCO2_PRE_3  5
#define RCC_MCO2_PRE_4  6
#define RCC_MCO2_PRE_5  7 


#define RCC_MCO1_HSI  0
#define RCC_MCO1_LSE  0x00100000
#define RCC_MCO1_HSE  0x00200000
#define RCC_MCO1_PLL  0x00300000

#define RCC_MCO1_PRE_ND 0
#define RCC_MCO1_PRE_2  4
#define RCC_MCO1_PRE_3  5
#define RCC_MCO1_PRE_4  6
#define RCC_MCO1_PRE_5  7 

//AHB1_peripheral 
#define AHB1  1
#define DMA2 22
#define DMA1 21
#define CRC  12
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOH 7
//AHB2_peripheral
#define AHB2  2
#define OTGFS 7

//APB1_peripheral
#define APB1  3
#define PWREN 28
#define I2C3 23
#define I2C2 22
#define I2C1 21
#define USART2 17
#define SPI3   15
#define SPI2   14
#define WWDG   11
#define TIM2   0
#define TIM3   1
#define TIM4   2
#define TIM5   3
   
//APB2_peripheral
#define APB2   4
#define SPI5  20
#define TIM9  16
#define TIM10 17
#define TIM11 18
#define SYSCFG 14
#define SPI4   13
#define SPI1   12
#define SDIO   11
#define ADC1   8
#define USART6 5
#define USART1 4
#define TIM1   0

	

void RCC_init(void);


void RCC_clockenable(u32 copy_busid , u32 copy_peripheralid);
void RCC_clickdisable(u32 copy_busid , u32 copy_peripheralid);



#endif
