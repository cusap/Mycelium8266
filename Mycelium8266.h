/*
  Mycelium8266.h - Test library for Wiring - description
  Copyright (c) 2020 Dhvanil Shah.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Mycelium8266_h
#define Mycelium8266_h

#include "ESP8266WiFi.h"
#include "time.h"
#include "vector"
using namespace std;

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
    int lowThres;
    int highThresh;
    int lastReading;
    int (*check)();
    bool activeIssue;
    String name;
} Sensor;

// library interface description
class Mycelium
{
    // user-accessible "public" interface
public:
    Mycelium();
    void connect(char *ssid, char *pwd, int timezone);
    int getTime();

    // Actuators
    void attachLights(void (*on)(), void (*off)(), vector<int> schedule);

    // Sensors
    void attachLiquidLevel(int (*check)(), int low, int high);
    void attachAirTemperature(int (*check)(), int low, int high);
    void attachAirHumidity(int (*check)(), int low, int high);

    // Main Loop Function
    void run();

    // library-accessible "private" interface
private:
    char *ssid;
    char *pwd;
    int tz; //timezone

    // Actuators
    vector<Actuator> actuators;
    void verifySchedule(vector<int> schedule);

    // Sensors
    vector<Sensor> sensors;

    // Error
    void throwError(String error);
};

#endif