#include <Arduino.h>
#include "line_follower.h"
#include "pins.h"
#include "motor_control.h"
#include "sensors_reader.h"

void followLine() {
    readInfraredSensors();
    
    
}

void avoidObstacle() {
    // TODO
}   