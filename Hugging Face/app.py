import gradio as gr
import joblib
import numpy as np
import pandas as pd
from datetime import datetime

# মডেল লোড করুন
model = joblib.load('agroai_xgboost_model.pkl')
scaler = joblib.load('agroai_scaler.pkl')

def predict_soil_moisture(temp, humidity, soil_current, light, ph, 
                           soil_lag1, soil_lag2, temp_lag1, hum_lag1):
    
    # বর্তমান সময়ের ফিচার
    now = datetime.now()
    hour = now.hour
    day_of_week = now.weekday()
    is_weekend = 1 if day_of_week >= 5 else 0
    
    # ফিচার অ্যারে তৈরি
    features = np.array([[
        temp, humidity, soil_current, light, ph,
        hour, day_of_week, is_weekend,
        soil_lag1, soil_lag2, temp_lag1, hum_lag1
    ]])
    
    # স্কেলিং
    features_scaled = scaler.transform(features)
    
    # প্রেডিকশন
    prediction = model.predict(features_scaled)[0]
    
    # পাম্প রিকমেন্ডেশন
    if prediction < 35:
        recommendation = "🔴 PUMP ON - Soil will become dry"
        status = "ON"
    else:
        recommendation = "🟢 PUMP OFF - Soil moisture adequate"
        status = "OFF"
    
    return f"""
    📊 **Prediction Results (Next 15 min)**
    
    🌱 Predicted Soil Moisture: **{prediction:.1f}%**
    🚰 Pump Recommendation: **{status}**
    💡 {recommendation}
    
    ℹ️ Pump turns ON when soil moisture < 35%
    """

# Gradio Interface
iface = gr.Interface(
    fn=predict_soil_moisture,
    inputs=[
        gr.Slider(15, 45, label="🌡️ Temperature (°C)"),
        gr.Slider(30, 90, label="💧 Humidity (%)"),
        gr.Slider(20, 80, label="🌱 Current Soil Moisture (%)"),
        gr.Slider(0, 100, label="☀️ Light Intensity (%)"),
        gr.Slider(5.5, 8.5, label="🧪 Soil pH"),
        gr.Slider(20, 80, label="⏪ Soil Moisture (1 step ago)"),
        gr.Slider(20, 80, label="⏪⏪ Soil Moisture (2 step ago)"),
        gr.Slider(15, 45, label="🌡️ Temperature (1 step ago)"),
        gr.Slider(30, 90, label="💧 Humidity (1 step ago)")
    ],
    outputs=gr.Markdown(label="🤖 AI Prediction"),
    title="🌾 AgroAI - Smart Farming Predictor",
    description="XGBoost model predicts soil moisture for next 15 minutes and recommends irrigation",
    theme="soft"
)

iface.launch()
