#include "Arduino.h"

#include <config.h>

bool checkLivedata()
{
  unsigned long lastPacket = DMXSerial.noDataSince();

  return (lastPacket < 2000);
}

void updateData()
{
  if (!checkLivedata())
  {
    digitalWrite(LED_BUILTIN, 0);
    return;
  }

  digitalWrite(LED_BUILTIN, 1);

  for (int i = 0; i < MAX_VIABLE_LEDS; i++)
  {
    uint8_t RED = DMXSerial.read((i * 3) + 1);
    uint8_t GREEN = DMXSerial.read((i * 3) + 2);
    uint8_t BLUE = DMXSerial.read((i * 3) + 3);

    CRGB c(RED, GREEN, BLUE);
    leds[i] = c;
  }

  FastLED.show();
}

void setup()
{
  DMXSerial.init(DMXReceiver, 2); 

  FastLED.addLeds<NEOPIXEL, PIN_DATA>(leds, MAX_VIABLE_CHANNELS);
}

void loop()
{
  updateData();

  delay(10);
}