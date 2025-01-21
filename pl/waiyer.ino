const int LED_WIRE = 2;            // LEDワイヤの本数
const int ledPin[LED_WIRE] = { 9, 10 }; // LEDはピン9と10に接続
const float pi = 3.14;             // π

int brightness;                    // 輝度 0-255
int counter[LED_WIRE];             // カウンタ 0-250 で一周期
unsigned long current_time;        // 現在時間
unsigned long next_time[LED_WIRE]; // 次の輝度変更時間
unsigned long interval[LED_WIRE];  // 輝度を変更する間隔(4-40mSec)

void setup() {
  randomSeed(analogRead(0)); // 未接続ピンのノイズを利用して乱数を初期化

  for(int i = 0; i < LED_WIRE; i++) { //ワイヤの本数分繰り返す
    counter[i] = 0;                // カウンタをクリア
    interval[i] = random(4, 40);   // 輝度を変更する間隔(4-40mSec)
  }
}

void loop() {
  current_time = millis();         // 現在時間を保存

// 各ワイヤの処理「0%～100%～0%」を間隔4ms～40ms、回数250回で輝度変更、1周期終えると間隔を再設定

  for(int i = 0; i < LED_WIRE; i++) { // LEDワイヤの本数分繰り返す
    if(next_time[i] < current_time) { // 該当ワイヤの輝度変更時間が来たら
      brightness = constrain(int(128 - cos((counter[i] * 2 * pi)/ 250) * 128),0,255);  // 輝度を計算（0～255で制限）
      analogWrite(ledPin[i], brightness); // 該当ワイヤのピンにアナログ出力
      if( ++counter[i] >= 250) {      // 1周期終えたら
        counter[i] = 0;               // カウンタをクリア
        interval[i] = random(4, 40);  // 間隔を4ms～40msの間で再設定
      }
      next_time[i] = current_time + interval[i]; // 次の輝度変更時間を設定
    }
  }
}
