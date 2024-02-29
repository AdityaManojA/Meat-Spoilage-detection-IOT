#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "ZM4a4NWN-gZQ5Amu4skk8qwhx8CGsQzH"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Batman";
char pass[] = "21savage";

BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}

void setup() {
  pinMode(D0, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
