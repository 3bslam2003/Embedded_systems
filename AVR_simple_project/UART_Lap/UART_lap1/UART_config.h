#ifndef UART_CONFIG_H_

#define UART_CONFIG_H_


#define System_Frequancy  8000000ul

#

/*
options:
	1-Asynchronous
	2-Synchronous

*/
#define UART_Mode   Asynchronous

/*

options:
	1-disable
	2-enable

*/
#define MP_MODE    disable


#define Receive_Complete_INT_Mode    enable

#define Transmit_Complete_INT_Mode   enable

#define Data_Reg_Empty_INT_Mode      enable

/*
options:
	1-Parity_disable 
	2-Parity_enable_even  
    3- Parity_enable_odd   

*/
#define  Parity_Mode    disable

/*
options:
	1-Data_5Bite 
	2-Data_6Bite 
	3-Data_7Bite 
	4-Data_8Bite 
	5-Data_9Bite 

*/
#define Data_Bite_Number   Data_8Bite

/*
options:

	1-One_Stop_Bit
	2-TWO_Stop_Bit

*/

#define Stop_Bite_Number   One_Stop_Bit

#define Baud     4800ul


/*

options :

	1-Trans_1Speed
	2-Trans_2Speed
*/

#define Trans_Speed  Trans_1Speed


#define Receiver_Enable    enable
#define Transmitter_Enable enable
#define TIME_OUT    10000ul

#endif
