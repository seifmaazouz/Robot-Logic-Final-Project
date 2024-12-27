#ifndef PINS_H
#define PINS_H

/**** Motors Pins ****/
#define MOTOR_LEFT_PWM 4 
#define MOTOR_LEFT_IN1 16
#define MOTOR_LEFT_IN2 17
#define MOTOR_LEFT_CHANNEL 0

#define MOTOR_RIGHT_PWM 19
#define MOTOR_RIGHT_IN1 5
#define MOTOR_RIGHT_IN2 18
#define MOTOR_RIGHT_CHANNEL 1

/**** IR Sensor Pins ****/
#define IR_SENSOR_LEFT 14
#define IR_SENSOR_CENTER 27
#define IR_SENSOR_RIGHT 26

/**** Ultrasonic Sensor Pins ****/
#define ULTRASONIC_RIGHT_TRIGGER 35
#define ULTRASONIC_RIGHT_ECHO 34

#define ULTRASONIC_FRONT_TRIGGER 33
#define ULTRASONIC_FRONT_ECHO 32

/**** Other Components (LDR, LED, BUZZER, SMOKE) ****/
#define LDR_PIN 10
// #define LED_PIN 9
#define BUZZER_PIN 13
#define SMOKE_PIN 25

#endif
