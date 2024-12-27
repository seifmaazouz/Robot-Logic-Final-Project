#include <Arduino.h>
#include "setup_config.h"
#include "pins.h"

BluetoothSerial SerialBT;
String rec;

void initPins() {
    // Motor pin configuration
    pinMode(MOTOR_LEFT_IN1, OUTPUT);
    pinMode(MOTOR_LEFT_IN2, OUTPUT);

    pinMode(MOTOR_RIGHT_IN1, OUTPUT);
    pinMode(MOTOR_RIGHT_IN2, OUTPUT);

    // IR Sensor pin configuration
    pinMode(IR_SENSOR_LEFT, INPUT);
    pinMode(IR_SENSOR_CENTER, INPUT);
    pinMode(IR_SENSOR_RIGHT, INPUT);

    // Ultrasonic Sensor pin configuration
    pinMode(ULTRASONIC_RIGHT_TRIGGER, OUTPUT);
    pinMode(ULTRASONIC_RIGHT_ECHO, INPUT);

    pinMode(ULTRASONIC_FRONT_TRIGGER, OUTPUT);
    pinMode(ULTRASONIC_FRONT_ECHO, INPUT);

    // Configure Other Components (LDR, BUZZER, SMOKE)
    pinMode(LDR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SMOKE_PIN, INPUT);

    analogReadResolution(12);
}

void calibrateIRSensors() {
    // TODO
}

void setupBluetooth() {
        // Check if Bluetooth is available
    #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
    #error Bluetooth is not enabled! Please run make menuconfig to and enable it
    #endif

    // Check Serial Port Profile
    #if !defined(CONFIG_BT_SPP_ENABLED)
    #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
    #endif

    SerialBT.begin(device_name);
}
