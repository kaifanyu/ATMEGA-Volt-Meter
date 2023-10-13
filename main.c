/*
 * GccApplication3.c
 *
 * Created: 3/06/2023 
 * Author : Kai
 
 This is the program for the micro controller that implements a simple volt-meter. It can take a 16 keypad input device and a lcd 
 screen output device. The volt-meter will take an AD sample every 500ms and update the display accordingly. It will show four parameters,
 (1) instantaneous voltage, (2) max voltage, (3) min voltage, and (4) average voltage. Minimum, maximum, and average voltage can be reset
 to --- or 0 with the push of button 'D', and '#'. Instantaneous voltage is always be displayed, starting from when the device is powered on. 
 printOutput is responsible for all displaying of properties. 
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "avr.h"
#include "lcd.h"

int reset = 0;
int get_key()
{
	int i, j;	
		for(i = 0; i < 4; ++i){
			for(j = 0; j < 4; ++j){
				if(is_pressed(i,j)){
					return i*4+j+1;
					}	
				}
		}
	return 0;
			
}

void refreshReset()
{
	
	if(get_key() == 16)
	{
		reset = 1;
	}
	if(get_key() == 14)
	{
		reset = 0;
	}
	
}

void printOutput()
{
	
	float sum = 0, count = 0;
	int max = 0, min = 1023;
	while(1)
	{
		if(get_key() == 15)
		{
			sum = 0, count = 0, max = 0, min = 1023;
		}
		
		
		if(reset == 0)
		{
			int new_sample = get_sample();
			
			sum += new_sample;
			
			if (new_sample > max) {
				max = new_sample;
			}

			if (new_sample < min) {
				min = new_sample;
			}
			
			char buf[20];
			sprintf(buf, "%.2f AVG:%.2f", (get_sample() / 1023.0) * 5, sum / ++count);

			lcd_pos(0, 0);
			lcd_puts2(buf);
			
			char buf2[20];
			sprintf(buf2, "MAX%.2f MIN%.2f", (max / 1023.0) * 5, (min / 1023.0) * 5);
			lcd_pos(1, 0);
			lcd_puts2(buf2);
			
		}
		else if(reset == 1)
		{
			lcd_clr();
			char buf[20];
			sprintf(buf, "%.2f AVG:---", (get_sample() / 1023.0) * 5);

			lcd_pos(0, 0);
			lcd_puts2(buf);
			
			char buf2[20];
			sprintf(buf2, "MAX--- MIN---");
			lcd_pos(1, 0);
			lcd_puts2(buf2);
		}
		refreshReset();
		
	}


}

int is_pressed(int r, int c)
{ 
	
	DDRC = 0x00;  // set lower 4 bits as input
	PORTC = 0x00;

	
	SET_BIT(DDRC, r);	
	CLR_BIT(PORTC, r);
	
	SET_BIT(PORTC, c + 4);
	
	avr_wait(10);
	if(GET_BIT(PINC, c+4) == 0)
	{
		
		return 1;
	}


	return 0;
}

int get_sample()
{
	ADMUX = 0b01000000;
	ADCSRA = 0b11000000;
	while (GET_BIT(ADCSRA, 6));
	int result = ADCL;
	return (ADCH << 8) + result;
	
}


int main () {
	char buf[20];
	lcd_init();
	while (1) {
		printOutput();

	}
}