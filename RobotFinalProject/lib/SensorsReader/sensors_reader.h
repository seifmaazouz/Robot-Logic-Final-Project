#ifndef SENSORS_READER_H
#define SENSORS_READER_H

void readAllSensors();
void readInfraredSensors();
void readUltrasonicSensors();
void readLightSensor();
void readSmokeSensor();

int irSensorLeftReading = 0;
int irSensorCenterReading = 0;
int irSensorRightReading = 0;

int ultrasonicRightDistance = 0;
int ultrasonicFrontDistance = 0;

int lightSensorReading = 0;
int smokeSensorReading = 0;

#endif
