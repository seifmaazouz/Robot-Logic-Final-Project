# Final Logic II Project: Autonomous Robot with 6 Distinct Functions

## Project Overview
This project is the final submission for the **Logic II** course at **Alexandria University, Faculty of Engineering, Computer and Communication Engineering, Term 5**. The aim is to design and develop an autonomous robot capable of performing six distinct functions. The robot was collaboratively designed and implemented by the following team members:

- **Seifeldin Ahmed**  
- **Ahmad Wael**  
- **Ahmad Zaki**  
- **Asser Hanafy**

The robot utilizes a variety of sensors and actuators to operate autonomously, supported by a custom-designed app for manual control and mode selection.

## Robot Features
The robot is equipped with the following six core functionalities:

1. **Manual Mode (Bluetooth App Control)**  
   The robot can be controlled manually using a custom-built Bluetooth app developed with MIT App Inventor. The app also enables switching between operation modes.

2. **Mode Selection (App-Enabled)**  
   Users can choose between **Line Following Mode** or **Maze Solving Mode** directly through the Bluetooth app.

3. **Line Following**  
   Infrared (IR) sensors enable the robot to follow a black line on a white surface with precision.

4. **Smoke Detection and Alert**  
   A smoke sensor allows the robot to detect smoke in its environment and trigger an alert using a buzzer or LED.

5. **Obstacle Detection and Avoidance**  
   Ultrasonic sensors help the robot identify obstacles and navigate around them.

6. **Light Detection**  
   The robot uses a Light Dependent Resistor (LDR) to detect and respond to light intensity variations.

## Contributions
Each team member contributed to different aspects of the project:

- **Seifeldin Ahmed & Ahmad Zaki**  
   Software programming of the robot, using **PlatformIO** for coding and debugging the ESP32.

- **Ahmad Wael**  
   Hardware development, including designing a custom PCB using **Eagle**.

- **Asser Hanafy**  
   Created the Bluetooth control app using **MIT App Inventor**, enabling manual control and mode selection.

## Hardware
The robot incorporates the following components:

- **ESP32** (Main control and processing unit)  
- **DC Motors** (with encoders for precise movement)  
- **IR Sensors** (for line following)  
- **Ultrasonic Sensors** (for obstacle detection)  
- **LDR (Light Dependent Resistor)** (for light intensity detection)  
- **Smoke Sensor** (for environmental safety alerts)  
- **Bluetooth Module** (for wireless communication with the app)  
- **Buzzer/LED** (for alert notifications)  

## Software
The robot’s software was developed using:

- **PlatformIO** and the **Arduino Framework**  
  Integrated for smooth control of motors, sensors, and communication with peripherals.  

- **Sensor Integration**  
  Ultrasonic and IR sensors work together to enable autonomous navigation and obstacle avoidance.

## Challenges and Future Improvements
- **Maze Solver Feature**: While initial attempts were made to implement maze-solving functionality, it remains incomplete. Future work can focus on refining this feature for a fully autonomous solution.

- **PID Controller for Line Following**: Implementing a PID control algorithm would improve the robot's ability to follow a line accurately by dynamically adjusting motor speeds based on real-time sensor feedback, ensuring smoother turns and reducing errors.

- **IR Sensor Calibration**: Fine-tuning the IR sensors for line-following to improve detection accuracy and ensure reliable performance under varying lighting conditions. 

## How to Use
1. **Manual Mode**: Use the Bluetooth app to control the robot's movement directly.  
2. **Mode Selection**: Select between **Line Following Mode** and **Maze Solving Mode** using the app.  
3. **Line Following**: Place the robot on a surface with a black line, and it will follow the path.  
4. **Smoke Detection**: The robot will alert you if it detects smoke in its surroundings.  
5. **Obstacle Avoidance**: The robot can navigate around obstacles without manual intervention.  
6. **Light Detection**: The robot responds to light intensity changes using its LDR sensor.  
