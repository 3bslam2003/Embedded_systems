#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

u8 ADC_status =IDLE;
u8* ADC_ASYNC_result=Null;
void (* ADC_ASYNC_notification)(void) =Null;
u8* ADC_chain_channel=Null;
u16 * ADC_chain_result=Null;
u8 ADC_chain_index=Null;
u8 ADC_chain_size=Null;


u8 ADC_INS_state=ASYNC_notification;


void ADC_init(void)
{
#if ADC_STATE ==ADC_ENABLE
		SET_BIT(ADCSRA_REG,ADCSRA_ADEN);
	#elif 	ADC_STATE ==ADC_DISABLE
			 CLR_BIT(ADCSRA_REG,ADCSRA_ADEN);
	#endif

	#if ADC_REFF==ADC_AREF
		CLR_BIT(ADMUX_REG,ADMUX_REF1);
		CLR_BIT(ADMUX_REG,ADMUX_REF0);
	#elif  ADC_REFF==ADC_AVCC
			CLR_BIT(ADMUX_REG,ADMUX_REF1);
			SET_BIT(ADMUX_REG,ADMUX_REF0);
	#elif  ADC_REFF==ADC_2_56INTERNAL
			SET_BIT(ADMUX_REG,ADMUX_REF1);
			SET_BIT(ADMUX_REG,ADMUX_REF0);
	#endif

	#if ADC_DATA_WRITE ==ADC_LEFT_ADJUST
			SET_BIT(ADMUX_REG,ADMUX_ADLAR);
	
	#elif ADC_DATA_WRITE ==ADC_RIGHT_ADJUST
			CLR_BIT(ADMUX_REG,ADMUX_ADLAR);
			
	#endif

	ADCSRA_REG&=PRE_MASK;	
	ADCSRA_REG|=ADC_PRE ;

	

    #if ADC_INTERRUPT==ADC_Interrupt_Enable
		SET_BIT(ADCSRA_REG,ADCSRA_ADIE);
	#elif 	ADC_INTERRUPT==ADC_Interrupt_Disable
			 CLR_BIT(ADCSRA_REG,ADCSRA_ADIE);
	#endif
	
	
}

u8 ADC_startconversion_sync(u8 copy_channel,u16* copy_result)
{
	u8 LOC_errorstate=Ok;
	u32 timeout_counter=0;
	if (copy_result !=Null)
	{
		if(ADC_status==IDLE)
		{
			ADC_status=Busy;
			
			ADMUX_REG&=MUX_MASK;
			ADMUX_REG|=copy_channel;
			
			SET_BIT(ADCSRA_REG,ADCSRA_ADSC);
			
			while(((GET_BIT(ADCSRA_REG,ADCSRA_ADIF))==0) && (timeout_counter<5000)){
				timeout_counter++;
			}
			if(timeout_counter==5000)
			{
				LOC_errorstate=TIME_OUT_STATE;
			}
			else {
				SET_BIT(ADCSRA_REG,ADCSRA_ADIF);
				#if ADC_DATA_WRITE==ADC_LEFT_ADJUST
				*copy_result=ADCH;
				#elif ADC_DATA_WRITE==ADC_RIGHT_ADJUST
				*copy_result=(ADCL|(ADCH<<8));
				#elif  
				#error "Wrong ADC_DATA_WRITE in config file"
				#endif
				
				
			}
			ADC_status=IDLE;
		}
		else
		{
			LOC_errorstate=Busy;
		}
		
	}
	else{
		LOC_errorstate=Nok;
	}
	return LOC_errorstate;
}

u8 ADC_startconversion_Async(u8 copy_channel,u8* result , void (*copy_notification)(void))
{
	u8 LOC_errorstate=Ok;
	if(copy_notification!=Null && result !=Null)
	{
		if(ADC_status==IDLE)
		{	ADC_ASYNC_result=result;
			ADC_ASYNC_notification=copy_notification;
			ADC_INS_state=ASYNC_notification;
			
			ADMUX_REG&=MUX_MASK;
			ADMUX_REG|=copy_channel;
			SET_BIT(ADCSRA_REG,ADCSRA_ADSC);
			
		}
		else{
			LOC_errorstate=Busy;
		}
	}
	else 
	{
	//	#error "No Notification Function"
	}
	return LOC_errorstate;
}


u8 ADC_chainAsync(chain_t copy_chain)
{
	u8 LOC_errorstate=Ok;
	if(copy_chain.channel!=Null && copy_chain.result != Null && copy_chain.size !=Null && copy_chain. notification_fun !=Null)
	{
		if(ADC_status==Busy)
		{
			ADC_chain_channel=copy_chain.channel;
			ADC_chain_result=copy_chain.result;
			ADC_chain_size=copy_chain.size;
			ADC_ASYNC_notification=copy_chain.notification_fun;
			
			ADC_INS_state=chain_notification;
			
			ADMUX_REG&=MUX_MASK;
			ADMUX_REG|=ADC_chain_channel[ADC_chain_index];
			
			SET_BIT(ADCSRA_REG,ADCSRA_ADSC);
		}
		else{
			LOC_errorstate=Busy;
		}
	}
	else 
	{
		LOC_errorstate=Null_pointer;
	}
	return LOC_errorstate;
}





//------------------------------------------------------------------------------------------------------------------------



void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{	
	
	if(ADC_INS_state==ASYNC_notification){
		#if 	ADC_DATA_WRITE==ADC_RIGHT_ADJUST
				*ADC_ASYNC_result=(ADCL|(ADCH<<8));
		#elif 	ADC_DATA_WRITE==ADC_LEFT_ADJUST
				*ADC_ASYNC_result=ADCH;
#endif
		ADC_status=IDLE;
		ADC_ASYNC_notification();
		
		CLR_BIT(ADCSRA_REG,ADCSRA_ADIE);
		
		
		
	}
	else 
	{
		#if ADC_DATA_WRITE==ADC_RIGHT_ADJUST
		*ADC_chain_result=((ADCL|(ADCH << 8)));
		#elif ADC_DATA_WRITE==ADC_LEFT_ADJUST
		*ADC_chain_result=ADCH;
       #endif
		ADC_chain_index++;
		
		if(ADC_chain_index==ADC_chain_size){
			ADC_status=IDLE;
			ADC_ASYNC_notification();
			
			
		}
		else
		{
			ADC_ASYNC_notification();
			ADMUX_REG&=MUX_MASK;
			ADMUX_REG|=ADC_chain_channel[ADC_chain_index];
			SET_BIT(ADCSRA_REG,ADCSRA_ADSC);
		}
	}
	
}
