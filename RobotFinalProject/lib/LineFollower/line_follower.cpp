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
  if (irSensorLeftReading > black_thresh_left && irSensorRightReading > black_thresh_right && irSensorCenterReading > black_thresh_center) {
        stopMotors();
        delay(50);
  }
  else if (irSensorLeftReading > black_thresh_left && irSensorRightReading < black_thresh_right) {
    while (irSensorCenterReading < black_thresh_center && rec == "LF") {
        move(default_left_lt_PWM-20, default_right_lt_PWM, FORWARD);
        readInfraredSensors();
    }
    if (irSensorCenterReading > black_thresh_center) {
        move(default_left_lt_PWM, default_right_lt_PWM, LEFT);
        delay(50);
    }
  }
  else if (irSensorLeftReading < black_thresh_left && irSensorRightReading > black_thresh_right) {
    while (irSensorCenterReading < black_thresh_center && rec == "LF") {
        move(default_left_lt_PWM, default_right_lt_PWM-20, FORWARD);
        readInfraredSensors();
    }
    if (irSensorCenterReading > black_thresh_center) {
        move(default_left_lt_PWM, default_right_lt_PWM, RIGHT);
        delay(50);
    }
  }
  else {
    move(default_left_lt_PWM, default_right_lt_PWM, FORWARD);
  }
}

void avoidObstacle() {
    // TODO
}   