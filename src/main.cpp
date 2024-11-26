#include "configuration.h"
#include "DebugConfiguration.h"
#include "wifi/wifi.h"
#include "sim/sim.h"

void setup()
{
  serialInit();

  sim_init();
  sim_test();
}

void loop()
{
}