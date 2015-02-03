// RadioShack Tricolor LED Strip 2760339
//
// THIS DOESN'T WORK.  It _almost_ works, but the GRGB::Black LEDs
// show up as a medium-intensity red, and the pattern--while
// semi-visible--tends to jump around out of order a lot.  I'm not
// sure if this is because of a problem with the code, or because
// I've partially fried my LED strip.  Oh, well.
//
// Partially inspired by:
// http://www.instructables.com/id/Import-a-Code-Library-to-Arduino/

#include <FastLED.h>

// Use our lowest-numbered PWM pin, in case the library needs it.
#define DATA_PIN 3

// 10 segments of 3 LEDs each.
#define NUM_LEDS 10

CRGB leds[NUM_LEDS];

void setup()
{
    FastLED.addLeds<TM1803, DATA_PIN, GBR>(leds, NUM_LEDS);
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
