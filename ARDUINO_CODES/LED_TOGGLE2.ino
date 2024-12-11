int ledPin = 2;
int buttonPin = 3;
int buttonState;
int lastButtonState = LOW;  // Store the previous state of the button
bool ledState = LOW;        // Store the current state of the LED

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(buttonPin);  // Read the current state of the button

    // Check for state change from LOW to HIGH (button press)
    if (buttonState == LOW && lastButtonState == HIGH) {
        ledState = !ledState;    // Toggle the LED state
        digitalWrite(ledPin, ledState);  // Set the LED to the new state
        delay(50);  // Debounce delay to avoid multiple toggles
    }

    lastButtonState = buttonState;  // Update the last button state
}