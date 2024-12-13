#include <M5StickCPlus.h> //include for LCD lib
#include "DHT_Async.h" //https://github.com/toannv17/DHT-Sensors-Non-Blocking

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define DHT_PIN 26 // using pin26 on M5stickC Plus as DHT11 input pin
#define TFT_GREY 0x5AEB

// Initialize DHT
DHT_Async dht_sensor(DHT_PIN, DHT_SENSOR_TYPE);

// Main function for data reading 
static bool measure_environment(float *temperature, float *humidity) {
    static unsigned long measurement_timestamp = millis();

    /* Measure once every four seconds. */
    if (millis() - measurement_timestamp > 4000ul) {
        if (dht_sensor.measure(temperature, humidity)) {
            measurement_timestamp = millis();
            return (true);
        }
    }

    return (false);
}

void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);
  Serial.begin(115200);
}

void loop() {
  float temperature = 0;
  float humidity = 0;

  // Measure temperature and humidity
  if (measure_environment(&temperature, &humidity)) {
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.print(" deg. C, H = ");
    Serial.print(humidity, 1);
    Serial.println("%");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Using M5 LCD lib to create a GUI
    // Clear screen
    M5.Lcd.fillScreen(BLACK);
    // Set text size and color
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    // Draw table borders
    M5.Lcd.drawRect(10, 10, 220, 100, TFT_GREY);
    M5.Lcd.drawLine(10, 55, 230, 55, TFT_GREY); // Horizontal divider
    M5.Lcd.drawLine(120, 10, 120, 110, TFT_GREY); // Vertical divider
    // Display titles
    M5.Lcd.setCursor(20, 25);
    M5.Lcd.print("Temp:");
    M5.Lcd.setCursor(20, 70);
    M5.Lcd.print("Humi:");
    // Display values
    M5.Lcd.setCursor(130, 25);
    M5.Lcd.print(temperature);
    M5.Lcd.print(" C");
    M5.Lcd.setCursor(130, 70);
    M5.Lcd.print(humidity);
    M5.Lcd.print(" %");
  } 
  delay(5000);
}
