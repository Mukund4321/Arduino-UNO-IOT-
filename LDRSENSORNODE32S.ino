#include <Arduino.h>
#include <WiFi.h>

#define USE_SERIAL Serial
#include <HTTPClient.h>

const char* ssid = "Entuple2";   // your network SSID (name)
const char* password = "En!uple@2023";   // your network password

void setup() {

    USE_SERIAL.begin(9600);
   // USE_SERIAL.setDebugOutput(true);
   WiFi.begin(ssid, password);   
   while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
   }
   Serial.println("");
   Serial.print("WiFi connected - ESP IP address:");
   Serial.println(WiFi.localIP());   
}

void loop() {
        
        // Read LDR value
        int ldr = analogRead(A0);
        USE_SERIAL.println(ldr);

        // Form URL
        char url[256];
        sprintf (url, "http://192.168.62.118:1880/nodemcu?ldr=%d", ldr);

        HTTPClient http;
        WiFiClient client;
        USE_SERIAL.print("[HTTP] begin...\n");
        // configure traged server and url
        http.begin(client,url); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();
        USE_SERIAL.print(httpCode);

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
  delay(2000);
}