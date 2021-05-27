#include <Servo.h> 
 
Servo nozzle_1;  // create servo object to control a servo // a maximum of eight servo objects can be created 
Servo nozzle_2; 
int i,pos;    // variable to store the servo position 
 
void setup() 
{ 
  // nozzles and pins attachments
  nozzle_1.attach(12);  // attaches the nozzle 1 on pin 12 
  nozzle_2.attach(13);
  
  nozzle_1.write(90); nozzle_2.write(90); delay(3000);
 // nozzle_1.write(90); nozzle_2.write(0); 
 // nozzle_1.write(0); nozzle_2.write(0); 
//  nozzle_1.write(0); nozzle_2.write(0); 
   
   
//   nozzle_1.write(90);delay(3000);
//  nozzle_1.write(180);delay(3000);
//  nozzle_1.write(90);delay(3000);
} 
 
 
void loop() 
{ 
  
 /* 
  nozzle_1.write(0);
  delay(5000);
  nozzle_1.write(45);
  delay(5000);
  nozzle_1.write(90);
  delay(5000);
  nozzle_1.write(135);
  delay(5000);
  nozzle_1.write(180);
  delay(5000);
  nozzle_1.write(135);
  delay(5000);
  nozzle_1.write(90);
  delay(5000);
  nozzle_1.write(45);
  delay(5000);
  
  */
  
   
  for(i=1;i<=10;i++)
  {
  for(pos = 70; pos <= 110; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    nozzle_1.write(pos); nozzle_2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 110; pos>=70; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    nozzle_1.write(pos); nozzle_2.write(pos);             // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  }
  
  nozzle_1.write(90); nozzle_2.write(90); delay(3000);
  
    
  for(i=1;i<=3;i++)
  { 
       nozzle_1.write(110); nozzle_2.write(110);
      delay(5000);
      nozzle_1.write(70); nozzle_2.write(70);
      delay(5000);
  
  }
  
  
} 
