/*
 * buzzer.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Administrator
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include <avr/io.h>

// Define the buzzer pin
#define BUZZER_DDR       DDRD
#define BUZZER_PORT      PORTD
#define BUZZER_PIN       PD3

// Function prototypes
void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);

#endif /* BUZZER_H_ */
