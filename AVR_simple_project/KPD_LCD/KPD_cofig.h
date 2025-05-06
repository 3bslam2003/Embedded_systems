/////////////////////////////////////////////////////////////////////KPD_config.h///////////////////////////////////////////////////////////////////////













#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_INIT_ROW 0
#define KPD_END_ROW 3
#define KPD_INIT_COL 4
#define KPD_END_COL 7

u8 KPD_button[4][4]={{'7','8','9','/'}, 
					 {'4','5','6','*'}, 
					 {'1','2','3','-'}, 
					 {'?','0','=','+'} 	};
					 
/* options:
			DIO_portA
			DIO_portB
			DIO_portC
			DIO_portD
*/
					 
#define KPD_PORT    DIO_portC




#define KPD_ROW1_PIN      PIN0
#define KPD_ROW2_PIN      PIN1
#define KPD_ROW3_PIN      PIN2
#define KPD_ROW4_PIN      PIN3


#define KPD_COL1_PIN      PIN4
#define KPD_COL2_PIN      PIN5
#define KPD_COL3_PIN      PIN6
#define KPD_COL4_PIN      PIN7





#endif
