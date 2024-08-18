#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define RL_VALUE 10.0 // Load resistance on the board, in kilo ohms
#define RO_CLEAN_AIR_FACTOR 9.83 // Clean air resistance factor
#define GAS_AMMONIA 0 // Ammonia gas


const int serverPort = 80; // HTTP server port, typically 80
const char* serverPath = "/sensordata/post-esp-data.php"; // Path to your PHP script
const char* ssid = "wifi address"; 
const char* password = "Wifi Password";
const char* serverName = "192.168.202.218"; // Correct IP address
String apiKeyValue = "tPmAT5Ab3j7F9";
String sensorName = "MQ137"; // Name of your sensor, adjust accordingly

int gasPin = A0; // Analog pin for gas sensor
float Ro = 10; // Initialize Ro to a default value (will be calibrated)

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

  Serial.println("MQ137 Ammonia Gas Sensor Test");
  Serial.println("Heating the sensor...");
  delay(10000); // Wait for the sensor to warm up (adjust as needed)
  Serial.println("Sensor ready!");
  Serial.println("Let's test some Meat ;)");
}

void loop() {
  float sensorValue = analogRead(gasPin);
  float sensorVoltage = sensorValue / 1023.0 * 5.0; // Convert analog value to voltage
  float RS_gas = (5.0 - sensorVoltage) / sensorVoltage * RL_VALUE; // Calculate RS in kilo ohms

  float ratio = RS_gas / Ro;
 // Calculate ammonia concentration
  float ammoniaConcentration = pow(10, ((log10(ratio) - 0.2042) / (-0.3268)));
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(sensorVoltage);
  Serial.print("V, Ammonia Concentration: ");
  Serial.print(ammoniaConcentration);
  Serial.println(" ppm");

  // Determine if spoiled
  String spoiledStatus;
  if (ammoniaConcentration > 0.1) { // Adjust threshold accordingly
    Serial.println("Spoiled");
    spoiledStatus = "Spoiled";
  } else {
    Serial.println("Not Spoiled");
    spoiledStatus = "Not Spoiled";
  }

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Prepare the complete URL
    String url = "http://" + String(serverName) + ":" + String(serverPort) + serverPath;

    http.begin(client, url);
    
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName + "&value1=" + String(ammoniaConcentration) + "&Sstatus=" + spoiledStatus;
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);

    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }

  delay(1000);
}
