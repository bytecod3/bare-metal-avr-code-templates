/*
 * adc_func.h
 *
 * Created: 9/8/2024 10:29:13 PM
 *  Author: PC
 */ 


#ifndef ADC_FUNC_H_
#define ADC_FUNC_H_

#include <avr/io.h>

/* initialize ADC in free running mode */
void initADCFreeRunning();

/* initialize the ADC in single conversion mode */
void initADCSingleConversion()

/* read ADC */
int readADCFreeRunning();
uint16_t readADCSingleConversion(uint8_t channel)


#endif /* ADC_FUNC_H_ */