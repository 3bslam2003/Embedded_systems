/*
 * EXTI_interface.h
 *
 *  Created on: Nov 29, 2024
 *      Author: HP
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#define EXTILINE_0     0
#define EXTILINE_1     1
#define EXTILINE_2     2
#define EXTILINE_3     3
#define EXTILINE_4     4
#define EXTILINE_5     5
#define EXTILINE_6     6
#define EXTILINE_7     7
#define EXTILINE_8     8
#define EXTILINE_9     9
#define EXTILINE_10     10
#define EXTILINE_11    11
#define EXTILINE_12     12
#define EXTILINE_13     13
#define EXTILINE_14     14
#define EXTILINE_15     15
#define EXTILINE_16     16
#define EXTILINE_17    17
#define EXTILINE_18     18
#define EXTILINE_21     21
#define EXTILINE_22     22


#define EXTI_TRIGGER_R  0
#define EXTI_TRIGGER_F  1
#define EXTI_TRIGGER_CH 2

#define Event     0
#define Interrupt 1





void EXTI_Init();

void EXTI_EnableLine(u8 copy_trigger,u8 copy_line);
void EXTI_DisableLine(u8 copy_trigger,u8 copy_line);

void EXTI_SetSoftwareTrigger(u8 copy_line);

void EXTI_SetTrigger(u8 copy_trigger,u8 copy_line);

void EXTI_SetCallBack(u8 copy_line ,void (*Notification_Func)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
