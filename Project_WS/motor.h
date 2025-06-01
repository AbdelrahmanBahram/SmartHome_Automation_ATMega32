/*
 * motor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include <avr/io.h>
#define MOTOR_PORT   PORTB
#define MOTOR_DDR    DDRB
#define MOTOR_PIN1   PB0
#define MOTOR_PIN2   PB1
#define MOTOR_ENABLE PB3
// Enum for motor states
typedef enum {
    STOP,
    CLOCKWISE,
    ANTICLOCKWISE
} DcMotor_State;

// Function to initialize the DC motor
void DcMotor_Init(void);

// Function to control the motor's state and speed
void DcMotor_Rotate(DcMotor_State state, uint8_t speed);


#endif /* MOTOR_H_ */
