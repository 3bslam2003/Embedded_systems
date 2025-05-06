#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_



// TIMER0_config



#define TIMER0_GENERTION_MODE  TIMER_FASTPWM_MODE






#define TIMER0_PRESCALER         TIMER_1024_PRESCALING

#if TIMER0_GENERTION_MODE==TIMER_NORMAL_MODE

		#define TIMER0_PRELOAD_VAL    192
		
		
		
		
		#define TIMER0_OVERFLOW_INTERRUPT   ENABLE
		
		
#elif TIMER0_GENERTION_MODE==TIMER_CTC_MODE
			#define TIMER0_OCR_VAL  125
			
			
			
			#define TIMER0_OC   CTC_OC_TOGGEL
			
			
			#define TIMER0_CTC_INTERRUPT   ENABLE

#elif   TIMER0_GENERTION_MODE==TIMER_PWM_MODE
			#define TIMER0_OCR_VAL  38
			
			#define TIMER0_OC PWM_OC_CLR_UPCOUNTING



#elif  		TIMER0_GENERTION_MODE==TIMER_FASTPWM_MODE
			#define TIMER0_OCR_VAL  38
			
			#define TIMER0_OC FASTPWM_OC_CLR_COMP

			
#endif 			
	








////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//TIMER2_config


#define TIMER2_GENERTION_MODE  TIMER_PWM_MODE






#define TIMER2_PRESCALER         TIMER_1024_PRESCALING

#if TIMER2_GENERTION_MODE==TIMER_NORMAL_MODE

		#define TIMER2_PRELOAD_VAL    192
		
		
		
		
		#define TIMER2_OVERFLOW_INTERRUPT   ENABLE
		
		
#elif TIMER2_GENERTION_MODE==TIMER_CTC_MODE
			#define TIMER2_OCR_VAL  125
			
			
			
			#define TIMER2_OC   CTC_OC_TOGGEL
			
			
			#define TIMER2_CTC_INTERRUPT   ENABLE

#elif   TIMER2_GENERTION_MODE==TIMER_PWM_MODE
			#define TIMER2_OCR_VAL  38
			
			#define TIMER2_OC PWM_OC_CLR_UPCOUNTING
#elif  		TIMER2_GENERTION_MODE==TIMER_FASTPWM_MODE
			#define TIMER2_OCR_VAL  38
			
			#define TIMER2_OC FASTPWM_OC_CLR_COMP

			
#endif 			




#define TIMER1_GENERTION_MODE	TIMER_NORMAL_MODE



#define TIMER1_PRESCALER         TIMER_1024_PRESCALING

#if TIMER1_GENERTION_MODE==TIMER_NORMAL_MODE
#define TIMER1_PRELOAD_VAL    0
		
		
		
		
#define TIMER1_OVERFLOW_INTERRUPT   DISABLE
		
		

#endif


#define TIMER1_ICU_Noise_Canceler   ENABLE
#define TIMER1_ICU_EDGE_SELECT      RAISING_EDGE
#define TIMER1_ICU_IN_STATE         ENABLE

#endif

