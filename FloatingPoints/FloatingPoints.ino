double variable = 1.100;
const double DELTA = .00001;
void setup() {
  Serial.begin(9600);
}

void loop() {
  variable -= 0.1;
  if(variable == 0.0){
    Serial.println("Value is exactly 0");
  }else if(almostEqual(variable,0.0)){
    Serial.print(variable,7);
    Serial.println(" is almost equal to 0");
    variable = 1.1;
  }else{
    Serial.println(variable);
  }
  delay(1000);

}
bool almostEqual(double a, double b){
  Serial.println("Inside Method");

  if(a==0.0){
    return fabs(b) <= DELTA;
  }else if(b == 0.0){
    return fabs(a) <= DELTA;
  }else{
    return fabs((a - b) / max(fabs(a), fabs(b))) <= DELTA;
  }

}