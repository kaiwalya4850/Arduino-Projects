// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 7;
int led1 = 6;
int led2 = 5;
int led3 = 4;
int led4 = 3;
int led5 = 2;
int led6 = 1;
int led7 = 0;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);   
  pinMode(led3, OUTPUT);   
  pinMode(led4, OUTPUT);   
  pinMode(led5, OUTPUT);   
  pinMode(led6, OUTPUT);   
  pinMode(led7, OUTPUT);   
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led6, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led7, HIGH);   // turn the LED on (HIGH is the voltage level)  
  delay(100);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led3, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led6, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led7, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
}
