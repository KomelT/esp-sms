#include "SerialConsole.h"
#include "configuration.h"

void serialInit()
{
  Serial.begin(SERIAL_BAUD);
}

void serialLogPrintf(String level, String format, ...)
{
  // format level
  int levelf_size = sizeof(char) * level.length() + 3;
  char *levelf = static_cast<char *>(malloc(levelf_size));
  snprintf(levelf, levelf_size, "[%s]", level.c_str());

  // format message
  int formatc_size = sizeof(char) * format.length() + 1;
  char *formatc = static_cast<char *>(malloc(formatc_size));
  strcpy(formatc, format.c_str());

  char *text = static_cast<char *>(malloc(formatc_size * 2));

  va_list args;
  va_start(args, format);
  vsnprintf(text, formatc_size * 2, formatc, args);
  va_end(args);

  Serial.printf("%-7s %s\n", levelf, text);

  free(levelf);
  free(formatc);
  free(text);
}

void serialPrintf(String format, ...)
{
  // format message
  int format_size = sizeof(char) * format.length() + 1;
  char *text = static_cast<char *>(malloc(format_size * 2));
  const char *formatc = format.c_str();
  va_list args;
  va_start(args, format);
  vsnprintf(text, format_size * 2, formatc, args);
  va_end(args);

  Serial.print(text);

  free(text);
}

void serialPrintln(String format)
{
  Serial.println(format);
}