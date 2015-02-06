// RadioShack Tricolor LED Strip 2760339 TM1803
//
// THIS MUST BE COMPILED ON WINDOWS (or probably a Mac).
//
// To make this work, you will need:
//
//   - In theory, the FastLED 3.0.3 release should work on Windows or
//     MacOS.  But if you have problems with animation timing and
//     stuttering, try FastLED 3.1 branch.  Failure to use this will result
//     in problems with the animation timing.
//   - An official Arduino distribution (NOT A LINUX PORT!) with the
//     correct version of avr-gcc.  When working with the TM1803, you need
//     to get the assembly language timings exactly correct or the colors
//     will be wrong.  If you use the wrong version of avr-gcc, your colors
//     will all be wrong.
//
// Many thanks to focalintent for his help figuring this out.
//
// If you want to test your strip, see ../working_firmware.hex for a
// compiled firmware that shows animated white dots moving outward from the
// the start of the strip.
//
// Honestly, you should just give up on this strip and buy an Adafruit
// DotStar instead--it's cheaper, it offers per-LED control, and the update
// frequency is much higher.  And it doesn't require precise
// assembly-language timing loops.
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
