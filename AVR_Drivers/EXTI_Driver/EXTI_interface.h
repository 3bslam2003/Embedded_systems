#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_LINE0   6
#define EXTI_LINE1   7
#define EXTI_LINE2   5


#define EXTI_FALLING_EDGE  0
#define EXTI_RISING_EDGE   1
#define EXTI_LOW_LEVEL     2
#define EXTI_ON_CHANGE     3

void EXTI_Init              ( void                                                  );
void EXTI_setsignallatch    ( u8 Copy_SenseMode , u8  Copy_Line                     );
u8   EXTI_disableinterrupt  ( u8 Copy_Line                                          );
u8   EXTI_enableinterrupt   ( u8 Copy_Line                                        	);
void EXTI_clearflag         ( u8 Copy_Line                                        	);
void EXTI_setcallback      ( void (*Copy_pvoidCallBack)(void) , u8 Copy_EXTILine 	);

#endif 
