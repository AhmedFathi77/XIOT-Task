/*
 * Timer.c
 *
 *  Created on: Jun 29, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>



void Overflow_TIMER0_Init(){
	TCNT0 = 0;
	TIMSK  |= (1<<TOIE0);			// Timer Interrupt overflow Enable pin
	//TCCR0 |= (1<<FOC0); 			// Force output compare pin
	TCCR0 |= (1<<FOC0) | (1<<CS00) | (1<<CS02);	// CLK 2014 From prescaler
}
