#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 2

Adafruit_NeoPixel eyes = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
bool blinker = true;

void setup() {
  eyes.begin();
  eyes.setBrightness(255);
  eyes.show();
}

void loop() {
  if (blinker) {
    eyes.setPixelColor(0, 227, 114, 34); // TUM orange
    eyes.setPixelColor(1, 0, 101, 189); // TUM blue
  } else {
    eyes.setPixelColor(1, 227, 114, 34); // TUM orange
    eyes.setPixelColor(0, 0, 101, 189); // TUM blue
  }
  eyes.show();
  blinker = !blinker;
  delay(100);
}
