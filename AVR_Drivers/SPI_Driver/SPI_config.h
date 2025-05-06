/*
 * SPI_config.h
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*
 * options:
 * 1-enable
 * 2-disable
 */

#define SPI_STATE  enable
/*
 * options:
 * 1-SPI_MASTER
 * 2-SPI_SLAVE
 */
#define SPI_MODE   SPI_MASTER

/*
 * options:
 * 1-enable
 * 2-disable
 */
#define SPI_INTERRUPT_STATE  disable

/*
 * options:
 * 1-SPI_LSB_FIRST
 * 2-SPI_MSB_FIRST
 */

#define SPI_DATA_ORDER   SPI_LSB_FIRST

/*
 * options :
 * 1-SPI_HIGH_IDLE
 * 2-SPI_LOW_IDLE
 */

#define SPI_CLK_POLARITY   SPI_HIGH_IDLE


/*
 * options:
 * 1-SPI_LEADING_READ
 * 2-SPI_LEADING_WRITE
 */

#define SPI_CLK_PHASE   SPI_LEADING_READ


/*
 * options:
	1- SPI_1X_4F     0
	2- SPI_1X_16F    1
	3- SPI_1X_64F    2
	4- SPI_1X_128F   3
	5- SPI_2X_2F     0
	6- SPI_2X_8F     1
	7- SPI_2X_32F    2
	8- SPI_2x_64F    3
 */


#define SPI_CLK_RATE   SPI_1X_16F



/*
 * options:
 * 	1- SPI_2X_SPEED   1
 *	2- SPI_1X_SPEED   0
 */
#define SPI_SPEED_MODE  SPI_1X_SPEED

#endif /* SPI_CONFIG_H_ */
