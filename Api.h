#include <string.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

//POST
void sendCardNo(String cardNo){

  if (WiFi.status() == WL_CONNECTED) {
    String urlFinal = "https://attendance-lohg.onrender.com/save-card";
    
    HTTPClient http;
    http.begin(urlFinal.c_str());
    http.addHeader("Content-Type", "application/json");
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);

    String jsonString= "{\"cardId\":\"" + cardNo + "\"}";

    int httpCode = http.POST(jsonString);

    if (httpCode == HTTP_CODE_CREATED) {//201
      onWhiteLed();
      Serial.println("Data successfully posted!");
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.println("HTTP POST request failed");
      onRedLed();
    }

    http.end();

  } else {
    Serial.println("WiFi not connected");
  }
}