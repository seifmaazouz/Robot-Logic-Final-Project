#include <Arduino.h>
#include "line_follower.h"
#include "pins.h"
#include "motor_control.h"
#include "sensors_reader.h"
#include "setup_config.h"
void followLine() {
    readAllSensors();

    if (ultrasonicFrontDistance < 10) {
        stopMotors();
        return;
    }

  // > black_thresh --> black line  
  if (irSensorLeftReading > black_thresh && irSensorRightReading > black_thresh && irSensorCenterReading > black_thresh) {
        stopMotors();
  }
  else if (irSensorLeftReading > black_thresh && irSensorRightReading < black_thresh) {
    while (irSensorCenterReading < black_thresh) {
        move(0, default_right_PWM, FORWARD);
        readInfraredSensors();
    }
    if (irSensorCenterReading > black_thresh) {
        move(default_left_PWM, default_right_PWM, LEFT);
    }
  }
  else if (irSensorLeftReading < black_thresh && irSensorRightReading > black_thresh) {
    while (irSensorCenterReading < black_thresh) {
        move(default_left_PWM, 0, FORWARD);
        readInfraredSensors();
    }
    if (irSensorCenterReading > black_thresh) {
        move(default_left_PWM, default_right_PWM, RIGHT);
    }
  }
  else {
    move(default_left_PWM, default_right_PWM, FORWARD);
  }
}

void avoidObstacle() {
    // TODO
}   