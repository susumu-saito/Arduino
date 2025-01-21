const int outPin=13;

void setup() {
  Serial.begin(9600);

  pinMode(outPin, OUTPUT);
}

void loop() {
    int led=random(0,2);
    
    if(led==1){
    digitalWrite(outPin, "ON");
    delay(500);
    Serial.println(led, DEC);
    }
    if(led==0){
    digitalWrite(outPin, "OFF");
    delay(500);
    Serial.println(led, DEC);
    }
    
  }


