//global variables
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "Adafruit_PWMServoDriver.h"

//stepper variables
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

//switch variable
int buttonPin = 11;
bool pinValue = HIGH;
int steptest = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing Fancy Feast Ferris Wheel!");
  AFMS.begin();
  pinMode(buttonPin, INPUT);
  myMotor->setSpeed(0.05); //rps
}

void loop() {
  pinValue = digitalRead(buttonPin);

  if (pinValue == LOW) {
    Serial.println("Motor is ON");
    myMotor->step(100, FORWARD, INTERLEAVE);
  } else {
    Serial.println("Motor is OFF");
  }
  delay(1000);
} //end main loop