#include <FastLED.h>

#define NUM_LEDS 144
#define DATA_PIN 3
#define BUTTON_PIN 2

CRGB leds[NUM_LEDS];
bool animationDone = true;

void setup() {
  Serial.begin(57600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(84);
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50);// Debounce delay
    if (digitalRead(BUTTON_PIN) == LOW) {
      Serial.println("Button pressed");
      delay(3000); // Wait 3 secs before the animation runs

      // Run the back-and-forth animation 5 times
      for (int cycle = 0; cycle < 5; cycle++) {
        // Forward
        for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CHSV(350, 255, 255); // Makes the color red
          FastLED.show();
          fadeall();
          delay(1);
        }

        // Backward
        for (int i = NUM_LEDS - 1; i >= 0; i--) {
          leds[i] = CHSV(350, 255, 255); // Makes the color red
          FastLED.show();
          fadeall();
          delay(1);
        }
      }

      // Turn all LEDs green
      fill_solid(leds, NUM_LEDS, CHSV(0, 255, 255)); // Makes the color green
      FastLED.show();

      delay(5000); // Wait 5 seconds

      // Turn off LEDs
      fill_solid(leds, NUM_LEDS, CRGB::Black); // Turn off the strip by setting the color to black
      FastLED.show();

      // Wait for button release
      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10); // Wait for the button release
      }
    }
  }
}