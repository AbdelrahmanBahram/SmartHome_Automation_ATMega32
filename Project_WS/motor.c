/*
 * motor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */

#include "motor.h"
#include "pwm.h"


void DcMotor_Init(void) {
    // Set motor control pins as output
	MOTOR_DDR |= (1 << MOTOR_PIN1) | (1 << MOTOR_PIN2) | (1 << MOTOR_ENABLE);
    // Stop the motor initially
    MOTOR_PORT &= ~((1 << MOTOR_PIN1) | (1 << MOTOR_PIN2));
}

void DcMotor_Rotate(DcMotor_State state, uint8_t speed) {
    // Set the speed using PWM
    PWM_Timer0_Start(speed);

    switch (state) {
        case STOP:
            // Stop the motor
            MOTOR_PORT &= ~((1 << MOTOR_PIN1) | (1 << MOTOR_PIN2));
            break;
        case CLOCKWISE:
            // Rotate the motor clockwise
            MOTOR_PORT |= (1 << MOTOR_PIN1);
            MOTOR_PORT &= ~(1 << MOTOR_PIN2);
            break;
        case ANTICLOCKWISE:
            // Rotate the motor anticlockwise
            MOTOR_PORT |= (1 << MOTOR_PIN2);
            MOTOR_PORT &= ~(1 << MOTOR_PIN1);
            break;
    }
}
