/*
 * timer_func.c
 *
 * Created: 9/8/2024 10:38:49 PM
 *  Author: PC
 */ 

#include "timer_func.h"

/* init timer 0 in phase correct mode */
void timer0InitPhaseCorrect() {
	TCCR0A |= (1 << WGM00);
	TCCR0A &= ~(1 << WGM01);
	TCCR0B |= (1 << WGM02);

	/* set pre-scaler to 64 */
	/* set the frequency to 50kHz - appropriate for motor control */
	TCCR0B |= (1 << CS00);
	TCCR0B |= (1 << CS01);
	TCCR0B &= (1 << CS02);	
}