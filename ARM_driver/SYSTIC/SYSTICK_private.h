/*
 * SYSTIC_private.h
 *
 *  Created on: Nov 29, 2024
 *      Author: HP
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_



#define SYSTICK_BASS_ADDRES    0xE000E010

#define CTRL_CF    16
#define CTRL_CLK_Source  2
#define CTRL_TICK_INT   1
#define CTRL_EN_SYSTICK  0


typedef struct
{

	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}SYSTICK_Memory_Mape;


#define SYSTICK    ((SYSTICK_Memory_Mape*)(SYSTICK_BASS_ADDRES ))



#endif /* MCAL_SYSTIC_SYSTIC_PRIVATE_H_ */
