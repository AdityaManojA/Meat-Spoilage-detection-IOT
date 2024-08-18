#include <ESP8266WiFi.h>

char ssid[] = "Wifi address";
char pass[] = "wifi pass";


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }

  Serial.print("Attempting to connect to SSID");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("*");

    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
}

void loop() {
}