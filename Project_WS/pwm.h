/*
 * pwm.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

// Function to initialize Timer0 in PWM mode and set the duty cycle
void PWM_Timer0_Start(uint8_t duty_cycle);

#endif /* PWM_H_ */
