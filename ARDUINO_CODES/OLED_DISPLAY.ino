#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define display width and height (128x64 OLED)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Pin definitions for SPI
/*#define sclk/D0 11
#define mosi/D1 13
#define cs   10
#define rst  9
#define dc   8*/
#define OLED_RESET    9   // Reset pin
#define OLED_DC       8   // Data/Command pin
#define OLED_CS       10  // Chip Select pin

// Create display object for SPI
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  
  // Initialize OLED display with SPI
  if(!display.begin(SSD1306_SWITCHCAPVCC)) { // Internal charge pumpl
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Loop forever if allocation fails
  }

  // Clear the display buffer
  display.clearDisplay();

  // Display text on the OLED
  display.setTextSize(1);           // Text size (1 is normal)
  display.setTextColor(SSD1306_WHITE); // Set color to white
  display.setCursor(10, 0);          // Set starting position
  display.println(F("Hello,£ SPI OLED!"));
				display.drawRect(20,20 , 50, 25, WHITE);
				display.fillCircle(30, 30, 25, WHITE);
				// Draws a rectangle.
			//	display.fillTriangle(10, 10, 50, 30, 50, 40, WHITE);
				
  
  // Update the display with the buffer
  display.display();
}

void loop() {
  // Additional code or animations can go here
}