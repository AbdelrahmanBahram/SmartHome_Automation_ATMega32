/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Administrator
 */
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "ldr.h"
#include "adc.h"
#include "lcd.h"
#include "pwm.h"
#include "motor.h"
#include "flame.h"
void LED_CONTROL(uint16 light_percentage){
	if(light_percentage<=15){
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_on(BLUE_LED);
	}
	else if(light_percentage>15 && light_percentage<=50){
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_off(BLUE_LED);
	}
	else if(light_percentage>50 && light_percentage<=70){
		LED_on(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
	else{
		LED_off(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
}
void LDR_SetPin(void){
	DDRA &= ~(1 << 0);

}
void flame_mode(void){
	LCD_clearScreen();
	while(FlameSensor_getValue()==0){
		Buzzer_on();
		LCD_moveCursor(0,3);
		LCD_displayString("ALERT !!!!! ");
		LCD_moveCursor(1,0);
		LCD_displayString("FIRE DETECTED!!!");
	}
	Buzzer_off();
	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString("   Fan is ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp=   ");
	LCD_moveCursor(1,8);
	LCD_displayString("LDR=   %");
}

int main(void)
{
	uint16 light_percentage;
	uint8 temp;
	uint8 fan_state=0;
	LDR_SetPin();
	FlameSensor_init();
	LCD_init();
	ADC_init();
	DcMotor_Init();
	Buzzer_init();
	LCD_moveCursor(0,0);
	LCD_displayString("   Fan is ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp=   ");
	LCD_moveCursor(1,8);
	LCD_displayString("LDR=   %");
	while(1){
		if(FlameSensor_getValue()==0){
			flame_mode();
		}
		light_percentage = LDR_getLightIntensity();
		temp=LM35_getTemperature();
		LED_CONTROL(light_percentage);
		LCD_moveCursor(0,10);
		if(fan_state==0){
			LCD_displayString("OFF  ");
		}
		if(fan_state==1){
			LCD_displayString("ON   ");
		}
		LCD_moveCursor(1,12);
		if(light_percentage >= 100)
		{
			LCD_intgerToString(light_percentage);
		}
		else
		{
			LCD_intgerToString(light_percentage);
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(1,5);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
		if (temp >= 40.0) {
			DcMotor_Rotate(CLOCKWISE, 100);
			fan_state=1;
		} else if (temp >= 35.0 && temp < 40.0) {
			DcMotor_Rotate(CLOCKWISE, 75);
			fan_state=1;
		} else if (temp >= 30.0 && temp < 35.0) {
			DcMotor_Rotate(CLOCKWISE, 50);
			fan_state=1;
		} else if (temp >= 25.0 && temp < 30.0) {
			DcMotor_Rotate(CLOCKWISE, 25);
			fan_state=1;
		} else {
			DcMotor_Rotate(STOP, 0);
			fan_state=0;
		}
	}
}
