//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "room-test-25090.firebaseio.com"
#define FIREBASE_AUTH "CZpWY1gJcMiLMDb1puST1rphthZIZZga0GJFYOpj"
#define WIFI_SSID "super"
#define WIFI_PASSWORD "abcd1234"



// defines pins numbers
const int trigPin = 5;  //D1
const int echoPin = 4;  //D2
const int trigPin1 = 14;  //D5
const int echoPin1 = 12;  //D6


// defines variables
long duration;
int distance;
long duration1;
int distance1;

void setup() {
  Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;
int t = 0;
int t1 = 0;

void loop() {
//DISTANCE FOR SENSOR 1
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(1000);

//DISTANCE FOR SENSOR 2
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance1);
delay(1000);

//FOR FIRST ULTRASONIC
if(distance<=10)
  {  
 
  // append a new value to /logs
    Firebase.set("manager / gujarat /380015 /loc1 /lat", "23.030575");
    Firebase.set("manager / gujarat /380015 /loc1 /long", "72.5113607");
    Firebase.set("manager / gujarat /380015 /loc1 /city", "Ahmedabad");
    Firebase.set("manager / gujarat /380015 /loc1 /cost", "20");
    Firebase.set("manager / gujarat /380015 /loc1 /name", "Aryaman Awash");
    Firebase.set("manager / gujarat /380015 /loc1 /sensor / 1 ", "True");
    Firebase.set("manager / gujarat /380015 /loc1 /Time / 1 ", t );
    t=t+1;
        if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }

  }

else
{
  // append a new value to /logs
    
    Firebase.set("manager / gujarat /380015 /loc1 /lat", "23.030575");
    Firebase.set("manager / gujarat /380015 /loc1 /long", "72.5113607");
    Firebase.set("manager / gujarat /380015 /loc1 /city", "Ahmedabad");
    Firebase.set("manager / gujarat /380015 /loc1 /cost", "20");
    Firebase.set("manager / gujarat /380015 /loc1 /name", "Aryaman Awash");
    Firebase.set("manager / gujarat /380015 /loc1 /sensor / 1 ", "False");
    t=0;
    Firebase.set("manager / gujarat /380015 /loc1 /Time / 1 ", t );
        if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  
}
  
  }

//FOR SECOND SENSOR
if(distance1<=10)
  {  
 

  // append a new value to /logs
    Firebase.set("manager / gujarat /380015 /loc2 /lat", "23.030575");
    Firebase.set("manager / gujarat /380015 /loc2 /long", "72.5113607");
    Firebase.set("manager / gujarat /380015 /loc2 /city", "Ahmedabad 1");
    Firebase.set("manager / gujarat /380015 /loc2 /cost", "20");
    Firebase.set("manager / gujarat /380015 /loc2 /name", "Aryaman Awash 1");
    Firebase.set("manager / gujarat /380015 /loc2 /sensor / 2 ", "True");
    Firebase.set("manager / gujarat /380015 /loc2 /Time / 2 ", t1 );
    t1=t1+1;
        if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }

  }

else
{
  // append a new value to /logs
    
    Firebase.set("manager / gujarat /380015 /loc2 /lat", "23.030575");
    Firebase.set("manager / gujarat /380015 /loc2 /long", "72.5113607");
    Firebase.set("manager / gujarat /380015 /loc2 /city", "Ahmedabad 1");
    Firebase.set("manager / gujarat /380015 /loc2 /cost", "20");
    Firebase.set("manager / gujarat /380015 /loc2 /name", "Aryaman Awash 1");
    Firebase.set("manager / gujarat /380015 /loc2 /sensor / 2 ", "False");
    t1=0;
    Firebase.set("manager / gujarat /380015 /loc1 /Time / 2 ", t1 );
        if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  
}
  
  }


}
