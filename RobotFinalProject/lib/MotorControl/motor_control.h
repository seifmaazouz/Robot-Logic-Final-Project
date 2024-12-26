#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>
#include "setup_config.h"
#include "pins.h"

enum Direction {
    STOP = 0,
    FORWARD = 1,
    BACKWARD = 2,
    LEFT = 3,
    RIGHT = 4
};

void setMotorSpeed(int leftSpeed, int rightSpeed);
void move(Direction direction);
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stop();

#endif
