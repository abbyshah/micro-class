#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield ROBOT = Adafruit_MotorShield();
Adafruit_DCMotor *LMotor = ROBOT.getMotor(4);
Adafruit_DCMotor *RMotor = ROBOT.getMotor(1);

const int trigPin = A0;
const int echoPin = A1;

void setup() 
{
  Serial.begin(9600);
  ROBOT.begin();
}

void loop()
{
  uint8_t i; 
  
  if(BAT() < 10){
      turnRobot();
  }
  else{
      //speed to start (150)
      LMotor->setSpeed(250);
      RMotor->setSpeed(250);
      //direction
      LMotor->run(FORWARD);
      RMotor->run(FORWARD);
      //release break???
      LMotor->run(RELEASE);
      RMotor->run(RELEASE);
  }
  
}

long BAT()
{
  long duration; 
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH); 
  return duration / 29 / 2; 
}

void turnRobot()
{
      LMotor->setSpeed(150);
      RMotor->setSpeed(150);

      LMotor->run(FORWARD);
      RMotor->run(BACKWARD);

      LMotor->run(RELEASE);
      RMotor->run(RELEASE);

      delay(500);
}
