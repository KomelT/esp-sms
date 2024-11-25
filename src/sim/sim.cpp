#include "sim.h"

String sim_listen_for_response(int timeout_ms = 1000)
{
  int timeout_sum = 0;
  String res = "";
  while (timeout_sum < timeout_ms)
  {
    while (SerialAT.available())
    {
      res = SerialAT.readString();
      return res;
    }
    timeout_sum += 100;
    delay(100);
  }

  return res;
}

void sim_init()
{
  LOG_INFO("Initializing SIM modem");

  // Set GSM module baud rate and UART pins
  SerialAT.begin(115200, SERIAL_8N1, MODEM_TX, MODEM_RX);

  // Keep reset high
  pinMode(MODEM_RST, OUTPUT);
  digitalWrite(MODEM_RST, HIGH);

  pinMode(MODEM_PWRKEY, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);

  // Turn on the Modem power first
  digitalWrite(MODEM_POWER_ON, HIGH);

  // Pull down PWRKEY for more than 1 second according to manual requirements
  digitalWrite(MODEM_PWRKEY, HIGH);
  delay(100);
  digitalWrite(MODEM_PWRKEY, LOW);
  delay(1000);
  digitalWrite(MODEM_PWRKEY, HIGH);

  // Wait for modem to wake up
  delay(6000);
  LOG_INFO("SIM modem initialized");
}

bool sim_test()
{
  LOG_INFO("Testing SIM modem");

  LOG_DEBUG("Sending AT command to SIM modem, expecting response 'AT OK'");
  SerialAT.println("AT");

  if (sim_listen_for_response(2000) == "AT\r\r\nOK\r\n")
  {
    LOG_INFO("SIM modem test successful");
    return true;
  }

  LOG_ERROR("SIM modem test failed");
  return false;
}

// https://www.smssolutions.net/tutorials/gsm/sendsmsat/
bool sim_send_sms(String number, String text)
{
  LOG_INFO("Sending SMS to '%s'", number);

  LOG_DEBUG("Sending 'AT+CMGF=1\r'")
  SerialAT.print("AT+CMGF=1\r"); // Set the shield to SMS mode

  LOG_INFO(sim_listen_for_response())

  LOG_DEBUG("Sending 'AT+CMGS=\"number\"\r'")
  SerialAT.print("AT+CMGS=\"");
  SerialAT.print(number);
  SerialAT.println("\"");

  LOG_INFO(sim_listen_for_response())

  /*
  if (sim_listen_for_response() != "AT+CMGF=1\r\r\nOK\r\n")
  {
    LOG_ERROR("Failed to set SMS mode");
    return false;
  }
  */

  // LOG_DEBUG("Sending text '%s'", text)
  // SerialAT.print(text);
  // delay(100);
  // SerialAT.write(26);
  // delay(100);
}