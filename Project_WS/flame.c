/*
 * flame.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Administrator
 */

#include "flame.h"

// Define the flame sensor pin (assuming it's connected to PD2)
#define FLAME_SENSOR_PIN   PD2
#define FLAME_SENSOR_PORT  PORTD
#define FLAME_SENSOR_DDR   DDRD
#define FLAME_SENSOR_PINR  PIND

void FlameSensor_init(void) {
    // Set the flame sensor pin as input
    FLAME_SENSOR_DDR &= ~(1 << FLAME_SENSOR_PIN);
    // Enable pull-up resistor on the flame sensor pin
    FLAME_SENSOR_PORT |= (1 << FLAME_SENSOR_PIN);
}

uint8_t FlameSensor_getValue(void) {
    // Read and return the value of the flame sensor pin
    return (FLAME_SENSOR_PINR & (1 << FLAME_SENSOR_PIN)) ? 0 : 1;
}
