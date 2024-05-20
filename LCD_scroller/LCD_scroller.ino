#include <LiquidCrystal.h> 
const int LCDcol = 16; // number of LCD columns
const int LCDrow = 2; 
const int RS = 2;
const int E = 3;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;
String text = "Youssif Khalifa~";
int start = 0;
int finish = 0;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  lcd.begin(LCDcol, LCDrow);
  lcd.setCursor(0, 0);
  text = text +  "     ";
}
void loop() {
  String substring;
    if(finish < LCDcol){
        substring += text.substring(start,finish);
        lcd.setCursor(LCDcol-finish, 0);
        lcd.print(substring);
        finish++;
    }else if(finish < text.length() && finish >= LCDcol){
        substring += text.substring(start,finish);
        lcd.setCursor(0, 0);
        lcd.print(substring);
        start++;
        finish++;
    }else if(finish >= text.length()){
      Serial.println("finish >= text.length()");
      if(start <text.length()){
        Serial.println("start < text.length()");
        substring += text.substring(start,text.length());
        substring += text.substring(0,finish-text.length());
        lcd.setCursor(0, 0);
        lcd.print(substring);
        start++;
        finish++;
      }else if(start >= text.length()){
        Serial.println("start >= text.length()");
        start = 0;
        finish = finish-text.length();
        lcd.setCursor(LCDcol-finish, 0);
        lcd.print(substring);
        finish ++;
      }
    }
delay(1000);
}
/*
int LCDcol = 16; // number of LCD columns
int LCDrow = 4; // number of LCD rows
LiquidCrystal lcd(2,3,4,5,6,7); // define LCD pins RS, E and D4 to D7
int first; // position of first letter in 16 character substring
int last = 0; // position of last letter in 16 character substring
int row = 1; // row of LCD to display text
int col;
String text = "The quick brown fox jumps over the lazy dog \
contains every letter of the alphabet."; // line continuation with 
void setup()
{
 lcd.begin(LCDcol, LCDrow); // define LCD dimensions
 text = text + " "; // add space at end of text as a buffer
}
void loop()
{
 if(last>text.length()+15) last=1; // set first column of substring
 if(last<17) first = 0; // substring<17 characters, start character =0
 else first = last-16; // substring>=17 chars, start char = last-16
 if(last>16) col = 0; // substring>16 characters, start column = 0
 else col = 16-last; // substring<=16 chars, start col  = last-16
 lcd.setCursor(col,row); // set cursor position
 lcd.print(text.substring(first, last)); // print substring
 last = last +1; // increment last
 delay(250); // delay 250ms
}
*/