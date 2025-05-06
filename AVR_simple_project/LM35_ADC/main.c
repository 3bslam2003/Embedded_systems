/*

 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Mahmoud Karem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

#include "LED_interface.h"
#include "LCD_interface.h"
#include "LM35_interface.h"

u8 LM35_V = 0;
/***********************************************/

LED_TYPE LED1={LED_PORTA,LED_PIN5,LED_ACTIVE_HIGH};

LM35_t LM35_S = {5,ADC_CHANNEL0,1};

/***********************************************/

static void APP_Init()
{
	ADC_init();
	LCD_init();
	LED_init(LED1);
	LED_turnoff(LED1);
}

/***********************************************/
int main ()
{
	APP_Init();
	LCD_sendstring((u8 *)"Ahmed Mhammed :)");
	while(1)
	{
		LCD_voidsetcursor(LCD_ROW_2,LCD_COL_2);
		LCD_sendstring((u8 *)"Temp = ");
		LM35_gettemp(&LM35_S,&LM35_V);
		LCD_sendnumber(LM35_V);
		LCD_voidsetcursor(LCD_ROW_2,LCD_COL_12);
		LCD_sendstring((u8 *)" C");

		if (LM35_V >= 20)
		{
			LED_turnon(LED1);
		}
		else
		{
			LED_turnoff(LED1);
		}
	}
	return 0;
}
