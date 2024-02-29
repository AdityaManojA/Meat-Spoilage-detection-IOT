#include <ESP8266WiFi.h>

const char* ssid     = "FTTH-C928"; 
const char* password = "anitha1090"; 


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