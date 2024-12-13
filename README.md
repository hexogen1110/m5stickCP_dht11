# DHT11 Temperature and Humidity Sensor Project

This project interfaces a DHT11 sensor with the M5StickC Plus device to measure and display temperature and humidity values. The implementation uses non-blocking techniques for efficient data handling.

## Features

- **Temperature and Humidity Measurement**:
  Uses the DHT11 sensor to monitor environmental conditions.

- **Non-blocking Sensor Reading**:
  Leverages the `DHT-Sensors-Non-Blocking` library for smooth operations.

- **LCD Display**:
  Utilizes the M5StickC Plus's built-in LCD to present real-time data.

## Setup and Configuration

1. **Libraries Used**:
   - `M5StickCPlus.h`: Manages the LCD display.
   - `DHT_Async.h`: Handles non-blocking DHT sensor operations.

2. **Pin Configuration**:
   - **DHT Pin**: Connect the DHT11 sensor to pin 26 on the M5StickC Plus.

3. **Customizations**:
   - Color settings for the LCD display are defined with `TFT_GREY`.

## Code Overview

- **Sensor Initialization**:
  The `DHT_Async` class is used to configure the DHT11 sensor.

- **Data Reading**:
  The `measure_environment` function retrieves temperature and humidity values without blocking the main program flow.

## Hardware Requirements

- M5StickC Plus
- DHT11 Temperature and Humidity Sensor
- Connection Wires

## Preview

![Project Preview](#)

## How to Use

1. Connect the DHT11 sensor to pin 26 of the M5StickC Plus.
2. Install the required libraries in your Arduino IDE.
3. Upload the code to the M5StickC Plus.
4. View the real-time temperature and humidity data on the device's LCD.

## References

- [DHT-Sensors-Non-Blocking Library](https://github.com/toannv17/DHT-Sensors-Non-Blocking)
- [M5StickC Plus Documentation](https://docs.m5stack.com/en/core/m5stickc_plus)

---

![image](https://github.com/hexogen1110/m5stickCP_dht11/blob/main/Front.jpg)
![image](https://github.com/hexogen1110/m5stickCP_dht11/blob/main/End.jpg)
