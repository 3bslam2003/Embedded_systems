////////////////////////////////////////////////////////// LCD_interface.h////////////////////////////////////////////////////////////////





#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_config.h"

#if LCD_MOD == 8
#define EIGHT_BITS  0x38
#endif

#if LCD_MOD == 4
#define FOUR_BITS  0x28
#endif

#define LCD_displayon_cursoroff       0x0c          // display on, cursor off, don't blink character 
#define LCD_displayon_cursoron        0x0e          // display on, cursor on, don't blink character 
#define LCD_displayoff_cursoroff      0x08          // turn display off
#define LCD_displayclear              0x01          //replace all characters with ASCII 'space'  
#define LCD_entrymode                 0x06          // shift cursor from left to right on read/write
#define LCD_home                      0x02          // return cursor to first position on first line 
#define LCD_CGRAM                     0x40          // the first Place/Address at CGRAM
#define LCD_setcursor                 0x80          // set cursor position
#define LCD_functionreset             0x30          // reset the LCD


#define LCD_ROW_1   1
#define LCD_ROW_2   2

#define LCD_COL_1   1
#define LCD_COL_2   2
#define LCD_COL_3   3
#define LCD_COL_4   4
#define LCD_COL_5   5
#define LCD_COL_6   6
#define LCD_COL_7   7
#define LCD_COL_8   8
#define LCD_COL_9   9
#define LCD_COL_10  10
#define LCD_COL_11  11
#define LCD_COL_12  12
#define LCD_COL_13  13
#define LCD_COL_14  14
#define LCD_COL_15  15
#define LCD_COL_16  16

void LCD_init();
void LCD_sendcommand(u8 copy_num);
void LCD_senddata(u8 copy_data);
void LCD_voidsetcursor(u8 copy_row,u8 copy_colum);
void LCD_sendnumber(u16 copy_number);
void LCD_sendstring(u8 * ptr_data);
void LCD_cleardisplay();
#endif
