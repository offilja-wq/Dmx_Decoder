#include <Arduino.h>
#include <DMXSerial.h>
#include <FastLED.h>

#define MAX_VIABLE_LEDS 170
#define MAX_VIABLE_CHANNELS (MAX_VIABLE_LEDS * 3)

#define PIN_DATA 13

CRGB leds[MAX_VIABLE_LEDS];