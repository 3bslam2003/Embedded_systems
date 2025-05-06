/*
 * INVIC_programe.c
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */

#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"
#include "INVIC_interface.h"
#include "INVIC_config.h"
#include"INVIC_private.h"



static u32 group_config;



void INVIC_enableperipheral(u32 copy_peripheral_id)
{
	INVIC->ISER[copy_peripheral_id/32]=(1<<(copy_peripheral_id%32));
}


void INVIC_disableperipheral(u32 copy_peripheral_id)
{
	INVIC->ICER[copy_peripheral_id/32]=(1<<(copy_peripheral_id%32));
}


void INVIC_setpinding(u32 copy_peripheral_id)
{
	INVIC->ISPR[copy_peripheral_id/32]=(1<<(copy_peripheral_id%32));

}
void INVIC_disablepinding(u32 copy_peripheral_id)
{
	INVIC->ICPR[copy_peripheral_id/32]=(1<<(copy_peripheral_id%32));
}

u8 INVIC_getactive(u32 copy_peripheral_id)
{
	return GET_BIT(INVIC->IABR[copy_peripheral_id/32],copy_peripheral_id%32)  ;
}



void INVIC_setgroupnum(u8 copy_groupnum)
{
	group_config=0x5FA0000|(copy_groupnum<<8);
	SCB->AIRCR=group_config;
}


void INVIC_setperiorty(u_8 copy_peripheral_id,u8 copy_subperiorty,u8 copy_groupperiorty)
{
	u8 LOCAL_periorty=copy_subperiorty|copy_groupperiorty<<((group_config-0x05fa0300)/256);
	if(copy_peripheral_id<0){
	if (copy_peripheral_id==MemManage || copy_peripheral_id==Bus_fault ||copy_peripheral_id==Usage_fault)
	{
		copy_peripheral_id+=3;
		SCB->SHPR1=LOCAL_periorty<<((8*copy_peripheral_id)+4);

	}
	if(copy_peripheral_id==SVCall )
	{
		copy_peripheral_id+=7;
		SCB->SHPR2=LOCAL_periorty<<((8*copy_peripheral_id)+4);
	}
	if(copy_peripheral_id==PendSV || copy_peripheral_id==SysTick)
	{
		copy_peripheral_id+=8;
		SCB->SHPR3=LOCAL_periorty<<((8*copy_peripheral_id)+4);
	}
	}
	else if(copy_peripheral_id>=0)
	{
		INVIC->IPR[copy_peripheral_id]=LOCAL_periorty<<4;

	}

}
