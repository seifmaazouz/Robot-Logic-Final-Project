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
  }
  else if (irSensorLeftReading < black_thresh && irSensorRightReading > black_thresh) {
    while (irSensorCenterReading < black_thresh) {
        move(default_left_PWM, 0, FORWARD);
        readInfraredSensors();
    }
  }
  else {
    move(default_left_PWM, default_right_PWM, FORWARD);
}
}

void avoidObstacle() {
    // TODO
}   