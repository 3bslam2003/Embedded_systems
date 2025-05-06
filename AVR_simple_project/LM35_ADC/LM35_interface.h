#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_


typedef struct
{
	u8 refrance;
	u8 channel;
	u8 resolution;
}LM35_t;





#define LM35_10resolution  1;
#define LM35_8resoultion   0 ;



u16 LM35_gettemp(LM35_t* copy_sensor,u8 * copy_result);
#endif
