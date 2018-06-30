/*
 * main.c
 *
 *  Created on: Jun 26, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "Interrupt.h"
#include "UART.h"
#include "ADC.h"
#include "Timer.h"
unsigned int PressedFlag = 0 ;
unsigned char overflow_counter = 0;

ISR(TIMER0_OVF_vect){
	overflow_counter++;
	if(overflow_counter == num_overflow){ // number of overflow per second is 4 so for 3 seconds is 12
		Terminl_IntegerToStringPrint(ADC_Value);
		ADC_Value = ADC_Result(0);
		overflow_counter = 0;
	}
}
ISR(INT1_vect){
	PORTC ^=(1<<PC0);
	PressedFlag = 1;
}
int main(void){

	DDRC|= (1<<PC0);
	Interrupt_init();
	UART_Init();
	ADC_Init();
	Overflow_TIMER0_Init();
	ADC_Value = ADC_Result(0);
	while(1){

		if(PressedFlag == 1){
			if(PORTC&(1<<PC0)){
				UART_SendString("LED ON - Pressed \r");
				PressedFlag = 0;
			}else{
				UART_SendString("LED OFF - Pressed \r");
				PressedFlag = 0;
			}
		}
	}

	return 0;
}

