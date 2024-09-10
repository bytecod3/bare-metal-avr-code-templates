/*
 * pot-LED-control;.c
 *
 * Created: 9/8/2024 10:19:42 PM
 * Author : PC
 */ 

//#define F_CPU 16000000UL
#include <avr/io.h>
//#include <util/delay.h>



int main(void)
{
	
	/* init ADC */ 
	//initADCFreeRunning();
	
	/* init UART */
	//USART_Init();

	/* init timer */
	//timer0InitPhaseCorrect();	

	/* set up LED pin - OC0A */
	//DDRB |= (1 << PB7);
    
    while (1) 
    {

		/* read the potentiometer */
		/* write value to timer counter to change duty cycle */
		//for(int i = 0; i < 255; i++) {
		//	OCR0A = i;
		//	_delay_ms(20);

		//}

		//for(int i = 255; i > 0; i--) {
		//	OCR0A = i;
		//	_delay_ms(20);
		//}

		/* turn on the LED PWM channel with the given duty cycle */
		
    }

}

