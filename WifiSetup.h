/*-------------------------------------------------------------------------------------------------
WIFI LIBRARY
-------------------------------------------------------------------------------------------------*/
#include <WiFi.h>

/*-------------------------------------------------------------------------------------------------
SSID & PASSWORD
-------------------------------------------------------------------------------------------------*/
const char* ssid = "Balki Home-4G";
const char* password = "6r77ykprh4";

/*-------------------------------------------------------------------------------------------------
WIFI SETUP
-------------------------------------------------------------------------------------------------*/
void wifiSetup(){

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  Serial.print("\nConnecting to WiFi");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}