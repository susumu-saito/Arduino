const int LED_PIN = 11;
const double C = 255.0; // LEDに依存

void setup() {
  
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); 
  
}

void loop() {
  
  for(int i=0; i<=255; i++){
    analogWrite(LED_PIN, getDuty(i/255.0));
    Serial.println(i, DEC);
    delay(10);
  }
  for(int i=255; i>0; i--){
    analogWrite(LED_PIN, getDuty(i/255.0));
    Serial.println(i, DEC);
    delay(10);
  }

}

int getDuty(double ratio){
  
  return round(exp(log(255.0)-(1-ratio)*log(C)));

}
