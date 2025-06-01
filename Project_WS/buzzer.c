/*
 * buzzer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Administrator
 */
#include "buzzer.h"

// Function to initialize the buzzer
void Buzzer_init(void) {
    // Set buzzer pin as output
    BUZZER_DDR |= (1 << BUZZER_PIN);  // Set PD3 as output
    Buzzer_off();                // Ensure buzzer is off initially
}

// Function to activate the buzzer
void Buzzer_on(void) {
    BUZZER_PORT |= (1 << BUZZER_PIN);  // Set PD3 high to turn on buzzer
}

// Function to deactivate the buzzer
void Buzzer_off(void) {
    BUZZER_PORT &= ~(1 << BUZZER_PIN); // Set PD3 low to turn off buzzer
}

