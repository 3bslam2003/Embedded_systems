/*
 * I2C_private.h
 *
 *  Created on: Dec 3, 2024
 *      Author: HP
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWCR   *((volatile u8 *)(0x56))

//TWCR_Pins

#define TWCR_TWI   7
#define TWCR_TWEA  6
#define TWCR_TWST  5
#define TWCR_TWSTO 4
#define TWCR_TWWC  3
#define TWCR_TWEN  2
#define TWCR_TWIE  0




#define TWDR   *((volatile u8*)(0x23))




#define TWAR   *((volatile u8*)(0x22))
#define TWSR   *((volatile u8*)(0x21))

//TWSR_PINS


#define TWSR_TWPS1   1
#define TWSR_TWPS0   0




#define TWBR   *((volatile u8*)(0x20))  //I2c_Data_Register



#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */


#define PRESCALLER_BY_1    1
#define PRESCALLER_BY_4    4
#define PRESCALLER_BY_16   16
#define PRESCALLER_BY_64   64
#endif /* I2C_PRIVATE_H_ */
