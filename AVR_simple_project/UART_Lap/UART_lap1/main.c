/*
 * main.c
 *
 *  Created on: Nov 24, 2024
 *      Author: HP
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "LCD_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>


void init()
{
LCD_init();
UART_init();

}

int main()
{
	init();
	u8 g=0;

	UART_senddata_syn((u8*)"Ahmed mohamed");
	LCD_sendstring("LCD_ready");
	_delay_ms(1000);
	LCD_cleardisplay();

while(1)
{
	UART_receivedata(&g);
	if(g!=0)
	{
		LCD_senddata(g);
		g=0;
	}

}

	return 0;
}
