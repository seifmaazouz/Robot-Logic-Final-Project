#include <Arduino.h>
#include "pins.h"
#include "setup_config.h"
#include "motor_control.h"
#include "sensors_reader.h"
#include "line_follower.h"
#include "maze_solver.h"

void setup() {
  initPins();
  setupMotors();
  Serial.begin(115200);
  setupBluetooth();
}

void loop() {
  readLightSensor();
  readSmokeSensor();
  readUltrasonicSensors();

  // Feature: scared of darkness
  if (lightSensorReading == 1) {
    tone(BUZZER_PIN, 3000);
  }
  

  // Feature: smoke detection
  else if (smokeSensorReading > smoke_thresh) {
    tone(BUZZER_PIN, 3500);
  }

else if (ultrasonicFrontDistance < MAX_DISTANCE) {
        int frequency = map(ultrasonicFrontDistance, 0, MAX_DISTANCE, 2000, 500);
        tone(BUZZER_PIN, frequency);
} else {
    noTone(BUZZER_PIN);
}
    

  if (SerialBT.available()) {
    rec = (String)SerialBT.readStringUntil('\n');
    Serial.println(rec);  
    if (rec == "S") {
        stopMotors();
    }
    else if (rec == "R") {
        move(default_left_PWM, default_right_PWM, RIGHT);
    }
    else if (rec == "L") {
      move(default_left_PWM, default_right_PWM, LEFT);
    }
    else if (rec == "F") {
      move(default_left_PWM, default_right_PWM, FORWARD);
    }
    else if (rec == "B") {
      move(default_left_PWM, default_right_PWM, BACKWARD);
    }
  }

  if (rec == "LF") {
    followLine();
  }
  if (rec == "MZ") {
    solveMaze();
  }

  // readInfraredSensors();

  // Serial.print (irSensorLeftReading);
  // Serial.print (" ");
  // Serial.print (irSensorCenterReading);
  // Serial.print (" ");
  // Serial.print (irSensorRightReading);
  // Serial.println (" ");

  // Serial.print("Right Distance: ");
  // Serial.println(ultrasonicRightDistance);
  // Serial.print("Front Distance: ");
  // Serial.println(ultrasonicFrontDistance);
}
