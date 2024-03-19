/*
 * main.c
 *
 *  Created on: Mar 12, 2024
 *      Author: User
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include<util/delay.h>
#include <avr/interrupt.h>

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

#include"SW_config.h"
#include"SW_private.h"
#include"SW_interface.h"

#include"SSD_config.h"
#include"SSD_private.h"
#include"SSD_interface.h"


volatile u8 global_counter_leftssd;
volatile u8 global_counter_rightssd;

SSD_Type loc_structleftssd = {SSD_COMMON_CATHODE , DIO_PORTB};
SSD_Type loc_structrightssd = {SSD_COMMON_CATHODE , DIO_PORTA};


void init_interrupts() {

    // Configure INT0 to trigger on falling edge
    MCUCR |= (1 << ISC01);  // Falling edge
    MCUCR &= ~(1 << ISC00); // Falling edge

    // Configure INT1 to trigger on falling edge
    MCUCR |= (1 << ISC11);  // Falling edge
    MCUCR &= ~(1 << ISC10); // Falling edge

    // Enable INT0 and INT1 external interrupts
    GICR |= (1 << INT0) | (1 << INT1);

    // Enable global interrupts
    sei();
}

ISR(INT0_vect) {
	_delay_ms(1000);
}

ISR(INT1_vect) {
	global_counter_leftssd =0;
	global_counter_rightssd=0;
	SSD_voidSendNumber( loc_structleftssd , global_counter_leftssd );
	SSD_voidSendNumber( loc_structrightssd , global_counter_rightssd );
	_delay_ms(100);

}

void main()
{
	SSD_voidInitializeDataPort  ( loc_structleftssd );
	SSD_voidInitializeDataPort  ( loc_structrightssd );

	SW_Type loc_structpauseSW = {DIO_PORTD , DIO_PIN2 , SW_Int_PULL_UP};
	SW_Type loc_structresetSW = {DIO_PORTD , DIO_PIN3 , SW_Int_PULL_UP};

	SW_voidInit       ( loc_structpauseSW );
	SW_voidInit       ( loc_structresetSW );

	init_interrupts();

	while(1)
	{
		for(global_counter_leftssd = 0 ; global_counter_leftssd < 10 ; global_counter_leftssd++)
		{
			SSD_voidSendNumber( loc_structleftssd , global_counter_leftssd );
			for(global_counter_rightssd = 0 ; global_counter_rightssd < 10 ; global_counter_rightssd++)
			{
				SSD_voidSendNumber( loc_structrightssd , global_counter_rightssd );
				_delay_ms(100);
			}
		}
	}

}
