#include <FastLED.h>
#include "PrimeCycles.h"

#define NUM_LEDS 144
#define DATA_PIN 11
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS]; 
CHSV frame_hsv[Pattern::num_leds];
PrimeCycles gen;

void setup() {
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB, DATA_RATE_MHZ(12)>(leds, NUM_LEDS);
}

void loop() {
    gen.updateFrame(frame_hsv);
    for (int i = 0; i < Pattern::num_leds; ++i) {
      leds[i] = frame_hsv[i];
    }
    FastLED.show();
//    delay(30);
}
