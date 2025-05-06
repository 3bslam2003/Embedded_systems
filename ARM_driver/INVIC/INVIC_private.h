/*
 * INVIC_private.h
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */

#ifndef INVIC_PRIVATE_H_
#define INVIC_PRIVATE_H_


#define INVIC_SCB_BASE     0xE000ED00


#define INVIC_BASE_ADDRESS      0xE000E100



typedef struct
{
	volatile u32 ISER[32];
	volatile u32 ICER[32];
	volatile u32 ISPR[32];
	volatile u32 ICPR[32];
	volatile u32 IABR[32];
	volatile u32  RESERVED[32];
	volatile u8 IPR[128];

}INVIC_MEMORY_M;



typedef struct
{
	u32 CPUID;
	u32 ICSR;
	u32  VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32  SHCSR;
	u32 CFSR;
	u32  HFSR;
	u32 MMAR;
	u32 BFAR;
	u32  AFSR;

}SCB_MEMORY_M;

#define INVIC   ((INVIC_MEMORY_M*  )(INVIC_BASE_ADDRESS))
#define INVIC_STIR   ((u32 *)(INVIC_BASE_ADDRESS +0xE00))
#define SCB   ((SCB_MEMORY_M*)(INVIC_SCB_BASE))

#endif /* MCAL_INVIC_INVIC_PRIVATE_H_ */
