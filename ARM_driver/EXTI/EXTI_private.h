/*
 * EXTI_private.h
 *
 *  Created on: Nov 29, 2024
 *      Author: HP
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


#define EXTI_BASSE_ADDRESS    0x40013C00


typedef struct
{

	u32 IMR;
	u32  EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_Memory_Mape;



#define EXTI     ((EXTI_Memory_Mape*)(EXTI_BASSE_ADDRESS))





#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
