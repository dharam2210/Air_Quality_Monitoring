# IoT Environmental Monitoring using ESP32 (Wokwi Simulation)

**Author:** Dharam Chandanshive

This project demonstrates how to monitor **temperature, humidity, and gas levels** using an ESP32 microcontroller in a simulated environment on [Wokwi](https://wokwi.com/). The system uses a **DHT22 sensor** to measure temperature and humidity and a **gas sensor** (analog output) to detect gas concentration.

---

## Features

- **ESP32-based monitoring** (Wi-Fi capable microcontroller)  
- **DHT22 Sensor** – Measures temperature and humidity  
- **Gas Sensor (Analog Output)** – Detects gas levels in real time  
- **Serial Monitor Output** – Displays sensor readings in real-time  
- Fully simulated on **Wokwi** (no physical hardware required)  

---

## Components Used

1. **ESP32 DevKit-C V4**  
2. **DHT22 Temperature and Humidity Sensor**  
3. **Gas Sensor (Analog type)**  

---

## Circuit Connections

- **DHT22 SDA → GPIO 4**  
- **DHT22 VCC → 5V (ESP32)**  
- **DHT22 GND → GND (ESP32)**  
- **Gas Sensor AOUT → GPIO 34**  
- **Gas Sensor VCC → 5V (ESP32)**  
- **Gas Sensor GND → GND (ESP32)**  

Serial communication is connected internally to Wokwi’s Serial Monitor:  
- **ESP32 TX → Serial Monitor RX**  
- **ESP32 RX → Serial Monitor TX**

---

## How to Run the Simulation

1. Go to [Wokwi](https://wokwi.com/).  
2. Open your project file (`.json`).  
3. Start the simulation.  
4. Open the **Serial Monitor** to see real-time sensor readings.

---

## Output

- Displays **temperature (°C)** and **humidity (%)** from the DHT22.  
- Shows **gas sensor analog readings** for detecting gas presence.  

---

## Future Enhancements

- Add **Wi-Fi connectivity** to send data to a cloud platform.  
- Use **Blynk or MQTT** for remote monitoring.  
- Add **alerts or buzzer** when gas levels exceed a threshold.  
