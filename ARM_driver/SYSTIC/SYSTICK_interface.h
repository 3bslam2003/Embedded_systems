/*
 * SYSTICK_interface.h
 *
 *  Created on: Nov 29, 2024
 *      Author: HP
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


void SYSTICK_Init();

u8 SYSTICK__SetBusyWait(u32 copy_TickNum);
u8 SYSTICK__SetIntervalSingle(u32 copy_TickNum, void (*copy_Notification)(void));
u8 SYSTICK__SetIntervalPeriodic(u32 copy_TickNum, void (*copy_Notification)(void));
void SYSTICK__StopInterval(void);
u32 SYSTIC_GetElapsedTime(void);
u32 SYSTIC_GetRemaininingTime(void);
#endif /* MCAL_SYSTIC_SYSTICK_INTERFACE_H_ */
