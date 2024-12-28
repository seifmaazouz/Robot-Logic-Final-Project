#include <Arduino.h>
#include "setup_config.h"
#include "pins.h"
// #include "sensors_reader.h"

BluetoothSerial SerialBT;
String rec;
// int black_thresh_left = 1000;
// int black_thresh_center = 1000;
// int black_thresh_right = 1000;

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
    ledcSetup(BUZZER_CHANNEL, PWM_FREQ, PWM_RES);
    ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);

    analogReadResolution(12);
}

// void calibrateIRSensors() {
//     int minLeft = 1023, maxLeft = 0;
//     int minRight = 1023, maxRight = 0;
//     int minCenter = 1023, maxCenter = 0;

//     Serial.println("Calibrating sensors... Move the robot over the line and press any key to stop.");
//     while (!Serial.available()) {
//         readInfraredSensors();

//         // Track min and max values for each sensor
//         minLeft = min(minLeft, irSensorLeftReading);
//         maxLeft = max(maxLeft, irSensorLeftReading);
        
//         minRight = min(minRight, irSensorRightReading);
//         maxRight = max(maxRight, irSensorRightReading);
        
//         minCenter = min(minCenter, irSensorCenterReading);
//         maxCenter = max(maxCenter, irSensorCenterReading);
//     }

//     // Calculate thresholds as midpoints
//     black_thresh_left = (minLeft + maxLeft) / 2;
//     black_thresh_right = (minRight + maxRight) / 2;
//     black_thresh_center = (minCenter + maxCenter) / 2;

//     Serial.println("Calibration complete!");
//     Serial.print("Left Threshold: "); Serial.println(black_thresh_left);
//     Serial.print("Right Threshold: "); Serial.println(black_thresh_right);
//     Serial.print("Center Threshold: "); Serial.println(black_thresh_center);

//     Serial.read(); // Clear the input buffer
// }

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
