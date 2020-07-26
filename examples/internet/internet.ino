#include <Mycelium8266.h>
#include <CloudIoTCore.h>
#include "esp8266_mqtt.h"
// Connecting to the Internet
// by Dhvanil Shah

// Demostrates how to connect to the internet

// Created in 2020

Mycelium mycel = Mycelium();

void setup()
{
  Serial.begin(115200);
  mycel.connect();
}

void loop()
{
  mycel.run();
  delay(500);
}
