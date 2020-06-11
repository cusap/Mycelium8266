/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include this library's description file
#include "Mycelium8266.h"

void Mycelium::attachLiquidLevel(int (*check)(), int low, int high)
{
    Sensor liquidLevelSensor;
    liquidLevelSensor.highThresh = high;
    liquidLevelSensor.lowThres = low;
    liquidLevelSensor.check = check;
    liquidLevelSensor.name = "LiquidLevel";

    sensors.push_back(liquidLevelSensor);
}

void Mycelium::attachAirTemperature(int (*check)(), int low, int high)
{
    Sensor airTemp;
    airTemp.highThresh = high;
    airTemp.lowThres = low;
    airTemp.check = check;
    airTemp.name = "AirTemperature";

    sensors.push_back(airTemp);
}

void Mycelium::attachAirHumidity(int (*check)(), int low, int high)
{
    Sensor airHum;
    airHum.highThresh = high;
    airHum.lowThres = low;
    airHum.check = check;
    airHum.name = "AirHumidity";

    sensors.push_back(airHum);
}