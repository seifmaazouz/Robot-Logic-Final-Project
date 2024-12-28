#include <Arduino.h>
#include "pins.h"
#include "setup_config.h"
#include "motor_control.h"
#include "sensors_reader.h"
#include "line_follower.h"
#include "maze_solver.h"

void playBuzzer(int frequency);

void setup() {
  initPins();
  setupMotors();
  Serial.begin(115200);
  setupBluetooth();
  // calibrateIRSensors();
}

void loop() {
  readLightSensor();
  readSmokeSensor();
  readUltrasonicSensors();

  // Feature: scared of darkness
  if (lightSensorReading == 1) {
    ledcWriteTone(BUZZER_CHANNEL, 3000);
  }

    // Feature: smoke detection
  else if (smokeSensorReading > smoke_thresh) {
    ledcWriteTone(BUZZER_CHANNEL, 3500);
  }

  else if (ultrasonicFrontDistance < MAX_DISTANCE) {
    // int frequency = 0;
    int frequency = map(ultrasonicFrontDistance, 3, MAX_DISTANCE, 3000, 500);
    
    // Prevent extreme frequency values (e.g., below 500 Hz)
    if (frequency < 500) {
        frequency = 500;
    }
    
    // Play the mapped tone based on the distance
    playBuzzer(frequency);

    // if(ultrasonicFrontDistance <= 10) {
    //   stopMotors();
    // }
    if(ultrasonicFrontDistance <= 10) {
        stopMotors();
        delay(200);
        move(default_left_PWM, default_right_PWM, RIGHT);
        delay(200);
        stopMotors();
        return;
      }
  } 
  else {
    ledcWriteTone(BUZZER_CHANNEL, 0);
  }


  if (SerialBT.available()) {
    rec = (String)SerialBT.readStringUntil('\n');
    Serial.println(rec);  
    if (rec == "S") {
        stopMotors();
    }
    else if (rec == "R") {
        move(default_left_PWM-20, default_right_PWM, RIGHT);
    }
    else if (rec == "L") {
      move(default_left_PWM, default_right_PWM-20, LEFT);
    }
    else if (rec == "F") {
      //   if(ultrasonicFrontDistance <= 10) {
      //   stopMotors();
      //   return;
      // }
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
  Serial.print("Front Distance: ");
  Serial.println(ultrasonicFrontDistance);

  Serial.println("REC: " + rec);
}

void playBuzzer(int frequency) {
    static unsigned long lastTime = 0;
    static bool buzzerState = false;
    int period = 1000000 / frequency;

    if (micros() - lastTime >= period / 2) {
        lastTime = micros();
        buzzerState = !buzzerState;
        if(buzzerState) {
            ledcWriteTone(BUZZER_CHANNEL, frequency);
        }
        else {
            ledcWriteTone(BUZZER_CHANNEL, 0);
        }
    }
}
