/*
 * MCP2515_interface.h
 *
 *  Created on: Dec 12, 2024
 *      Author: HP
 */

#ifndef MCAL_MCP2515_MCP2515_INTERFACE_H_
#define MCAL_MCP2515_MCP2515_INTERFACE_H_






u8 MCP_u8ReadRigster(u8 copy_adress);

u8 MCP_u8WriteRigster(u8 copy_adress);

void MCP_vidSetBitTimeing(u8 Copy_cnf1   ,u8 Copy_cnf2 ,u8 Copy_cnf1);
void MCP_vidChangeBite(u8 copy_adress,u8 mask,u8 value);
void MCP_vidRest(u8 copy_adress);
void MCP_vidChangeMode(u8 mode);

void MCP_SendMsg(u8 BufferId ,u32 ID,u8 DLC,u8* copy_data);

void MCP_vifInit(void);

#endif /* MCAL_MCP2515_MCP2515_INTERFACE_H_ */
