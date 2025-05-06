#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_



#define PORTA  0
#define PORTB  1
#define PORTC  2


#define  GPIO_INPUT   0
#define  GPIO_OUTPUT  1
#define  GPIO_AF      2
#define  GPIO_ANALOG  3

#define PUSH_PULL   0
#define OPEN_DRAIN  1

#define GPIO_HIGH  1
#define GPIO_LOW   0

#define GPIO_NO_PU_NO_PD  0
#define GPIO_PU           1
#define GPIO_PD           2

#define GIPO_LS  0
#define GPIO_MS  1
#define GPIO_FS  2
#define GPIO_HS  3





void GPIO_MODE_TYPE(u8 copy_port,u8 copy_pin,u8 copy_mode);

void GPIO_OUT_TYPE(u8 copy_port,u8 copy_pin,u8 copy_type);

void GPIO_OUT_SPEED(u8 copy_port,u8 copy_pin,u8 copy_speed);
 void GPIO_PUPDR_TYPE(u8 copy_port,u8 copy_pin,u8 copy_type);
 void GPIO_GET_PIN_VALUE(u8 copy_port,u8 copy_pin,u8* copy_data);
 void GPIO_PIN_OUT_VALUE(u8 copy_port,u8 copy_pin,u8 copy_value);
 void GPIO_FAST_PIN_OUT_VALUE(u8 copy_port,u8 copy_pin,u8 copy_value);
 void GPIO_AF_EN(u8 copy_port,u8 copy_pin,u8 copy_af);







#endif
