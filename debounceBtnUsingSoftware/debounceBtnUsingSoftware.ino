int switchPin = 8;
int LEDpin = 4;
int reading;
int switchState = HIGH;
int LEDState = LOW;
unsigned long switchTime;
int lastSwitch = HIGH; 
int debounceTime = 50; 
void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  digitalWrite(LEDpin, LEDState);
}

void loop(){
  reading = digitalRead(switchPin);
  if(reading != lastSwitch){
    switchTime = millis();
    lastSwitch = reading;
  }
  if((millis()-switchTime) > debounceTime){
    if(reading == LOW && switchState == HIGH){
      LEDState != LEDState;
      switchState = reading;
      digitalWrite(LEDpin, !reading);
    }else if(reading == HIGH && switchState == LOW){
       LEDState != LEDState;
      switchState = reading;
      digitalWrite(LEDpin, !reading);
    }

  }
}