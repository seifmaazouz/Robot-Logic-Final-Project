#ifndef SENSORS_READER_H
#define SENSORS_READER_H

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

#endif
