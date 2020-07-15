/*
  Mycelium8266.h - Test library for Wiring - description
  Copyright (c) 2020 Dhvanil Shah.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Mycelium8266_h
#define Mycelium8266_h

#include "ESP8266WiFi.h"
#include <time.h>
#include "vector"
#include <ArduinoJson.h>
using namespace std;

#define IOT_INTERVAL 60 * 5 //  1 Minute
#define SENSORS_SUPPORTED 3 // Number of Sensors Supported

// STRUCT DEFS
typedef struct
{
    vector<int> schedule;
    void (*on)();
    void (*off)();
    bool actuatorOn;
    String name;
} Actuator;

typedef struct
{
    float low;
    float high;
    float lastReading;
    float (*check)();
    bool activeIssue;
    String name;
    String code;
} Sensor;

// library interface description
class Mycelium
{
    // user-accessible "public" interface
public:
    Mycelium();
    void connect();
    int getTime();

    // Actuators
    void attachLights(void (*on)(), void (*off)(), vector<int> schedule);

    // Sensors
    void attachLiquidLevel(float (*check)(), float low, float high);
    void attachAirTemperature(float (*check)(), float low, float high);
    void attachAirHumidity(float (*check)(), float low, float high);
    String publishSensors();

    // Main Loop Function
    void run();

    // library-accessible "private" interface
private:
    // Cloud IoT
    bool cloudConnected = false;

    // Actuators
    vector<Actuator> actuators;
    void verifySchedule(vector<int> schedule);

    // Sensors
    long lastUpdate = 0;
    long updateInterval = 5; //5 Seconds
    vector<Sensor> sensors;

    // Error
    void throwError(String error);
};

#endif