#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"



void GIE_enable(void){
	SET_BIT(SREG_REG,SREG_BIT);
	
	
}


void GIE_disable(void)
{
	CLR_BIT(SREG_REG,SREG_BIT);
}


