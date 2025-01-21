#define FADE_TIME 2
int led_pin[] = {3, 5, 6, 9, 10, 11};
 
void setup(){
 
    for (int i=0; i<6; i++) {
    pinMode(led_pin[i], OUTPUT);
  }
}
 

void loop() {
 
  int i,j;
  // 暗→明
  for (j=0; j<6; j++) {
    for (i=0; i<256; i++) {
      analogWrite(led_pin[j], i);
      delay(FADE_TIME);
    }
  }
 
  // 明→暗
  for (j=0; j<6; j++) {
    for (i=255; i>-1; i--) {
      analogWrite(led_pin[j], i);
      delay(FADE_TIME);
    }
  }
}
 
