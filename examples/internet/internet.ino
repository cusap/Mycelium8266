#include <Mycelium8266.h>

// Doing Something
// by John Doe <http://www.yourwebsite.com>

// Demostrates how to do something with the Test library

// Created 1 April 2006

Mycelium mycel = Mycelium();

void setup()
{
  Serial.begin(115200);
  mycel.connect("Home", "103yogicenter", -4);
}

void loop()
{
  mycel.getTime();
  delay(500);
}
