#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include "LM35_interface.h"
#include "ADC_interface.h"




u16 LM35_gettemp(LM35_t* copy_sensor,u8 * copy_result)
{
	u8 LOCAL_errorstate=Ok;
	u16 LOCAL_analogresult;
	u16 LOCAL_adcresult;

	ADC_startconversion_sync(copy_sensor->channel,&LOCAL_adcresult);
	if((copy_sensor->resolution)==1)
	{
		LOCAL_analogresult = (u16) ( ((u32)LOCAL_adcresult * 5000ul  ) / 1024UL) ;
		
	}
	/*else if(copy_sensor->resolution==0)
	{
		LOCAL_analogresult= (u16) ( ((u32)LOCAL_adcresult* (u32)LOCAL_ref ) / 256UL) ;
		
	}*/
	*copy_result=LOCAL_analogresult/10;
	

	return LOCAL_errorstate;
	
	
}
