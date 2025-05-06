/*
 * SPI_programe.c
 *
 *  Created on: Nov 26, 2024
 *      Author: HP
 */


#include "STD_types.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

static u8 SPI_GSTATE=IDLE;
static u8 G_index=0;
static u8 G_size_buffer;
static u8* copy_send_buffer;
static u8* copy_receive_buffer;
static void (*notification)(void);
void SPI_init()
{

#if  	SPI_MODE==SPI_MASTER
		SET_BIT(SPCR,SPCR_MSTR);
#elif   SPI_MODE==SPI_SLAVE
		CLR_BIT(SPCR,SPCR_MSTR);
#endif

#if 	SPI_INTERRUPT_STATE == enable
		SET_BIT(SPCR,SPCR_SPIE);
#elif	SPI_INTERRUPT_STATE == disable
		CLR_BIT(SPCR,SPCR_SPIE);
#endif

#if  	SPI_DATA_ORDER  == SPI_LSB_FIRST
		SET_BIT(SPCR,SPCR_DORD);
#elif   SPI_DATA_ORDER  == SPI_MSB_FIRST
		CLR_BIT(SPCR,SPCR_DORD);
#endif

#if		SPI_CLK_POLARITY  == SPI_HIGH_IDLE
		SET_BIT(SPCR,SPCR_CPOL);
#elif   SPI_CLK_POLARITY  == SPI_LOW_IDLE
		SET_BIT(SPCR,SPCR_CPOL);
#endif

#if 	SPI_CLK_PHASE ==  SPI_LEADING_READ
		CLR_BIT(SPCR,SPCR_CPHA);
#elif   SPI_CLK_PHASE ==  SPI_LEADING_WRITE
		SET_BIT(SPCR,SPCR_CPHA);
#endif

#if   	SPI_SPEED_MODE==SPI_1X_SPEED
		CLR_BIT(SPSR,SPSR_SPI2X);
	#if 	SPI_CLK_RATE==SPI_1X_16F
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
 	#elif	SPI_CLK_RATE==SPI_1X_64F
			SET_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
	#elif	SPI_CLK_RATE==SPI_1X_128F
			SET_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
	#elif	SPI_CLK_RATE==SPI_1X_4F
			CLR_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
	#endif
#elif	SPI_SPEED_MODE==SPI_2X_SPEED
			SET_BIT(SPSR,SPSR_SPI2X);
		#if 	SPI_CLK_RATE==SPI_2X_8F
				CLR_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPCR,SPCR_SPR0);
	 	#elif	SPI_CLK_RATE==SPI_2X_32F
				SET_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPCR,SPCR_SPR0);
		#elif	SPI_CLK_RATE==SPI_2x_64F
				SET_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPCR,SPCR_SPR0);
		#elif	SPI_CLK_RATE==SPI_2X_2F
				CLR_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPCR,SPCR_SPR0);
		#endif
#endif
#if 	SPI_STATE==enable
		SET_BIT(SPCR,SPCR_SPE);
#elif 	SPI_STATE==disable
		CLR_BIT(SPCR,SPCR_SPE);
#endif
}

u8 SPI_tranceive(u8 copy_data_send,u8* copy_data_receive)
{
	u8 LOC_state=Ok;
	u32 LOC_counter=0;
	if(SPI_GSTATE==IDLE){
		SPI_GSTATE=Busy;
		SPDR=copy_data_send;
		while ((GET_BIT(SPSR,SPSR_SPIF)==0)&&(LOC_counter<TIME_OUT)){
			LOC_counter++;
		}
		if(LOC_counter==TIME_OUT){
			LOC_state=Nok;
		}
		else
		{
			*copy_data_receive=SPDR;
		}

	}
	else {
		LOC_state=Busy;
	}
	return LOC_state;
}
/*
u8 SPI_initconfig(SPI_config* copy_config)
{

}
*/

u8 SPI_buffertranceive_sync(u8* copy_data_send,u8* copy_data_receive)
{
	u8 LOC_state=Ok;

	u8 LOC_index=0;
	if(copy_data_send !=Null && copy_data_receive !=Null)
		{

			while(copy_data_send[LOC_index]!='\0')
			{
				LOC_state=SPI_tranceive(copy_data_send[LOC_index],&copy_data_receive[LOC_index]);
				if(LOC_state!=Ok)
				{
					return LOC_state;
				}
				LOC_index++;
			}
		}
	else
	{
		LOC_state=Null_pointer;
	}
	return LOC_state;
}


u8 SPI__buffertranceive_async(SPI_buffer* copy_buffer)
{
	u8 LOC_state=Ok;
	if(copy_buffer->copy_data_receive!=Null  &&  copy_buffer->copy_data_send!=Null  && copy_buffer->notification_func!=Null  && copy_buffer->copy_buffer_size!=Null)
	{
		if(SPI_GSTATE==IDLE){
		SPI_GSTATE=Busy;
		 G_size_buffer=copy_buffer->copy_buffer_size;
		 copy_send_buffer=copy_buffer->copy_data_send;
		copy_receive_buffer=copy_buffer->copy_data_receive;
		notification=copy_buffer->notification_func;
		G_index=0;
		 SPDR=copy_send_buffer[G_index];
		 SET_BIT(SPCR,SPCR_SPIE);
		}
		else
		{
			LOC_state=Busy;
		}
	}
	else
	{
		LOC_state=Null_pointer;
	}
	return LOC_state;
}







void __vector_12 (void)		__attribute__ ((signal)) ;
void __vector_12 (void)
{
	copy_receive_buffer[G_index]=SPDR;
	G_index++;
	if(G_index==G_size_buffer)
	{
		G_index=0;
		SPI_GSTATE=IDLE;
		CLR_BIT(SPCR,SPCR_SPIE);
		notification();
	}
	else
	{
		SPDR=copy_send_buffer[G_index];
	}
}








