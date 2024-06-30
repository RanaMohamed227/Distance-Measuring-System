/*
 * ultransonic.h
 *
 *  Created on: Oct 20, 2023
 *      Author: user
 */

#ifndef ULTRANSONIC_H_
#define ULTRANSONIC_H_

void Ultransonic_edgeProcessing(void);
void ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRANSONIC_H_ */
