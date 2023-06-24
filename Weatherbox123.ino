#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <BH1750.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP085 bmp;   //barometer

BH1750 lightMeter;     //light intensity

const int rainSensorPin = A0;
const int mq135Pin = A1;      //Air qualitity
const int uvSensorPin = A2;

void setup() {

  lcd.init();
  lcd.clear();         
  lcd.backlight();


  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  
  // Initialize sensors
  dht.begin();
  bmp.begin();
  lightMeter.begin();
  
  // Set pin modes
  pinMode(rainSensorPin, INPUT);
  pinMode(mq135Pin, INPUT);
}

void loop() {
  // Read data from sensors
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;
  float altitude = bmp.readAltitude();
  int rainSensorValue = analogRead(rainSensorPin);
  float Air = analogRead(mq135Pin) / 1024.0 * 5.0;
  float uvValue = lightMeter.readLightLevel();
  
  // Print data to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("*C\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.print(" hPa\t");
  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.print(" m\t");
  Serial.print("Rain Sensor Value: ");
  Serial.print(rainSensorValue);
  Serial.print("\tAir: ");
  Serial.print(Air);
  Serial.print("\tUV Value: ");
  Serial.print(uvValue);
  Serial.print(" lx\n");

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.setCursor(4,0);
  lcd.print(temperature);  
 
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
   lcd.setCursor(8,8);
  lcd.print(humidity);
  lcd.print("%");
  delay(1000);
  
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pressure:");
  lcd.print(pressure);
   lcd.setCursor(11,0);
  lcd.print(" hPa");
  delay(1000);

  lcd.setCursor(0,1);
  lcd.print("Altitude:  ");
  lcd.setCursor(9,9);
  lcd.print(altitude);
  lcd.print("m");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Air: ");
  lcd.setCursor(5,0);
  lcd.print(Air);
  lcd.print(" %");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Rain: ");
  lcd.setCursor(6,0);
  lcd.print(rainSensorValue);
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("UV Value:  ");
  lcd.setCursor(9,0);
  lcd.print(uvValue);
  lcd.print(" lx");
  delay(1000);
  lcd.clear();

  delay(1000);



}
