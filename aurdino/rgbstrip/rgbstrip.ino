#include <FastLED.h>

#define NUM_LEDS 144
#define DATA_PIN 3

CRGB leds[NUM_LEDS]; // Array of leds CRGB = color object

void setup() { 
    Serial.begin(57600);
    Serial.println("resetting");
    FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
    FastLED.setBrightness(84); // Set global brightness (range: 0–255)
}

void fadeall() { 
    for(int i = 0; i < NUM_LEDS; i++){
        leds[i].nscale8(250); // each step fades slightly ex: 250/256 ~ 98%
    }
}

void loop() { 
    // static uint8_t hue = 0; //use for rainbow effect

    Serial.print("x");

    // ------ Slide led in one direction ------
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(360, 255, 255); // Set the i'th led to red 
        FastLED.show(); // Show the leds
        // leds[i] = CRGB::Black; // Resets the i'th led to black
        fadeall();
        delay(10); // Wait a little bit before loop around
    }

  Serial.print("x");

    // ------ Go in the other direction ------
    for(int i = (NUM_LEDS)-1; i >= 0; i--) { 
        leds[i] = CHSV(360, 255, 255); // Set the i'th led to red
        FastLED.show(); // Show the leds
        // leds[i] = CRGB::Black; // Resets the i'th led to black
        fadeall();
        delay(10); // Wait a little bit before loop around
    }
}

/* change color syntax

1) Predefined FastLED colors

leds[0] = CRGB::Red;
leds[1] = CRGB::Green;

2) Manually setting RGB values

leds[3] = CRGB(255, 128, 0); // Orange
leds[4] = CRGB(0, 255, 255); // Cyan

3) HSV (Hue, Saturation, Value) Model

leds[5] = CHSV(0, 255, 255);   // Red
leds[6] = CHSV(96, 255, 255);  // Green

Extra: Cycle through colors

static uint8_t hue = 0;
leds[i] = CHSV(hue, 255, 255);
hue++;  // Increment to rotate through colors over time

*/