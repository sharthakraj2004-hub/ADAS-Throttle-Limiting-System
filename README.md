# ADAS-Inspired Obstacle-Aware Throttle Limiting System

## Overview

This project implements an ADAS-inspired throttle control prototype using Arduino Uno. The system monitors the distance to obstacles using an HC-SR04 ultrasonic sensor and dynamically limits throttle output to improve safety during close-range operation.

## Hardware Components

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Servo Motor
* Potentiometer
* LEDs (4)
* Resistors
* Jumper Wires

## Features

* Real-time obstacle detection
* Potentiometer-based throttle input
* Servo-based throttle actuation
* Multi-level throttle limiting
* Four-level warning indication

## Safety Logic

| Distance | Condition | Throttle Output |
| -------- | --------- | --------------- |
| > 30 cm  | Safe      | 100%            |
| 20-30 cm | Caution   | 50%             |
| 10-20 cm | Warning   | 33%             |
| < 10 cm  | Emergency | 25%             |

## Working Principle

The potentiometer simulates driver throttle input. The ultrasonic sensor continuously measures obstacle distance. Based on predefined thresholds, the controller limits the requested throttle command and actuates a servo motor accordingly.

## Technologies Used

* Embedded C
* Arduino IDE
* PWM Servo Control
* Ultrasonic Distance Measurement

## Author

Sharthak Raj
