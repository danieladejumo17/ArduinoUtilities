#include "arduino_utilities.h"

void setup()
{
    Serial.begin(9600);

    // ---------- LOGGING ----------
    logdebug("Hello World");
    loginfo("Hello World");
    logerr("Hello World");
    logwarn("Hello World");
    logfatal("Hello World");
}

void loop()
{}