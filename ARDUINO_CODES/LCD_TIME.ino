#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set I2C address (typically 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
 lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("I2C LCD Display");
}

void loop() {
  // Update display every 5 seconds
  delay(5000);
  lcd.setCursor(0, 0);
  lcd.print("Time:      ");
  lcd.print(millis() / 1000);
}