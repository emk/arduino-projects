// -*- mode: c++ -*-

#include <FastLED.h>

#define NUM_LEDS 60

#define LED_PIN 4
#define CLOCK_PIN 3

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<DOTSTAR, LED_PIN, CLOCK_PIN, GBR>(leds, NUM_LEDS);
  // Startup delay so we don't pull extra current right away.
  delay(100);
}

int mod(int k, int m) {
  int result = k % m;
  if (result < 0)
    result += m;
  return result;
}

void loop()
{
  for (size_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
    leds[mod(i-1, NUM_LEDS)] = CRGB::Red;
    leds[mod(i-2, NUM_LEDS)] = CRGB::Green;
    leds[mod(i-3, NUM_LEDS)] = CRGB::Blue;
    leds[mod(i-6, NUM_LEDS)] = CRGB(0x00, 0x00, 0x44);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    leds[mod(i-1, NUM_LEDS)] = CRGB::Black;
    leds[mod(i-2, NUM_LEDS)] = CRGB::Black;
    leds[mod(i-3, NUM_LEDS)] = CRGB::Black;
    leds[mod(i-6, NUM_LEDS)] = CRGB::Black;
  }

  for (int b = 0; b < 256; b++) {
    for (size_t i = 0; i < NUM_LEDS; i+=3) {
      leds[i] = CRGB(b, b, 0);
      leds[i+1] = CRGB(0, b, b);
      leds[i+2] = CRGB(b, 0, b);
    }
    FastLED.show();
    delay(5);
  }

  for (size_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}
