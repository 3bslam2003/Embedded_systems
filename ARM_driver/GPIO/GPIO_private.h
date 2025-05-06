#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define GPIOA_BASE_ADRESS    0x40020000
#define GPIOB_BASE_ADRESS    0x40020400
#define GPIOC_BASE_ADRESS    0x40020800




typedef struct
{
u32 MODER;
u32 OTYPER;
u32 OSPEEDR;
u32 PUPDR;
u32 IDR;
u32 ODR;
u32 BSRR;
u32 LCKR;
u32 AFRL;
u32 AFRH;
}GPIO_MMAP;



#define GPIOA     ((volatile GPIO_MMAP*)(GPIOA_BASE_ADRESS) )
#define GPIOB     ((volatile GPIO_MMAP*)(GPIOB_BASE_ADRESS) )
#define GPIOC     ((volatile GPIO_MMAP*)(GPIOC_BASE_ADRESS) )






#endif
