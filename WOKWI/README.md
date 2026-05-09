# 🌾 AgroAI - Smart Irrigation System

[![Wokwi](https://img.shields.io/badge/Wokwi-Simulation-orange)](https://wokwi.com)
[![ESP32](https://img.shields.io/badge/ESP32-Platform-blue)](https://www.espressif.com)
[![ThingSpeak](https://img.shields.io/badge/ThingSpeak-IoT-green)](https://thingspeak.com)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Python](https://img.shields.io/badge/Python-3.8+-blue)](https://python.org)


---

## 📋 Project Overview

AgroAI is a smart irrigation system that monitors soil conditions using IoT sensors and makes automated irrigation decisions using Machine Learning.

### 🎯 Objectives
- Monitor soil moisture, temperature, humidity, and pH levels
- Real-time irrigation need prediction
- ESP32 microcontroller-based data collection
- ThingSpeak for data storage and visualization
- XGBoost model for intelligent decision making

---

## 🏗️ System Architecture


---

## 📡 Hardware Components (Wokwi Simulation)

| Component | Specification | Purpose |
|-----------|--------------|---------|
| ESP32 | WiFi + Bluetooth | Main controller |
| Soil Moisture Sensor | Analog output | Measure soil water content |
| DHT22 | Digital sensor | Temperature & Humidity |
| pH Sensor | Analog output | Soil pH monitoring |
| Light Sensor | LDR/BH1750 | Sunlight intensity |
| Water Pump | 5V DC | Automated irrigation |

---

## 🛠️ Software Stack

| Layer | Technology |
|-------|------------|
| Firmware | Arduino C++ (ESP32) |
| IoT Platform | ThingSpeak API |
| Data Processing | Python, Pandas, NumPy |
| Machine Learning | XGBoost, Scikit-learn |
| Visualization | Gradio, Matplotlib |
| Version Control | Git, GitHub |

---

## 📊 Data Flow

1. **Data Generation** (Wokwi + ESP32)
   - Simulated sensor readings every 15 minutes
   - Real-time data via serial monitor

2. **Data Transmission** (ThingSpeak)
   - HTTP POST requests from ESP32
   - Channel ID: `3375451`
   - Fields: Temperature, Humidity, Soil Moisture, pH, Light, Battery

3. **Data Processing** (Python)
   - Fetch data from ThingSpeak API
   - Clean and preprocess
   - Feature engineering

4. **ML Prediction** (XGBoost)
   - Trained on synthetic data initially
   - Real data integration in progress
   - Irrigation need classification

---

## 🚀 Getting Started

### Prerequisites

```bash
# Python packages
pip install pandas numpy scikit-learn xgboost joblib
pip install gradio thingspeak
pip install requests matplotlib

# Arduino libraries
# - ThingSpeak by MathWorks
# - DHT sensor library by Adafruit
