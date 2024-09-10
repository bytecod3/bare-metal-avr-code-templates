/*
 * timer-0-overflow.c
 *
 * Created: 8/30/2024 3:16:59 AM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

#pragma interrupt_handler timer_0_interrupt_isr:19

#define BIT_FIVE 5

void initTimer0();
void initGPIO();

void initGPIO() {
	DDRB &= ~(1 << BIT_FIVE);
}

void initTimer0() {
	/* pre-scale the clock by 1024*/
	TCCR0B = (1 << CS02) | (1 << CS00);
	
	/* clear the overflow flag. Timer will overflow every 16.38 ms */
	TIFR0 = 1 << TOV0;
	
	/* enable overflow interrupt */	
	TIMSK0 = (1 << TOIE0);
	
	/* enable global interrupt */
	asm("SEI");
	
}

/************************************************************************/
/* Overflow ISR                                                         */
/************************************************************************/
void timer_0_interrupt_isr (TIMER0_OVF_vect) {
	/* Toggle a pin on timer overflow */
	PORTB ^= (1 << BIT_FIVE);	
}


int main(void)
{
    /* setup */
	initGPIO();
	initTimer0();
	
    while (1) 
    {
    }
}

