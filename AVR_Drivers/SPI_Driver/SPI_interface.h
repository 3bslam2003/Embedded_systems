/*
 * SPI_interface.h
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_MASTER  1
#define SPI_SLAVE   0


#define SPI_LSB_FIRST  1
#define SPI_MSB_FIRST  0



#define SPI_HIGH_IDLE   1
#define SPI_LOW_IDLE    0


#define SPI_LEADING_READ  0
#define SPI_LEADING_WRITE  1


#define SPI_1X_4F     0
#define SPI_1X_16F    1
#define SPI_1X_64F    2
#define SPI_1X_128F   3
#define SPI_2X_2F     0
#define SPI_2X_8F     1
#define SPI_2X_32F    2
#define SPI_2x_64F    3



#define SPI_2X_SPEED   1
#define SPI_1X_SPEED   0



typedef struct
{

	u8 SPI_interruptenable ;
	u8 SPI_spienable ;
	u8 SPI_dataorder  ;
	u8 SPI_masterslaveselect ;
	u8 SPI_clkpolarity ;
	u8 SPI_clkphase ;
	u8 SPI_clkrate ;
}SPI_config;

typedef struct
{
	u8 * copy_data_send;
	u8 * copy_data_receive;
	u8 copy_buffer_size;
	void (*notification_func)();
}SPI_buffer;

void SPI_init();

u8 SPI_tranceive(u8 copy_data_send,u8* copy_data_receive);
u8 SPI_initconfig(SPI_config* copy_config);

u8 SPI_buffertranceive_sync(u8* copy_data_send,u8* copy_data_receive);

u8 SPI__buffertranceive_async(SPI_buffer* copy_buffer);


#endif /* SPI_INTERFACE_H_ */
