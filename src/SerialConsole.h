#pragma once

#include "DebugConfiguration.h"

#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

void serialInit();
void serialLogPrintf(char *level, char *format, ...);
void serialPrintf(char *format, ...);
void serialPrintln(char *format);