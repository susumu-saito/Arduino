#include  <Adafruit_NeoPixel.h>

#define strand_Pin 6
#define strand_Pixels 7

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(strand_Pixels, strand_Pin, NEO_RGB + NEO_KHZ800);

const float pi = 3.14;      // π
unsigned long current_time; // 現在時間
unsigned long strand_time;  // ストランド配色変更時間
int led_data[3];            // 0:R, 1:G 2:B

double limit;
int strand_pos = 0;
int strand_interval = 360 / strand_Pixels;

void setup() {
//  Serial.begin(9600);

  strip.begin();
  strip.show();             // Initialize all pixels to 'off'

  limit = cos(pi * 2 / 3) + 1;
}

void loop() {
  current_time = millis();  // 現在時間を保存

  if(strand_time < current_time) {       // 時間になったら・・・
    for(int i=0; i<strand_Pixels; i++) { // 各ピクセルのRGB値を設定
      for(int j = 0; j < 3; j++) {       // 0:R, 1:G 2:B
         led_data[j] = constrain((cos((pi * 2 * ((strand_interval * i) + strand_pos)/360) - (pi * j * 2 / 3)) + 1 - limit) * 171, 0, 255);
      }
      strip.setPixelColor(i, led_data[0], led_data[1], led_data[2]);
      if(++strand_pos >= 360) strand_pos = 0;
    }
// Serial.print(led_data[0]);
// Serial.print(",\t");
// Serial.print(led_data[1]);
// Serial.print(",\t");
// Serial.println(led_data[2]);

    strip.show();        // ピクセルデータ転送
    strand_time += 50;   // 次の処理は50ms後
  }
}
