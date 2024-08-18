#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

char auth[] = "ZM4a4NWN-gZQ5Amu4skk8qwhx8CGsQzH";
char ssid[] = "Wifi address";
char pass[] = "wifi pass";

// Define sensor and calibration parameters
#define RL_VALUE 10.0 // Load resistance on the board, in kilo ohms
#define RO_CLEAN_AIR_FACTOR 9.83 // Clean air resistance factor
#define GAS_AMMONIA 0 // Ammonia gas

int gasPin = A0; // Analog pin for gas sensor
float Ro = 10; // Initialize Ro to a default value (will be calibrated)

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  Serial.println("MQ137 Ammonia Gas Sensor Test");
  Serial.println("Heating the sensor...");
  delay(10000); // Wait for the sensor to warm up (adjust as needed)
  Serial.println("Sensor ready!");
}

void loop() {
  Blynk.run();

  float sensorValue = analogRead(gasPin);
  float sensorVoltage = sensorValue / 1023.0 * 5.0; // Convert analog value to voltage
  float RS_gas = (5.0 - sensorVoltage) / sensorVoltage * RL_VALUE; // Calculate RS in kilo ohms

  float ratio = RS_gas / Ro;
  float ammoniaConcentration = pow(10, ((log10(ratio) - 0.2042) / (-0.3268))); // Calculate ammonia concentration

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(sensorVoltage);
  Serial.print("V, Ammonia Concentration: ");
  Serial.print(ammoniaConcentration);
  Serial.println(" ppm");

  // Check if ammonia concentration indicates spoilage
  if (ammoniaConcentration > 2) {
    Serial.println("Spoiled");
  } else {
    Serial.println("Not Spoiled");
  }

  // Send sensor values to Blynk app
  Blynk.virtualWrite(V1, ammoniaConcentration); // Send ammonia concentration to Gauge Widget (V1)
  Blynk.virtualWrite(V2, sensorVoltage);        // Send voltage to Gauge Widget (V2)

  delay(1000); // Delay between readings
}
