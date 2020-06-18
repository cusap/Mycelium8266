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

//  Connect to WIFI
void Mycelium::connect(char *ssid, char *pwd, int timezone)
{
  ssid = ssid;
  pwd = pwd;
  tz = timezone;

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");

  Serial.println("Connecting to Time Server");
  configTime(tz * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("Waiting on Time Sync...");
  while (time(nullptr) < 1592326510) //timestamp last updated 06/16/2020
  {
    delay(10);
  }
  Serial.println("Connected to Time Server");
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