/*
 * gpio.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Administrator
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "std_types.h"
#define PORT_NUMBERS 4
#define PINS_PER_PORT 8

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;


void GPIO_SetupPinDirection(uint8 port_num,uint8 pin_num, GPIO_PinDirectionType direction);
void GPIO_SetupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);
void GPIO_WritePin(uint8 port_num,uint8 pin_num, uint8 value);
void GPIO_WritePort(uint8 port_num,uint8 value);
uint8 GPIO_ReadPin(uint8 port_num,uint8 pin_num);
uint8 GPIO_ReadPort(uint8 port_num);

#endif /* GPIO_H_ */
