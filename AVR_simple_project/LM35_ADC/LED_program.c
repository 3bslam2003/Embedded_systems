/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LED_program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
 NAME  : Ahmed Mohammed Abdelsalam
 
 Layer : HAL
 
 SWC   : LED
 
 
 
 *
 */
 
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"


void LED_init (LED_TYPE led_config)
{
	DIO_setpindirection(led_config.port,led_config.pin,DIO_pin_output);
}


void LED_turnon (LED_TYPE led_config){
	if(led_config.active_state==0){
		DIO_setpinvalue(led_config.port,led_config.pin,PIN_LOW);
	}
	else {
	DIO_setpinvalue(led_config.port,led_config.pin,PIN_HIGH);
}
}

void LED_turnoff (LED_TYPE led_config)
{
	if(led_config.active_state==0){
		DIO_setpinvalue(led_config.port,led_config.pin,PIN_HIGH);
	}else{
	DIO_setpinvalue(led_config.port,led_config.pin,PIN_LOW);
}
}

void LED_togel (LED_TYPE led_config)
{
	DIO_togelpinvalue(led_config.port,led_config.pin);
}




