#define RL_VALUE 10.0 // Define the load resistance on the board, in kilo ohms
#define RO_CLEAN_AIR_FACTOR 9.83 // RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO,
                                  // which is derived from the chart in datasheet
#define GAS_AMMONIA 0 // Ammonia gas

int gasPin = A0; // Define the analog pin for gas sensor
float Ro = 10; // Ro is initialized to 10 kilo ohms

void setup() {
  Serial.begin(9600); // Initialize serial communication
  // Print a message to the serial monitor
  Serial.println("MQ137 Ammonia Gas Sensor Test");
  Serial.println("Heating the sensor...");
  // Wait for the sensor to warm up
  delay(10000); // Delay 10 seconds for sensor warming up
  Serial.println("Sensor ready!");
}

void loop() {
  float sensorValue = analogRead(gasPin); // Read the analog value from sensor
  float sensorVoltage = sensorValue / 1023.0 * 5.0; // Convert the analog value to voltage
  float RS_gas = (5.0 - sensorVoltage) / sensorVoltage * RL_VALUE; // Get the value of RS in kilo ohms

  // Use the ratio of RS/Ro to calculate the gas concentration
  float ratio = RS_gas / Ro;
  
  // Calculate the ammonia concentration using the MQ137 gas sensor curve
  float ammoniaConcentration = pow(10, ((log10(ratio) - 0.2042) / (-0.3268))); // Adjusted curve parameters for increased sensitivity
  
  // Print the sensor and gas concentration values to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(sensorVoltage);
  Serial.print("V, Ammonia Concentration: ");
  if(ammoniaConcentration>13){
    Serial.print("Spoiled");
  }
  else if(ammoniaConcentration<=13){
    Serial.print("not Spoiled");
  }
  Serial.println(" ppm");

  delay(1000); // Delay for 1 second between readings
}

