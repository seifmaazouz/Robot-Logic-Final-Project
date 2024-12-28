#ifndef SETUP_CONFIG_H
#define SETUP_CONFIG_H

#include "BluetoothSerial.h"

#define device_name "ESP32_ZWAS"
#define default_left_PWM 210
#define default_right_PWM 210
#define default_left_lt_PWM 210
#define default_right_lt_PWM 210
#define smoke_thresh 2050
#define MAX_DISTANCE 15
// extern int black_thresh_left;
// extern int black_thresh_center;
// extern int black_thresh_right;
#define black_thresh_left 1000
#define black_thresh_center 1000
#define black_thresh_right 1000

#define BUZZER_CHANNEL 2
#define PWM_FREQ 5000
#define PWM_RES 8
#define BUZZER_DURATION 500

extern BluetoothSerial SerialBT;
extern String rec;

void initPins();
void calibrateIRSensors();
void setupBluetooth();

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#endif
