/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DIO_privit.H>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
 NAME  : Ahmed Mohammed Abdelsalam
 
 Layer : MCAL
 
 SWC   : DIO/GIO
 
 
 
 *
 */
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "DIO_private.h"
 #include "DIO_interface.h"
 
 
 /* this function used in set direction of pin (INPUT|OUTPUT)
	paramters: copy_port         =>-------- port name  		 =>----- ( DIO_portA , DIO_portB , DIO_portC , DIO_portD )
			   copy_pinnumber    =>-------- pin number 		 =>-------- ( PIN0 , PIN1 , PIN2 ,PIN3 , PIN4 , PIN5 , PIN6 , PIN7 )
			   copy_pindirection =>-------- direction of pin =>-------- ( DIO_pin_input , DIO_pin_output )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/	

DIO_errorstate DIO_setpindirection(u8 copy_port,u8 copy_pinnumber , u8 copy_pindirection )
{
DIO_errorstate LOC_STATE =DIO_ok;

/* check if the given paramter is in valid range */

if((copy_port<=DIO_portD) && (copy_pinnumber<=PIN7))
{
	
if(copy_pindirection==DIO_pin_input)
{
/* check on the port name */
switch(copy_port)
{
	case	DIO_portA:CLR_BIT(DDRA_REGISTER,copy_pinnumber); break;
	case	DIO_portB:CLR_BIT(DDRB_REGISTER,copy_pinnumber); break;
	case	DIO_portC:CLR_BIT(DDRC_REGISTER,copy_pinnumber); break;
	case	DIO_portD:CLR_BIT(DDRD_REGISTER,copy_pinnumber); break;
}
}
else if(copy_pindirection== DIO_pin_output)
{
/* check on the port name */
switch(copy_port){
	case	DIO_portA:SET_BIT(DDRA_REGISTER,copy_pinnumber); break;
	case	DIO_portB:SET_BIT(DDRB_REGISTER,copy_pinnumber); break;
	case 	DIO_portC:SET_BIT(DDRC_REGISTER,copy_pinnumber); break;
	case	DIO_portD:SET_BIT(DDRD_REGISTER,copy_pinnumber); break;
}
}
else {
	LOC_STATE=DIO_Nok;
}
}
else{
	LOC_STATE=DIO_Nok;
}
return LOC_STATE;
}

/*
-----------------------------------------------------------------------------------------------------------------------------------------------------
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>





 this function used in set VALUE of pin (HIGH|LOW)
	paramters: copy_port         =>-------- port name  		 =>----- ( DIO_portA , DIO_portB , DIO_portC , DIO_portD )
			   copy_pinnumber    =>-------- pin number 		 =>-------- ( PIN0 , PIN1 , PIN2 ,PIN3 , PIN4 , PIN5 , PIN6 , PIN7 )
			   copy_pinvalue =>-------- value of pin =>-------- ( PIN_HIGH , PIN_LOW )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/	

DIO_errorstate DIO_setpinvalue(u8 copy_port,u8 copy_pinnumber , u8 copy_pinvalue         )
{
DIO_errorstate LOC_STATE =DIO_ok;
/* check if the given paramter is in valid range */
if((copy_port<=DIO_portD)&&(copy_pinnumber<=PIN7))
{
if(copy_pinvalue==PIN_LOW)
{
	/* check on the port name */
switch(copy_port)
{
		case    DIO_portA:CLR_BIT(PORTA_REGISTER,copy_pinnumber); break;
		case	DIO_portB:CLR_BIT(PORTB_REGISTER,copy_pinnumber); break;
		case 	DIO_portC:CLR_BIT(PORTC_REGISTER,copy_pinnumber); break;
		case	DIO_portD:CLR_BIT(PORTD_REGISTER,copy_pinnumber); break;
}
}
if(copy_pinvalue==PIN_HIGH)
{
switch(copy_port)
{
	/* check on the port name */
	case	DIO_portA:SET_BIT(PORTA_REGISTER,copy_pinnumber); break;
	case	DIO_portB:SET_BIT(PORTB_REGISTER,copy_pinnumber); break;
	case	DIO_portC:SET_BIT(PORTC_REGISTER,copy_pinnumber); break;
	case	DIO_portD:SET_BIT(PORTD_REGISTER,copy_pinnumber); break;
}
}
else
{
	LOC_STATE=DIO_Nok;
}
}
else
{
	LOC_STATE=DIO_Nok;
}
return LOC_STATE;
}

/* 

--------------------------------------------------------------------------------------------------------------------------------------------------
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



 this function used to get pin value (HIGH|LOW)
	paramters: copy_port         =>-------- port name  				  =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   copy_pinnumber    =>-------- pin number 				  =>-------- ( PIN0 , PIN1 , PIN2 ,PIN3 , PIN4 , PIN5 , PIN6 , PIN7 )
			   u8* pinvalue =>-------- pointer to char to store value =>-------- (                                                      )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/	


DIO_errorstate DIO_getpinvalue(u8 copy_port,u8 copy_pinnumber , u8* pinvalue             )
{
DIO_errorstate LOC_STATE=DIO_ok;
/* check if the given paramter is in valid range */
if((copy_port<=DIO_portD)&&(copy_pinnumber<=PIN7))
{
switch(copy_port)
{
	/* check on the port name */
	case	DIO_portA:* pinvalue  = GET_BIT(PINA_REGISTER,copy_pinnumber);break;
	case	DIO_portB:* pinvalue  = GET_BIT(PINB_REGISTER,copy_pinnumber);break;
	case	DIO_portC:* pinvalue  = GET_BIT(PINC_REGISTER,copy_pinnumber);break;
	case	DIO_portD:* pinvalue  = GET_BIT(PIND_REGISTER,copy_pinnumber);break;
}
}
else
{
	LOC_STATE=DIO_Nok;
}
return LOC_STATE ;
}
/* 
----------------------------------------------------------------------------------------------------------------------------------------------
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



 this function used to togel pin value (HIGH <======> LOW)
	paramters: copy_port         =>-------- port name  				  =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   copy_pinnumber    =>-------- pin number 				  =>-------- ( PIN0 , PIN1 , PIN2 ,PIN3 , PIN4 , PIN5 , PIN6 , PIN7 )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/

DIO_errorstate DIO_togelpinvalue(u8 copy_port,u8 copy_pinnumber                          )
{
DIO_errorstate LOC_STATE=DIO_ok;
/* check if the given paramter is in valid range */
if((copy_port<=DIO_portD)&&(copy_pinnumber<=PIN7))
{
switch(copy_port){
	/* check on the port name */
	case	DIO_portA:TOG_BIT(PORTA_REGISTER,copy_pinnumber); break;
	case	DIO_portB:TOG_BIT(PORTB_REGISTER,copy_pinnumber); break;
	case	DIO_portC:TOG_BIT(PORTC_REGISTER,copy_pinnumber); break;
	case	DIO_portD:TOG_BIT(PORTD_REGISTER,copy_pinnumber); break;
}
}
else 
{
	LOC_STATE=DIO_Nok;
}
return LOC_STATE ;
}


/* 
----------------------------------------------------------------------------------------------------------------------------------------------
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



 this function used to set port direction ( OUTPUT | INPUT )
	paramters: copy_port         =>-------- port name  				  =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   copy_portdirection    =>-------- direction of port 	  =>-------- ( DIO_port_OUTPUT , DIO_port_INPUT                       )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/

DIO_errorstate DIO_setportdirection (u8 copy_port , u8 copy_portdirection )
{
	DIO_errorstate LOC_STATE = DIO_ok;
	/* check on givin paramter is in valid range */
	
	if( copy_port<=DIO_portD ){
		/* check on port name */
		switch(copy_port)
		{
		case	DIO_portA : DDRA_REGISTER = copy_portdirection ; break ;
		case    DIO_portB : DDRB_REGISTER = copy_portdirection ; break ;
		case	DIO_portC : DDRC_REGISTER = copy_portdirection ; break ;
		case    DIO_portD : DDRD_REGISTER = copy_portdirection ; break ;
		}
	}
	else 
	{
		LOC_STATE =DIO_Nok;
	}
	return LOC_STATE ;
}
   
/*
 this function used to set port VALUE ( HIGH | LOW )
	paramters: copy_port         =>-------- port name  				  =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   copy_portvalue    =>-------- value of port 	  		  =>-------- ( DIO_port_HIGH , DIO_port_LOW                           )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/


DIO_errorstate DIO_setportvalue     (u8 copy_port , u8 copy_portvalue     )
{
		DIO_errorstate LOC_STATE = DIO_ok;
	/* check on givin paramter is in valid range */
	
	if( copy_port<=DIO_portD ){
		
		/* check on port name */
		switch(copy_port)
		{
		case	DIO_portA : PORTA_REGISTER = copy_portvalue ; break ;
		case    DIO_portB : PORTB_REGISTER = copy_portvalue ; break ;
		case	DIO_portC : PORTC_REGISTER = copy_portvalue ; break ;
		case    DIO_portD : PORTD_REGISTER = copy_portvalue ; break ;
		}
	}
	else 
	{
		LOC_STATE =DIO_Nok;
	}
	return LOC_STATE ;
}


/*
 this function used to get port VALUE ( HIGH | LOW )
	paramters: copy_port         =>-------- port name  				           =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   u8 * ptr_data     =>-------- pointer to cahre to store value    =>-------- (                                                        )
			   
	return : its statues (DIO_Nok,DIO_ok)

*/

DIO_errorstate DIO_getportvalue     (u8 copy_port , u8 * ptr_data         )
{
			DIO_errorstate LOC_STATE = DIO_ok;
	/* check on givin paramter is in valid range */
	
	if( copy_port<=DIO_portD ){
		
		/* check on port name */
		switch(copy_port)
		{
		case	DIO_portA :  *ptr_data =    PINA_REGISTER ; break ;
		case    DIO_portB :  *ptr_data =    PINB_REGISTER ; break ;
		case	DIO_portC :  *ptr_data =    PINC_REGISTER ; break ;
		case    DIO_portD :  *ptr_data =    PIND_REGISTER ; break ;
		}
	}
	else 
	{
		LOC_STATE =DIO_Nok;
	}
	return LOC_STATE ;
}



/*
 this function used to togel port VALUE ( HIGH | LOW )
	paramters: copy_port         =>-------- port name  				           =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   
			   
	return : its statues (DIO_Nok,DIO_ok)

*/

DIO_errorstate DIO_togelportvalue   (u8 copy_port                         )
{
			DIO_errorstate LOC_STATE = DIO_ok;
	/* check on givin paramter is in valid range */
	
	if( copy_port<=DIO_portD ){
		
		/* check on port name */
		switch(copy_port)
		{
		case	DIO_portA :  PORTA_REGISTER =   ~ PORTA_REGISTER ; break ;
		case    DIO_portB :  PORTB_REGISTER =   ~ PORTB_REGISTER ; break ;
		case	DIO_portC :  PORTC_REGISTER =   ~ PORTC_REGISTER ; break ;
		case    DIO_portD :  PORTD_REGISTER =   ~ PORTD_REGISTER ; break ;
		}
	}
	else 
	{
		LOC_STATE =DIO_Nok;
	}
	return LOC_STATE ;
}

/*
 this function used to write in high nibles ( HIGH | LOW )
	paramters: copy_port         =>-------- port name  	    =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   copy_value        =>-------- value of pins   =>-------- ( HIGH          , LOW                                    )
			   
	return : its statues (DIO_Nok,DIO_ok)
	Hint   : high nibles is pins from 4 to 7

*/


DIO_errorstate DIO_writehighnibles (u8 copy_port , u8 copy_value )
{
				DIO_errorstate LOC_STATE = DIO_ok;
	/* check on givin paramter is in valid range */
	
	if( copy_port<=DIO_portD ){
		copy_value = (copy_value<<4);
		/* check on port name */
		switch(copy_port)
		{
		case	DIO_portA :  PORTA_REGISTER = ((PORTA_REGISTER & 0x0f )|(copy_value)) ; break ;
		case    DIO_portB :  PORTB_REGISTER = ((PORTB_REGISTER & 0x0f )|(copy_value)) ; break ;
		case	DIO_portC :  PORTC_REGISTER = ((PORTC_REGISTER & 0x0f )|(copy_value)) ; break ;
		case    DIO_portD :  PORTD_REGISTER = ((PORTD_REGISTER & 0x0f )|(copy_value)) ; break ;
		}
	}
	else 
	{
		LOC_STATE =DIO_Nok;
	}
	return LOC_STATE ;
}

/*
 this function used to write in LOW nibles ( HIGH | LOW )
	paramters: copy_port         =>-------- port name  	    =>-------- (DIO_portA , DIO_portB , DIO_portC , DIO_portD           )
			   copy_value        =>-------- value of pins   =>-------- ( HIGH          , LOW                                    )
			   
	return : its statues (DIO_Nok,DIO_ok)
	Hint   : high nibles is pins from 0 to 3

*/




DIO_errorstate DIO_writelownibles  (u8 copy_port , u8 copy_value )
{
				DIO_errorstate LOC_STATE = DIO_ok;
	/* check on givin paramter is in valid range */
	
	if( copy_port<=DIO_portD ){
		copy_value = (copy_value&0x0f);
		/* check on port name */
		switch(copy_port)
		{
		case	DIO_portA :  PORTA_REGISTER = ((PORTA_REGISTER & 0xf0 )|(copy_value)) ; break ;
		case    DIO_portB :  PORTB_REGISTER = ((PORTB_REGISTER & 0xf0 )|(copy_value)) ; break ;
		case	DIO_portC :  PORTC_REGISTER = ((PORTC_REGISTER & 0xf0 )|(copy_value)) ; break ;
		case    DIO_portD :  PORTD_REGISTER = ((PORTD_REGISTER & 0xf0 )|(copy_value)) ; break ;
		}
	}
	else 
	{
		LOC_STATE =DIO_Nok;
	}
	return LOC_STATE ;
}

