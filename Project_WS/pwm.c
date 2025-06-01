/*
 * pwm.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */
#include "pwm.h"

void PWM_Timer0_Start(uint8_t duty_cycle) {
    // Set OC0 (PB3) as output pin
    DDRB |= (1 << PB3);

    // Set Timer0 in Fast PWM mode, non-inverting mode
    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01);

    // Set the pre-scaler to F_CPU/1024
    TCCR0 |= (1 << CS00) | (1 << CS02);

    // Set the duty cycle
    OCR0 = (duty_cycle * 255) / 100;

    // Start the PWM by enabling Timer0
    TCNT0 = 0;  // Reset Timer0 counter
}

