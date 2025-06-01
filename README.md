# Smart Home Automation using ATmega32

This project implements a Smart Home Automation system using the ATmega32 microcontroller, designed to control lighting, fan speed, and provide safety alerts based on environmental conditions. It includes sensors like LM35 (temperature), LDR (light), and a flame sensor, with real-time status display on an LCD and feedback via LEDs, buzzer, and a motor-controlled fan.

##  Objectives

- Automatically control lighting using an LDR and RGB LEDs
- Adjust fan speed proportionally to temperature using PWM
- Detect fire and trigger critical alerts using a flame sensor and buzzer
- Display all system statuses in real-time on a 16x2 LCD

##  Key Features

###  Lighting Control (via LDR)
- **< 15%** light → Red, Green, Blue LEDs ON  
- **16–50%** light → Red, Green LEDs ON  
- **51–70%** light → Red LED ON  
- **> 70%** light → All LEDs OFF  

###  Temperature-Based Fan Control (via LM35)
- **≥ 40°C** → Fan @ 100% speed  
- **35–39°C** → Fan @ 75%  
- **30–34°C** → Fan @ 50%  
- **25–29°C** → Fan @ 25%  
- **< 25°C** → Fan OFF  

###  Fire Detection
- Flame sensor triggers LCD alert **"Critical alert!"**
- Buzzer is activated
- System remains in alert mode until fire is cleared

###  LCD Display
- **Line 1:** `"FAN is ON"` or `"FAN is OFF"`
- **Line 2:** `"Temp=xx°C LDR=xxx%"`

##  Hardware Components

- **Microcontroller**: ATmega32 (16 MHz)
- **Sensors**: 
  - LM35 (Temperature) → PA1 / ADC1
  - LDR (Light) → PA0 / ADC0
  - Flame Sensor → PD2
- **Display**: 16x2 LCD (8-bit mode)
  - RS: PD0, Enable: PD1, R/W: GND, Data: PORTC
- **Fan (DC Motor)**: Controlled via H-bridge
  - IN1: PB0, IN2: PB1, EN: PB3/OC0
- **LEDs**: 
  - Red: PB5, Green: PB6, Blue: PB7
- **Buzzer**: PD3

##  Architecture

The system is built using a layered driver-based architecture:
- **ADC Driver** – Reads LM35 and LDR
- **PWM Driver** – Controls motor speed via Timer0 (OC0)
- **LCD Driver** – Displays real-time values
- **DC Motor Driver** – Starts/stops fan with speed control
- **LED Driver** – Controls RGB LEDs based on LDR values
- **Flame Sensor Driver** – Monitors for fire
- **Buzzer Driver** – Alerts on flame detection
- **GPIO Driver** – Core for all pin setups

