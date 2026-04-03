#include <Arduino.h>
#include <DMXSerial.h>
#include <Adafruit_NeoPixel.h>

#define MAX_VIABLE_LEDS 170
#define MAX_VIABLE_CHANNELS (MAX_VIABLE_LEDS * 3)

#define PIN_DATA 13

Adafruit_NeoPixel strip(MAX_VIABLE_LEDS, PIN_DATA, NEO_GRB + NEO_KHZ800);