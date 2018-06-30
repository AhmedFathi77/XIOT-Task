
#include <avr/io.h>
#include <avr/interrupt.h>


/* ############################################################################# */

void Interrupt_init(){
	SREG  &= ~(1<<7);        // Disable interrupts by clearing I-bit
	DDRD  &= ~(1<<PD3);	 	 // Initialize Pin PD3 As input
	PORTD |=  (1<<PD3);		 // Pull-Up Resistance
	GICR  |=  (1<<INT1); 	 // Enable INT1
	MCUCR |=  (1<<ISC10); 	 // Any Logical change will cause an interrupt
	SREG  |=  (1<<7);		 // Enable interrupts by setting I-bit
}
/*
	[ function name] : Interrupt_init
	[ return type] : void
	[ functionality ] : initiate interrupt service routine
*/
/* ############################################################################# */
