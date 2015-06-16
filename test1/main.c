/*
 * main.c
 *
 *  Created on: Jun 14, 2015
 *      Author: jimparker
 */
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRC |= (0b00111111);
	DDRD |= (0b00000000);

	char i = 0;
	char buttonJustPressed = 0;
	while (1) {
		if ((PIND & (1 << PD0)) == 0) {  // I've got a pushbutton between pin D0 and ground
			if (buttonJustPressed == 0) {
				i++;
				if (i >= 6) i = 0; // only hooked up 4 LEDs
				PORTC = (1 << i);
				_delay_ms(100);  // debounce
				buttonJustPressed = 1; // memory
			}
		} else {
			buttonJustPressed = 0;
			PORTC = (1 << i);
		}
	}
	return(0);
}


