#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"



#include "GPIO_interface.h"
#include "GPIO_private.h"



void GPIO_MODE_TYPE(u8 copy_port,u8 copy_pin,u8 copy_mode)
{
switch(copy_port)
{
case PORTA:
	GPIOA->MODER &= ~(0b11<<(copy_pin*2));
	GPIOA->MODER |=(copy_mode)<<(copy_pin*2);
	break;
case PORTB:
	GPIOB->MODER &= ~(0b11<<(copy_pin*2));
	GPIOB->MODER |=(copy_mode<<(copy_pin*2));
    break;
case PORTC:
	GPIOC->MODER &= ~(0b11<<(copy_pin*2));
	GPIOC->MODER |=(copy_mode)<<(copy_pin*2);
	break;

}
}

void GPIO_OUT_TYPE(u8 copy_port,u8 copy_pin,u8 copy_type)
{
	if(copy_type==PUSH_PULL){
switch(copy_port)
{
case PORTA:
	CLR_BIT(GPIOA->OTYPER,copy_pin);
	break;
case PORTC:
	CLR_BIT(GPIOC->OTYPER,copy_pin);
	break;
case PORTB:
	CLR_BIT(GPIOC->OTYPER,copy_pin);
	break;

}
}
	else
	{
		switch(copy_port)
		{
		case PORTA:
			SET_BIT(GPIOA->OTYPER,copy_pin);
			break;
		case PORTB:
			SET_BIT(GPIOB->OTYPER,copy_pin);
			break;
		case PORTC:
			SET_BIT(GPIOC->OTYPER,copy_pin);
			break;

		}
	}

}

void GPIO_OUT_SPEED(u8 copy_port,u8 copy_pin,u8 copy_speed)
{
	switch(copy_port)
	{
	case PORTA:
		GPIOA->OSPEEDR &= ~(0b11<<(copy_pin*2));
		GPIOA->OSPEEDR |=(copy_speed)<<(copy_pin*2);
		break;
	case PORTB:
		GPIOB->OSPEEDR &= ~(0b11<<(copy_pin*2));
		GPIOB->OSPEEDR |=(copy_speed<<(copy_pin*2));
	    break;
	case PORTC:
		GPIOC->OSPEEDR &= ~(0b11<<(copy_pin*2));
		GPIOC->OSPEEDR |=(copy_speed)<<(copy_pin*2);
		break;

	}
}
 void GPIO_PUPDR_TYPE(u8 copy_port,u8 copy_pin,u8 copy_type)
 {
		switch(copy_port)
		{
		case PORTA:
			GPIOA->PUPDR &= ~(0b11<<(copy_pin*2));
			GPIOA->PUPDR |=(copy_type)<<(copy_pin*2);
			break;
		case PORTB:
			GPIOB->PUPDR &= ~(0b11<<(copy_pin*2));
			GPIOB->PUPDR |=(copy_type<<(copy_pin*2));
		    break;
		case PORTC:
			GPIOC->PUPDR &= ~(0b11<<(copy_pin*2));
			GPIOC->PUPDR |=(copy_type)<<(copy_pin*2);
			break;

		}

 }
 void GPIO_GET_PIN_VALUE(u8 copy_port,u8 copy_pin,u8* copy_data)
 {
if(copy_data!=Null)
{
switch(copy_port)
{
case PORTA:
	*copy_data=GET_BIT(GPIOA->IDR,copy_pin);
	break;
case PORTB:
	*copy_data=GET_BIT(GPIOB->IDR,copy_pin);
	break;
case PORTC:
	*copy_data=GET_BIT(GPIOC->IDR,copy_pin);
	break;
}
}
 }
 void GPIO_PIN_OUT_VALUE(u8 copy_port,u8 copy_pin,u8 copy_value)
 {
if(copy_value==GPIO_HIGH)
{
	switch (copy_port)
	{
	case PORTA:
		SET_BIT(GPIOA->ODR,copy_pin);
		break;
	case PORTB:
			SET_BIT(GPIOB->ODR,copy_pin);
			break;
	case PORTC:
			SET_BIT(GPIOC->ODR,copy_pin);
			break;

	}
}

else
{
	switch (copy_port)
		{
		case PORTA:
			CLR_BIT(GPIOA->ODR,copy_pin);
			break;
		case PORTB:
			CLR_BIT(GPIOB->ODR,copy_pin);
				break;
		case PORTC:
			CLR_BIT(GPIOC->ODR,copy_pin);
				break;

		}
}
 }


 void GPIO_FAST_PIN_OUT_VALUE(u8 copy_port,u8 copy_pin,u8 copy_value)
 {


 }
 void GPIO_AF_EN(u8 copy_port,u8 copy_pin,u8 copy_af)
 {


 }
