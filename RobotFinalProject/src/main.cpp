#include <Arduino.h>
#include "setup_config.h"
#include "motor_control.h"

void setup() {
  initPins();
  setupMotors();
}

void loop() {
  move(100, 100, FORWARD);
  delay(2000);

  stopMotors();
  delay(1000);

  move(100, 100, BACKWARD);
  delay(2000);

  stopMotors();
  delay(1000);

  move(100, 100, RIGHT);
  delay(2000);

  stopMotors();
  delay(1000);

  move(100, 100, LEFT);
  delay(2000);
  
  stopMotors();
  delay(1000);
}
