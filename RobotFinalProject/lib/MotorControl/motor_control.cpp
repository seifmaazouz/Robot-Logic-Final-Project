#include <Arduino.h>
#include "motor_control.h"
#include "pins.h"

void setupMotors() {
    ledcSetup(MOTOR_LEFT_CHANNEL, PWM_FREQ, PWM_RES);
    ledcAttachPin(MOTOR_LEFT_PWM, MOTOR_LEFT_CHANNEL);

    ledcSetup(MOTOR_RIGHT_CHANNEL, PWM_FREQ, PWM_RES);
    ledcAttachPin(MOTOR_RIGHT_PWM, MOTOR_RIGHT_CHANNEL);
    // ledcAttachChannel(MOTOR_LEFT_PWM, PWM_FREQ, PWM_RES, MOTOR_LEFT_CHANNEL);
    // ledcAttachChannel(MOTOR_RIGHT_PWM, PWM_FREQ, PWM_RES, MOTOR_RIGHT_CHANNEL);

    stopMotors();
}

/*** Wheel Direction ***/
// Forward: IN1 = HIGH, IN2 = LOW
// Backward: IN1 = LOW, IN2 = HIGH

void setMotorsSpeed(int leftSpeed, int rightSpeed) {
    ledcWrite(MOTOR_LEFT_CHANNEL, leftSpeed);
    ledcWrite(MOTOR_RIGHT_CHANNEL, rightSpeed);
    // ledcWriteChannel(MOTOR_LEFT_CHANNEL, leftSpeed);
    // ledcWriteChannel(MOTOR_RIGHT_CHANNEL, rightSpeed);
}

void move(int leftSpeed, int rightspeed, Direction direction) {
    int leftDir = LOW, rightDir = LOW;

    switch (direction) {
        case FORWARD:
            leftDir = HIGH;
            rightDir = HIGH;
            break;
        case BACKWARD:
            leftDir = LOW;
            rightDir = LOW;
            break;
        case LEFT:
            leftDir = LOW;
            rightDir = HIGH;
            break;
        case RIGHT:
            leftDir = HIGH;
            rightDir = LOW;
            break;
        case STOP:
            stopMotors();
            return;
    }

    digitalWrite(MOTOR_LEFT_IN1, leftDir);
    digitalWrite(MOTOR_LEFT_IN2, ! leftDir);
    digitalWrite(MOTOR_RIGHT_IN1, ! rightDir);
    digitalWrite(MOTOR_RIGHT_IN2, rightDir);

    setMotorsSpeed(leftSpeed, rightspeed);
}

void stopMotors() {
    setMotorsSpeed(0, 0);
    digitalWrite(MOTOR_LEFT_IN1, LOW);
    digitalWrite(MOTOR_LEFT_IN2, LOW);
    digitalWrite(MOTOR_RIGHT_IN1, LOW);
    digitalWrite(MOTOR_RIGHT_IN2, LOW);
}   
