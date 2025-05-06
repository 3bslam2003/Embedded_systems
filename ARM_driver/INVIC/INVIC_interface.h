/*
 * INVIC_interface.h
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */

#ifndef INVIC_INTERFACE_H_
#define INVIC_INTERFACE_H_

#define GROUP_4BITES  0b000
#define GROUP_3BITES  0b100
#define GROUP_2BITES  0b101
#define GROUP_1BITES  0b110
#define GROUP_0BITES  0b111


#define MemManage    -3
#define Bus_fault    -2
#define Usage_fault   -1


#define SVCall   -4
#define PendSV   -6
#define SysTick  -5


void INVIC_enableperipheral(u32 copy_peripheral_id);


void INVIC_disableperipheral(u32 copy_peripheral_id);


void INVIC_setpinding(u32 copy_peripheral_id);
void INVIC_disablepinding(u32 copy_peripheral_id);

u8 INVIC_getactive(u32 copy_peripheral_id);

void INVIC_setgroupnum(u8 copy_peripheral_id);


void INVIC_setperiorty(u_8 copy_peripheral_id,u8 copy_subperiorty,u8 copy_groupperiorty);
#endif /* MCAL_INVIC_INVIC_INTERFACE_H_ */
