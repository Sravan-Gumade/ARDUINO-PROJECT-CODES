//#include <ESP8266WiFi.h>
//#include<String.h>
#define led 2

void setup() {
  pinMode(led, OUTPUT); // Changed to OUTPUT
  Serial.begin(9600); // Corrected baud rate
}

void loop() {
  if (Serial.available()) {
    String serial_data = Serial.readStringUntil('\n');
    
    if (serial_data == "ledon") {
      digitalWrite(led, HIGH);
    } else if (serial_data == "ledoff") {
      digitalWrite(led, LOW);
    } else {
      // You can add error handling or default action here
    }
  }
}