/*
 * UART.c
 *
 *  Created on: Jun 27, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>

#define F_CPU 1000000UL //1MHz Clock frequency
#define BaudRate 9600


#define BAUD_PRESCALE (((F_CPU / (BaudRate * 8UL))) - 1)

void UART_Init(){
		UCSRA |=(1<<U2X);
		UCSRB |= (1<<TXEN);		            // Enable Receive and Transmit
		UCSRC |= (1<<URSEL)|(1<<UCSZ0) | (1<<UCSZ1);	// 8-bit data mode
		UBRRH = (BAUD_PRESCALE>>8);
		UBRRL = BAUD_PRESCALE;
}

void UART_Send(unsigned char data){
	while(!( UCSRA & (1<<UDRE))); // WAIT Until UDRE becomes 1
	UDR = data;
}

void UART_SendString(const char* data){
	unsigned char  i =0;
	while(data[i] != '\0'){
		UART_Send(data[i]);
		i++;
	}
}
