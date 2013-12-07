/*
 * IR_Sensor.h
 *
 *  Created on: Dec 6, 2013
 *      Author: C15Gared.Chapman
 */

#include <msp430.h>
#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

void ADC10init();

unsigned int detectLeft();

unsigned int detectRight();

#endif /* IR_SENSOR_H_ */
