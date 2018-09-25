
/* 
 The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 */

/*
 For Ease of Concept & Programming, 
 Only Check Switch to Reset Password 
 When user has entered password initially
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 7, 6, 5, 4, 3); 

#define SET 2
#define BUZZER 13

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

char password[] = {
  '9','5','1','3','6','9'};

/*
 * Default Password: 951369
 */
char userPassword[6];

//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {
    '1','2','3'          }
  ,
  {
    '4','5','6'          }
  ,
  {
    '7','8','9'          }
  ,
  {
    '*','0','#'          }
};
byte rowPins[ROWS] = {
  12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  A5, A4, A3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

byte trials = 0;

void setup(){
  // set up the lcd's number of columns and rows: 
  lcd.begin(20,2);  
  pinMode(SET, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);  
  lcd.print("Enter Password:");
}

void loop(){
  getPassword();
}

void setPassword(){
  byte count = 0;
  while(1){
    char customKey = customKeypad.getKey();
    if(customKey){
      lcd.setCursor(count, 1);
      lcd.write(customKey);
      password[count]=customKey;
      delay(200);  // Debounce Delay
      count++;
    }
    if(count == 6)
      break;
  }
  lcd.clear();
  lcd.print("Confirm Password:");
  confirmPassword();
}

void confirmPassword(){
  byte count = 0;
  char confirmPassword[6];
  while(1){
    char customKey = customKeypad.getKey();
    if(customKey){
      confirmPassword[count]=customKey;
      lcd.setCursor(count, 1);
      lcd.write(customKey);
      delay(200);  // Debounce Delay
      count++;
    }
    if(count == 6)
      break;
  }
  byte temp=0;
  for(char t=0; t<6; t++){
    if(confirmPassword[t]==password[t]){
      temp++;
    }
  }
  if(temp == 6){
    lcd.clear();
    lcd.print("Password Matched!!");
    delay(1000);
    lcd.clear();
    lcd.print("Enter Password:");
    getPassword();
  }
  else{
    lcd.clear();
    lcd.print("Password Mismatch!!");
    delay(1000);
    lcd.clear();
    lcd.print("Set Password:");
    setPassword();
  }
}

void getPassword(){  
  byte count = 0;
  while(1){
    char customKey = customKeypad.getKey();
    if(customKey){
      userPassword[count]=customKey;
      lcd.setCursor(count, 1);
      lcd.write('*');
      delay(200);  // Debounce Delay
      count++;
    }
    if(count == 6)
      break;
  }
  verifyPassword();
}

void verifyPassword(){
  byte count=0;
  for(char t=0; t<6; t++){
    if(userPassword[t]==password[t]){
      count++;
    }
  }
  if(count == 6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Correct Password");
    delay(2000);
    lcd.clear();
    lcd.print("Press Switch for");
    lcd.setCursor(0,1);
    lcd.print("Password Reset");
    while(1){
      if(digitalRead(SET)==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Set Password:");
        setPassword();
      }
    }
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Incorrect Password");  
    delay(1500);
    trials++;
    if(trials > 2){
      lockSystem();
    } 
    else{
      lcd.clear();
      lcd.print("Enter Password:");
    }
  }
}

void lockSystem(){
  lcd.clear();
  lcd.print("System Locked!!");
  digitalWrite(BUZZER, HIGH);
  while(1);
}








