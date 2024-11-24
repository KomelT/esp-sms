#pragma once

#include "configuration.h"
#include "SerialConsole.h"

#define ESP_SMS_LOG_LEVEL_DEBUG "DEBUG"
#define ESP_SMS_LOG_LEVEL_INFO "INFO"
#define ESP_SMS_LOG_LEVEL_WARN "WARN"
#define ESP_SMS_LOG_LEVEL_ERROR "ERROR"
#define ESP_SMS_LOG_LEVEL_CRIT "CRIT"
#define ESP_SMS_LOG_LEVEL_TRACE "TRACE"

#define LOG_DEBUG(...) serialLogPrintf(ESP_SMS_LOG_LEVEL_DEBUG, __VA_ARGS__);
#define LOG_INFO(...) serialLogPrintf(ESP_SMS_LOG_LEVEL_INFO, __VA_ARGS__);
#define LOG_WARN(...) serialLogPrintf(ESP_SMS_LOG_LEVEL_WARN, __VA_ARGS__);
#define LOG_ERROR(...) serialLogPrintf(ESP_SMS_LOG_LEVEL_ERROR, __VA_ARGS__);
#define LOG_CRIT(...) serialLogPrintf(ESP_SMS_LOG_LEVEL_CRIT, __VA_ARGS__);
#define LOG_TRACE(...) serialLogPrintf(ESP_SMS_LOG_LEVEL_TRACE, __VA_ARGS__);