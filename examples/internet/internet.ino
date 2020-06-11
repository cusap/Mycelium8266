#include <Mycelium8266.h>

// Connecting to the Internet
// by Dhvanil Shah

// Demostrates how to connect to the internet

// Created in 2020

Mycelium mycel = Mycelium();

void setup()
{
  Serial.begin(115200);
  mycel.connect("SSID", "PASSWORD", -4);
}

void loop()
{
  mycel.run();
  delay(500);
}
