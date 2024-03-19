/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hagar Zaki Hashesh
 *  Layer  : HAL
 *  SWC   : SW
 *
 */
 
#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

//switch states

#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
#define SW_FLOATING        3

typedef struct{
	
	u8 port;
	u8 pin ;
	u8 pullstate;
	
}SW_Type;

void SW_voidInit       ( SW_Type SW_Config );
u8   SW_u8IsPressed    ( SW_Type SW_Config );
 
#endif