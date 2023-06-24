# IoT-weather-box


This repository contains an Arduino sketch for a weather monitoring system. The system utilizes various sensors to measure temperature, humidity, pressure, altitude, rain sensor value, air quality, and UV intensity. The data is displayed on an LCD screen and also printed to the serial monitor for debugging purposes.

### Hardware Requirements
To run this code, you will need the following components:
- Arduino board (such as Arduino Uno)
- I2C LCD screen (compatible with the LiquidCrystal_I2C library)
- DHT11 temperature and humidity sensor
- BMP085 barometer sensor
- BH1750 light intensity sensor
- Rain sensor
- MQ-135 air quality sensor
- UV sensor

### Wiring Instructions
Please follow these steps to correctly wire the components:
1. Connect the I2C LCD screen to the Arduino board using the SDA and SCL pins.
2. Connect the DHT11 sensor to digital pin 2 of the Arduino.
3. Connect the BMP085 sensor to the appropriate SDA and SCL pins of the Arduino.
4. Connect the BH1750 sensor to the appropriate SDA and SCL pins of the Arduino.
5. Connect the rain sensor to analog pin A0 of the Arduino.
6. Connect the MQ-135 sensor to analog pin A1 of the Arduino.
7. Connect the UV sensor to analog pin A2 of the Arduino.

### Library Dependencies
Before uploading the sketch, ensure that you have installed the following libraries in your Arduino IDE:
- LiquidCrystal_I2C: This library is used to control the I2C LCD screen.
- Adafruit_Sensor: This library provides necessary functions for the Adafruit BMP085 sensor.
- Adafruit_BMP085: Use this library to communicate with the BMP085 barometer sensor.
- DHT: This library allows reading data from the DHT11 temperature and humidity sensor.
- BH1750: Utilize this library to interface with the BH1750 light intensity sensor.
- Wire: This library is essential for I2C communication.

### Setup
The setup function performs the following tasks:
1. Initializes the LCD screen, clears the display, and turns on the backlight.
2. Starts the serial communication at a baud rate of 9600.
3. Initializes the DHT11 sensor, BMP085 sensor, and BH1750 sensor.
4. Sets the pin modes for the rain sensor and MQ-135 sensor.

### Loop
The main loop carries out the following actions repeatedly:
1. Reads data from the DHT11 sensor, BMP085 sensor, rain sensor, MQ-135 sensor, and BH1750 sensor.
2. Prints the sensor data to the serial monitor.
3. Updates the LCD display with the current temperature, humidity, pressure, altitude, rain sensor value, air quality, and UV intensity.
4. Delays for 1 second and clears the LCD screen for the next set of data.

### Usage
To use this weather monitoring system:
1. Connect the Arduino board to your computer.
2. Open the Arduino IDE and upload the sketch to the Arduino board.
3. Open the serial monitor to view the sensor data.
4. The LCD screen will display the sensor readings in a rotating manner.

Note: If your I2C LCD screen has a different address than the one provided (0x3F), make sure to adjust it accordingly in the code.

Feel free to customize the code to suit your specific requirements and extend it with additional features or functionality.

Enjoy using your weather monitoring system!
