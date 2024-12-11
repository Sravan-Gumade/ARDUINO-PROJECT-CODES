#include <AccelStepper.h>
#include <Servo.h>

// Stepper motor setup
#define DIR_PIN 2
#define STEP_PIN 3
#define ENABLE_PIN 4
#define STEPS_PER_MM ((200 * 16) / 2.0) // Steps per mm (adjust values as needed)


AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// Servo motors
Servo servoRed, servoGreen, servoYellow;
#define SERVO_RED_PIN 9
#define SERVO_GREEN_PIN 10
#define SERVO_YELLOW_PIN 11

// IR sensors
#define IR_SENSOR_1 A0
#define IR_SENSOR_2 A1
#define IR_SENSOR_3 A2

// Servo positions
const int SERVO_HOME = 90;
const int SERVO_ACTIVE = 30;

// Tomato classification
String tomatoClass;

void setup() {
  Serial.begin(9600);

  // Initialize stepper motor
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW); // Enable motor driver
  stepper.setMaxSpeed(1000);     // Set max speed
  stepper.setAcceleration(50);  // Set acceleration

  // Attach servos
  servoRed.attach(SERVO_RED_PIN);
  servoGreen.attach(SERVO_GREEN_PIN);
  servoYellow.attach(SERVO_YELLOW_PIN);

  // Set servos to home position
  servoRed.write(SERVO_HOME);
  servoGreen.write(SERVO_HOME);
  servoYellow.write(SERVO_HOME);

  // Initialize IR sensors
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(IR_SENSOR_3, INPUT);
}

void loop() {
  // Run the conveyor
  stepper.setSpeed(700);
  stepper.runSpeed();
  digitalWrite(ENABLE_PIN, LOW); // Enable motor driver
   
  // Check IR_SENSOR_1
  int IR_SENSOR_1Val = digitalRead(IR_SENSOR_1);
		
		
		if (digitalRead(IR_SENSOR_1) ==LOW) {
    // Tomato detected
   
      Serial.println("Tomato detected, stopping conveyor");

      // Setting servo to home postion
      servoRed.write(90);
		  if(IR_SENSOR_2 == HIGH && tomatoClass != "G"){
				servoGreen.write(90);
			}
		  if(IR_SENSOR_3 != LOW && tomatoClass != "Y" ){
						servoYellow.write(90);
			}
				
        // Stop the conveyor
        stepper.stop();
        //stepper.disableOutputs();
        digitalWrite(ENABLE_PIN, HIGH); // Disable motor driver

        // Wait for classification input
        Serial.println("Waiting for tomato classification...");
        while (Serial.available() == 0) {
        // Wait for Serial input
        }

        // Check for Serial input to classify tomato
      if (Serial.available() > 0) {
        tomatoClass = Serial.readStringUntil('\n'); // Read classification input
        tomatoClass.trim(); // Remove whitespace or newline
        Serial.print("Tomato classified as: ");
        Serial.println(tomatoClass);

        // Perform action based on classification
        if (tomatoClass == "R"){
				  servoRed.write(SERVO_ACTIVE); // Move servo to active position
          delay(50);             // Allow movement
        } else if (tomatoClass == "G") {
          servoGreen.write(SERVO_ACTIVE); // Move servo to active position
          delay(50);             // Allow movement                          // Green tomato servo
        } else if (tomatoClass == "Y" || tomatoClass == "D") {
          servoYellow.write(SERVO_ACTIVE); // Move servo to active position
          delay(50);             // Allow movement
      }

      digitalWrite(ENABLE_PIN, LOW); // Enable motor driver
      
      for (int i = 0; i < 300; i++) {
    digitalWrite(STEP_PIN, HIGH);  // Create a step pulse
    delayMicroseconds(500);        // Adjust delay for speed (500 us = 1 kHz)
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(500);        // Adjust delay for speed
  }
      
      digitalWrite(ENABLE_PIN, HIGH);
       /*stepper.moveTo(1000);
       delay(10);
       
        stepper.run();*/
       
      
    }
				
  }
}

// Function to move the specified servo
void moveServo(Servo &servo) {
  servo.write(SERVO_ACTIVE); // Move servo to active position
  delay(500);                // Allow movement
  // servo.write(SERVO_HOME);   // Reset servo to home position
  }


