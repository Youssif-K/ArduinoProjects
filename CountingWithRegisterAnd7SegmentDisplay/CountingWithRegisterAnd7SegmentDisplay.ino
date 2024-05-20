int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 7;
////Pin connected to DS of 74HC595
int dataPin = 13;
const int n_Leds = 7;
//bool digit[n_Leds] = {a,b,c,d,e,f,g};
bool zero[] = {1,1,1,1,1,1,0};
bool one[] = {0,1,1,0,0,0,0}; // LED brightness to display number one
bool two[] = {1,1,0,1,1,0,1}; // LED states to display number two
bool three[] = {1,1,1,1,0,0,1};
bool four[] = {0,1,1,0,0,1,1};
bool five[] = {1,0,1,1,0,1,1};
bool six[] = {1,0,1,1,1,1,1};
bool seven[] = {1,1,1,0,0,0,0};// LED brightness to display number seven
bool eight[] = {1,1,1,1,1,1,1};
bool nine[] = {1,1,1,1,0,1,1};
/*bool digits[][n_Leds] = {
    {zero[0], zero[1], zero[2], zero[3], zero[4], zero[5], zero[6]},
    {one[0], one[1], one[2], one[3], one[4], one[5], one[6]},
    {two[0], two[1], two[2], two[3], two[4], two[5], two[6]},
    {three[0], three[1], three[2], three[3], three[4], three[5], three[6]},
    {four[0], four[1], four[2], four[3], four[4], four[5], four[6]},
    {five[0], five[1], five[2], five[3], five[4], five[5], five[6]},
    {six[0], six[1], six[2], six[3], six[4], six[5], six[6]},
    {seven[0], seven[1], seven[2], seven[3], seven[4], seven[5], seven[6]},
    {eight[0], eight[1], eight[2], eight[3], eight[4], eight[5], eight[6]},
    {nine[0], nine[1], nine[2], nine[3], nine[4], nine[5], nine[6]}
};*/
bool* digits[] = {zero,one,two,three,four,five,six,seven,eight,nine};

void setup() {
  Serial.begin(9600);
//set pins to output so you can control the shift register
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);

}
void shiftNumber(uint8_t val){
  digitalWrite(latchPin, LOW);Serial.println("Inside method");
	for(int i = 0; i< n_Leds; i++){
    Serial.println("Inside FOR LOOP");
    digitalWrite(clockPin, LOW);
    delay(2);
    Serial.println(digits[val][i]);
    digitalWrite(dataPin, digits[val][i]);
    delay(2);
    digitalWrite(clockPin, HIGH);
    
    delay(50);

  }
  digitalWrite(latchPin, HIGH);
}

int count = 0;

void loop() {
shiftNumber(count);
if(count<9){++count;}else{count = 0;}


delay(350);

}

/*for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
  digitalWrite(latchPin, HIGH);
  delay(500);
}*/
