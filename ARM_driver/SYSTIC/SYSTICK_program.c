/*
 * SYSTICK_program.c
 *
 *  Created on: Nov 29, 2024
 *      Author: HP
 */

#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"


static void(*SET_CALLBACK_Single)(void);
static void(*SET_CALLBACK_Periodic)(void);
static u8 G_Systick_State=IDLE;

static u8 G_FLAG=0;
void SYSTICK_Init()
{
	CLR_BIT(SYSTICK->CTRL,CTRL_CLK_Source);
	CLR_BIT(SYSTICK->CTRL,CTRL_TICK_INT);
}

u8 SYSTICK__SetBusyWait(u32 copy_TickNum)
{
	u8 LOC_state=Ok;
	if(G_Systick_State==IDLE){
		G_Systick_State=Busy;
	SYSTICK->LOAD=copy_TickNum;
	SET_BIT(SYSTICK->CTRL, CTRL_EN_SYSTICK);
	while(GET_BIT(SYSTICK->CTRL,CTRL_CF)==0)
			{

			}
	CLR_BIT(SYSTICK->CTRL, CTRL_EN_SYSTICK);
	G_Systick_State=IDLE;

	}
	else LOC_state=Busy;
	return LOC_state;
}
u8 SYSTICK__SetIntervalSingle(u32 copy_TickNum, void (*copy_Notification)(void))
{
	u8 LOC_state=Ok;
	if(copy_Notification!=Null){
		if(G_Systick_State==IDLE){
			G_Systick_State=Busy;
	SET_CALLBACK_Single=copy_Notification;
	SYSTICK->LOAD=copy_TickNum;
	G_FLAG=0;
	SET_BIT(SYSTICK->CTRL,CTRL_TICK_INT);
	SET_BIT(SYSTICK->CTRL, CTRL_EN_SYSTICK);

		}
		else LOC_state=Busy;
	}
	else LOC_state=Null_pointer;
		return LOC_state;
}
u8 SYSTICK__SetIntervalPeriodic(u32 copy_TickNum, void (*copy_Notification)(void))
{
	u8 LOC_state=Ok;
	if(copy_Notification!=Null){
		if(G_Systick_State==IDLE){
			G_Systick_State=Busy;
	SET_CALLBACK_Periodic=copy_Notification;
	SYSTICK->LOAD=copy_TickNum;
	G_FLAG=1;
	SET_BIT(SYSTICK->CTRL,CTRL_TICK_INT);
	SET_BIT(SYSTICK->CTRL, CTRL_EN_SYSTICK);

		}
		else LOC_state=Busy;
	}
	else LOC_state=Null_pointer;
		return LOC_state;
}
void SYSTICK__StopInterval(void)
{
	CLR_BIT(SYSTICK->CTRL, CTRL_EN_SYSTICK);
}
u32 SYSTIC_GetElapsedTime(void)
{
	return (SYSTICK->LOAD)-(SYSTICK->VAL);
}
u32 SYSTIC_GetRemaininingTime(void)
{
	return (SYSTICK->VAL);
}

void Systick_Handler(void)
{
	u8 LOC_FLAG=0;

	if(G_FLAG==0)
	{
			CLR_BIT(SYSTICK->CTRL,CTRL_TICK_INT);
			CLR_BIT(SYSTICK->CTRL, CTRL_EN_SYSTICK);
			SET_CALLBACK_Single();
			G_Systick_State=IDLE;
	}
	else
	{
		SET_CALLBACK_Periodic();
		LOC_FLAG=GET_BIT(SYSTICK->CTRL,CTRL_CF);

	}
}
