/*
 * uart_func.h
 *
 * Created: 9/8/2024 10:28:53 PM
 *  Author: PC
 */ 


#ifndef UART_FUNC_H_
#define UART_FUNC_H_
#include <avr/io.h>

#define BAUD 9600
#define MYUBRR ( (F_CPU / (BAUD * 16UL)) - 1 ) /* to calculate the UBRR value */

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
unsigned char USART_Receive();
void USART_putString(char* pstr);

#endif /* UART_FUNC_H_ */