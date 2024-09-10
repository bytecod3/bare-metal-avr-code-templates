#ifndef MY_USART
#define MY_USART

#define BAUD 9600
#define MYUBRR ( (F_CPU / (BAUD * 16UL)) - 1 ) /* to calculate the UBRR value */

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
unsigned char USART_Receive();
void USART_putString(char* pstr);

#endif