#include "wifi.h"
#include <WiFi.h>

bool wifiConnected(bool printStatus=true)
{
  bool status = WiFi.status() == WL_CONNECTED;
  if(printStatus) LOG_INFO("WiFi %s\n", status ? "connected" : "not connected");
  return status;
}

bool wifiConnect()
{
  LOG_INFO("Connecting to WiFi '%s', password '%s'\n", WIFI_SSID, WIFI_PASS);

  if (wifiConnected())
    return true;

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  LOG_INFO(".");
  for(int i = 0; i < 10 && !wifiConnected(false); i++)
  {
    delay(1000);
    serialPrintf(".", "");
  }
  bool status = wifiConnected(false);
  serialPrintln("");
  LOG_INFO("Connection %s\n", status ? "successful" : "failed");
  return status;
}

void wifiDisconnect()
{
  WiFi.disconnect();
}