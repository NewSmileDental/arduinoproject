#include <Servo.h>

Servo myServo;                 // Create a Servo object
Servo myServo2;
const int rainSensorPin = A3;  // Pin connected to the rain sensor
const int servoPin = 9;  
const int servoPin2 = 6;      // Pin connected to the servo
const int ledPin = 4;         // Pin connected to the LED

bool lastWaterDetected = false; // Variable to track last water detection

void setup() {
  myServo.attach(servoPin);    // Attach the servo to the designated pin 
  myServo2.attach(servoPin2);
  pinMode(rainSensorPin, INPUT); // Set the rain sensor pin as input
  pinMode(ledPin, OUTPUT);       // Set the LED pin as output
}

void loop() {

  int rainState = digitalRead(rainSensorPin); // Read the state of the rain sensor

  if (rainState == HIGH) { // If water is detected


    if (!lastWaterDetected) {
      myServo.attach(servoPin); // Attach servo only if it wasn't previously attached
      myServo2.attach(servoPin2);
      lastWaterDetected = true;
    }

    digitalWrite(ledPin, LOW); // Turn off the LED

    myServo.write(180);    // Rotate the servo in one direction 
    myServo2.write(180); 
    delay(180);           // Rotate for 170 milliseconds (adjust as necessary)
    myServo.detach();      // Detach the 
    delay(200);           // Rotate for 170 milliseconds (adjust as necessary)
    myServo2.detach();      // Detach the servo
   
 

  } else if (lastWaterDetected) { // If no water is detected and it was previously detected

    digitalWrite(ledPin, HIGH); // Turn on the LED
    lastWaterDetected = false; // Update the state

    myServo.attach(servoPin); // Attach servo only if it wasn't previously attached
    myServo.write(0);       // Rotate in the opposite direction to return
    delay(170);            // Rotate for 170 milliseconds (adjust as necessary)
    myServo.detach();      // Detach the servo

    myServo2.attach(servoPin2); // Attach servo only if it wasn't previously attached
    myServo2.write(0);    // Rotate the servo in one direction 
    delay(400);           // Rotate for 400 milliseconds (adjust as necessary)
    myServo2.detach();      // Detach the servo

    


  }

  // delay(100); // Small delay to avoid rapid toggling
}