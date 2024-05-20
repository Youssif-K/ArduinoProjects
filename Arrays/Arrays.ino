const int numberOfIOs = 4;
const int inputs [4] = {2,3,4,5};
const int ledPins [4] = {8,9,10,11};


void setup() {
  Serial.begin(9600);
  for(int i = 0; i <numberOfIOs; i++){
    Serial.println();
    Serial.print("input  pin = ");Serial.println(inputs[i]);
    Serial.print("Output  pin = ");Serial.println(ledPins[i]);
    pinMode(inputs[i], INPUT_PULLUP);
    pinMode(ledPins[i],OUTPUT);;
  }
  


}

void loop() {
  for(int index = 0; index < numberOfIOs; index ++){
    int value = digitalRead(inputs[index]);
    if(value == LOW){
      digitalWrite(ledPins[index], HIGH);
    }else{
      digitalWrite(ledPins[index], LOW);
    }
  }
}
