/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<buz_program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
 NAME  : Ahmed Mohammed Abdelsalam
 
 Layer : HAL
 
 SWC   : buz
 
 
 
 *
 */
 
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "BUZ_interface.h"


void BUZ_init (BUZ_Type buz_config)
{
	DIO_setpindirection(buz_config.port,buz_config.pin,DIO_pin_output);
}


void BUZ_turnon (BUZ_Type buz_config){
	if(buz_config.active_state==0){
		DIO_setpinvalue(buz_config.port,buz_config.pin,PIN_LOW);
	}
	else {
	DIO_setpinvalue(buz_config.port,buz_config.pin,PIN_HIGH);
}
}

void BUZ_turnoff (BUZ_Type buz_config)
{
	if(buz_config.active_state==0){
		DIO_setpinvalue(buz_config.port,buz_config.pin,PIN_HIGH);
	}else{
	DIO_setpinvalue(buz_config.port,buz_config.pin,PIN_LOW);
}
}

void BUZ_toggel (BUZ_Type buz_config)
{
	DIO_togelpinvalue(buz_config.port,buz_config.pin);
}




