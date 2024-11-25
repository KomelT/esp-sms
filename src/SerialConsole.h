#pragma once

#include "DebugConfiguration.h"

#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

void serialInit();
void serialLogPrintf(String level, String format, ...);
void serialPrintf(String format, ...);
void serialPrintln(String format);