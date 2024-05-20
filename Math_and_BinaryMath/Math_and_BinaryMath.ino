void setup() {
  Serial.begin(9600);
  while (!Serial);

  //When you set a value to x the number of bits in x do not exceed the number of bits that are use to represent this number
  //If you set x to 0 then you can have as many bits as you want
  int x = 4;//100 = 4
  bitSet(x, 0);//101 = 5
  bitSet(x, 1);//111 = 7
  bitClear(x, 2);//011 = 3
  Serial.println(bitRead(x, 2));
  Serial.println(x);

  //Shifting Bits
  int y = 5;
  Serial.println(y);
  y = y << 1; // Shifitng 101 once to the left to get 1010 = 10 smae as y = y*2
  Serial.println(y);
  y = y >> 2; //Shifitng 1010 twice to the right to get 10 = 2 same as y = y/4
  Serial.println(y);

  Serial.println("--------------------------");
  int intValue = 255; 
  int loWord,hiWord;
  byte loByte, hiByte;

  hiByte = highByte(intValue);//to get the most significant byte from an integer.
  loByte = lowByte(intValue);//to get the least significant byte from an integer

  Serial.println(intValue, DEC);
  Serial.println(intValue, HEX);
  Serial.println(loByte, DEC);
  Serial.println(hiByte, DEC);
}

void loop() {
}
