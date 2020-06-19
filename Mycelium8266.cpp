// include this library's description file
#include "Mycelium8266.h"
// #include <ArduinoJson.h>

void mqttLoop();
bool publishTelemetry(String data);

// Constructor
Mycelium::Mycelium()
{
    return;
}

void Mycelium::run()
{
    Serial.println("Analyzing Actuators");
    for (auto actuatorit = actuators.begin(); actuatorit != actuators.end(); ++actuatorit)
    {
        Serial.print("Processing: ");
        Serial.println((*actuatorit).name);
        int t = getTime();
        Serial.println(t);
        bool toggleOn = false;
        for (auto timeit = ((*actuatorit).schedule).begin(); timeit != ((*actuatorit).schedule).end(); timeit++)
        {
            int min = *timeit;
            timeit++;
            int max = *timeit;

            if ((min < t) && (max > t))
            {
                toggleOn = true;
            }
        }
        if (toggleOn)
            (*actuatorit).on();
        else
            (*actuatorit).off();
    }

    Serial.println("Analyzing Sensors");
    for (auto sensorit = sensors.begin(); sensorit != sensors.end(); ++sensorit)
    {
        Serial.print("Processing: ");
        Serial.println((*sensorit).name);
        float reading = (*sensorit).check();
        Serial.print("Value: ");
        Serial.println(reading);
        (*sensorit).lastReading = reading;
        float min = (*sensorit).low;
        float max = (*sensorit).high;
        if ((min > reading) || (max < reading))
            (*sensorit).activeIssue = true;
        else
            (*sensorit).activeIssue = false;
    }
    Serial.println("\n");

    if (cloudConnected)
    {
        mqttLoop();
        long now = time(nullptr);
        if (now - IOT_INTERVAL > lastUpdate)
        {
            lastUpdate = now;
            publishTelemetry(publishSensors());
        }
    }
    return;
}

String Mycelium::publishSensors()
{
    const size_t capacity = SENSORS_SUPPORTED * JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(SENSORS_SUPPORTED);
    StaticJsonDocument<capacity> doc;
    for (auto sensorit = sensors.begin(); sensorit != sensors.end(); ++sensorit)
    {
        doc[(*sensorit).code]["val"] = (*sensorit).lastReading;
        doc[(*sensorit).code]["iss"] = (*sensorit).activeIssue;
    }
    String data;
    serializeJson(doc, data);
    return data;
}

void Mycelium::throwError(String error)
{
    while (1)
    {
        Serial.println(error);
        delay(500);
    }
}