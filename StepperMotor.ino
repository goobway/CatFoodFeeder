#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper Test!");

  AFMS.begin();

  myMotor->setSpeed(10); //10 rps
}

void loop() {
  Serial.println("Single coil steps");
  myMotor->step(100, FORWARD, SINGLE);
  myMotor->step(100, BACKWARD, SINGLE);
}