#ifndef   TIMER_INTERFACE_H_
#define   TIMER_INTERFACE_H_



#define TIMER_NORMAL_MODE  0
#define TIMER_PWM_MODE	   1
#define TIMER_CTC_MODE     2
#define TIMER_FASTPWM_MODE 3
#define CTC_OC_DISCONNECT 	0
#define CTC_OC_TOGGEL 		1
#define CTC_OC_CLEAR 		2
#define CTC_OC_set 	    	3

#define FASTPWM_OC_DISCONNECT 0

#define FASTPWM_OC_CLR_COMP   2	

#define FASTPWM_OC_SET_COMP   3



#define PWM_OC_DISCONNECT     0 

#define PWM_OC_CLR_UPCOUNTING 2

#define PWM_OC_SET_UPCOUNTING 3





#define TIMER_NO_CLOCK_SOURCE 0
#define TIMER_NO_PRESCALING   1
#define TIMER_8_PRESCALING    2 
#define TIMER_64_PRESCALING   4

#define TIMER_256_PRESCALING  6
#define TIMER_1024_PRESCALING 5
#define TIMER_EXT_SOURCE_FALLING 6
#define TIMER_EXT_SOURCE_RISING 7
#define ENABLE    1
#define DISABLE   0


#define RAISING_EDGE   1
#define FALLING_EDGE   0

#define TIMER0_OVF_VICTOR_ID  11

#define TIMER0_COMP_VICTOR_ID  10

#define TIMER2_OVF_VICTOR_ID   5 

#define TIMER2_COMP_VICTOR_ID  4
#define TIMER1_ICU_VICTOR_ID   6


void TIMER0_init();
void TIMER1_init();
void TIMER2_init();
u8 SET_CALLBACK(void (*copy_func)(void),u8 copy_vector_id);   


#endif
