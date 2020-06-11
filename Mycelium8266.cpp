// include this library's description file
#include "Mycelium8266.h"

// Constructor
Mycelium::Mycelium()
{
    return;
}

void Mycelium::run()
{
    Serial.println("Analyzing Actuatons");
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
            (*actuatorit).off()
    }
    Serial.println("\n");
    return;
}

void Mycelium::throwError(String error)
{
    while (1)
    {
        Serial.println(error);
        delay(500);
    }
}