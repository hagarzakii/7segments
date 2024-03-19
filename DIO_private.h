/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hagar Zaki Hashesh
 *  Layer  : MCAL
 *  SWC   : DIO/GPIO
 *
 */
 
 #ifndef DIO_PRIVATE_H
 #define DIO_PRIVATE_H
 
 /* Group A registers */
 
 #define PORTA_Register *((volatile u8*)0x3B) 
 #define DDRA_Register  *((volatile u8*)0x3A)
 #define PINA_Register  *((volatile u8*)0x39)
 
 /* Group B registers */
 
 #define PORTB_Register *((volatile u8*)0x38) 
 #define DDRB_Register  *((volatile u8*)0x37)
 #define PINB_Register  *((volatile u8*)0x36)
 
 /* Group C registers */
 
 #define PORTC_Register *((volatile u8*)0x35) 
 #define DDRC_Register  *((volatile u8*)0x34)
 #define PINC_Register  *((volatile u8*)0x33)
 
 /* Group D registers */
 
 #define PORTD_Register *((volatile u8*)0x32) 
 #define DDRD_Register  *((volatile u8*)0x31)
 #define PIND_Register  *((volatile u8*)0x30)
 
 
 #endif