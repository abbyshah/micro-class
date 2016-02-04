//commented out lines are for DC motors not servo

#include <Servo.h>

const int trigPin = 2; 
const int echoPin = 4; 
const int KILL = 11; //define kill switch for robot
Servo LMotor; 
Servo RMotor;
//int LMotor = 11; 
//int RMotor = 10; 

void setup() 
{
  RMotor.attach(11);
  LMotor.attach(10);
  Serial.begin(9600);
}

void loop() 
{
  while(KILL != HIGH) // or low, (as long as the kill switch isn't on. 
  {
      if(BAT() > 5){ //path is clear
          LMotor.write(90); //robot forward
          RMotor.write(90);
          //digitalWrite(LMotor, HIGH);
          //digitalWrite(RMotor, HIGH);
      }
      else{    //obstacle detected
          turnRobot();   
      }
  }
}

//function to use the sensor to make a measurement. 
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

void turnRobot(){ //turn right
    LMotor.write(180); //forward
    RMotor.write(0); //backward
    delay(500);  
    //digitalWrite(LMotor, HIGH);
    //digitalWrite(RMotor, LOW);
    //delay(500);
}

/*
sound travels 1130 feet per second, there are 29 microseconds per cm 
divide this by 2 to get one way distance
*/

