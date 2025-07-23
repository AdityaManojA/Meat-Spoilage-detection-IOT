# ServeGuard: Food Spoilage Sensing Module 🥩📡

[![Paper Link](https://img.shields.io/badge/Read%20Our%20Paper%20on-Academia.edu-blue)](https://www.academia.edu/143035003/ServeGuard_Food_Spoilage_Sensing_Module)

> 📄 **[Click here to access our full research paper](https://www.academia.edu/143035003/ServeGuard_Food_Spoilage_Sensing_Module)**  
> Published as part of the KSCSTE TECHFEST 2024 proceedings, Volume 14, Issue 07, July 2025 (IJERT submission).

---

## 🧠 Project Overview

**ServeGuard** is a real-time meat spoilage detection system that leverages **IoT sensors** and **airborne gas analysis** to assess the freshness of chicken. Using an **MQ137 ammonia gas sensor** and a **pH sensor**, the system provides early warnings of spoilage without physical contact. This project was developed as part of our academic research initiative to combat foodborne illness through tech-enabled food safety.

---

## 🎯 Key Features

- 🔬 **Contactless Detection**: Measures airborne ammonia without physical contact with the meat.
- 📈 **Dual Sensor Analysis**: Combines pH level and gas concentration for reliable spoilage estimation.
- 🌐 **Wi-Fi Enabled**: Uses ESP8266 for seamless data transmission to a server.
- 📲 **PHP-MySQL Backend Integration**: Real-time data logging and analysis via web infrastructure.
- 🔁 **Continuous Monitoring**: Real-time updates make it suitable for food storage units, supermarkets, and supply chains.
- 📊 **Backed by Research**: Full paper with methodology, results, and future scope is [available here](https://www.academia.edu/143035003/ServeGuard_Food_Spoilage_Sensing_Module).

---

## ⚙️ Hardware Requirements

- ESP8266 (NodeMCU)
- MQ137 Ammonia Gas Sensor
- pH Sensor (optional for advanced detection)
- Jumper wires, Breadboard
- Power source (5V)

---

## 💻 Software Requirements

- Arduino IDE (with ESP8266 board support)
- Local or cloud-based LAMP stack (Linux, Apache, MySQL, PHP)
- PHP script: `post-esp-data.php`
- Optional: Python script for serial monitoring

---

## 🚀 Installation & Setup

### 1. Clone the Repository
```bash
git clone https://github.com/username/meat-spoilage-detection.git
cd meat-spoilage-detection
```

### 2. Configure the Server
- Copy `post-esp-data.php` to your PHP server root directory.
- Setup a MySQL database to log the incoming data.

### 3. Flash the ESP8266
- Open `main.ino` in Arduino IDE.
- Enter your Wi-Fi credentials and server details.
- Upload to ESP8266.

### 4. Start the System
```bash
python main.py  # (Optional Python monitor script)
```

---

## 🔍 How It Works

### 🧪 Ammonia Gas Detection
The MQ137 sensor reads airborne ammonia released from decomposing meat.

### 📡 Wireless Communication
ESP8266 transmits sensor readings to a PHP script over Wi-Fi.

### ⚙️ Spoilage Logic
Spoilage is flagged based on predefined thresholds from empirical data collected during testing.

### 🧾 Data Logging
Sensor data and spoilage status are logged into a MySQL database for review and visualization.

---

## 📚 Code Overview

### Wi-Fi Initialization
```cpp
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
}
```

### Ammonia Calculation
```cpp
float RS_gas = (5.0 - sensorVoltage) / sensorVoltage * RL_VALUE;
float ratio = RS_gas / Ro;
float ammoniaConcentration = pow(10, ((log10(ratio) - 0.2042) / (-0.3268)));
```

### Data Transmission
```cpp
String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName + "&value1=" + String(ammoniaConcentration) + "&Sstatus=" + spoiledStatus;
int httpResponseCode = http.POST(httpRequestData);
```

---

## 🧪 Research Backing

This project was conceptualized and developed as part of a research paper titled:

### 📘 *ServeGuard: Food Spoilage Sensing Module*

> Published: KSCSTE TECHFEST 2024  
> Submitted to: IJERT, Volume 14, Issue 07, July 2025  
> Authors: Aditya Manoj, Melvin Davis, Palakulam Alita Antony, Vishnudath M, Aswathy Wilson  

📎 **[Read the full paper on Academia.edu →](https://www.academia.edu/143035003/ServeGuard_Food_Spoilage_Sensing_Module)**

---

## 🧑‍🔬 Future Scope

- Integrate **machine learning** for spoilage prediction models
- Expand to other meats and perishable foods
- Deploy cloud dashboards for supply chain integration
- Include temperature & humidity sensors for greater accuracy

---

## 🤝 Contributing

Pull requests are welcome! For significant changes, open an issue first to discuss what you'd like to change.

---

## 📄 License

Licensed under the [MIT License](LICENSE).

---

## 📬 Contact

📧 Aditya Manoj – [adityamanoja@gmail.com](mailto:adityamanoja@gmail.com)  
GitHub: [@AdityaManojA](https://github.com/AdityaManojA)

---

> 🚨 **Ensure food safety using smart tech – one sensor at a time.**
