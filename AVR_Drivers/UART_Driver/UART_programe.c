#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


static u8 UART_STATE=IDLE;

static const u8* LOC_Asyn_send=0;
static  u32 LOC_Asyn_index=0;
static  void(*notification_func) ()=0;
u8 ISR_state=0;
static u32 BUFFER_SIZE=0;
static  u8* LOC_receive=0;
static  u32 LOC_Asyn_indexR=0;

void UART_init()
{		u8 LOC_UCSRC=0;

		u16 LOC_BUDRATE=0;
#if (UART_Mode==Asynchronous)&&(Trans_Speed ==Trans_1Speed)
	LOC_BUDRATE=(System_Frequancy/(16*Baud))-1;
	CLR_BIT(UCSRA,UCSRA_U2X);
	CLR_BIT(LOC_UCSRC,UCSRC_UMSEL);
#elif (UART_Mode==Asynchronous)&&(Trans_Speed ==Trans_2Speed)
	LOC_BUDRATE=(System_Frequancy/(8*Baud))-1;
	SET_BIT(UCSRA,UCSRA_U2X);
	CLR_BIT(LOC_UCSRC,UCSRC_UMSEL);
	
#elif (UART_Mode==Synchronous)
	LOC_BUDRATE=(System_Frequancy/(2*Baud))-1;
	
	SET_BIT(LOC_UCSRC,UCSRC_UMSEL);
#endif	
UBRRH=(u8)(LOC_BUDRATE>>8);
UBRRL=(u8)(LOC_BUDRATE);

#if MP_MODE==disable
	CLR_BIT(UCSRA,UCSRA_MPCM);
#elif 	MP_MODE==enable
	SET_BIT(UCSRA,UCSRA_MPCM);
#endif
#if Receive_Complete_INT_Mode==enable	
	SET_BIT(UCSRB,UCSRB_RXCIE);
#elif 	Receive_Complete_INT_Mode==disable	
	CLR_BIT(UCSRB,UCSRB_RXCIE);
#endif

#if Transmit_Complete_INT_Mode==enable
	SET_BIT(UCSRB,UCSRB_TXCIE);	
#elif 	Transmit_Complete_INT_Mode==disable
	CLR_BIT(UCSRB,UCSRB_TXCIE);
#endif

#if Data_Reg_Empty_INT_Mode==enable
	SET_BIT(UCSRB,UCSRB_UDRIE);
#elif	Data_Reg_Empty_INT_Mode==disable
	CLR_BIT(UCSRB,UCSRB_UDRIE);
#endif	


#if Receiver_Enable==enable
	SET_BIT(UCSRB,UCSRB_RXEN);
#elif Receiver_Enable==disable
	CLR_BIT(UCSRB,UCSRB_RXEN);	
#endif
#if Transmitter_Enable==enable
	SET_BIT(UCSRB,UCSRB_TXEN);
#elif Transmitter_Enable==disable
	CLR_BIT(UCSRB,UCSRB_TXEN);	
#endif

#if Parity_Mode==disable
	CLR_BIT(LOC_UCSRC,UCSRC_UPM0);
	CLR_BIT(LOC_UCSRC,UCSRC_UPM1);
#elif 	Parity_Mode==Parity_enable_even
		CLR_BIT(LOC_UCSRC,UCSRC_UPM0);
		SET_BIT(LOC_UCSRC,UCSRC_UPM1);
#elif 	Parity_Mode==Parity_enable_odd
		SET_BIT(LOC_UCSRC,UCSRC_UPM0);
		SET_BIT(LOC_UCSRC,UCSRC_UPM1);	
#endif		
#if Stop_Bite_Number==One_Stop_Bit
	CLR_BIT(LOC_UCSRC,UCSRC_USBS);
#elif Stop_Bite_Number==Two_Stop_Bit
	SET_BIT(LOC_UCSRC,UCSRC_USBS);
#endif
#if Data_Bite_Number==Data_5Bite
	CLR_BIT(LOC_UCSRC,UCSRC_UCSZ0);
	CLR_BIT(LOC_UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	
#elif Data_Bite_Number==Data_6Bite
	SET_BIT(LOC_UCSRC,UCSRC_UCSZ0);
	CLR_BIT(LOC_UCSRC,UCSRC_UCSZ1);	
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif 	Data_Bite_Number==Data_7Bite
	CLR_BIT(LOC_UCSRC,UCSRC_UCSZ0);
	SET_BIT(LOC_UCSRC,UCSRC_UCSZ1);	
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif 	Data_Bite_Number==Data_8Bite
	SET_BIT(LOC_UCSRC,UCSRC_UCSZ0);
	SET_BIT(LOC_UCSRC,UCSRC_UCSZ1);	
	CLR_BIT(UCSRB,UCSRB_UCSZ2);	
#elif 	Data_Bite_Number==Data_9Bite
	SET_BIT(LOC_UCSRC,UCSRC_UCSZ0);
	SET_BIT(LOC_UCSRC,UCSRC_UCSZ1);	
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#endif	
SET_BIT(LOC_UCSRC,UBRRH_URSEL);
UCSRC=LOC_UCSRC;
}

u8 UART_senddata(u8 copy_data )
{	u32 LOC_counter=0;
	u8 LOC_STATE=Ok;
	if(UART_STATE==IDLE)
	{  UART_STATE=Busy;
		u32 LOC_counter=0;
		while ((GET_BIT(UCSRA,UCSRA_UDRE))==0||LOC_counter<TIME_OUT)
		{
			LOC_counter++;
		}
		if(LOC_counter==TIME_OUT){
			LOC_STATE=Nok
		}
		else {
			UDR=copy_data;
		}
		UART_STATE=IDLE;
		
	}
	else
		{
			LOC_STATE=Nok;
		}
	return LOC_STATE;
	
}

u8 UART_receivedata(u8* copy_recevieddata)
{	
	u32 LOC_counter=0;
	u8 LOC_STATE=Ok;
	if(copy_recevieddata!=Null){
	if(UART_STATE==IDLE)
	{
		UART_STATE=Busy;
		while ((GET_BIT(UCSRA,UCSRA_RXC))==0||LOC_counter<TIME_OUT)
		{
			LOC_counter++;
		}
		if(LOC_counter==TIME_OUT)
		{
			LOC_STATE=Nok;
		}
		else 
		{
			*copy_recevieddata=UDR;
		}
	}
	else LOC_STATE=Nok;
}
else 
{
	LOC_STATE=Nok;
}
	return LOC_STATE;
}

u8 UART_senddata_syn(const u8* copy_string)
{
	u8 LOC_STATE=Ok;
	LOC_INDEX=0;
	if(copy_string!=Null)
	{
		
		
			
			while (copy_string[LOC_INDEX]!='\0')
			{
				LOC_STATE=UART_senddata(copy_string[LOC_INDEX]);
				LOC_INDEX++;
				if(LOC_STATE!=Ok)
				{
					return LOC_STATE;
				}
				
			}
			
    }
	else 
	{
		LOC_STATE=Nok;
	}
return LOC_STATE;	
}


void UART_senddata_asyn(const u8* copy_string,void (*copy_notification)())
{
	u8 LOC_STATE=Ok;
	if(copy_string!=Null||copy_notification!=Null)
	{ 
		if(UART_STATE==IDLE){
		UART_STATE=Busy;
		LOC_Asyn_send=copy_data;
		notification_func=copy_notification;
		ISR_state=1
		UDR=LOC_Asyn_send[LOC_Asyn_index];
		SET_BIT(UCSRB , UCSRB_TXCIE) ;
	}
	else LOC_STATE=nok;
	}
	else LOC_STATE=Nok;
	return LOC_STATE;
}



void UART_receivedata_syn(const u8* copy_string,u32 copy_size)
{	
	u8 LOC_STATE=Ok;
	u32 LOC_index=0;
	if(copy_size!=0)
	{
		
			
			while (LOC_index<copy_size)
			{
				LOC_STATE=UART_receivedata(copy_string[LOC_index]);
				if(LOC_STATE==Nok)
				{
					return LOC_STATE;
				}
				else 
				{
					LOC_index++;
				}
			}
		
	}
	else LOC_STATE=Nok;
	return LOC_STATE;
}
void UART_receivedata_asyn(const u8* copy_string,u32 copy_size,void (*copy_notification)())
{
	u8 LOC_STATE=Ok;
	ISR_state=1;
	if(copy_string!=0||copy_notification!=0)
	{
		if(UART_STATE==IDLE)
		{
			UART_STATE=Busy;
			LOC_receive=copy_string;
			BUFFER_SIZE=copy_size;
			notification_func=copy_notification;
			LOC_Asyn_indexR=0
			SET_BIT(UCSRB , UCSRB_RXCIE) ;
		}
		else LOC_STATE=Nok;
		
	}
	else LOC_STATE=Nok;
	return LOC_STATE;
}

void __vector_13 (void)		__attribute__ ((signal)) ;
void __vector_13 (void)
{
	if(ISR_state==1)
	{
		LOC_Asyn_data[LOC_Asyn_index]=UDR;
		LOC_Asyn_index++;

		if(LOC_Asyn_index==BUFFER_SIZE)
		{
			LOC_Asyn_index=0;
			notification_func();
			UART_STATE=IDLE;
			CLR_BIT(UCSRB , UCSRB_RXCIE) ;
			
		}
		else 
		{
			
		}
	}
}

void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void)
{
	if(ISR_state==1){
	LOC_Asyn_index++;
	if(LOC_Asyn_data[LOC_Asyn_index]!='\0')
	{   
		UDR=LOC_Asyn_data[LOC_Asyn_index]
		
	}
	else {
	LOC_Asyn_index=0;
	notification_func();
	UART_STATE=IDLE;
	CLR_BIT(UCSRB , UCSRB_TXCIE) ;
	}
	}
	else
	{
		
	}
}