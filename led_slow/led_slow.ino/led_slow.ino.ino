#define ledPin1 11
//#define ledPin2 13
#define FADE_TIME 2

void setup(){
  Serial.begin(9600);
  
  pinMode(ledPin1, OUTPUT); 
  //pinMode(ledPin2, OUTPUT); 
 
}

void loop() {
  float i;
  
  for(;;){
   for(i=0;i<256;i+=10){
     analogWrite(ledPin1, i);
     Serial.println(i,DEC);
     delay(50);
   }  

   for(i=255;i>0;i-=10){
     analogWrite(ledPin1, i);
     Serial.println(i,DEC);
     delay(900);
   }
   delay(10);
  }
}
