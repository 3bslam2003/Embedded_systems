/////////////////////////////////////////////////////////////////KPD_programe.c///////////////////////////////////////




#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"KPD_interface.h"
#include"KPD_cofig.h"
#include <util/delay.h>



void KPD_init()
{
	DIO_setpindirection(KPD_PORT,KPD_ROW1_PIN,DIO_pin_input);
	DIO_setpindirection(KPD_PORT,KPD_ROW2_PIN,DIO_pin_input);
	DIO_setpindirection(KPD_PORT,KPD_ROW3_PIN,DIO_pin_input);
	DIO_setpindirection(KPD_PORT,KPD_ROW4_PIN,DIO_pin_input);
	
	/////////////////////////////////////////////////////////
	
	DIO_setpinvalue(KPD_PORT,KPD_ROW1_PIN,PIN_HIGH);
	DIO_setpinvalue(KPD_PORT,KPD_ROW2_PIN,PIN_HIGH);
	DIO_setpinvalue(KPD_PORT,KPD_ROW3_PIN,PIN_HIGH);
	DIO_setpinvalue(KPD_PORT,KPD_ROW4_PIN,PIN_HIGH);
	
	/////////////////////////////////////////////////
	
	DIO_setpindirection(KPD_PORT,KPD_COL1_PIN,DIO_pin_output);
	DIO_setpindirection(KPD_PORT,KPD_COL2_PIN,DIO_pin_output);
	DIO_setpindirection(KPD_PORT,KPD_COL3_PIN,DIO_pin_output);
	DIO_setpindirection(KPD_PORT,KPD_COL4_PIN,DIO_pin_output);
	
	
	////////////////////////////////////////////////////////
	
	DIO_setpinvalue(KPD_PORT,KPD_COL1_PIN,PIN_HIGH);
	DIO_setpinvalue(KPD_PORT,KPD_COL2_PIN,PIN_HIGH);
	DIO_setpinvalue(KPD_PORT,KPD_COL3_PIN,PIN_HIGH);
	DIO_setpinvalue(KPD_PORT,KPD_COL4_PIN,PIN_HIGH);
	
	
	////////////////////////////////////////////////////////
	
}

u8 KPD_getpressed()
{
	u8 LOC_datareturn=KPD_NOT_PRESSED;
	u8 LOC_getpressed;
	u8 LOC_COL;
	u8 LOC_ROW;

	for(LOC_COL=0+KPD_INIT_COL;LOC_COL<KPD_END_COL+1;LOC_COL++)
	{
		DIO_setpinvalue(KPD_PORT,LOC_COL,PIN_LOW);


		for(LOC_ROW=0+KPD_INIT_ROW;LOC_ROW<KPD_END_ROW+1;LOC_ROW++)
		{
			DIO_getpinvalue(KPD_PORT,LOC_ROW,&LOC_getpressed);
			if(LOC_getpressed==0)
			{
				_delay_ms(50);

				DIO_getpinvalue(KPD_PORT,LOC_ROW,&LOC_getpressed);
				if(LOC_getpressed==0)
				{
					LOC_datareturn=KPD_button[LOC_ROW-KPD_INIT_ROW][LOC_COL-KPD_INIT_COL];
				}

				while(LOC_getpressed==0)
				{
					DIO_getpinvalue(KPD_PORT,LOC_ROW,&LOC_getpressed);
				}
				break;

			}

		}
		DIO_setpinvalue(KPD_PORT,LOC_COL,PIN_HIGH);

	}


	return LOC_datareturn;


}
