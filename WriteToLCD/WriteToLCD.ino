#include <LiquidCrystal.h> // include the LiquidCrystal library
int LCDcol = 16; // number of LCD columns
int LCDrow = 2; 
int RS = 2;
int E = 3;
int D4 = 4;
int D5 = 5;
int D6 = 6;
int D7 = 7;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
void setup()
{
 Serial.begin(9600); // define Serial output baud rate
}
void loop()
{
 if (Serial.available()>0) // if data in Serial input buffer
 {
 lcd.clear(); // clear the LCD
 while (Serial.available()>0){
  String s = Serial.readString();
  Serial.println(s);
  lcd.print(s);
 } // read and display input buffer
 }
}
