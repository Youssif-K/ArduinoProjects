const int firstBit = 8, secondBit = 9, thirdBit = 10, fourthBit = 11;
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(firstBit,OUTPUT);
  pinMode(secondBit,OUTPUT);
  pinMode(thirdBit,OUTPUT);
  pinMode(fourthBit,OUTPUT);
}

void loop() {
  Serial.print(count);
  Serial.println();
  switch(count){
    case 0:
    break;
    case 1:
      digitalWrite(firstBit,HIGH);
    break;
    case 2:
      digitalWrite(secondBit,HIGH);
    break;
    case 3:
      digitalWrite(firstBit,HIGH);
      digitalWrite(secondBit,HIGH);
    break;
    case 4:
      digitalWrite(thirdBit,HIGH);
    break;
    case 5:
      digitalWrite(firstBit,HIGH);
      digitalWrite(thirdBit,HIGH);
    break;
    case 6:
      digitalWrite(secondBit,HIGH);
      digitalWrite(thirdBit,HIGH);
    break;
    case 7:
      digitalWrite(firstBit,HIGH);
      digitalWrite(secondBit,HIGH);
      digitalWrite(thirdBit,HIGH);
    break;
    case 8:
      digitalWrite(fourthBit,HIGH);
    break;
    case 9:
      digitalWrite(firstBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
    case 10:
      digitalWrite(secondBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
    case 11:
      digitalWrite(firstBit,HIGH);
      digitalWrite(secondBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
    case 12:
      digitalWrite(thirdBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
    case 13:
      digitalWrite(firstBit,HIGH);
      digitalWrite(thirdBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
    case 14:
      digitalWrite(secondBit,HIGH);
      digitalWrite(thirdBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
    case 15:
      digitalWrite(firstBit,HIGH);
      digitalWrite(secondBit,HIGH);
      digitalWrite(thirdBit,HIGH);
      digitalWrite(fourthBit,HIGH);
    break;
   }

   if(count < 15){
    count ++;
    }else{count = 0;}
   delay(2000);
    digitalWrite(firstBit,LOW);
    digitalWrite(secondBit,LOW);
    digitalWrite(thirdBit,LOW);
    digitalWrite(fourthBit,LOW);
    delay(200);
   
}
