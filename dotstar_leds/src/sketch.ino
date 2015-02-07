#include <FastLED.h>

#define NUM_LEDS 60

#define LED_PIN 4
#define CLOCK_PIN 3

CRGB leds[NUM_LEDS];

void setup()
{
    FastLED.addLeds<DOTSTAR, LED_PIN, CLOCK_PIN, GBR>(leds, NUM_LEDS);
}

void loop()
{
    for (size_t i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::White;
        FastLED.show();
	delay(100);
	leds[i] = CRGB::Black;
    }
}
