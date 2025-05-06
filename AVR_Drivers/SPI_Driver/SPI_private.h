/*
 * SPI_private.h
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR  *((u8*)(0x2F))



#define SPSR  *((u8*)(0x2E))

#define SPSR_SPIF   7
#define SPSR_WCOL   6
#define SPSR_SPI2X   0



#define SPCR  *((u8*)(0x2D))


#define SPCR_SPIE   7
#define SPCR_SPE    6
#define SPCR_DORD   5
#define SPCR_MSTR   4
#define SPCR_CPOL   3
#define SPCR_CPHA   2
#define SPCR_SPR1   1
#define SPCR_SPR0   0




#endif /* SPI_PRIVATE_H_ */
