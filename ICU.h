/*
 * ICU.h
 *
 *  Created on: Oct 14, 2023
 *      Author: rana
 */

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_ClockType;

typedef enum
{
	FALLING,RAISING
}ICU_EdgeType;

/*
 * implement structure that contains the configurations of ICU
 *
 * */

typedef struct
{
	ICU_ClockType clock;
	ICU_EdgeType edge;
}ICU_ConfigType;

/*  FUNCTIONS DECLARATIONS*/

void ICU_init(const ICU_ConfigType * Config_Ptr);

void ICU_setCallBack(void(*a_ptr)(void));


void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType);

uint16 ICU_getInputCaptureValue(void);

void ICU_clearTimerValue(void);

void ICU_deInit(void);

#endif
/* ICU_H_ */
