#include <Mycelium8266.h>
#include <DHT.h>
#include <CloudIoTCore.h>
#include "esp8266_mqtt.h"

// Adding a Sensor
// by Dhvanil Shah

// Demostrates how to add a sensor, in this case air temperature and humidity,
// with the Mycelium library.

// Created in 2020

#define DHTTYPE DHT22 // DHT 22  (AM2302), AM2321
uint8_t DHTPin = D2;
DHT dht(DHTPin, DHTTYPE);

Mycelium mycel = Mycelium();

void setup()
{
    Serial.begin(115200);
    mycel.connect("SSID", "PASSWORD", -4);
    pinMode(DHTPin, INPUT);
    dht.begin();

    // Add all the sensors
    mycel.attachAirHumidity(getHumidity, 30.0, 40.0);
    mycel.attachAirTemperature(getAirTemperature, 70.0, 85.0);

    setupCloudIoT();
}
unsigned long lastMillis = 0;
void loop()
{
    mycel.run();
    mqtt->loop();
    delay(10); // <- fixes some issues with WiFi stability

    if (!mqttClient->connected())
    {
        ESP.wdtDisable();
        connect();
        ESP.wdtEnable(0);
    }

    // TODO: Replace with your code here
    if (millis() - lastMillis > 60000)
    {
        lastMillis = millis();
        publishTelemetry(mycel.publishSensors());
    }
    delay(500);
}

float getHumidity()
{
    float humidity = dht.readHumidity();
    return humidity;
}

float getAirTemperature()
{
    float airTemp = dht.readTemperature();
    return airTemp;
}