/*
 * ultransonic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: user
 */

#include "gpio.h"
#include <util/delay.h>
#include "ICU.h"
#include "std_types.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;

void Ultransonic_edgeProcessing(void){

	g_edgeCount++;
		if(g_edgeCount == 1)
		{
			/*
			 * Clear the timer counter register to start measurements from the
			 * first detected rising edge
			 */
			ICU_clearTimerValue();
			/* Detect falling edge */
			ICU_setEdgeDetectionType(FALLING);
		}
		else if(g_edgeCount == 2)
		{
			/* Store the High time value */
			g_timeHigh = ICU_getInputCaptureValue();
			/* Detect rising edge */
			g_edgeCount = 0;
			ICU_setEdgeDetectionType(RAISING);

		}

}
void ultrasonic_init(void){

	ICU_ConfigType ICU_setup ={F_CPU_8 , RAISING};
	ICU_init(&ICU_setup);
	ICU_setCallBack(Ultransonic_edgeProcessing);

	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}
void Ultrasonic_Trigger(void){
	   GPIO_writePin(PORTB_ID, PIN5_ID,LOGIC_HIGH );
	   _delay_us(10);
	   GPIO_writePin(PORTB_ID, PIN5_ID,LOGIC_LOW );
}


uint16 Ultrasonic_readDistance(void){

uint16 distance=0;
Ultrasonic_Trigger();
Ultransonic_edgeProcessing();
distance = g_timeHigh / 60;

	return distance;
}


