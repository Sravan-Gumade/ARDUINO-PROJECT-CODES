//#include <ESP8266WiFi.h>
int led = 12;
int swt = 6;
int swtstate;
int ledstate = LOW;
int lastSwtState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // Debounce delay time in milliseconds

void setup()
{
    Serial.begin(115200);
    pinMode(led, OUTPUT);
    pinMode(swt, INPUT);
}

void loop()
{
    int reading = digitalRead(swt);

    // Check if the button state has changed
    if (reading != lastSwtState) {
        lastDebounceTime = millis();
    }

    // If enough time has passed, check if the button is stable
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != swtstate) {
            swtstate = reading;
            // Only toggle the LED if the switch is HIGH
            if (swtstate == HIGH) {
                ledstate = !ledstate;
                digitalWrite(led, ledstate);
                Serial.println(ledstate);
            }
        }
    }

    // Update the last switch state
    lastSwtState = reading;
}