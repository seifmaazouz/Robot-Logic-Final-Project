#include <Arduino.h>
#include "setup_config.h"
#include "pins.h"

void initPins() {
    // Motor pin configuration
    pinMode(MOTOR_LEFT_PWM, OUTPUT);
    pinMode(MOTOR_LEFT_IN1, OUTPUT);
    pinMode(MOTOR_LEFT_IN2, OUTPUT);

    pinMode(MOTOR_RIGHT_PWM, OUTPUT);
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

    // Configure Other Components (LDR, LED, BUZZER, SMOKE)
    pinMode(LDR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SMOKE_PIN, INPUT);
}
