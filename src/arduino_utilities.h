#ifndef ARDUINO_UTILITIES_HEADER
#define ARDUINO_UTILITIES_HEADER

#include <Arduino.h>
#include <ArduinoJson.h>

// ---------- LOGGING ---------------
void logdebug(const String& message);
void loginfo(const String& message);
void logerr(const String& message);
void logwarn(const String& message);
void logfatal(const String& message);


// ---------- JSON HANDLING ---------------
/**
 * @brief deserialize a JSON string into a JsonObject
 * @param json the JSON string to deserialize
 * @param callback the callback to call with the deserialized JsonObject
 */ 
template <typename Callback>
void deserializeJSON(const String &json, Callback callback);

/**
 * @brief serialize a JsonObject into a JSON string
 * @param json the JsonObject to serialize
 * @return the serialized JSON string
 */ 
String serializeJSON(const JsonObject &json);

/**
 * @brief serialize a JsonObject into a JSON string and call the callback with the serialized string
 * @param json the JsonObject to serialize
 * @param callback the callback to call with the serialized JSON string
 */ 
template <typename Callback>
void serializeJSON(const JsonObject &json, Callback callback);

#endif