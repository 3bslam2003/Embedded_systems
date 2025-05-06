/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BUZ_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Ahmed Mohamed Abdelsalame
 *  Layer  : HAL
 *  SWC    : BUZ
 *
 */
#ifndef   BUZ_INTERFACE_H_
#define   BUZ_INTERFACE_H_

// Port Defines
#define  BUZ_PORTA  0
#define  BUZ_PORTB  1
#define  BUZ_PORTC  2
#define  BUZ_PORTD  3


// PIN Defines
#define BUZ_PIN0   0
#define BUZ_PIN1   1
#define BUZ_PIN2   2
#define BUZ_PIN3   3
#define BUZ_PIN4   4
#define BUZ_PIN5   5
#define BUZ_PIN6   6
#define BUZ_PIN7   7

#define BUZ_ACTIVE_HIGH    1
#define BUZ_ACTIVE_LOW     0

typedef struct{
	
	u8 port         ;
	u8 pin          ;
	u8 active_state ;
	
}BUZ_Type;

  
void BUZ_init        ( BUZ_Type buz_config );

void BUZ_turnon          ( BUZ_Type buz_config );

void BUZ_turnoff         ( BUZ_Type buz_config );
 
void BUZ_toggel     ( BUZ_Type buz_config );
 


#endif
