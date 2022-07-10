#ifndef ARDUINO_UTILITIES_HEADER
#define ARDUINO_UTILITIES_HEADER

#include <Arduino.h>

// ---------- LOGGING ---------------
void logdebug(const String& message);
void loginfo(const String& message);
void logerr(const String& message);
void logwarn(const String& message);
void logfatal(const String& message);

#endif