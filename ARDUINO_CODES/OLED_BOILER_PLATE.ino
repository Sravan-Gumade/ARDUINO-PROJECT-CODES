#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define display width and height (128x64 OLED)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Pin definitions for SPI
      /*#define sclk 11
        #define mosi 13
        #define cs   10
        #define rst  9
        #define dc   8*/
#define OLED_RESET    9   // Reset pin
#define OLED_DC       8   // Data/Command pin
#define OLED_CS       10  // Chip Select pin

// Create display object for SPI
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);


void setup() {
  
  Serial.begin(9600);
  
  // Initialize OLED display with SPI
  if(!display.begin(SSD1306_SWITCHCAPVCC)) { // Internal charge pumpl
    Serial.println(F("SSD1306 allocation failed"));
								
    for(;;); // Loop forever if allocation fails
  }
				
  // Clear the display buffer
  display.clearDisplay();
				
  display.setTextSize(1.2);           // Text size (1 is normal)
				
  display.setTextColor(SSD1306_WHITE); // Set color to white
				
  display.setCursor(10, 5);          // Set starting position
			
  display.println(F("Hello, SPI OLED!"));
  // Display text on the OLED
								
		display.drawRect(0,0 , 128, 64, WHITE); 	
				//display rectangle
						
		display.fillCircle(80, 40, 10, WHITE);
	   //display filled circle
				
				int x1 = 64, y1 = 15, x2 = 40, y2= 60, x3 = 60, y3 = 38;
				
				for(int i = 0; i <24; i++){
		display.fillTriangle(x1, y1, x2, y2, x3+i, y3+i, WHITE);
								display.display();
								delay(200);
								}
							//Draws a filled triangle.
		
		 display.display();
}

void loop() {
  // Additional code or animations can go here
}