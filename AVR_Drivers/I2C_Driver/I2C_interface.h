/*
 * I2C_interface.h
 *
 *  Created on: Dec 3, 2024
 *      Author: HP
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_



typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	SlaveWriteByteErr,
	SlaveReadByteErr,



}TWI_ErrStatus;


void MASTER_init(u8 copy_adress);
void SLAVE_init(u8 copy_adress);

TWI_ErrStatus  I2C_sendstart(void);
TWI_ErrStatus  I2C_repeatstart(void);
TWI_ErrStatus  Master_sendslavewithwrite(u8 copy_slave_adress);
TWI_ErrStatus  Master_sendslavewithread(u8 copy_slave_adress);
TWI_ErrStatus  Master_senddatabyte(u8 copy_data);
TWI_ErrStatus  Master_readdatabyte(u8* copy_data);

TWI_ErrStatus Slave_transmit_data(u8 copy_data);
TWI_ErrStatus Slave_receive_data(u8* copy_data);

void I2C_stopcondition();

#endif /* I2C_INTERFACE_H_ */
