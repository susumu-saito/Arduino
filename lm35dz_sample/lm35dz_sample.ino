float analogIn;          
float temp = 0;  

void setup(){
  Serial.begin(9600);  
}

void loop(){
  analogIn=analogRead(0);     // A0ピンからセンサ値を取得
  temp=((5*analogIn)/1024)*100;     // センサ値を摂氏に換算
  Serial.println(temp);     // シリアルモニタに表示
  delay(1000);      // 1000ms待機
}
