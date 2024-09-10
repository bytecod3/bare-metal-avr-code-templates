/*
 * adc_func.c
 *
 * Created: 9/8/2024 10:29:34 PM
 *  Author: PC
 */ 

#include "adc_func.h"


/* initialize the ADC */
void initADCFreeRunning() {
	/* set pre-scaler to 128 - 125KHz clock to the ADC */
	ADCSRA = ((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
	
	/* set voltage reference to AVCC(5V)*/
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << REFS1);

	/* set the ADC to free running mode, AUTO trigger enable  */
	ADCSRA |= (1 << ADATE);
	ADCSRB &= ~(1 << ADTS0);
	ADCSRB &= ~(1 << ADTS1);
	ADCSRB &= ~(1 << ADTS2);

	/* power up the ADC */
	ADCSRA |= (1 << ADEN);

	/* start converting  */
	ADCSRA |= (1 << ADSC);
}

/* read ADC */
int readADCFreeRunning() {
	return ADCW;
}

/* initialize the ADC in single conversion mode */
void initADCSingleConversion() {
	/* set pre-scaler to 128 - 125KHz clock to the ADC */
	ADCSRA = ((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
	
	/* set voltage reference to AVCC(5V)*/
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << REFS1);

	/* power up the ADC */
	ADCSRA |= (1 << ADEN);

	/* start converting - do an initial conversion to set things up okay */
	ADCSRA |= (1 << ADSC);
}

uint16_t readADCSingleConversion(uint8_t channel) {
	/* clear the older channel that was read */
	ADMUX &= 0xf0;
	ADMUX |= channel;
	ADCSRA |= (1 << ADSC);
	
	/* wait until the conversion is done  */
	while(ADCSRA & (1<< ADSC));
	return ADCW;
}