/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include this library's description file
#include "Mycelium8266.h"
// #include "vector"

void Mycelium::attachLights(void (*on)(), void (*off)(), vector<int> schedule)
{
    verifySchedule(schedule);
    Actuator lights;
    lights.on = on;
    lights.off = off;
    lights.actuatorOn = false;
    lights.schedule = schedule;
    lights.name = "Lights";

    actuators.push_back(lights);
    return;
}

void Mycelium::verifySchedule(vector<int> schedule)
{
    int count = 0, last = 0;
    for (auto vectorit = schedule.begin(); vectorit != schedule.end(); ++vectorit)
    {
        count += 1;
        if (*vectorit > last)
            last = *vectorit;
        else if (*vectorit < 0 || *vectorit > 2400)
            throwError("Times are out of bound. Must be within 0-2400");
        else
            throwError("Schedule Should Be in Ascending time order.");
    }

    if ((count % 2) != 0)
        throwError("Schedule Should Have an Even Number of On/Off Times.");

    return;
}