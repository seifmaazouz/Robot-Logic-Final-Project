# Final Logic II Project: Autonomous Robot with 6 Distinct Functions

## Project Overview
This project is a final project for the **Logic II** course at **Alexandria University, Faculty of Engineering, Computer and Communication Engineering, Term 5**. The goal is to design and implement an autonomous robot that can perform six distinct functions. The robot is designed and developed by a team of four students: 


- **Seifeldin Ahmed**
- **Ahmad Wael**
- **Ahmad Zaki**
- **Asser Hanafy**

The robot is equipped with various sensors and actuators to enable it to perform tasks autonomously.

## Robot Functions
The robot has the following six core functions:

1. **Line Following**  
   The robot can follow a black line on a white surface using infrared (IR) sensors.

2. **Obstacle Avoidance**  
   It uses ultrasonic sensors to detect obstacles in its path and can avoid them by changing direction.

3. **Line Following**  
   It is equipped with a Light Dependent Resistor (LDR) to follow a line.

4. **Smoke Detection and Alert**  
   The robot can detect smoke in the environment and will trigger an alert (e.g., buzzer or LED).

4. **Remote Control via Bluetooth**  
   The robot can be controlled remotely via Bluetooth for manual operation.

6. **Insert 6th Function Here (Obstacle Detection?)**  
   TBD.

## Hardware
The robot is built using the following components:

- **ESP32** development board (for main control and processing)
- **Motors** (DC motors with encoders)
- **IR Sensors** (for line following)
- **Ultrasonic Sensors** (for obstacle detection)
- **LDR (Light Dependent Resistor)** (for light following)
- **Smoke Sensor** (for smoke detection)
- **Bluetooth Module** (for remote control)
- **Buzzer/LED** (for alerting)

## Software
The robot's software is developed using the **Arduino IDE** and the **PlatformIO** framework, leveraging the ESP32 for its Wi-Fi and Bluetooth capabilities.

- **Arduino Framework** for controlling motors, sensors, and communication.
- **PID Control Algorithms** for smooth and accurate motor control. # Check if included TBD
- **Ultrasonic and IR sensor integration** for environment interaction.
