/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hagar Zaki Hashesh
 *  Layer  : HAL
 *  SWC   : SW
 *
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"SW_config.h"
#include"SW_private.h"
#include"SW_interface.h"

void SW_voidInit       ( SW_Type SW_Config )
{
	DIO_enumSetPinDirection (SW_Config.port , SW_Config.pin , DIO_PIN_INPUT);
	if(SW_Config.pullstate == SW_Int_PULL_UP)
	{
		DIO_enumSetPinValue (SW_Config.port, SW_Config.pin, DIO_PIN_HIGH );
	}
}
u8   SW_u8IsPressed   ( SW_Type SW_Config )
{
	u8 loc_pinvalue = SW_NOT_PRESSED;
	u8 loc_pressedOrNot = SW_NOT_PRESSED;
	if(SW_Config.pullstate == SW_Int_PULL_UP || SW_Config.pullstate == SW_Ext_PULL_UP)
	{
		DIO_enumGetPinValue (SW_Config.port , SW_Config.pin , & loc_pinvalue );
		if(loc_pinvalue == 0)
		{
			loc_pressedOrNot = SW_PRESSED;
		}
		else if(loc_pinvalue == 1)
		{
			loc_pressedOrNot = SW_NOT_PRESSED;
		}
	}
	else if (SW_Config.pullstate == SW_Ext_PULL_DOWN)
	{
		DIO_enumGetPinValue (SW_Config.port , SW_Config.pin , & loc_pinvalue );
		if(loc_pinvalue == 1)
		{
			loc_pressedOrNot = SW_PRESSED;
		}
		else if(loc_pinvalue == 0)
		{
			loc_pressedOrNot = SW_NOT_PRESSED;
		}
	}
	
	return loc_pressedOrNot;
}