#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define Asynchronous 0
#define Synchronous   1
#define Parity_disable 0
#define Parity_enable_even  2
#define Parity_enable_odd   3
#define One_Stop_Bit   0
#define Two_Stop_Bit   1
#define Data_5Bite 0
#define Data_6Bite 1
#define Data_7Bite 2
#define Data_8Bite 3
#define Data_9Bite 7
#define enable    1
#define disable   0

#define Trans_1Speed 0
 
#define Trans_2Speed 1


void UART_init();

u8 UART_senddata(u8 copy_data );

u8 UART_receivedata(u8* copy_recevieddata);

u8 UART_senddata_syn(const u8* copy_string);
u8 UART_senddata_asyn(const u8* copy_string,void (*copy_notification)());



u8 UART_receivedata_syn( u8* copy_string,u32 copy_size);
u8 UART_receivedata_asyn( u8* copy_string,u32 copy_size,void (*copy_notification)());




#endif 
