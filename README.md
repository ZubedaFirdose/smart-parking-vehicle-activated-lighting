# 🚗 Smart Parking with Automatic Vehicle-Activated Lighting

An Arduino UNO based smart parking system that combines automatic gate control with vehicle-activated LED lighting.

## 📌 Project Overview

This project is a prototype of a smart parking system designed to automate vehicle entry and exit.

When a vehicle is detected at the entrance, the system automatically opens the gate and turns ON the LED lights. After the vehicle passes through the monitored area, the ultrasonic sensor detects the vehicle and the system closes the gate and turns OFF the lights.

## 🔧 Components Used

- Arduino UNO
- IR Sensor
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- 4 LEDs
- 16×2 I2C LCD
- Breadboard
- Resistors
- Jumper Wires

## 🔌 Pin Connections

| Component | Arduino Pin |
|---|---|
| LED 1 | D4 |
| LED 2 | D5 |
| LED 3 | D6 |
| LED 4 | D7 |
| IR Sensor | D8 |
| Ultrasonic Trig | D9 |
| Ultrasonic Echo | D10 |
| Servo Motor | D11 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## ⚙️ Working

1. The IR sensor detects an approaching vehicle.
2. The four LEDs turn ON.
3. The servo motor opens the parking gate.
4. The ultrasonic sensor monitors the vehicle passage.
5. When the vehicle is detected within the defined distance, the servo motor closes the gate.
6. The LEDs turn OFF.
7. The system returns to its initial state.

## 🧠 Programming

The project was programmed using Arduino C/C++.

The code uses:
- Digital input/output
- Ultrasonic distance measurement
- Servo motor control
- I2C LCD communication
- Functions
- Conditional logic

## ✨ Features

- Automatic vehicle detection
- Automatic parking gate control
- Vehicle-activated LED lighting
- Ultrasonic-based vehicle passage detection
- LCD interface
- Arduino-based control

## 🚀 Future Improvements

- Add multiple parking slots
- Display available parking spaces
- Add IoT connectivity
- Add mobile monitoring
- Add automatic parking-slot detection
- Add cloud-based parking data

## 📁 Source Code

The complete Arduino source code is available in [`mini_pro1.ino`](mini_pro1.ino).

## 👩‍💻 Project Type

Arduino | Embedded Systems | IoT | ECE Mini Project
