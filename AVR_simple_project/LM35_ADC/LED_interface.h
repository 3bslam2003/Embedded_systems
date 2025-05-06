/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LED_INTERFACE.H>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
 NAME  : Ahmed Mohammed Abdelsalam
 
 Layer : HAL
 
 SWC   : LED
 
 
 
 *
 */
 
 
 #ifndef LED_INTERFACE_H_
 #define LED_INTERFACE_H_
 
 /* define led ports */
 #define LED_PORTA 0
 #define LED_PORTB 1
 #define LED_PORTC 2
 #define LED_PORTD 3
 
 
 /* define LEd pins */
 
 #define LED_PIN0 0
 #define LED_PIN1 1
 #define LED_PIN2 2
 #define LED_PIN3 3
 #define LED_PIN4 4
 #define LED_PIN5 5
 #define LED_PIN6 6
 #define LED_PIN7 7
 
 /* define active state */
 
 #define LED_ACTIVE_HIGH 1
 #define LED_ACTIVE_LOW 0
 
 typedef struct{
	 
	u8 port;
	u8 pin ;
	u8 active_state ;
	 
 }LED_TYPE;
 
 
 
 
 void LED_turnon (LED_TYPE led_config);
 void LED_turnoff (LED_TYPE led_config);
 void LED_togel (LED_TYPE led_config);
 void LED_init (LED_TYPE led_config);
 
 
 #endif
 
 
 
 
 