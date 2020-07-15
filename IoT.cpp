/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core WIFI API
// #include "ESP8266WiFi.h"
// include core time API

// include this library's description file
#include "Mycelium8266.h"
#include <time.h>

void setupCloudIoT();
void connect();

//  Connect to WIFI
void Mycelium::connect()
{
  setupCloudIoT();
  cloudConnected = true;
  return;
}

int Mycelium::getTime()
{
  struct tm *timeinfo;

  time_t now = time(nullptr);
  timeinfo = localtime(&now);
  int hour = timeinfo->tm_hour, min = timeinfo->tm_min;
  return hour * 100 + min;
}

// void Mycelium::setupCert()
// {
//   // Set CA cert on wifi client
//   // If using a static (pem) cert, uncomment in ciotc_config.h:
//   certList.append(primary_ca);
//   certList.append(backup_ca);
//   netClient->setTrustAnchors(&certList);
//   return;
// }

// void Mycelium::setupCloudIoT()
// {
//   // Create the device
//   device = new CloudIoTCoreDevice(
//       project_id, location, registry_id, device_id,
//       private_key_str);
//   // ESP8266 WiFi setup
//   netClient = new WiFiClientSecure();
//   // ESP8266 WiFi secure initialization
//   setupCert();
//   mqttClient = new MQTTClient(512);
//   mqttClient->setOptions(180, true, 1000); // keepAlive, cleanSession, timeout
//   mqtt = new CloudIoTCoreMqtt(mqttClient, netClient, device);
//   mqtt->setUseLts(true);
//   mqtt->startMQTT(); // Opens connection
// }