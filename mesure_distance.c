/*
 * mesure_distance.c
 *
 *  Created on: Oct 20, 2023
 *      Author: user
 */

#include "LCD.h"
#include "std_types.h"
#include "ultransonic.h"
#include <avr/io.h>


int main(void){
	SREG |= (1<<7);
	LCD_init();
	ultrasonic_init();
	LCD_DisplayString("distance=     cm");
	uint16 distance=0;
while(1){
LCD_moveCursor(0,10);
	distance=Ultrasonic_readDistance();
	if(distance >= 100)
	{
		LCD_moveCursor(0,10);
		LCD_intgerToString(distance);
	}
	else
	{
		LCD_moveCursor(0,10);
		LCD_intgerToString(distance);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_DisplayCharacter(' ');
	}
}

}
