#include "Arduino.h"

#include <config.h>

#include <Adafruit_NeoPixel.h>

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
    RED = DMXSerial.read(1 + (i * 3));
    GREEN = DMXSerial.read(2 + (i * 3));
    BLUE = DMXSerial.read(3 + (i * 3));

    strip.setPixelColor(i, RED, GREEN, BLUE);
  }

  strip.show();
}

void setup()
{
  DMXSerial.init(DMXReceiver, 2); 
}

void loop()
{
  updateData();

  delay(25);
}