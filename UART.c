
#include <avr/io.h>
#include "UART.h"

/* ############################################################################# */
void UART_Init(){
		UCSRA |=(1<<U2X);
		UCSRB |= (1<<TXEN);		            // Enable Receive and Transmit
		UCSRC |= (1<<URSEL)|(1<<UCSZ0) | (1<<UCSZ1);	// 8-bit data mode
		UBRRH = (BAUD_PRESCALE>>8);
		UBRRL = BAUD_PRESCALE;
}
/*
	[ function name] : UART_Init
	[ return type] : void
	[ functionality ] : initiate UART Communication protocol
*/
/* ############################################################################# */


void UART_Send(unsigned char data){
	while(!( UCSRA & (1<<UDRE))); // WAIT Until UDRE becomes 1
	UDR = data;
}
/*
	[ function name] : UART_Send
	[ return type] : void
	[ functionality ] : use to send a unsigned char using UART
*/
/* ############################################################################# */


void UART_SendString(const char* data){
	unsigned char  i =0;
	while(data[i] != '\0'){
		UART_Send(data[i]);
		i++;
	}
}
/*
	[ function name] : UART_SendString
	[ return type] : void
	[ functionality ] : use to send a String using UART
*/
/* ############################################################################# */
