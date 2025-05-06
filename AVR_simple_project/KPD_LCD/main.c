/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
//#include "lcd_config.h"
#include "KPD_interface.h"
//#include "KPD_cofig.h"
#include <util/delay.h>





void main()

{
	u8 data2=KPD_NOT_PRESSED;
	LCD_init();
	KPD_init();

	while(1){
data2=KPD_getpressed();
if(data2!=KPD_NOT_PRESSED){
if(data2=='?'){
	LCD_cleardisplay();
}
else {

	LCD_senddata(data2);

}
}

}
}

