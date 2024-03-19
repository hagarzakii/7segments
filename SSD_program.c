/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hagar Zaki Hashesh
 *  Layer  : HAL
 *  SWC   : SSD
 *
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"SSD_config.h"
#include"SSD_private.h"
#include"SSD_interface.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;
 
void SSD_voidInitializeDataPort  ( SSD_Type Copy_structConfig )
{
	DIO_enumSetPortDirection(Copy_structConfig.DataPort, DIO_PORT_OUTPUT);
}

void SSD_voidSendNumber       ( SSD_Type Copy_structConfig , u8 Copy_u8Number )
{
	if(Copy_structConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPortValue (Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
	}
	else if(Copy_structConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPortValue (Copy_structConfig.DataPort, ~(Local_u8SSDNumbers[Copy_u8Number]));
	}
}