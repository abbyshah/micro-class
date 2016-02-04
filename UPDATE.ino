const int KILL = 11; 
const int trigPin = 2; 
const int echoPin = 4; 

void setup() 
{
  //LMotor
  pinMode(12, OUTPUT); //Motor Channel A 
  pinMode(9, OUTPUT); //Brake Channel A
  
  //RMotor
  pinMode(13, OUTPUT); //Motor Channel B 
  pinMode(8, OUTPUT); //Brake Channel B
}

void loop()
{
  while(KILL != HIGH) //or low, as long as kill switch isn't activated
  {
    if(BAT() > 8) //path is clear up to 8 cm
    {
        //LMotor forward 
        digitalWrite(12, HIGH); //direction forward
        digitalWrite(9, LOW); //brake off
        analogWrite(3, 255); //speed full
        //RMotor forward
        digitalWrite(13, HIGH); 
        digitalWrite(8, LOW); 
        analogWrite(11, 255); 

        delay(500); //stay on for 500 ms
    }
    else 
    {
        turnRobot();   
    }  
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
   //LMotor forward @ half speed
   digitalWrite(12, HIGH); //direction forward
   digitalWrite(9, LOW); //brake off
   analogWrite(3, 123); //speed half
   //RMotor Back (or stop)
   digitalWrite(13, LOW); //direction backward
   digitalWrite(8, LOW); //brake off
   analogWrite(11, 100); //speed less than half

   delay(500); //stay on for 500 ms
}
