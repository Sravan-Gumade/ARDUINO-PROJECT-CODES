#include <LCD_I2C.h>
#include <Wire.h>
#include <DHT11.h>

#define COLUMN 16
#define ROWS 2

LCD_I2C lcd(0x27, COLUMN, ROWS);  // Check your I2C address (e.g., 0x27 or 0x3F)
DHT11 dht11(2);                  // DHT11 connected to pin 2

void setup() {
    Serial.begin(9600);
    Wire.begin();
    lcd.begin(&Wire);  // Initialize LCD
    lcd.backlight();   // Turn on the backlight
    lcd.print("Initializing..."); 
    delay(2000);
    lcd.clear();
}

void loop() {
    int temperature = 0;
    int humidity = 0;

    // Attempt to read temperature and humidity
    int result = dht11.readTemperatureHumidity(temperature, humidity);

    if (result == 0) { // Success
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperature);
        lcd.print(" °C");

        lcd.setCursor(0, 1);  // Move to second row
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print(" %");

        // Print values to Serial Monitor
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");

    } else {
        // Print error message
        Serial.println(DHT11::getErrorString(result));
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error");
    }

    delay(2000);  // Update every 2 seconds
}