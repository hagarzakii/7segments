/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hagar Zaki Hashesh
 *  Layer  : HAL
 *  SWC   : SSD
 *
 */
 
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE    1

typedef struct{

	u8 Type       ;                 // SSD_COMMON_CATHODE or SSD_COMMON_ANODE
	u8 DataPort   ;                 // PORTA or PORTB or PORTC or PORTD
	//u8 EnablePort ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	//u8 EnablePin  ;                 // PIN0 , PIN1 ,PIN2 ,PIN3 ,PIN4 ,PIN5 ,PIN6 ,PIN7

}SSD_Type;

void SSD_voidInitializeDataPort  ( SSD_Type Copy_structConfig );
//void SSD_voidEnable           ( SSD_Type Copy_structConfig );
//void SSD_voidDisable          ( SSD_Type Copy_structConfig );
void SSD_voidSendNumber       ( SSD_Type Copy_structConfig , u8 Copy_u8Number );
 
#endif
