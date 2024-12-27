#include <Arduino.h>
#include "sensors_reader.h"
#include "pins.h"
#include <Ultrasonic.h>

float ultrasonicRightDistance = 0.0;
float ultrasonicFrontDistance = 0.0;
float irSensorLeftReading = 0.0;
float irSensorCenterReading = 0.0;
float irSensorRightReading = 0.0;
float lightSensorReading = 0.0;
float smokeSensorReading = 0.0;

// Ultrasonic ultrasonicSensorRight(ULTRASONIC_RIGHT_TRIGGER, ULTRASONIC_RIGHT_ECHO);
Ultrasonic ultrasonicSensorFront(ULTRASONIC_FRONT_TRIGGER, ULTRASONIC_FRONT_ECHO);

// Function to read all sensors
void readAllSensors() {
    readInfraredSensors();
    readUltrasonicSensors();
    readLightSensor();
    readSmokeSensor();
}

// Function to read IR sensors
void readInfraredSensors() {
    irSensorLeftReading = analogRead(IR_SENSOR_LEFT);
    irSensorCenterReading = analogRead(IR_SENSOR_CENTER);
    irSensorRightReading = analogRead(IR_SENSOR_RIGHT);
}



void readUltrasonicSensors() {
    // ultrasonicRightDistance = ultrasonicSensorRight.read();
    ultrasonicFrontDistance = ultrasonicSensorFront.read();
}

// Function to read LDR sensor
void readLightSensor() {
    lightSensorReading = digitalRead(LDR_PIN);
}

// Function to read smoke sensor
void readSmokeSensor() {
    smokeSensorReading = analogRead(SMOKE_PIN);
}
