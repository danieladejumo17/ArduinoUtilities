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

    // ----------- JSON HANDLING ------------
    // A JSON String
    String json = "{\"name\":\"John\",\"age\":30,\"cars\":[\"Ford\",\"BMW\",\"Fiat\"]}";
    
    // Deserialize the JSON String into a JsonObject
    deserializeJSON(json, [&](JsonObject& root) {
        // Get the name
        String name = root["name"];
        logdebug("Name: " + name);
        
        // Get the age
        int age = root["age"];
        logdebug("Age: " + String(age));
        
        // Get the cars
        JsonArray& cars = root["cars"];
        for (JsonArray::iterator it = cars.begin(); it != cars.end(); ++it)
        {
            String car = *it;
            logdebug("Car: " + car);
        }

        // Add a new field, 'city'
        root["city"] = "Berlin";

        // Serialize the JsonObject into a JSON String
        json = serializeJSON(root);
    });

    // Print the updated JSON String
    loginfo("Updated JSON: " + json);
}

void loop()
{}