/*
 * flame.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Administrator
 */

#ifndef FLAME_H_
#define FLAME_H_
#include <avr/io.h>

// Function to initialize the flame sensor pin direction
void FlameSensor_init(void);

// Function to read the value from the flame sensor
uint8_t FlameSensor_getValue(void);


#endif /* FLAME_H_ */
