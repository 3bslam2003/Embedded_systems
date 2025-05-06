#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define PRE_MASK    0b11111000
#define MUX_MASK    0b11100000

#define ADMUX_REG  *((volatile u8 *)0x27)

#define ADMUX_ADLAR  5       // LEDFT_ADJUST_bite
#define ADMUX_REF1   7		
#define ADMUX_REF0   6

#define ADMUX_0		 0
#define ADMUX_1		 1
#define ADMUX_2		 2
#define ADMUX_3		 3
#define ADMUX_4		 4
	   



#define ADCSRA_REG *((volatile u8 *)0x26)

#define ADCSRA_ADEN   7	  // adc enable
#define ADCSRA_ADSC   6   // start conversion
#define ADCSRA_ADATE  5   // outo trigger
#define ADCSRA_ADIF   4	  // interruptflag
#define ADCSRA_ADIE	  3	  // interruptenable
#define ADCSRA_ADPS2  2
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS0  0


#define ADCH   *((volatile u8 *)0x25)
#define ADCL   *((volatile u8 *)0x24)
#define ADC_DATA *((volatile u16 *)0x24)
#define SFIOR_REG  *((volatile u8 *)0x50)


#define SFIOR_ADTS2 7       // adc auto trigger source bits
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5

#define ASYNC_notification 0
#define chain_notification 1

#endif

