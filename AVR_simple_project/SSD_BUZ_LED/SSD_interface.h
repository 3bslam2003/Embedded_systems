/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Ahmed Mohamed Abdelsalame
 *  Layer  : HAL
 *  SWC    : SSD
 *
 */
#ifndef   SSD_INTERFACE_H_
#define   SSD_INTERFACE_H_

// Port Defines
#define  SSD_PORTA  0
#define  SSD_PORTB  1
#define  SSD_PORTC  2
#define  SSD_PORTD  3


// PIN Defines
#define SSD_PIN0   0
#define SSD_PIN1   1
#define SSD_PIN2   2
#define SSD_PIN3   3
#define SSD_PIN4   4
#define SSD_PIN5   5
#define SSD_PIN6   6
#define SSD_PIN7   7

#define SSD_COMMON_CATHODE   0
#define SSD_COMMON_ANODE     1

typedef struct{
	u8 ssd_type         ;
	u8 ssd_port         ;
	u8 enable_port      ;
	u8 enable_pin       ;
	
}SSD_Type;

  
void SSD_init        	 ( SSD_Type SSD_config );
// to enable ssd
void SSD_enable          ( SSD_Type SSD_config );
// to disable the SSD
void SSD_disable         ( SSD_Type SSD_config );
 // to_write_number_on_SSD
void SSD_sendnumber      ( SSD_Type SSD_config,u8 copy_number );



/* this function to write some letters on Seven Segmant Display 

   paramter : SSD_Type , 
   copy_number    options ------> ( 0 = A, 1 = C , 2 = E , 3 = F , 4 = H ,5 = L ,6 = P ,7 = U ) 
*/   
/*void SSD_sendletter      ( SSD_Type SSD_config,copy_number );
*/

#endif
