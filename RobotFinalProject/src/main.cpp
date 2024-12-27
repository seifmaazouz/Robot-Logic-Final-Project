#include <Arduino.h>
#include "setup_config.h"
#include "motor_control.h"

void setup() {
  initPins();
  setupMotors();
}

void loop() {
  move(100, FORWARD);
  delay(1000);
  stop();
  delay(1000);
  move(100, BACKWARD);
  delay(1000);
  stop();
  delay(1000);
  move(100, RIGHT);
  delay(1000);
  stop();
  delay(1000);
  move(100, LEFT);
  stop();
  delay(1000);
}
