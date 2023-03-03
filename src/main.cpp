#include <Arduino.h>
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

// Include Firebase library
#include <Firebase_ESP_Client.h>

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// config.host = FIREBASE_HOST;
// config.api_key = API_KEY;

// auth.user.email = USER_EMAIL;
// auth.user.password = USER_PASSWORD;

// Firebase.begin(&config, &auth);

// Firebase.reconnectWiFi(true);

void setup(){
  Serial.begin(115200);
}

void loop(){
}
