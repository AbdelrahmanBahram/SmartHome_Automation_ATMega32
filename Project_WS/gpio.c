/*
 * gpio.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Administrator
 */

#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"
#include <avr/io.h>
void GPIO_SetupPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDirectionType direction){
	if((port_num>PORT_NUMBERS) || (pin_num>PINS_PER_PORT)){
		//do nothing
	}
	else{
		switch(port_num){
		case PORTA_ID:
			if(direction==PIN_INPUT){
				CLEAR_BIT(DDRA,pin_num);
			}
			else{
				SET_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction==PIN_INPUT){
				CLEAR_BIT(DDRB,pin_num);
			}
			else{
				SET_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction==PIN_INPUT){
				CLEAR_BIT(DDRC,pin_num);
			}
			else{
				SET_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction==PIN_INPUT){
				CLEAR_BIT(DDRD,pin_num);
			}
			else{
				SET_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}
void GPIO_SetupPortDirection(uint8 port_num, GPIO_PortDirectionType direction){
	if(port_num > PORT_NUMBERS){
		//do nothing
	}
	else{
		switch(port_num){
		case PORTA_ID:
			if(direction==PORT_INPUT){
				DDRA=direction;
			}
			else{
				DDRA=direction;
			}
			break;
		case PORTB_ID:
			if(direction==PORT_INPUT){
				DDRB=direction;
			}
			else{
				DDRB=direction;
			}
			break;
		case PORTC_ID:
			if(direction==PORT_INPUT){
				DDRC=direction;
			}
			else{
				DDRC=direction;
			}
			break;
		case PORTD_ID:
			if(direction==PORT_INPUT){
				DDRD=direction;
			}
			else{
				DDRD=direction;
			}
			break;
		}
	}
}
void GPIO_WritePin(uint8 port_num,uint8 pin_num,uint8 value){

	if(port_num > PORT_NUMBERS){
		//do nothing
	}
	else{
		switch(port_num){
		case PORTA_ID:
			if(value==LOGIC_LOW){
				CLEAR_BIT(PORTA,pin_num);
			}
			else{
				SET_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value==LOGIC_LOW){
				CLEAR_BIT(PORTB,pin_num);
			}
			else{
				SET_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value==LOGIC_LOW){
				CLEAR_BIT(PORTC,pin_num);
			}
			else{
				SET_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value==LOGIC_LOW){
				CLEAR_BIT(PORTD,pin_num);
			}
			else{
				SET_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}
void GPIO_WritePort(uint8 port_num,uint8 value){
	if(port_num > PORT_NUMBERS){
			//do nothing
		}
		else{
			switch(port_num){
			case PORTA_ID:
						PORTA = value;
						break;
					case PORTB_ID:
						PORTB = value;
						break;
					case PORTC_ID:
						PORTC = value;
						break;
					case PORTD_ID:
						PORTD = value;
						break;
			}
		}
}
uint8 GPIO_ReadPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	if((pin_num >= PINS_PER_PORT) || (port_num >= PORT_NUMBERS))
	{
		/* Do Nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}

	return pin_value;
}
uint8 GPIO_ReadPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;


	if(port_num >= PORT_NUMBERS)
	{
		/* Do Nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		}
	}

	return value;
}
