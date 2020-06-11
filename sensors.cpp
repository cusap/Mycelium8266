/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include this library's description file
#include "Mycelium8266.h"

void Mycelium::attachLiquidLevel(float (*check)(), float low, float high)
{
    Sensor liquidLevelSensor;
    liquidLevelSensor.high = high;
    liquidLevelSensor.low = low;
    liquidLevelSensor.check = check;
    liquidLevelSensor.name = "LiquidLevel";

    sensors.push_back(liquidLevelSensor);
}

void Mycelium::attachAirTemperature(float (*check)(), float low, float high)
{
    Sensor airTemp;
    airTemp.high = high;
    airTemp.low = low;
    airTemp.check = check;
    airTemp.name = "AirTemperature";

    sensors.push_back(airTemp);
}

void Mycelium::attachAirHumidity(float (*check)(), float low, float high)
{
    Sensor airHum;
    airHum.high = high;
    airHum.low = low;
    airHum.check = check;
    airHum.name = "AirHumidity";

    sensors.push_back(airHum);
}