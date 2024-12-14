const int soundSensorPin = A0; // Analog pin for sound sensor
const int ledPin = 2; // Digital pin for LED

int soundThreshold = 500; // Adjust this value for sensitivity
int clapCount = 0; // Counter for claps
bool ledState = false; // Flag for LED state (on/off)

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int soundValue = analogRead(soundSensorPin); // Read sound sensor value

  // Check if sound value is above threshold
  if (soundValue > soundThreshold) {
    clapCount++;
    Serial.println("Clap detected!");
  }

  // Check for two claps and toggle LED state
  if (clapCount == 2) {
    clapCount = 0; // Reset clap count
    ledState = !ledState; // Toggle LED state
    digitalWrite(ledPin, ledState); // Turn LED on/off
    
    if (ledState) {
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF");
    }
  }

  delay(100); // Small delay for stability
}