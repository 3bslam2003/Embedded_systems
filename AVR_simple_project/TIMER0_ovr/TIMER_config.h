#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_



// TIMER0_config



#define TIMER0_GENERTION_MODE  TIMER_NORMAL_MODE






#define TIMER0_PRESCALER        TIMER_8_PRESCALING

#if TIMER0_GENERTION_MODE==TIMER_NORMAL_MODE

		#define TIMER0_PRELOAD_VAL    192
		
		
		
		
		#define TIMER0_OVERFLOW_INTERRUPT   ENABLE
		
		
#elif TIMER0_GENERTION_MODE==TIMER_CTC_MODE
			#define TIMER0_OCR_VAL  125
			
			
			
			#define TIMER0_OC   CTC_OC_TOGGEL
			
			
			#define TIMER0_CTC_INTERRUPT   ENABLE
			
#endif 			
	



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//TIMER2_config


#define TIMER2_GENERTION_MODE  TIMER_CTC_MODE






#define TIMER2_PRESCALER         TIMER_64_PRESCALING

#if TIMER2_GENERTION_MODE==TIMER_NORMAL_MODE

		#define TIMER2_PRELOAD_VAL    192
		
		
		
		
		#define TIMER2_OVERFLOW_INTERRUPT   ENABLE
		
		
#elif TIMER2_GENERTION_MODE==TIMER_CTC_MODE
			#define TIMER2_OCR_VAL  125
			
			
			
			#define TIMER2_OC   CTC_OC_TOGGEL
			
			
			#define TIMER2_CTC_INTERRUPT   ENABLE
			
#endif 			
	


#endif
