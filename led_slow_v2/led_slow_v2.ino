#define pin 11

void setup() {
  Serial.begin(9600);
  
  pinMode(pin,OUTPUT);
}
 
int val=0; 
int dir=1; 

void loop(){
  analogWrite(pin,val);
  val=val+dir;
  Serial.println(val,DEC);
  if(val==0) dir=1;
  if(val==255) dir=-1;
  delay(10);
}
