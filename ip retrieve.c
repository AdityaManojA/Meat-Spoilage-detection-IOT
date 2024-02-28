#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin("Nothing", "melvindavis");

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print IP address
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your loop code here
}
