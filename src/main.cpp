#include <Arduino.h>
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

// Include Firebase library
#include <Firebase_ESP_Client.h>

// Other dependencies
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;


bool signedUp = false;

void setup(){
  Serial.begin(115200);
  WiFi.begin(std::getenv("WIFI_SSID"), std::getenv("WIFI_PASSWORD"));

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }

  config.api_key = std::getenv("API_KEY");
  config.database_url = std::getenv("DATABASE_URL");

  auth.user.email = std::getenv("USER_EMAIL");
  auth.user.password = std::getenv("USER_PASSWORD");

  if (Firebase.signUp(&config, &auth, auth.user.email, auth.user.password)) {
    Serial.print("Sign up was a success.");
    signedUp = true;
  } else {
    Serial.print(config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop(){

}
