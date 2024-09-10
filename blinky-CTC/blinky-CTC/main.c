/*
 * blinky-CTC.c
 *
 * Created: 8/31/2024 11:08:53 PM
 * Author : PC
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_COMPA_vect) {
	PORTE ^= (1 << PE4);
}

int main(void)
{
    DDRE &= ~(1 << PE4); /* set LED pin as output */
	
	TCCR1A |= (1 << WGM12); /* configure timer in CTC mode */
	
	TCCR1B |= (1 << CS12); /* set timer pre scaler value  to 256*/
	
	TIMSK1 |= (1 << OCIE0A);	/* enable timer on compare interrupt */
	
	OCR1A = 31249; /* value to compare with */
	
	sei(); /* enable global interrupts */
	
    while (1) 
    {
    }

}

