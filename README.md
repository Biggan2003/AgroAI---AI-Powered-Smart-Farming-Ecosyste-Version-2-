<div align="center">
  
# 🌾 AgroAI---AI-Powered-Smart-Farming-Ecosyste-Version-2
  
<img src="https://img.shields.io/badge/ESP32-Online-22c55e?style=for-the-badge&logo=espressif&logoColor=white"/>
<img src="https://img.shields.io/badge/ThingSpeak-Connected-3b82f6?style=for-the-badge&logo=thingspeak&logoColor=white"/>
<img src="https://img.shields.io/badge/XGBoost-Active-f97316?style=for-the-badge&logo=xgboost&logoColor=white"/>
<img src="https://img.shields.io/badge/HuggingFace-Deployed-8B5CF6?style=for-the-badge&logo=huggingface&logoColor=white"/>
<img src="https://img.shields.io/badge/Netlify-Live-22c55e?style=for-the-badge&logo=netlify&logoColor=white"/>

**AI-Powered IoT Smart Farming | Real-Time Crop Monitoring | Predictive Irrigation**

</div>

### Live Demo: https://agroai-biggan.netlify.app/
### ThingSpeak Dashboard: https://thingspeak.mathworks.com/channels/3375451
### AI model predictor(Huggging Face) : https://huggingface.co/spaces/bigganbiggan/agroai-xgboost
### Sensor with ESP(WOKWI):  https://wokwi.com/projects/463509416388137985



<img width="1918" height="993" alt="image" src="https://github.com/user-attachments/assets/bb42fcf7-abb2-479b-8701-aaf0c381083b" />

<img width="1913" height="957" alt="image" src="https://github.com/user-attachments/assets/2867fa7c-70fe-44d1-96f3-6a1144350496" />


<img width="1909" height="955" alt="image" src="https://github.com/user-attachments/assets/e569a371-0a78-49c7-9e83-5d63dc444493" />

<img width="1365" height="675" alt="image" src="https://github.com/user-attachments/assets/5a0d9a87-2264-45f0-af93-87d3de11b697" />

<img width="1365" height="635" alt="image" src="https://github.com/user-attachments/assets/426ddd47-374c-4fe6-853b-b05abf2dcb96" />

<img width="1895" height="961" alt="image" src="https://github.com/user-attachments/assets/cd27bc37-9b96-4865-b91f-0d9d9416f1b8" />

# 🌾 AgroAI - Smart Farming Dashboard

AI-Powered IoT Smart Farming Ecosystem | Real-Time Crop Monitoring & Predictive Irrigation

## 🚀 Live Demo
https://agroai-biggan.netlify.app/

## 📊 Features
- Real-time sensor monitoring (Temperature, Humidity, Soil Moisture, Water Level, Light, pH, Battery)
- XGBoost AI model for soil moisture prediction
- Interactive dashboard with glassmorphism design
- Animated pump status with fan & water drops
- ThingSpeak cloud integration
- Complete IoT-to-AI pipeline visualization

## 🛠️ Tech Stack
- **Frontend:** HTML5, TailwindCSS, JavaScript, Chart.js
- **Backend:** ThingSpeak API, Hugging Face Spaces
- **AI Model:** XGBoost Regressor
- **Hardware:** ESP32, DHT22, Ultrasonic, LDR, Relay Module

## 🔧 Local Setup
1. Clone this repository
2. Open `index.html` in your browser
3. Make sure your ThingSpeak channel is public or add your Read API Key

## 📡 Data Pipeline


## 👨‍💻 Author
**G.M. Biggan**

</div>

---

## 🎯 Features at a Glance

| Feature | Status | Description |
|---------|--------|-------------|
| 🌡️ Temperature Monitoring | ✅ Live | Real-time ambient temperature (0-60°C) |
| 💧 Humidity Tracking | ✅ Live | Air humidity percentage (0-100%) |
| 🌱 Soil Moisture | ✅ Live | Soil water content with pump automation |
| 🚰 Water Level | ✅ Live | Tank water level monitoring (0-400cm) |
| ☀️ Light Intensity | ✅ Live | Dynamic background glow effect |
| 🧪 Soil pH | ✅ Live | Acidity/alkalinity measurement |
| 🔋 Battery Status | ✅ Live | Solar-powered system health |
| 🤖 AI Prediction | ✅ Smart | XGBoost predicts next 15min soil moisture |
| 🎨 Premium UI | ✅ Glassmorphism | Modern, colorful, eye-catching design |
| 📊 Live Charts | ✅ Interactive | Bar chart + Donut chart visualization |

---

## 🚀 How It Works


---

## 🛠️ Technologies Used

### Frontend
| Technology | Purpose |
|------------|---------|
| **HTML5** | Structure of dashboard |
| **TailwindCSS** | Styling, glassmorphism effects, responsiveness |
| **JavaScript (ES6)** | Real-time data fetching, DOM manipulation |
| **Chart.js** | Bar charts, doughnut charts, sparklines |
| **Font Awesome 6** | Premium icons for visual enhancement |

### Backend & Cloud
| Technology | Purpose |
|------------|---------|
| **ThingSpeak** | IoT cloud platform - stores all sensor data |
| **Hugging Face Spaces** | Hosts XGBoost AI model as REST API |
| **FastAPI** | Python framework for AI model serving |

### AI & Machine Learning
| Technology | Purpose |
|------------|---------|
| **XGBoost Regressor** | Predicts soil moisture for next 15 minutes |
| **Feature Engineering** | Time-based features (hour, day, lag values) |
| **Scikit-learn** | Data preprocessing, scaling |

### Hardware (Simulated/Real)
| Component | Purpose | Pin (ESP32) |
|-----------|---------|-------------|
| DHT22 | Temperature & Humidity | GPIO 15 |
| HC-SR04 | Water Level (Ultrasonic) | GPIO 2, 4 |
| LDR | Light Intensity | GPIO 34 |
| Potentiometer | Soil Moisture (Simulated) | GPIO 33 |
| Potentiometer | Soil pH (Simulated) | GPIO 32 |
| Relay Module | Pump Control | GPIO 19 |
| LCD 1602 I2C | Local Display | GPIO 21, 22 |

---

## 📊 Benefits of This System

| Problem | Solution | Benefit |
|---------|----------|---------|
| 💧 Over-irrigation | AI predicts exact soil needs | Save 30-50% water |
| ⚡ Wasted electricity | Pump runs only when needed | Lower energy bills |
| 🌱 Crop diseases | Real-time pH & moisture alerts | Early detection |
| 📉 Low yield | Optimal growing conditions | Higher crop quality |
| 🧑‍🌾 Manual labor | Fully automated system | Save time & effort |
| 📡 No remote access | Cloud dashboard | Monitor from anywhere |
| 🤷 Poor decisions | AI-powered recommendations | Data-driven farming |

---

## 📈 Model Performance


---

## 🎨 Dashboard Features Explained

| Section | What It Shows |
|---------|---------------|
| **8 Sensor Cards** | Individual parameters with sparkline trends |
| **Live Sensor Trends** | Bar chart comparing all current values |
| **System Health** | Donut chart for overall system status |
| **AI Insight Engine** | XGBoost prediction with confidence score |
| **IoT-to-AI Pipeline** | Visual data flow from sensors to AI |
| **Status Indicators** | Real-time online/offline status of each component |
| **Pump Animation** | Fan spinning + water drops when pump is ON |
| **Light Glow Effect** | Card brightness changes with light intensity |

---

## 🔧 How to Use

### Prerequisites
1. A web browser (Chrome/Firefox/Edge recommended)
2. Internet connection
3. ThingSpeak channel (public or with Read API Key)

### Local Setup (5 Minutes)

```bash
# 1. Clone the repository
git clone https://github.com/yourusername/agroai-dashboard.git

# 2. Navigate to folder
cd agroai-dashboard

# 3. Open index.html in browser
# Double-click index.html OR
# Use live server extension

```
Configuration (2 Minutes)

```jacascript
// Edit index.html - find these lines
const THINGSPEAK_URL = 'https://api.thingspeak.com/channels/YOUR_CHANNEL_ID/feeds/last.json';
const HF_API_URL = 'https://yourusername-agroai-xgboost.hf.space/api/predict';

// Replace with your values
// Channel ID: 3375451
// Read API Key: YOUR_API_KEY (if channel is private)
```



👨‍💻 Author: 
### github: https://github.com/Biggan2003
### Linkedin: https://www.linkedin.com/in/g-m-biggan-371956305/
### Kaggle: https://www.kaggle.com/gmbiggan
### Youtube: https://www.youtube.com/@G.M-Biggan/videos
