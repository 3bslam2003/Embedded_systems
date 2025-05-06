/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DIO_INTERFACE.H>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
 NAME  : Ahmed Mohammed Abdelsalam
 
 Layer : MCAL
 
 SWC   : DIO/GIO
 
 
 
 *
 */
 
 
 #ifndef DIO_INTERFACE_H_
 #define DIO_INTERFACE_H_
 
 
 
 
 typedef enum 
 {
 DIO_Nok,
 DIO_ok
 }DIO_errorstate;
 
 
 #define DIO_portA 0
 #define DIO_portB 1
 #define DIO_portC 2
 #define DIO_portD 3
 
 
 /* define pin direction 8*/
 
 
 #define DIO_pin_input  0
 #define DIO_pin_output  1
 
 
 
 #define PIN0   0
 #define PIN1   1
 #define PIN2   2
 #define PIN3   3
 #define PIN4   4
 #define PIN5   5
 #define PIN6   6
 #define PIN7   7
 
 /* define bin value*/
 
 #define PIN_HIGH 1
 #define PIN_LOW 0
 
 /* define direction for port */
 
 #define DIO_PORT_OUTPUT 0xff
 #define DIO_PORT_INPUT 0
 
 /* define value for port */
 
 #define DIO_PORT_HIGH 0xff
 #define DIO_PORT_LOW 0
 
 
 
 /* IO PIN FUNCTION */
 
 DIO_errorstate DIO_setpindirection(u8 copy_port,u8 copy_pinnumber , u8 copy_pindirection );
 DIO_errorstate DIO_setpinvalue(u8 copy_port,u8 copy_pinnumber , u8 copy_pinvalue         );
 DIO_errorstate DIO_getpinvalue(u8 copy_port,u8 copy_pinnumber , u8* pinvalue             );
 DIO_errorstate DIO_togelpinvalue(u8 copy_port,u8 copy_pinnumber                          );
 
 
 /* PORT FUNCTION */
 
 
 DIO_errorstate DIO_setportdirection (u8 copy_port , u8 copy_portdirection );
 DIO_errorstate DIO_setportvalue     (u8 copy_port , u8 copy_portvalue     );
 DIO_errorstate DIO_getportvalue     (u8 copy_port , u8 * ptr_data         );
 DIO_errorstate DIO_togelportvalue   (u8 copy_port                         );

/* NIBLES FUNCTION */
DIO_errorstate DIO_writehighnibles (u8 copy_port , u8 copy_value );
DIO_errorstate DIO_writelownibles  (u8 copy_port , u8 copy_value );
 
 
 
 #endif
 
 
 
 