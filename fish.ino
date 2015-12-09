#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo             
 
int pos = 0;    // variable to store the servo position 

long FISHFEEDER = 5000; // 43200000 12 hours between feeding
                        // for the sake of an example i made the time btwn feeding 5 seconds
                        // just to be able to realistically show 
long endtime; 
long now;

void setup() 
{ 
 
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object 
  
  myservo.write(0);
  delay(15);
  
}

//user defined function to feed fish 
void feedFish()
{
  now = millis();     //millis is a function that returns the number of ms since the board started running current sketch
                      //works well for timing circuits so you can do multiple things at once or stay more organized.
  endtime = now + FISHFEEDER;
  
  while(now < endtime) {
   myservo.write(0); //servo stays in position 0 until it is time to feed fish. 
   delay(3000); //20000 delays until it's time to check again. 
   now = millis();   
  }
  
  //this part tilts the container to actually feed fish 
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}

//calls user defined function 
void loop() 
{ 
  feedFish();
}
