#include <Arduino.h>

#include <DMXSerial.h>

#include <FastLED.h>

#define MAX_VIABLE_LEDS 170
#define MAX_VIABLE_CHANNELS (MAX_VIABLE_LEDS * 3)

#define DATA_PIN 2

uint8_t RED;
uint8_t GREEN;
uint8_t BLUE;