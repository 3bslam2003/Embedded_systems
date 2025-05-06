#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "DIO_interface.h"


void (*func[16])(void)={Null};


void TIMER0_init()
{
	#if  TIMER0_GENERTION_MODE == TIMER_NORMAL_MODE
			CLR_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			
			#if TIMER0_OVERFLOW_INTERRUPT==DISABLE
					CLR_BIT(TMISK,TIMSK_TOIE0);
			#elif 	TIMER0_OVERFLOW_INTERRUPT==ENABLE
						SET_BIT(TIMSK,TIMSK_TOIE0);
			#endif			
			TCNT0=TIMER0_PRELOAD_VAL;			
	#elif    TIMER0_GENERTION_MODE == TIMER_CTC_MODE 
	
			CLR_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			DIO_setpindirection(DIO_portB,PIN4,DIO_pin_output);
			
			
			#if TIMER0_CTC_INTERRUPT ==  ENABLE
				SET_BIT(TIMSK,TIMSK_OCIE0);
				
			#elif TIMER0_CTC_INTERRUPT  == DISABLE
			
				CLR_BIT(TIMSK,TIMSK_OCIE0);
				
			#endif
			
			#if TIMER0_OC == CTC_OC_TOGGEL
				CLR_BIT(TCCR0,TCCR0_COM01);
				SET_BIT(TCCR0,TCCR0_COM00);
			#elif 	TIMER0_OC == CTC_OC_DISCONNECT
				CLR_BIT(TCCR0,TCCR0_COM01);
				CLR_BIT(TCCR0,TCCR0_COM00);
			#elif TIMER0_OC == CTC_OC_CLEAR
				SET_BIT(TCCR0,TCCR0_COM01);
				CLR_BIT(TCCR0,TCCR0_COM00);
				
			#elif 	TIMER0_OC == CTC_OC_SET
				SET_BIT(TCCR0,TCCR0_COM01);
				SET_BIT(TCCR0,TCCR0_COM00);
				
			#endif	
			OCT0=TIMER0_OCR_VAL;
			
				
			
	#endif
	
	TCCR0&=PRE_SCALER_MASK ;
	TCCR0|=TIMER0_PRESCALER;
}





void TIMER2_init()
{
	#if  TIMER2_GENERTION_MODE == TIMER_NORMAL_MODE
			CLR_BIT(TCCR2,TCCR2_WGM20);
			CLR_BIT(TCCR2,TCCR2_WGM21);
			
			#if TIMER2_OVERFLOW_INTERRUPT==DISABLE
					CLR_BIT(TMISK,TIMSK_TOIE2);
			#elif 	TIMER2_OVERFLOW_INTERRUPT==ENABLE
						SET_BIT(TMISK,TIMSK_TOIE2);
			#endif			
			TCNT0=TIMER2_PRELOAD_VAL;			
	#elif    TIMER2_GENERTION_MODE == TIMER_CTC_MODE 
	
			CLR_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21);
			DIO_setpindirection(DIO_portD,PIN7,DIO_pin_output);
			
			
			#if TIMER2_CTC_INTERRUPT ==  ENABLE
				SET_BIT(TIMSK,TIMSK_OCIE2);
				
			#elif TIMER2_CTC_INTERRUPT  == DISABLE
			
				CLR_BIT(TIMSK,TIMSK_OCIE2);
				
			#endif
			
			#if TIMER2_OC == CTC_OC_TOGGEL
				CLR_BIT(TCCR2,TCCR2_COM21);
				SET_BIT(TCCR2,TCCR2_COM20);
			#elif 	TIMER2_OC == CTC_OC_DISCONNECT
				CLR_BIT(TCCR2,TCCR2_COM21);
				CLR_BIT(TCCR2,TCCR2_COM20);
			#elif TIMER2_OC == CTC_OC_CLEAR
				SET_BIT(TCCR2,TCCR2_COM21);
				CLR_BIT(TCCR2,TCCR2_COM20);
				
			#elif 	TIMER2_OC == CTC_OC_SET
				SET_BIT(TCCR2,TCCR2_COM21);
				SET_BIT(TCCR2,TCCR2_COM20);
				
			#endif	
			OCR2=TIMER2_OCR_VAL;
			
				
			
	#endif
	
	TCCR2&=PRE_SCALER_MASK ;
	TCCR2|=TIMER2_PRESCALER;
}







u8  SET_CALLBACK(void (*copy_func)(void),u8 copy_vector_id)
{
	u8 LOCAL_errorstate=Ok;
	
	if(copy_func!=Null)
	{
		if(copy_vector_id!=0)
		{
			func[copy_vector_id]=copy_func;
		}
		else{
			LOCAL_errorstate=Nok;
		}
	}
	else{
		LOCAL_errorstate=Nok;
	}
	return LOCAL_errorstate;
}




void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void){
	
	if(func[TIMER0_OVF_VICTOR_ID]!=Null)
	{
		func[TIMER0_OVF_VICTOR_ID]();
	}
	
}


void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void){
	
	if(func[TIMER0_COMP_VICTOR_ID]!=Null)
	{
		func[TIMER0_COMP_VICTOR_ID]();
	}
	
}


void __vector_4 (void)		__attribute__((signal)) ;
void __vector_4 (void){
	
	if(func[TIMER2_COMP_VICTOR_ID]!=Null)
	{
		
		func[TIMER2_COMP_VICTOR_ID]();
		
	}
	
}




void __vector_5 (void)		__attribute__((signal)) ;
void __vector_5 (void){
	
	
	if(func[TIMER2_OVF_VICTOR_ID]!=Null)
	{
		
		func[TIMER2_OVF_VICTOR_ID]();
		
	}
	
}


