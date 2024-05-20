const int n_Pins = 7;
const int n_Digits = 4;
int pins[n_Pins] = {2,3,4,5,6,7,8}; // LED pins
int digits[n_Digits] = {10,11,12,13}; // digit control pins
int zero[] = {1,1,1,1,1,1,0}; 
int one[] = {0,1,1,0,0,0,0}; 
int two[] = {1,1,0,1,1,0,1};
int three[] = {1,1,1,1,0,0,1};
int four[] = {0,1,1,0,0,1,1};
int five[] = {1,0,1,1,0,1,1};
int six[] = {1,0,1,1,1,1,1};
int seven[] = {1,1,1,0,0,0,0};
int eight[] = {1,1,1,1,1,1,1};
int nine[] = {1,1,1,1,0,1,1};
int del = 5;
int time = 0;
int n;
void setup(){
 for (int i = 0; i<n_Pins; i++) pinMode (pins[i], OUTPUT);
 for (int i = 0; i<n_Digits; i++) pinMode (digits[i], OUTPUT);
 Serial.begin(9600);
 while(!Serial);
 }

void loop(){
   if((millis()/1000 - time) > 1) {
   time++;
   }
   if(time>9999){
    time = 0;
   }

  n = time%10;
  setDigit(3);
  setNumber(n);
  delay(del);

  n = ((time%100)- (time%10))/10 ;
  setDigit(2);
  setNumber(n);
  delay(del);

  n = ((time%1000) - (time%100))/100;
  setDigit(1);
  setNumber(n);
  delay(del);

  n = ((time%10000) - (time%1000))/1000;
  setDigit(0);
  setNumber(n);
  delay(del);

 

}

void setDigit(int d) {
 for (int i = 0; i<4; i++) digitalWrite(digits[i], 1);
 digitalWrite(digits[d], 0); 
}

void setNumber(int n){
  if (n==0) for (int i = 0; i<n_Pins; i++)
 digitalWrite(pins[i], zero[i]);
 else if (n==1) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], one[i]);
 else if (n==2) for (int i = 0; i<n_Pins; i++)
 digitalWrite(pins[i], two[i]);
 else if (n==3) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], three[i]);
 else if (n==4) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], four[i]);
 else if (n==5) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], five[i]);
 else if (n==6) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], six[i]);
 else if (n==7) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], seven[i]);
 else if (n==8) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], eight[i]);
 else if (n==9) for (int i = 0; i<n_Pins; i++) 
 digitalWrite(pins[i], nine[i]);
}
