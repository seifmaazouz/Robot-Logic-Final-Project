#ifndef SENSORS_READER_H
#define SENSORS_READER_H

// #include <Ultrasonic.h>
#include <NewPing.h>

void readAllSensors();
void readInfraredSensors();
void readUltrasonicSensors();
void readLightSensor();
void readSmokeSensor();

extern float irSensorLeftReading;
extern float irSensorCenterReading;
extern float irSensorRightReading;
extern float ultrasonicRightDistance;
extern float ultrasonicFrontDistance;
extern float lightSensorReading;
extern float smokeSensorReading;

extern NewPing ultrasonicSensorFront;
extern NewPing ultrasonicSensorRight;
// extern Ultrasonic ultrasonicSensorFront;
// extern Ultrasonic ultrasonicSensorRight;

#endif
