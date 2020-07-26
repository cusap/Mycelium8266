#include <Mycelium8266.h>
#include <CloudIoTCore.h>
#include "esp8266_mqtt.h"

Mycelium mycel = Mycelium();

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    mycel.run();
}