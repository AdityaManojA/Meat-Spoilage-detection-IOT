# Meat Spoilage Detection System

## Project Overview

This project aims to develop a **Meat Spoilage Detection System** that accurately estimates the spoilage level of chicken samples. The system leverages pH and ammonia values to analyze the spoilage factor. Notably, the detection is contactless, with the system designed to read ammonia values emitted into the air from the meat sample.

## Features

- **No-Contact Detection**: Utilizes air-sensing technology to detect ammonia levels without direct contact with the meat sample.
- **Dual Parameter Analysis**: Employs both pH and ammonia measurements to assess the spoilage level.
- **Real-Time Monitoring**: Capable of providing real-time spoilage data for better decision-making in food safety.
- **Wi-Fi Connectivity**: The system uses the ESP8266 module to send sensor data to a remote server via Wi-Fi.
- **PHP Backend Integration**: The data is sent to a server running a PHP script, which can store and process the information for further analysis.

## Installation

### Hardware Requirements

- ESP8266 Wi-Fi Module
- MQ137 Ammonia Gas Sensor
- Analog pin for gas sensor connection

### Software Requirements

- Arduino IDE with ESP8266 Board Support
- A server with PHP installed
- A database (MySQL recommended)

### Setting Up the Project

1. **Clone the repository**:
    ```bash
    git clone https://github.com/username/meat-spoilage-detection.git
    cd meat-spoilage-detection
    ```

2. **Install required dependencies**:
    ```bash
    pip install -r requirements.txt
    ```

3. **Configure the PHP script**:
   - Place the `post-esp-data.php` script in your server’s root directory.
   - Ensure your server's IP address and port number are correctly set in the code.

4. **Flash the ESP8266**:
   - Open the Arduino IDE.
   - Load the `main.ino` file from the repository.
   - Ensure the Wi-Fi credentials and server details are correctly entered.
   - Flash the code onto the ESP8266.

5. **Run the system**:
    ```bash
    python main.py
    ```

## How It Works

1. **Ammonia Detection**: The system uses an MQ137 sensor to detect ammonia levels in the air around the chicken sample. Ammonia is a key indicator of meat spoilage.

2. **Wi-Fi Communication**: The ESP8266 connects to a Wi-Fi network using the provided SSID and password. It sends sensor data to a PHP script hosted on a server.

3. **pH Analysis**: Alongside ammonia readings, the pH value is also considered for more accurate spoilage detection.

4. **Spoilage Estimation**: The system calculates the ammonia concentration and determines if the meat is spoiled based on a predefined threshold.

5. **Data Logging**: The sensor data, including ammonia concentration and spoilage status, is sent via HTTP POST to a server-side PHP script, which can log the data into a database for further analysis.

## Code Explanation

### Main Code Components

- **Wi-Fi Setup**: 
   ```cpp
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
       Serial.print("*");
       delay(1000);
   }
   ```
   Connects the ESP8266 to the specified Wi-Fi network.

- **Ammonia Concentration Calculation**: 
   ```cpp
   float RS_gas = (5.0 - sensorVoltage) / sensorVoltage * RL_VALUE;
   float ratio = RS_gas / Ro;
   float ammoniaConcentration = pow(10, ((log10(ratio) - 0.2042) / (-0.3268)));
   ```
   This calculates the ammonia concentration in parts per million (ppm) using the sensor's analog output.

- **HTTP POST Request**:
   ```cpp
   String url = "http://" + String(serverName) + ":" + String(serverPort) + serverPath;
   http.begin(client, url);
   String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName + "&value1=" + String(ammoniaConcentration) + "&Sstatus=" + spoiledStatus;
   int httpResponseCode = http.POST(httpRequestData);
   ```
   Sends the sensor data to the server using a POST request to the specified PHP script.

### PHP Backend

The PHP script (`post-esp-data.php`) receives the sensor data and can store it in a database for further analysis. Make sure to configure your PHP server to handle the incoming data and store it securely.

## Usage

1. **Prepare the Sensor**: Ensure the MQ137 sensor is properly connected and calibrated.
2. **Start the System**: Power on the ESP8266 and monitor the serial output for connection status and sensor readings.
3. **View Results**: Data is sent to the server where it can be accessed and analyzed.

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For any inquiries, please contact Aditya Manoj at [adityamanoja@gmail.com](mailto:adityamanoja@gmail.com).
