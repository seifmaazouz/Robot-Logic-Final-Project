#include <Arduino.h>
#include "sensors_reader.h"
#include "pins.h"
#include "setup_config.h"

float ultrasonicRightDistance = 0.0;
float ultrasonicFrontDistance = 0.0;
float irSensorLeftReading = 0.0;
float irSensorCenterReading = 0.0;
float irSensorRightReading = 0.0;
float lightSensorReading = 0.0;
float smokeSensorReading = 0.0;

// Ultrasonic ultrasonicSensorRight(ULTRASONIC_RIGHT_TRIGGER, ULTRASONIC_RIGHT_ECHO);
// Ultrasonic ultrasonicSensorFront(ULTRASONIC_FRONT_TRIGGER, ULTRASONIC_FRONT_ECHO);
NewPing ultrasonicSensorFront(ULTRASONIC_FRONT_TRIGGER, ULTRASONIC_FRONT_ECHO, MAX_DISTANCE);
NewPing ultrasonicSensorRight(ULTRASONIC_RIGHT_TRIGGER, ULTRASONIC_RIGHT_ECHO, MAX_DISTANCE);

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

unsigned long lastReadTime = 0;
unsigned long readInterval = 50;

void readUltrasonicSensors() {
    ultrasonicFrontDistance = ultrasonicSensorFront.ping_cm();
    // ultrasonicRightDistance = ultrasonicSensorRight.ping_cm();

    if (ultrasonicFrontDistance <= 0) {
        ultrasonicFrontDistance = MAX_DISTANCE;
    }

    // if(ultrasonicRightDistance <= 0) {
    //     ultrasonicRightDistance = MAX_DISTANCE;
    // }

    delay(50);
}

// Function to read LDR sensor
void readLightSensor() {
    lightSensorReading = digitalRead(LDR_PIN);
}

// Function to read smoke sensor
void readSmokeSensor() {
    smokeSensorReading = analogRead(SMOKE_PIN);
}
