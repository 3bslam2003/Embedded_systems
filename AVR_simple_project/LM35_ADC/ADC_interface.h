#ifndef  ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



#define ADC_AREF 0
#define ADC_AVCC 1
#define ADC_2_56INTERNAL  3

#define ADC_RIGHT_ADJUST  0
#define ADC_LEFT_ADJUST  1



#define ADC_CHANNEL0 0
#define ADC_CHANNEL1 1
#define ADC_CHANNEL2 2
#define ADC_CHANNEL3 3
#define ADC_CHANNEL4 4
#define ADC_CHANNEL5 5
#define ADC_CHANNEL6 6
#define ADC_CHANNEL7 7

#define ADC_ENABLE  1
#define ADC_DISABLE 0


#define ADC_START_CONVERSION 1

#define ADC_Auto_Trigger_Enable 1
#define ADC_Auto_Trigger_Disable 0

#define ADC_Interrupt_Enable 1
#define ADC_Interrupt_Disable 0 
	

#define ADC_PrescalerSelections2 0
#define ADC_PrescalerSelections4 2
#define ADC_PrescalerSelections8 3
#define ADC_PrescalerSelections16 4

#define ADC_PrescalerSelections32 5
#define ADC_PrescalerSelections64 6
#define ADC_PrescalerSelections128 7


#define ADC_FRM 0
#define ADC_AC 1
#define ADC_EIR 2


typedef struct{
	
	u8* channel;
	u16* result;
	u8 size;
	void ( *notification_fun)(void);
	
}chain_t;

void ADC_init(void);
/*void ADC_enable();
void ADC_disable();
void ADC_enableint();
void ADC_disableint();
*/
u8 ADC_startconversion_sync(u8 copy_channel,u16* copy_result);
u8 ADC_startconversion_Async(u8 copy_channel ,u8* result , void (*copy_notification)(void));

u8 ADC_chainAsync(chain_t copy_chain);

#endif


