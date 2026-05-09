#include <WiFi.h>
#include <DHT.h>
#include "ThingSpeak.h"
#include <LiquidCrystal.h>

// ========== WiFi Configuration ==========
const char* SSID = "Wokwi-GUEST";
const char* PASS = "";

// ========== ThingSpeak Configuration ==========
unsigned long myChannelNumber = 3375451;
const char* myWriteAPIKey = " আপনার API Key দিন ";  // আপনার API Key দিন

// ========== Pin Definitions ==========
// DHT22
#define DHTPIN 15
#define DHTTYPE DHT22

// Ultrasonic
#define TRIG_PIN 2
#define ECHO_PIN 4

// Relay (Pump)
#define RELAY_PIN 19

// LDR
#define LDR_PIN 34

// Potentiometers
#define SOIL_PIN 33
#define PH_PIN 32

// LCD Pins (1602 Parallel)
#define LCD_RS 13
#define LCD_EN 12
#define LCD_D4 14
#define LCD_D5 27
#define LCD_D6 26
#define LCD_D7 25

// ========== Objects ==========
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// ========== Setup ==========
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Initialize sensors
  dht.begin();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(SOIL_PIN, INPUT);
  pinMode(PH_PIN, INPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AgroAI System");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  
  // Connect WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi Connected!");
  
  ThingSpeak.begin(client);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Ready!");
  delay(2000);
  lcd.clear();
}

// ========== Loop ==========
void loop() {
  // === Read DHT22 ===
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  if (isnan(t)) t = 25.0;
  if (isnan(h)) h = 60.0;
  
  // === Ultrasonic (Water Level) ===
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  if (distance > 400) distance = 400;
  
  // === Soil Moisture ===
  float soilMoisture = map(analogRead(SOIL_PIN), 0, 4095, 0, 100);
  
  // === pH Value ===
  float phValue = map(analogRead(PH_PIN), 0, 4095, 0, 140) / 10.0;
  
  // === Light Intensity ===
  float light = map(analogRead(LDR_PIN), 0, 4095, 0, 100);
  
  // === Pump Control ===
  int pumpStatus = (soilMoisture < 35) ? 1 : 0;
  digitalWrite(RELAY_PIN, pumpStatus);
  
  // === Battery Simulation ===
  float battery = (float)random(88, 98);
  
  // === LCD Display ===
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t, 1);
  lcd.print("C H:");
  lcd.print(h, 1);
  lcd.print("%");
  
  lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.print(soilMoisture, 0);
  lcd.print("% P:");
  lcd.print(pumpStatus ? "ON " : "OFF");
  
  // === Serial Monitor ===
  Serial.println("========== AGROAI DATA ==========");
  Serial.print("Temp: "); Serial.print(t); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(h); Serial.println(" %");
  Serial.print("Soil Moisture: "); Serial.print(soilMoisture); Serial.println(" %");
  Serial.print("Water Level: "); Serial.print(distance); Serial.println(" cm");
  Serial.print("Light: "); Serial.print(light); Serial.println(" %");
  Serial.print("pH: "); Serial.println(phValue);
  Serial.print("Pump: "); Serial.println(pumpStatus ? "ON" : "OFF");
  Serial.print("Battery: "); Serial.print(battery); Serial.println(" %");
  Serial.println("==================================\n");
  
  // === ThingSpeak Upload ===
  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  ThingSpeak.setField(3, soilMoisture);
  ThingSpeak.setField(4, distance);
  ThingSpeak.setField(5, pumpStatus);
  ThingSpeak.setField(6, light);
  ThingSpeak.setField(7, phValue);
  ThingSpeak.setField(8, battery);
  
  int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
  if (status == 200) {
    Serial.println("✅ ThingSpeak Upload Success!");
  } else {
    Serial.println("❌ Upload Error: " + String(status));
  }
  
  delay(15000);  // 15 seconds delay for free tier
}