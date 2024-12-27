#include <Arduino.h>
#include "motor_control.h"
#include "pins.h"

void setupMotors() {
    ledcSetup(MOTOR_LEFT_CHANNEL, PWM_FREQ, PWM_RES);
    ledcAttachPin(MOTOR_LEFT_PWM, MOTOR_LEFT_CHANNEL);

    ledcSetup(MOTOR_RIGHT_CHANNEL, PWM_FREQ, PWM_RES);
    ledcAttachPin(MOTOR_RIGHT_PWM, MOTOR_RIGHT_CHANNEL);

    stop();
}

/*** Wheel Direction ***/
// Forward: IN1 = HIGH, IN2 = LOW
// Backward: IN1 = LOW, IN2 = HIGH

void setMotorsSpeed(int leftSpeed, int rightSpeed) {
    ledcWrite(MOTOR_LEFT_CHANNEL, leftSpeed);
    ledcWrite(MOTOR_RIGHT_CHANNEL, rightSpeed);
}

void move(int speed, Direction direction) {
    switch (direction) {
        case FORWARD:
            moveForward();
            break;
        case BACKWARD:
            moveBackward();
            break;
        case LEFT:
            turnLeft();
            break;
        case RIGHT:
            turnRight();
            break;
        default:
            stop();
            break;
    }
    setMotorsSpeed(speed, speed);
}

void moveWheels (bool left_dir, int left_pwm, bool right_dir, int right_pwm) {
    digitalWrite(MOTOR_LEFT_IN1, left_dir);
    digitalWrite(MOTOR_LEFT_IN2, ! left_dir);
    
    digitalWrite(MOTOR_RIGHT_IN1, right_dir);
    digitalWrite(MOTOR_RIGHT_IN2, ! right_dir);

    setMotorsSpeed(left_pwm, right_pwm);
}

// Both wheels move forward
void moveForward() {
    digitalWrite(MOTOR_LEFT_IN1, HIGH);
    digitalWrite(MOTOR_LEFT_IN2, LOW);
    digitalWrite(MOTOR_RIGHT_IN1, HIGH);
    digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

// Both wheels move backward
void moveBackward() {
    digitalWrite(MOTOR_LEFT_IN1, LOW);
    digitalWrite(MOTOR_LEFT_IN2, HIGH);
    digitalWrite(MOTOR_RIGHT_IN1, LOW);
    digitalWrite(MOTOR_RIGHT_IN2, HIGH);
}

// Left wheel move backward, right wheel move forward
void turnLeft() {
    digitalWrite(MOTOR_LEFT_IN1, LOW);
    digitalWrite(MOTOR_LEFT_IN2, HIGH);
    digitalWrite(MOTOR_RIGHT_IN1, HIGH);
    digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

// Left wheel move forward, right wheel move backward
void turnRight() {
    digitalWrite(MOTOR_LEFT_IN1, HIGH);
    digitalWrite(MOTOR_LEFT_IN2, LOW);
    digitalWrite(MOTOR_RIGHT_IN1, LOW);
    digitalWrite(MOTOR_RIGHT_IN2, HIGH);
}

void stop() {
    setMotorsSpeed(0, 0);

    digitalWrite(MOTOR_LEFT_IN1, LOW);
    digitalWrite(MOTOR_LEFT_IN2, LOW);
    digitalWrite(MOTOR_RIGHT_IN1, LOW);
    digitalWrite(MOTOR_RIGHT_IN2, LOW);
}   
