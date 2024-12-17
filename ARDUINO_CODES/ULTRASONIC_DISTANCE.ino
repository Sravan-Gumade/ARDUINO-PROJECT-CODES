#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the I2C LCD (0x27 is the default address, check your LCD address)
/*Pin connections
trigPin --> D9
echoPin --> D10
LCD SCL --> A4
LCD SDA --> A5 
*/
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Variables for duration and distance
long duration;
float distance;

void setup() {
  // Initialize LCD
  lcd.init();  // Use 'init()' instead of 'begin()'
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic Test");

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  delay(2000);
  lcd.clear();
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (in cm)
  distance = (duration * 0.0343) / 2;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear previous data
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(500); // Update every 500ms
}