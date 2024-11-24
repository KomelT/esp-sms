#include "SerialConsole.h"
#include "configuration.h"

void serialInit()
{
  Serial.begin(SERIAL_BAUD);
}

void serialLogPrintf(char *level, char *format, ...)
{
  // format log level
  char levelF[16];
  snprintf(levelF, sizeof(levelF), "[%s]", level);
  char text[256];

  // format message
  va_list args;
  va_start(args, format);
  vsnprintf(text, sizeof(text), format, args);
  va_end(args);

  Serial.printf("%-7s %s", levelF, text);
}

void serialPrintf(char *format, ...)
{
  char text[256];

  // format message
  va_list args;
  va_start(args, format);
  vsnprintf(text, sizeof(text), format, args);
  va_end(args);

  Serial.print(text);
}

void serialPrintln(char *format)
{
  Serial.println(format);
}