/*
 * uart_func.c
 *
 * Created: 9/8/2024 10:28:31 PM
 *  Author: PC
 */ 

#include <avr/io.h>
#include "uart_func.h"
#define BAUD 9600

void USART_Init(unsigned int ubrr) {
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = ubrr;
	
	/* enable receiver and transmitter */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	
	/* set frame format: 8 data, 2 stop bit*/
	UCSR0C = (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);
	
}

void USART_Transmit(unsigned char data){
	/* polling - wait for empty TX buffer */
	while (!(UCSR0A & (1 << UDRE0)));
	
	UDR0 = data; /* put data into data register and send */
}

unsigned char USART_Receive() {
	/* check is RXC(receive complete) flag is set */
	while(!(UCSR0A & (1 << RXC0)));
	
	/* get and return received data from buffer */
	return UDR0;
}

void USART_putString(char* pstr) {
	/* if we are not yet at the end of the string */
	while(*pstr != 0x00) {
		USART_Transmit(*pstr);
		pstr++;
	}
}

