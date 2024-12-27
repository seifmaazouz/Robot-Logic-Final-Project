#ifndef SETUP_CONFIG_H
#define SETUP_CONFIG_H

#include "BluetoothSerial.h"

#define device_name "ESP32_ZWAS"
#define default_left_PWM 220
#define default_right_PWM 220
#define smoke_thresh 2050
#define MAX_DISTANCE 15

extern BluetoothSerial SerialBT;
extern String rec;

void initPins();
void calibrateIRSensors();
void setupBluetooth();

#endif
