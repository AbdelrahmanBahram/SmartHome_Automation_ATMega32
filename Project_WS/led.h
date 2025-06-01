/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
typedef enum
{
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LED_ID;

/*typedef enum
{
    POSITIVE_LOGIC,
    NEGATIVE_LOGIC
} LED_LogicType;
*/
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the LED pins.
 */
void LEDS_init(void);

/*
 * Description :
 * Function responsible for turning on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Function responsible for turning off the specified LED.
 */
void LED_off(LED_ID id);


#endif /* LED_H_ */
