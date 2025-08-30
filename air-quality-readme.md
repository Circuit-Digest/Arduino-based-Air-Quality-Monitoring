# Arduino-based Air Quality Monitoring System

![Arduino Air Quality Monitoring System](https://raw.githubusercontent.com/Circuit-Digest/Arduino-based-Air-Quality-Monitoring/71eabee18ff563a43116fe98ca758ce8a2a0f1c3/arduino-air-quality-monitoring-system.gif)

## Overview

This project demonstrates how to build a comprehensive air quality monitoring system using Arduino. The system monitors environmental parameters including gas levels, temperature, and humidity in real-time, providing accurate Air Quality Index (AQI) readings on an OLED display.

**Project Source:** [CircuitDigest - Arduino Air Quality Monitoring System](https://circuitdigest.com/microcontroller-projects/arduino-based-air-quality-monitoring-system)

## Table of Contents

- [Features](#features)
- [Components Required](#components-required)
- [Circuit Diagram](#circuit-diagram)
- [Pin Configuration](#pin-configuration)
- [How It Works](#how-it-works)
- [Air Quality Index (AQI) Scale](#air-quality-index-aqi-scale)
- [Installation](#installation)
- [Code Explanation](#code-explanation)
- [Troubleshooting](#troubleshooting)
- [Future Enhancements](#future-enhancements)
- [FAQ](#faq)
- [License](#license)

## Features

- **Real-time Monitoring**: Continuous monitoring of air quality, temperature, and humidity
- **AQI Classification**: Categorizes air quality as Good, Poor, Very Bad, or Toxic
- **OLED Display**: Clear visual representation of all sensor readings
- **Cost-effective**: DIY solution using affordable components
- **Educational**: Perfect for learning about environmental monitoring and Arduino programming
- **Customizable**: Easy to modify and add additional sensors

## Components Required

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | Main microcontroller board |
| MQ135 Gas Sensor | 1 | For detecting various gases and air pollutants |
| DHT11 Sensor | 1 | Temperature and humidity sensor |
| OLED Display (128x64) | 1 | SSD1306-based display for visual output |
| Breadboard | 1 | For prototyping connections |
| Jumper Wires | Several | For making connections |
| Power Supply | 1 | 5V power source for Arduino |

## Circuit Diagram

The system uses I2C communication for the OLED display and analog/digital pins for sensors:

- **OLED Display**: Connected via I2C (SDA/SCL pins)
- **MQ135 Sensor**: Analog output to A0 pin
- **DHT11 Sensor**: Digital data pin to D2

## Pin Configuration

| Arduino Pin | Connected Component | Wire Color (Suggested) |
|-------------|-------------------|----------------------|
| A0 | MQ135 Analog Output | Yellow |
| D2 | DHT11 Data Pin | Blue |
| A4 (SDA) | OLED SDA | Green |
| A5 (SCL) | OLED SCL | White |
| 5V | VCC (All Components) | Red |
| GND | Ground (All Components) | Black |

## How It Works

The Air Quality Monitoring System operates through the following process:

1. **Gas Detection**: The MQ135 sensor detects various gases and provides analog readings
2. **Environmental Sensing**: DHT11 measures temperature and humidity
3. **Data Processing**: Arduino processes sensor data and maps gas levels to AQI categories
4. **Display Output**: Real-time data is displayed on the OLED screen
5. **Continuous Monitoring**: The system updates readings in real-time

## Air Quality Index (AQI) Scale

| AQI Range | Category | Health Impact | Color Code |
|-----------|----------|---------------|------------|
| 0-50 | Good | Minimal impact | Green |
| 51-100 | Moderate | Acceptable for most people | Yellow |
| 101-150 | Unhealthy for Sensitive Groups | Sensitive individuals may experience symptoms | Orange |
| 151-200 | Unhealthy | Everyone may experience health effects | Red |
| 201-300 | Very Unhealthy | Health warnings for emergency conditions | Purple |
| 301-500 | Hazardous | Health alert - serious effects for everyone | Maroon |

### Project AQI Mapping

The system uses simplified thresholds based on sensor readings:

- **< 151**: Good Air Quality
- **151-200**: Poor Air Quality  
- **200-300**: Very Bad Air Quality
- **300-500**: Toxic Air Quality
- **> 500**: Extremely Toxic

## Installation

### Hardware Setup

1. **Assemble Components**: Connect all components according to the pin configuration table
2. **Power Connections**: Ensure all components share common 5V and GND connections
3. **Sensor Placement**: Position the MQ135 sensor in an area with good air circulation

### Software Setup

1. **Install Arduino IDE**: Download from [arduino.cc](https://www.arduino.cc/en/software)

2. **Install Required Libraries**:
   - Adafruit GFX Library
   - Adafruit SSD1306 Library
   - DHT Sensor Library

3. **Upload Code**: Copy the provided code and upload to your Arduino

### Library Installation via Arduino IDE

```
Tools → Manage Libraries → Search for:
- "Adafruit GFX"
- "Adafruit SSD1306" 
- "DHT sensor library"
```

## Code Explanation

### Key Functions

**`air_sensor()`**: 
- Reads analog values from MQ135 sensor
- Maps readings to AQI categories
- Displays gas level and quality status

**`sendSensor()`**:
- Reads temperature and humidity from DHT11
- Handles sensor errors
- Updates display with environmental data

**`setup()`**:
- Initializes serial communication
- Configures OLED display
- Shows startup messages

**`loop()`**:
- Continuously updates sensor readings
- Refreshes display with current data

### Sensor Calibration

The MQ135 sensor requires a warm-up period of 24-48 hours for accurate readings. Initial readings may be unstable until the sensor stabilizes.

## Troubleshooting

| Issue | Possible Cause | Solution |
|-------|----------------|----------|
| No sensor reading | Loose connections | Check wiring and connections |
| Erratic readings | Sensor not warmed up | Wait 24-48 hours for MQ135 stabilization |
| Display not working | I2C connection issue | Verify SDA/SCL connections |
| Wrong AQI values | Calibration needed | Perform sensor calibration procedure |
| Sensor values stuck | Power supply issue | Check 5V power connections |

## Future Enhancements

- **Machine Learning Integration**: Implement predictive analytics for air quality trends
- **Multi-gas Detection**: Add sensors for PM2.5, PM10, CO, and other pollutants
- **IoT Connectivity**: Enable cloud data storage and remote monitoring
- **Mobile Application**: Develop smartphone app for remote monitoring
- **Solar Power**: Add solar charging capability for outdoor installations
- **Data Logging**: Implement SD card storage for historical data
- **Alert System**: Add buzzer/LED warnings for poor air quality

## Working Demo

The system displays:
- **Top Section**: Air quality level and status (Good/Poor/Very Bad/Toxic)
- **Middle Section**: Gas sensor reading (numerical value)
- **Bottom Section**: Temperature (°C) and Relative Humidity (%)

When exposed to gas sources (like a lighter), the system responds by changing the air quality status from "Good" to higher pollution levels.

## FAQ

**Q: What is the accuracy of the MQ135 sensor?**
A: The MQ135 sensor has an accuracy of ±10%, suitable for general air quality monitoring and educational purposes.

**Q: How long does the MQ135 sensor take to stabilize?**
A: The sensor requires 24-48 hours of continuous operation to provide stable and accurate readings.

**Q: Can I add more sensors to the system?**
A: Yes, you can integrate additional sensors like PM2.5, CO sensors, or other environmental monitoring modules.

**Q: How long does the MQ135 sensor last?**
A: With continuous operation, MQ135 sensors typically last 2-5 years, depending on environmental conditions.

**Q: Can this system be used outdoors?**
A: The basic design is for indoor use. For outdoor applications, add weatherproof enclosure and consider power management solutions.

## Technical Specifications

- **Operating Voltage**: 5V DC
- **Current Consumption**: ~200mA
- **Display**: 128x64 OLED (I2C)
- **Sensor Range**: 10-1000ppm (MQ135)
- **Temperature Range**: 0-50°C (DHT11)
- **Humidity Range**: 20-95% RH (DHT11)
- **Update Frequency**: Real-time (continuous loop)

## Related Projects

- [IoT Air Pollution Monitoring using ESP8266](https://circuitdigest.com/microcontroller-projects/iot-air-pollution-monitoring-using-arduino)
- [AQI Monitoring System with PM2.5/PM10](https://circuitdigest.com/microcontroller-proejcts/iot-based-air-quality-index-monitoring-system-measure-pm25-pm10-co-using-esp32)
- [Arduino Home Automation Projects](https://circuitdigest.com/arduino-home-automation-projects)

## License

This project is open-source and available under the MIT License. Feel free to modify and distribute according to your needs.

## Contributing

Contributions are welcome! Please feel free to submit pull requests, report bugs, or suggest new features.

## Support

For technical support and questions:
- Visit: [CircuitDigest Arduino Projects](https://circuitdigest.com/arduino-projects)
- Original Project: [Arduino Air Quality Monitoring System](https://circuitdigest.com/microcontroller-projects/arduino-based-air-quality-monitoring-system)

---

**Built with ❤️ by the Arduino Community**