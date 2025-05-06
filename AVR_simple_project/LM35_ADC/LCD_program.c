




#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_init(){
	_delay_ms(40);
	#if LCD_MODE == 8
	
		DIO_setportdirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
		DIO_setpindirection(LCD_COMMAND_PORT,LCD_RW,DIO_pin_output);
		DIO_setpindirection(LCD_COMMAND_PORT,LCD_EN,DIO_pin_output);
		DIO_setpindirection(LCD_COMMAND_PORT,LCD_RS,DIO_pin_output);
		
		LCD_sendcommand(0x38);
		_delay_ms(1);
		
		LCD_sendcommand(LCD_displayon_cursoroff);
		_delay_ms(1);
		LCD_sendcommand(LCD_displayclear);
		_delay_ms(2);
		LCD_sendcommand(LCD_entrymode);
		
	
	
	
	#elif LCD_MODE==4
	
		DIO_setpindirection(LCD_DATA_PORT,PIN4,DIO_PORT_OUTPUT);
		DIO_setpindirection(LCD_DATA_PORT,PIN5,DIO_PORT_OUTPUT);
		DIO_setpindirection(LCD_DATA_PORT,PIN6,DIO_PORT_OUTPUT);
		DIO_setpindirection(LCD_DATA_PORT,PIN7,DIO_PORT_OUTPUT);
		DIO_setpindirection(LCD_COMMAND_PORT,LCD_RW,DIO_pin_output);
		DIO_setpindirection(LCD_COMMAND_PORT,LCD_EN,DIO_pin_output);
		DIO_setpindirection(LCD_COMMAND_PORT,LCD_RS,DIO_pin_output);
		LCD_sendcommand(LCD_home);
		_delay_ms(1);
		LCD_sendcommand(0x28);
		_delay_ms(1);
		
		LCD_sendcommand(LCD_displayon_cursoroff);
		_delay_ms(1);
		LCD_sendcommand(LCD_displayclear);
		_delay_ms(2);
		LCD_sendcommand(LCD_entrymode);
		
	#endif
}




void LCD_sendcommand(u8 copy_num){
	#if LCD_MODE == 8
		
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_RS,PIN_LOW);
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_RW,PIN_LOW);
		DIO_setportvalue(LCD_DATA_PORT,copy_num);
		LCD_sendfallingedge();
		
	
	#elif LCD_MODE ==4
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_RS,PIN_LOW);
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_RW,PIN_LOW);
		DIO_writehighnibles(LCD_DATA_PORT,(copy_num)>>4);
		LCD_sendfallingedge();
		DIO_writehighnibles(LCD_DATA_PORT,copy_num);
		LCD_sendfallingedge();
	#endif
	
}

static void LCD_sendfallingedge(){
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_EN,PIN_HIGH);
		_delay_ms(1);
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_EN,PIN_LOW);
		_delay_ms(1);
}



void LCD_senddata(u8 copy_data)
{
	#if LCD_MODE==8
	
		DIO_setportvalue(LCD_DATA_PORT,copy_data);
		DIO_setpinvalue(LCD_COMMAND_PORT,LCD_RS,PIN_HIGH);
		LCD_sendfallingedge();
	
	#elif LCD_MODE==4
		DIO_setpinvalue  ( LCD_COMMAND_PORT , LCD_RS ,PIN_HIGH );
			DIO_setpinvalue  ( LCD_COMMAND_PORT ,LCD_RW , PIN_LOW  );
		DIO_writehighnibles(LCD_DATA_PORT,(copy_data)>>4);
		LCD_sendfallingedge();
		DIO_writehighnibles(LCD_DATA_PORT,copy_data);
		LCD_sendfallingedge();
	#endif
}
void LCD_voidsetcursor(u8 copy_row,u8 copy_colum)
{
	
	if(copy_row<1||copy_row>2||copy_colum<1||copy_colum>16){
		
		LCD_sendcommand(LCD_setcursor);
		
	}
	if(copy_row==1){
		LCD_sendcommand(LCD_setcursor+(copy_colum-1));
		
	}
	
	if(copy_row==2){
		LCD_sendcommand(LCD_setcursor+64+(copy_colum-1));
		
	}
	
}
void LCD_sendnumber(u16 copy_number)
{
	u32 LOC_u64Reversed = 1 ;

	if( copy_number == 0 ){ LCD_senddata('0'); }

	else{

		while( copy_number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( copy_number % 10 );
			copy_number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			LCD_senddata( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}


}


void LCD_sendstring(u8 * ptr_data)
{
	u8 LOC_char=0;

	while(ptr_data [LOC_char]!='\0')
	{

		LCD_senddata(ptr_data[LOC_char]);
		LOC_char++;
	}
	
}
void LCD_cleardisplay(){
	LCD_sendcommand(LCD_displayclear);

}
