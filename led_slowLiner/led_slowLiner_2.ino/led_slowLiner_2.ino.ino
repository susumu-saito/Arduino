const int ledPin=11;
const int outPin=9;
const double C=255.0; // LEDに依存

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,  OUTPUT); 
  pinMode(outPin, OUTPUT);

}

int val=0; 
int dir=1; 

void loop() { 
    analogWrite(ledPin, getDuty(val/255.0));
    val=val+dir;
    //Serial.println(val, DEC);
    
    if(val==0) dir=3;
    if(val==255) dir=-1;
    delay(7);

    int outVal=0;
    outVal=outVal+val;
    analogWrite(outPin, outVal);
    Serial.println(outVal, DEC);
    
}

int getDuty(double ratio){
  
  return round(exp(log(255.0)-(1-ratio)*log(C)));

}

