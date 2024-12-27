#include <Arduino.h>
#include "sensors_reader.h"
#include "pins.h"
#include <Ultrasonic.h>

// Function to read all sensors
void readAllSensors() {
    readInfraredSensors();
    readUltrasonicSensors();
    readLightSensor();
    readSmokeSensor();
}

// Function to read IR sensors
void readInfraredSensors() {
    irSensorLeftReading = digitalRead(IR_SENSOR_LEFT);
    irSensorCenterReading = digitalRead(IR_SENSOR_CENTER);
    irSensorRightReading = digitalRead(IR_SENSOR_RIGHT);
}

// Function to read ultrasonic sensors
void readUltrasonicSensors() {
    Ultrasonic ultrasonicSensorRight(ULTRASONIC_RIGHT_TRIGGER, ULTRASONIC_RIGHT_ECHO);
    Ultrasonic ultrasonicSensorFront(ULTRASONIC_FRONT_TRIGGER, ULTRASONIC_FRONT_ECHO);
    
    ultrasonicRightDistance = ultrasonicSensorRight.read();
    ultrasonicFrontDistance = ultrasonicSensorFront.read();
}

// Function to read LDR sensor
void readLightSensor() {
    lightSensorReading = digitalRead(LDR_PIN);
}

// Function to read smoke sensor
void readSmokeSensor() {
    smokeSensorReading = digitalRead(SMOKE_PIN);
}
