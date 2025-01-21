void setup() {
  // put your setup <span class="hilite1">co</span>de here, to run once:
  pinMode( 11, OUTPUT );
}
 
int val = 0; // 現在の明るさ
int dir = 1; // 明るさの変化方向
 
void loop() {
  // put your main <span class="hilite1">co</span>de here, to run repeatedly:
  analogWrite( 11, val );
  val = val + dir;
  if( val ==   0 ) dir =  1;
  if( val == 255 ) dir = -1;
  delay( 10 );
}
