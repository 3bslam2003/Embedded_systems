#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_




#define TIMSK     *((volatile u8*)0x59)

// TIMSK_PINS
#define TIMSK_OCIE2     7
#define TIMSK_TOIE2     6
#define TIMSK_TICIE1    5
#define TIMSK_OCIE1A    4
#define TIMSK_OCIE1B    3
#define TIMSK_TOIE1     2
#define TIMSK_OCIE0     1
#define TIMSK_TOIE0     0




#define TIFR	  *((volatile u8*)0x58)	 


#define TIFR_OCF2    7
#define TIFR_TOV2    6
#define TIFR_ICF1    5
#define TIFR_OCF1A   4
#define TIFR_OCF1B   3
#define TIFR_TOV1    2
#define TIFR_OCF0    1
#define TIFR_TOV0    0

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define TCNT0     *((volatile u8*)0x52)


#define TCCR0     *((volatile u8*)0x53)

#define TCCR0_FOC0      7
#define TCCR0_WGM00     6
#define TCCR0_COM01     5
#define TCCR0_COM00     4
#define TCCR0_WGM01     3
#define TCCR0_CS02      2
#define TCCR0_CS01      1
#define TCCR0_CS00      0


#define OCR0      *((volatile u8*)0x5C)







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#define TCCR2     *((volatile u8*)0x45)

#define TCCR2_FOC2      7
#define TCCR2_WGM20     6
#define TCCR2_COM21     5
#define TCCR2_COM20     4
#define TCCR2_WGM21     3
#define TCCR2_CS22      2
#define TCCR2_CS21      1
#define TCCR2_CS20      0



#define TCNT2    *((volatile u8*)0x44)

#define OCR2     *((volatile u8*)0x43)


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PRE_SCALER_MASK   0b11111000



#endif
