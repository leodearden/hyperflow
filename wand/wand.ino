#include <FastLED.h>
#define NUM_LEDS 144
#define DATA_PIN 11
#define CLOCK_PIN 13
//#define DATA_PIN 7
//#define CLOCK_PIN 14

CRGB leds[NUM_LEDS]; 

void setup() {
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB, DATA_RATE_MHZ(12)>(leds, NUM_LEDS);
}

void loop() {
    for(int dot = 0; dot < NUM_LEDS; dot++) { 
        leds[dot] = CRGB::Blue;
        FastLED.show();
        // clear this led for the next time around the loop
        leds[dot] = CRGB::Black;
        delay(30);
    }
}
