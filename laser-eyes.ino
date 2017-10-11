#include <Adafruit_NeoPixel.h>

const uint16_t NUM_LEDS = 2;
const uint8_t PIN = 6;

Adafruit_NeoPixel eyes = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  eyes.begin();
  eyes.setBrightness(255);
  eyes.show();
}

void loop() {
  breathe_blue(20);
  breathe_orange(20);
}

void breathe_blue(uint8_t wait) {
  uint16_t j;
  float m;

  for (j = 0; j < 256; j++) {
    m = sin(j * 0.01231997119);
    eyes.setPixelColor(0, 0, int(101.0 * m), int(189.0 * m)); // TUM blue
    eyes.setPixelColor(1, 0, int(101.0 * m), int(189.0 * m)); // TUM blue
    eyes.show();
    delay(wait);
  }
}

void breathe_orange(uint8_t wait) {
  uint16_t j;
  float m;

  for (j = 0; j < 256; j++) {
    m = sin(j * 0.01231997119);
    eyes.setPixelColor(0, int(227.0 * m), int(114.0 * m), int(34.0 * m)); // TUM orange
    eyes.setPixelColor(1, int(227.0 * m), int(114.0 * m), int(34.0 * m)); // TUM orange
    eyes.show();
    delay(wait);
  }
}
