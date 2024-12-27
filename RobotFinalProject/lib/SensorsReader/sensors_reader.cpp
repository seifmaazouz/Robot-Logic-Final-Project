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
    // // ultrasonicRightDistance = ultrasonicSensorRight.read();
    // ultrasonicFrontDistance = ultrasonicSensorFront.read();
    // delay(50);

    ultrasonicFrontDistance = ultrasonicSensorFront.ping_cm();

    if (ultrasonicFrontDistance > 0) {
        // Valid reading, handle it (e.g., obstacle detected logic)
    } else {
        // No valid reading, handle error case
        ultrasonicFrontDistance = MAX_DISTANCE;
    }

    delay(50);

//        digitalWrite(ULTRASONIC_RIGHT_TRIGGER, LOW);
//    delayMicroseconds(2);
//    digitalWrite(ULTRASONIC_RIGHT_TRIGGER, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(ULTRASONIC_RIGHT_TRIGGER, LOW);
  
//    duration = pulseIn(ULTRASONIC_RIGHT_ECHO, HIGH);
  
//    // Calculate the distance
//    return duration * SOUND_SPEED/2;

//    //  digitalWrite(ULTRASONIC_FRONT_TRIGGER, LOW);
//   //  delayMicroseconds(2);
//   //  digitalWrite(ULTRASONIC_FRONT_TRIGGER, HIGH);
//   //  delayMicroseconds(10);
//   //  digitalWrite(ULTRASONIC_FRONT_TRIGGER, LOW);


}

// Function to read LDR sensor
void readLightSensor() {
    lightSensorReading = digitalRead(LDR_PIN);
}

// Function to read smoke sensor
void readSmokeSensor() {
    smokeSensorReading = analogRead(SMOKE_PIN);
}
