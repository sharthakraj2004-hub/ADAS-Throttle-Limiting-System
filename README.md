# ADAS-Inspired Obstacle-Aware Throttle Limiting System

## Overview

This project implements an ADAS-inspired electronic throttle control prototype using an Arduino Uno. The system continuously monitors obstacle distance using an HC-SR04 ultrasonic sensor and dynamically limits throttle output to improve operational safety. A potentiometer is used to emulate driver throttle input, while a servo motor acts as the electronic throttle actuator.

## Hardware Components

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Servo Motor
* Potentiometer
* 4 LEDs
* 220Ω Resistors
* Breadboard and Jumper Wires

## Features

* Real-time obstacle detection
* Potentiometer-based throttle input
* Servo-based throttle actuation
* Multi-level throttle limiting logic
* Four-level visual warning system
* Serial monitor diagnostics

## System Logic

| Distance Range | Condition | Throttle Output |
| -------------- | --------- | --------------- |
| > 30 cm        | Safe      | 100%            |
| 20 – 30 cm     | Caution   | 50%             |
| 10 – 20 cm     | Warning   | 33%             |
| < 10 cm        | Emergency | 25%             |

## Circuit Connections

| Component            | Arduino Pin |
| -------------------- | ----------- |
| HC-SR04 TRIG         | D9          |
| HC-SR04 ECHO         | D10         |
| Potentiometer Output | A0          |
| Servo Signal         | D13         |
| LED1                 | D2          |
| LED2                 | D3          |
| LED3                 | D4          |
| LED4                 | D5          |

## Manual Pin Mapping

Arduino Uno
A0  ← Potentiometer Output

D2  → LED1 (Safe)
D3  → LED2 (Caution)
D4  → LED3 (Warning)
D5  → LED4 (Emergency)

D9  → HC-SR04 TRIG
D10 ← HC-SR04 ECHO

D13 → Servo Signal

5V  → Potentiometer VCC
5V  → HC-SR04 VCC
5V  → Servo VCC

GND → Potentiometer GND
GND → HC-SR04 GND
GND → Servo GND
GND → All LED Resistors

## Working Principle

1. The potentiometer simulates driver throttle demand.
2. The HC-SR04 sensor continuously measures obstacle distance.
3. The Arduino evaluates the distance and selects an appropriate safety level.
4. The requested throttle value is reduced according to predefined safety thresholds.
5. The servo motor represents the electronic throttle actuator.
6. LEDs indicate Safe, Caution, Warning, and Emergency conditions.

## Technologies Used

* Embedded C
* Arduino IDE
* PWM Servo Control
* Ultrasonic Distance Measurement
* Real-Time Embedded Systems

## Author

Sharthak Raj
