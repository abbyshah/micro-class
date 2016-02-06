#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield ROBOT = Adafruit_MotorShield();
Adafruit_DCMotor *LMotor = ROBOT.getMotor(4);
Adafruit_DCMotor *RMotor = ROBOT.getMotor(1);


void setup() 
{
  Serial.begin(9600);
  ROBOT.begin();
}

void loop()
{
  uint8_t i; 

      //speed to start (150)
      LMotor->setSpeed(200);
      RMotor->setSpeed(200);
      //direction
      LMotor->run(FORWARD);
      RMotor->run(FORWARD);
      //release break???
      LMotor->run(RELEASE);
      RMotor->run(RELEASE);
  
  
}


