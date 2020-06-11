#include <Mycelium8266.h>

// Adding an Actuator
// by Dhvanil Shah

// Demostrates how add an actuator, in this case lights, with the Mycelium library

// Created 1 April 2006

Mycelium mycel = Mycelium();

void setup()
{
    Serial.begin(115200);
    mycel.connect("Home", "103yogicenter", -4);
    String lightSchedule[] = {"08:00", "20:00"};
    mycel.attachLights(nullptr, nullptr, lightSchedule);
}

void loop()
{
    mycel.run();
    delay(500);
}
