/*
 * UART.h
 *
 *  Created on: Jun 27, 2018
 *      Author: leenovoz510
 */

#ifndef UART_H_
#define UART_H_



void UART_Init();
void UART_Send(unsigned char data);
void UART_SendString(const char* data);

#endif /* UART_H_ */
