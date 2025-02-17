// Define pins
const int pirSensorPin = 2; // PIR sensor OUT pin connected to D2
const int ledPin = 13;       // LED connected to D7

void setup() {
  pinMode(pirSensorPin, INPUT); // PIR sensor pin as input
  pinMode(ledPin, OUTPUT);      // LED pin as output
  Serial.begin(9600);           // Initialize serial monitor
}

void loop() {
  int motionState = digitalRead(pirSensorPin); // Read motion sensor state
  
  if (motionState == HIGH) { // Motion detected
    Serial.println("Motion Detected - LED Blinking");
    for (int i = 0; i < 5; i++) { // LED blinks 5 times per detection
      digitalWrite(ledPin, HIGH); // Turn LED ON
      delay(200);                 // Delay for 200 ms
      digitalWrite(ledPin, LOW);  // Turn LED OFF
      delay(200);                 // Delay for 200 ms
    }
  } else {
    Serial.println("No Motion - LED OFF");
    digitalWrite(ledPin, LOW);    // Ensure LED is OFF when no motion
  }
}
