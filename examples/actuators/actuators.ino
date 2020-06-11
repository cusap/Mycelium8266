#include <Mycelium8266.h>

// Adding an Actuator
// by Dhvanil Shah

// Demostrates how to add an actuator, in this case lights, with the Mycelium library

// Created in 2020

Mycelium mycel = Mycelium();

void setup()
{
    Serial.begin(115200);
    mycel.connect("SSID", "PASSWORD", -4);
    vector<int> schedule = {100, 200, 2000, 2400};
    mycel.attachLights(nullptr, nullptr, lightSchedule);
}

void loop()
{
    mycel.run();
    delay(500);
}
