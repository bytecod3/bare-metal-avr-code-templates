/*
 * fastPWM.c
 *
 * Created: 9/1/2024 7:37:36 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void initTimer();

void initTimer() {
	TCCR0A = ((1 << WGM01) | (1 << WGM00)); /* set wave generation mode to fast PWM */
	TCCR0A |= (1 << COM0A1);			/* clear OC01A on compare match */
	
	TCCR0B = (1 << CS01); /* set pre-scaler to 8 */
	
}


int main(void) {
	
	unsigned char i = 0;
	DDRB = (1 << PB7); /* set OCOA pin as output */
	initTimer();
	
    while (1) {
		
		/* fade up */
		for(i = 0; i < 255; i++) {
			OCR0A = i;
			_delay_ms(50);
		}
		
		/* fade down */
		for(i = 255; i > 0; i--) {
			OCR0A = i;
			_delay_ms(50);
		}
		
    }
}

