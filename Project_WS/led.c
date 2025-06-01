/*
 * led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */
#include "led.h"
#include "gpio.h"

/*******************************************************************************
 *                      Static Variables                                       *
 *******************************************************************************/
//static LED_LogicType g_ledLogicType;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LEDS_init(void)
{
    /* Set the LED logic type */
    //g_ledLogicType = logic;

    /* Initialize LED pins as output */
    GPIO_SetupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
    GPIO_SetupPinDirection(PORTB_ID, PIN6_ID, PIN_OUTPUT);
    GPIO_SetupPinDirection(PORTB_ID, PIN7_ID, PIN_OUTPUT);

    /* Turn off all LEDs initially */
    LED_on(RED_LED);
    LED_on(GREEN_LED);
    LED_on(BLUE_LED);
}

void LED_on(LED_ID id)
{
    switch(id)
    {
    case RED_LED:
        GPIO_WritePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
        break;
    case GREEN_LED:
        GPIO_WritePin(PORTB_ID, PIN6_ID, LOGIC_HIGH);
        break;
    case BLUE_LED:
        GPIO_WritePin(PORTB_ID, PIN7_ID, LOGIC_HIGH);
        break;
    }
}

void LED_off(LED_ID id)
{
    switch(id)
    {
    case RED_LED:
        GPIO_WritePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
        break;
    case GREEN_LED:
        GPIO_WritePin(PORTB_ID, PIN6_ID, LOGIC_LOW);
        break;
    case BLUE_LED:
        GPIO_WritePin(PORTB_ID, PIN7_ID, LOGIC_LOW);
        break;
    }
}

