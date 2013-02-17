
// include the LCD library 
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//LM35 sensor pin
const int LM35_Pin = A0;

//analog reading from 0 to 5 v
int analogReading;

//temperature reading in Celsius
int temperatureReading;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature: ");
  //setup LM35 sensor in as input
  pinMode(LM35_Pin, INPUT); 
}

void loop() {
  //get the reading from the sensor
  analogReading = analogRead(LM35_Pin);
  //convert to  corresponding temperature
  temperatureReading = (analogReading * 500) /1024;
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print(String(temperatureReading) + " C");
}
