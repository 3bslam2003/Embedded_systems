/*
 * main.c
 *
 *  Created on: Oct 30, 2024
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "LED_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "GIE_interface.h"

u32 counter_ov =0;
u32 counter_comp=0;

LED_TYPE led1={LED_PORTA,LED_PIN0,LED_ACTIVE_HIGH};
LED_TYPE led2={LED_PORTA,LED_PIN1,LED_ACTIVE_HIGH};
void init(){


	TIMER0_init();
	TIMER2_init();
	LED_init(led1);
	LED_init(led2);
}

void func_OV (){
	counter_ov++;
	if(counter_ov==19532){
	LED_togel(led1);
	counter_ov=0;
	}
}

void func_COMP(){

	counter_comp++;
		if(counter_comp==1000){
		LED_togel(led2);
		counter_comp=0;
		}
}


void main(){
	init();
	GIE_enable();
	SET_CALLBACK(func_OV,TIMER0_OVF_VICTOR_ID);
	SET_CALLBACK(func_COMP,TIMER2_COMP_VICTOR_ID);

while(1){};

}

