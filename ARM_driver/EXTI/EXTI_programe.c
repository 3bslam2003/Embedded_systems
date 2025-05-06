/*


 * EXTI_programe.c
 *
 *  Created on: Nov 29, 2024
 *      Author: HP
 */




#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


static void (*GSetCallBack[22])(void);


void EXTI_Init()
{
#if HARD_WARE_SELECTION==Interrupt
SET_BIT(EXTI->IMR,EXTI_LINE_NUM);
#elif  HARD_WARE_SELECTION==Event
SET_BIT(EXTI->EMR,EXTI_LINE_NUM);
#endif
#if  EXTI_LINE_TRIIGER==EXTI_TRIGGER_R

		SET_BIT(EXTI->RTSR,EXTI_LINE_NUM);

#elif  EXTI_LINE_TRIIGER==EXTI_TRIGGER_F

		SET_BIT(EXTI->FTSR,EXTI_LINE_NUM);
#elif  EXTI_LINE_TRIIGER==EXTI_TRIGGER_CH

		SET_BIT(EXTI->FTSR,EXTI_LINE_NUM);
		SET_BIT(EXTI->RTSR,EXTI_LINE_NUM);

#endif

		EXTI->PR=0;
}

void EXTI_EnableLine(u8 copy_trigger,u8 copy_line)
{
	if(copy_line<=16){
SET_BIT(EXTI->IMR,copy_line);
if(copy_trigger==EXTI_TRIGGER_F){
	SET_BIT(EXTI->FTSR,copy_line);
}
else if(copy_trigger==EXTI_TRIGGER_R)
{
	SET_BIT(EXTI->RTSR,copy_line);
}
else if (copy_trigger==EXTI_TRIGGER_CH)
{
	SET_BIT(EXTI->RTSR,copy_line);
	SET_BIT(EXTI->FTSR,copy_line);
}
}
}
void EXTI_DisableLine(u8 copy_trigger,u8 copy_line)
{
	if(copy_line<=16){
CLR_BIT(EXTI->IMR,copy_line);

}
}

void EXTI_SetSoftwareTrigger(u8 copy_line)
{
SET_BIT(EXTI->SWIER,copy_line);
}

void EXTI_SetTrigger(u8 copy_trigger,u8 copy_line)
{
	if(copy_line<=16){
if(copy_trigger==EXTI_TRIGGER_F){
	SET_BIT(EXTI->FTSR,copy_line);
}
else if(copy_trigger==EXTI_TRIGGER_R)
{
	SET_BIT(EXTI->RTSR,copy_line);
}
else if (copy_trigger==EXTI_TRIGGER_CH)
{
	SET_BIT(EXTI->RTSR,copy_line);
	SET_BIT(EXTI->FTSR,copy_line);
}
}
}

void EXTI_SetCallBack(u8 copy_line ,void (*Notification_Func)(void))
{
	if(Notification_Func!=Null){
		GSetCallBack[copy_line]=Notification_Func;
	}
}


void EXTI0_IRQHandler(void)
{
	GSetCallBack[0]();
	SET_BIT(EXTI->PR,EXTILINE_0);
}

void EXTI1_IRQHandler(void)
{
	GSetCallBack[1]();
	SET_BIT(EXTI->PR,EXTILINE_1);
}
void EXTI2_IRQHandler(void)
{
	GSetCallBack[2]();
	SET_BIT(EXTI->PR,EXTILINE_2);
}
void EXTI3_IRQHandler(void)
{
	GSetCallBack[3]();
	SET_BIT(EXTI->PR,EXTILINE_3);
}
void EXTI4_IRQHandler(void)
{
	GSetCallBack[4]();
	SET_BIT(EXTI->PR,EXTILINE_4);
}


