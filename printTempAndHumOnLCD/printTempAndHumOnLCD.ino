#include "DHT11.h"
#include <LiquidCrystal.h> // include the LiquidCrystal library
int LCDcol = 16; // number of LCD columns
int LCDrow = 4; 
int RS = 2;
int E = 3;
int D4 = 4;
int D5 = 5;
int D6 = 6;
int D7 = 7;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
const int tempPin = A0; 
DHT11 d(tempPin);
void setup() {
  Serial.begin(9600);
  while (!Serial);
  lcd.begin(LCDcol, LCDrow); // define LCD dimensions
  setUpLCD();

}
void setUpLCD(){
  lcd.setCursor(0,0); // move cursor to start of first row
  lcd.print("LCD to display"); // print first row "LCD to display"
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.setCursor(8, 1);
  lcd.print("Hum:");
}
void loop() {
  lcd.setCursor(5, 1);
  int temp = d.readTemperature();
  lcd.print(temp);
  lcd.setCursor(12, 1);
  int hum = d.readHumidity();
  lcd.print(hum);

  delay(1000);
}
