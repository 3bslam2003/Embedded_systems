#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (* EXTI_CALLBACK[3]) (void)={null};


void EXTI_init              ( void                                                  )
{
	#ifdef EXTI_LINE
			#if EXTI_LINE==EXTI_LINE0
			
				#if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
				SET_BIT(MCUCR_REG,3);
				CLR_BIT(MCUCR_REG,2);
				
				#elif EXTI_SENSE_MODE==EXTI_RISING_EDGE
				SET_BIT(MCUCR,3);
				SET_BIT(MCUCR,2);
				#elif EXTI_SENSE_MODE==EXTI_LOW_LEVEL
				CLC_BIT(MCUCR,2);
				CLC_BIT(MCUCR,3);
				#elif EXTI_SENSE_MODE==EXTI_ON_CHANGE
				SET_BIT(MCUCR,2);
				CLC_BIT(MCUCR,3);
			#endif
			
			#elif EXTI_LINE==EXTI_LINE1
			
				#if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
				SET_BIT(MCUCR,3);
				CLC_BIT(MCUCR,2);
				
				#elif EXTI_SENSE_MODE==EXTI_RISING_EDGE
				SET_BIT(MCUCR,3);
				SET_BIT(MCUCR,2);
				#elif EXTI_SENSE_MODE==EXTI_LOW_LEVEL
				CLC_BIT(MCUCR,2);
				CLC_BIT(MCUCR,3);
				#elif EXTI_SENSE_MODE==EXTI_ON_CHANGE
				SET_BIT(MCUCR,2);
				CLC_BIT(MCUCR,3);
			#endif
				
			#elif EXTI_LINE==EXTI_LINE2
			
				#if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
				CLC_BIT(MCUCSR,6);
				
				
				#elif EXTI_SENSE_MODE==EXTI_RISING_EDGE
				SET_BIT(MCUCSR,6);
				
			#endif
			#else
				#error "Wrong INT0_SENSE configuration option"
			#endif
			#endif
}


void EXTI_setsignallatch   ( u8 Copy_SenseMode , u8 Copy_Line                  )
{
	if(Copy_Line >= EXTI_LINE0 && Copy_Line <= EXTI_LINE1){
		Copy_Line=(6-Copy_Line)*-2;
		switch(Copy_SenseMode)
		{
			case EXTI_FALLING_EDGE:SET_BIT(MCUCR_REG,(Copy_Line+1));CLR_BIT(MCUCR_REG,Copy_Line);break;
			case EXTI_RISING_EDGE:SET_BIT(MCUCR_REG,Copy_Line);SET_BIT(MCUCR_REG,(Copy_Line+1));break;
			case EXTI_LOW_LEVEL:CLR_BIT(MCUCR_REG,Copy_Line);CLR_BIT(MCUCR_REG,(Copy_Line+1));break;
			case EXTI_ON_CHANGE:SET_BIT(MCUCR_REG,Copy_Line);CLR_BIT(MCUCR_REG,(Copy_Line+1));break;
		}
	}
	
	else if(Copy_Line==EXTI_LINE2){
		
		switch(Copy_SenseMode){
			
			case EXTI_FALLING_EDGE:CLR_BIT(MCUCSR_REG,6);break;
			case EXTI_RISING_EDGE:SET_BIT(MCUCSR_REG,6);break;
		}
		
	}
}

u8   EXTI_disableinterrupt  ( u8 Copy_Line                                        )
{
	u8 LOCAL_errorstate=1;
	if(Copy_Line>=EXTI_LINE2 &&  Copy_Line<=EXTI_LINE1)
	{
		CLR_BIT(GICR_REG ,Copy_Line);
		
	}
	else{
		LOCAL_errorstate=0;
	}
	
	return LOCAL_errorstate;
	
	
}
u8   EXTI_enableinterrupt   ( u8 Copy_Line                                        )
{
	u8 LOCAL_errorstate=1;
	if((Copy_Line>=EXTI_LINE2 )  &&    (Copy_Line<=EXTI_LINE1 ))
	{
		SET_BIT(GICR_REG,Copy_Line);
	}
	else 
	{
		LOCAL_errorstate=0;
	}
	return LOCAL_errorstate;
}

void EXTI_clearflag        ( u8 Copy_Line                                        )
{
	SET_BIT(GIFR_REG,Copy_Line);
}

void EXTI_setcallback       ( void (*Copy_CALLBACK)(void) , u8 Copy_EXTILine )
{
	if(Copy_CALLBACK!=null){
		
		EXTI_CALLBACK[Copy_EXTILine-5]=Copy_CALLBACK;
	}
}





void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	
	
	if(EXTI_CALLBACK[1] !=null){
		EXTI_CALLBACK[1]();
		EXTI_clearflag(EXTI_LINE0);
		
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	
	if(EXTI_CALLBACK[2]!=null){
		EXTI_CALLBACK[2]();
		EXTI_clearflag(EXTI_LINE1);
		
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	
	if(EXTI_CALLBACK[0]!=null){
		EXTI_CALLBACK[0]();
		EXTI_clearflag(EXTI_LINE2);
		
	}
}
