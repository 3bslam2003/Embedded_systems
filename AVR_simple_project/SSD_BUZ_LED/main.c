/*
 * main.c
 *
 *  Created on: Sep 28, 2024
 *      Author: HP
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"BUZ_interface.h"
#include"SSD_interface.h"
#include"DIO_interface.h"
#include"LED_interface.h"

#include <util/delay.h>

void main(){
	LED_TYPE led[]={ {LED_PORTA,LED_PIN0,LED_ACTIVE_HIGH},{LED_PORTA,LED_PIN1,LED_ACTIVE_HIGH},
			{LED_PORTA,LED_PIN2,LED_ACTIVE_HIGH},{LED_PORTA,LED_PIN3,LED_ACTIVE_HIGH},
			{LED_PORTA,LED_PIN4,LED_ACTIVE_HIGH},{LED_PORTA,LED_PIN5,LED_ACTIVE_HIGH},
			{LED_PORTA,LED_PIN6,LED_ACTIVE_HIGH},{LED_PORTA,LED_PIN7,LED_ACTIVE_HIGH}} ;
	BUZ_Type buz={BUZ_PORTB,BUZ_PIN0,BUZ_ACTIVE_HIGH};
	SSD_Type ssd1={SSD_COMMON_ANODE,SSD_PORTC,SSD_PORTB,SSD_PIN1};
	for(int i=0;i<10;i++){
				LED_init(led[i]);
}
	BUZ_init(buz);
	SSD_init(ssd1);
	SSD_enable(ssd1);

	while(1){
		for(int i=0;i<8;i++){
			LED_turnon(led[i]);
			SSD_sendnumber(ssd1,i+1);
			_delay_ms(1000);
		}
BUZ_turnon(buz);
		_delay_ms(1000);
		for(int i=0;i<10;i++){
				LED_turnoff(led[i]);
				}
	}
}

