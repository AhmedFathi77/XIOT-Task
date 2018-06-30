/*
 * ADC.c
 *
 *  Created on: Jun 29, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "ADC.h"

void ADC_Init(){
	ADMUX  |= (1<<REFS0) | (1<<REFS1);				 // Internal 2.55v voltage Reference
	ADCSRA |= (1<<ADEN); 							 // Enable ADC
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);  // 128 Bit Prescaler
	ADMUX  |= (1<<ADLAR); 							 // Left Adjust


}
int ADC_Result(unsigned char channel){
	channel &= 0x07;  // AND operation with 7
	 ADMUX = (ADMUX & 0xF8)|channel;
	ADCSRA |= (1<<ADSC); 	//Start Conversion
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	return ADCH;
}

void Terminl_IntegerToStringPrint(int num){
	char buff[16]; /* String to hold the ascii result */
	itoa(num,buff,10); /* 10 for decimal */
	UART_SendString(buff);
	UART_SendString("\r");
}
