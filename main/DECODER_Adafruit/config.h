#include <Arduino.h>

#include <DMXSerial.h>
#include <Adafruit_NeoPixel.h>

#define MAX_VIABLE_LEDS 170
#define DATA_PIN 2
#define INDICATOR_LED_PIN LED_BUILTIN

#define REFRESH_RATE 60 // Frequency defined in Hz

#define MAX_VIABLE_CHANNELS (MAX_VIABLE_LEDS * 3)

Adafruit_NeoPixel strip(MAX_VIABLE_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

uint8_t RED;
uint8_t GREEN;
uint8_t BLUE;