#include "arduino_utilities.h"

// ----------- LOGGING ------------
void logdebug(const String& debugString)
{
  Serial.println(String("DEBUG: ") + debugString);
}

void loginfo(const String& info)
{
  Serial.println(String("INFO: ") + info);
}

void logwarn(const String& warning)
{
  Serial.println(String("WARN: ") + warning);
}

void logerr(const String& err)
{
  Serial.println(String("ERROR: ") + err);
}

void logfatal(const String& info)
{
  Serial.println(String("FATAL: ") + info);
}


// ----------- JSON HANDLING ------------
template <typename Callback>
void deserializeJSON(const String &json, Callback callback)
{
    DynamicJsonBuffer jsonBuffer(JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(3) + json.length());
    JsonObject& root = jsonBuffer.parseObject(json);
    if (!root.success())
    {
        logerr("Failed to parse JSON");
        return;
    }
    callback(root);
}

String serializeJSON(const JsonObject &json)
{
    String result;
    json.printTo(result);
    return result;
}

template <typename Callback>
void serializeJSON(const JsonObject &json, Callback callback)
{
    callback(serializeJSON(json));
}