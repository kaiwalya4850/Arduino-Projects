
/* The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {
    '7','8','9','%'      }
  ,
  {
    '4','5','6','x'      }
  ,
  {
    '1','2','3','-'      }
  ,
  {
    'C','0','=','+'      }
};
byte rowPins[ROWS] = {
  12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  A0, A1, A2, A3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  // set up the lcd's number of columns and rows: 
  lcd.begin(16,2);

  lcd.print("Key Pressed:");

}
void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
    // set the cursor to the top row, 0th Coumn, 1st Row:
    lcd.setCursor(0, 1);
    // draw the arrow
    lcd.write(customKey);
    delay(300);
  }
}


