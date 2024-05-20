const int Vdivid = A0; // voltage divider analog pin
const int nLEDs = 5; // number of LEDs
const int LEDpin[] = {8, 9, 10, 11 ,12}; // LED pins
int reading, level;

void setup() {
  for(int i = 0; i < nLEDs; i++){
    pinMode(LEDpin[i],OUTPUT);
  }
  pinMode(Vdivid,INPUT);
  Serial.begin(9600);

}

void loop() {
 reading = analogRead(Vdivid); // voltage divider reading
 level = 0; // set number of LEDs to zero
 level = map(reading, 0, 1023, 0, nLEDs+1); // map reading to level
 for (int i = 0; i < nLEDs; i++)
 { // turn on LED
 if (i < level) digitalWrite(LEDpin[i], HIGH); // less than level
 else digitalWrite(LEDpin[i],LOW); // otherwise turn off LED
 }
 delay(1000); 
}
