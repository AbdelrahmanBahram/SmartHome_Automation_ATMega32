/*
 * ldr.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */
#include "ldr.h"
#include "adc.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

uint16 LDR_getLightIntensity(void)
{
	/* Read the ADC value from the LDR sensor channel */
	uint16 adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Convert the ADC value to the corresponding voltage */
	float voltage = (adc_value * ADC_REF_VOLT_VALUE) / ADC_MAXIMUM_VALUE;

	/* Map the voltage to the light intensity percentage */
	uint16 light_intensity = (voltage * LDR_SENSOR_MAX_LIGHT_INTENSITY) / LDR_SENSOR_MAX_VOLT_VALUE;

	return light_intensity;
}

