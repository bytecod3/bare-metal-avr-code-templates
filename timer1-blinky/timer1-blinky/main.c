/*
 * timer1-blinky.c
 *
 * Created: 8/31/2024 10:41:02 PM
 * Author : PC
 */ 

#include <avr/io.h>


int main(void)
{
    
	/* set PE5 as output */
	DDRE &= ~(1 << PE5);
	
	TCCR1B |= (1 << CS12); /* set pre-scaler to 256 */	
	
    while (1) {
		
		if(TCNT1 >= 31249) {
			PORTE ^= (1 << PE5);
			TCNT1 = 0x00; /* reset the timer */
		}
    }
}

