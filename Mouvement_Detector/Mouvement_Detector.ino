int trigPin = 6; // HC-SR04 trigger pin
int echoPin = 7; // HC-SR04 echo pin
const int ledPins[2] = {13,12} ;
const int MotorPin = 11;
unsigned long timeOfSwitch = 0;
bool switching = false, led13 = true, led12 = false;
int switchTime = 200;
float duration, distance;
void setup()
{
  pinMode(ledPins[0],OUTPUT);
  pinMode(ledPins[1],OUTPUT);
  pinMode(MotorPin,OUTPUT);
 Serial.begin(9600); // define Serial output baud rate
 pinMode(trigPin, OUTPUT); // define trigger pin as output
}

void loop()
{
digitalWrite(echoPin, LOW); // set the echo pin LOW
 digitalWrite(trigPin, LOW); // set the trigger pin LOW
 delayMicroseconds(20);
 digitalWrite(trigPin, HIGH); // set the trigger pin HIGH for 10μs
 delayMicroseconds(100);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH); // measure the echo time (μs)
distance = (duration/2.0)*0.0343; // convert echo time to distance (cm)
 
if(distance>400 || distance<2) {
  Serial.println("Out of range");
  //timeOfSwitch = 0;
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(MotorPin, LOW);
  
}else{
  digitalWrite(MotorPin, HIGH);
  if(timeOfSwitch == 0){
    digitalWrite(ledPins[0], led13);
    digitalWrite(ledPins[1], led12);
    timeOfSwitch = millis();
    delay(2);
  }else if((millis() - timeOfSwitch) > switchTime){
    led13 = !led13;
    led12 = !led12;
    digitalWrite(ledPins[0], led13);
    digitalWrite(ledPins[1], led12);
    timeOfSwitch = 0;
  }
 }
}