/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SSD_program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
 NAME  : Ahmed Mohammed Abdelsalam
 
 Layer : HAL
 
 SWC   : SSD
 
 
 
 *
 */
 
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"

static u8 SSDnum[10]=SSD_NUM;
//static u8 SSDletters [8]=SSD_LETTERS;
void SSD_init (SSD_Type SSD_config)
{
	DIO_setportdirection(SSD_config.ssd_port,DIO_PORT_OUTPUT);
	DIO_setpindirection(SSD_config.enable_port,SSD_config.enable_pin,DIO_pin_output);
}


void SSD_enable (SSD_Type SSD_config){
	if(SSD_config.ssd_type==SSD_COMMON_CATHODE){
		DIO_setpinvalue(SSD_config.enable_port,SSD_config.enable_pin,PIN_LOW);
	}
	else {
	DIO_setpinvalue(SSD_config.enable_port,SSD_config.enable_pin,PIN_HIGH);
}
}

void SSD_disable (SSD_Type SSD_config)
{
if(SSD_config.ssd_type==SSD_COMMON_CATHODE){
		DIO_setpinvalue(SSD_config.enable_port,SSD_config.enable_pin,PIN_HIGH);
	}
	else {
	DIO_setpinvalue(SSD_config.enable_port,SSD_config.enable_pin,PIN_LOW);
}
}

void SSD_sendnumber (SSD_Type SSD_config,u8 copy_number)
{
	if(SSD_config.ssd_type == SSD_COMMON_CATHODE ){
	DIO_setportvalue(SSD_config.ssd_port,SSDnum[copy_number]);
	}
	
	else if(SSD_config.ssd_type == SSD_COMMON_ANODE ){
	DIO_setportvalue(SSD_config.ssd_port,~(SSDnum[copy_number]));
	}
	
}
/*void SSD_sendletter (SSD_Type SSD_config,u8 copy_number)
{
	if(SSD_config.ssd_type == SSD_COMMON_CATHODE ){
	DIO_setportvalue(SSD_config.SSD_port,SSDletters[copy_number]);
	}
	
	else if(SSD_config.ssd_type == SSD_COMMON_ANODE ){
	DIO_setportvalue(SSD_config.SSD_port,~(SSDletters[copy_number]));
	}
}*/





