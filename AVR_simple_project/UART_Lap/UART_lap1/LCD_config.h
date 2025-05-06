/////////////////////////////////////////////////////////////// LCD_config.h/////////////////////////////////////////////////////////////////////////

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*    options: 4
			   8
			   
*/
#define LCD_MODE   8


/* options: portA
			portB
			portC
			portD
			
			
*/			
#define LCD_DATA_PORT      DIO_portA
#define LCD_COMMAND_PORT   DIO_portB



/*   options :  PIN0
				PIN1
				PIN2
				PIN3
				PIN4
				PIN5
				PIN6
				PIN7
				
				
*/
#define LCD_RS  PIN0
#define LCD_RW  PIN1
#define LCD_EN  PIN2 



#endif
	



