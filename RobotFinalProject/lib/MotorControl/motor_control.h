#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#define PWM_FREQ 5000
#define PWM_RES 8

enum Direction {
    STOP = 0,
    FORWARD = 1,
    BACKWARD = 2,
    LEFT = 3,
    RIGHT = 4
};

void setupMotors();
void setMotorsSpeed(int leftSpeed, int rightSpeed);
void move(int leftSpeed, int rightspeed, Direction direction);
void stopMotors();

#endif
