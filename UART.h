

#ifndef UART_H_
#define UART_H_

#define F_CPU 1000000UL //1MHz Clock frequency
#define BaudRate 9600
#define BAUD_PRESCALE (((F_CPU / (BaudRate * 8UL))) - 1)

void UART_Init();
void UART_Send(unsigned char data);
void UART_SendString(const char* data);

#endif /* UART_H_ */
