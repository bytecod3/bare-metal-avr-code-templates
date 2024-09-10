/*
 * timer0_precision_delay.c
 *
 * Created: 8/30/2024 4:16:31 PM
 * Author : PC
 */ 
#define F_CPU 16000000UL /* 16MHz for 2560 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED 5

void init_timer0();
void init_gpio();
void delay(unsigned int no_of_4_096_ms_interrupts);

unsigned int interrupt_counter; /* to count the number of overflows */

void init_timer0() {
	//TCCR0B |= (1 << CS02);  /* divide the clock by 256, overflow occurs every 4.096ms */
	//TCCR0B &= ~(1 << CS01);
	//TCCR0B &= ~(1 << CS00);
	
	TCCR0B = 0x04;
	//TIMSK0 |= (1 << TOIE0);	/* enable timer0 overflow interrupt */
	TIMSK0 = 0x01;
	
	sei(); /* enable global interrupts */
}

ISR (TIMER0_OVF_vect) {
	interrupt_counter++;
}

void init_gpio() {
	DDRE &= ~(1 << LED); /* set pin5 as output */
}

void delay(unsigned int no_of_4_096_ms_interrupts) {
	TCNT0 = 0x00;	/* reset timer0 counter */
	interrupt_counter = 0; /* reset timer0 interrupt counter */	
	
	while(interrupt_counter <= no_of_4_096_ms_interrupts) {
		; /* wait for a specified number of interrupts */
	}
		
}

int main(void)
{	
	init_gpio();
	init_timer0();
    
    while (1) 
    {
		PORTE &= ~(1 << LED);
		delay(244); /* delay apx. 1 second */
		PORTE |= (1 << LED);
		delay(244); /* delay apx. 1 second */
    }
}

