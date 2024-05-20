const int readPin = A0, writePin = 11;
double convertToVolts = 204.8;
double convertTo8Bit = 51.0;
void setup() {
  pinMode(readPin, INPUT);
  pinMode(writePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int statues = (analogRead(readPin)/convertToVolts)*convertTo8Bit;

  analogWrite(writePin, statues);
  Serial.print(statues);
  Serial.println();
  delay(500);

}
