#include "../configuration.h"

// Set serial for AT commands (to the module)
#define SerialAT  Serial1

void sim_init();
bool sim_test();
bool sim_send_sms(String number, String text);