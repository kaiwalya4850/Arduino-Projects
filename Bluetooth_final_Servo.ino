#include<SoftwareSerial.h>

#include <Servo.h>

#define TxD 3
#define RxD 2
Servo myservo;

int pos = 0; 
SoftwareSerial bluetoothSerial(TxD,RxD);

char c;

void setup() {
  bluetoothSerial.begin(9600);
 Serial.begin(9600);
  
    myservo.attach(9);
  }

void loop() 
{
  if(bluetoothSerial.available())
  {
    c = bluetoothSerial.read();
    Serial.println(c);
    if(c=='1')
    {
      for (pos = 0; pos <= 270; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }        
    }
    if(c=='0')
    {
     for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
  }
}
