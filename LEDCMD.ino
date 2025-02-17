#define PIN_LED 4 // D4

void setup() {
  // Initialize serial port
  Serial.begin(9600);
  Serial.println("Ready to receive commands.");

  // Configure D4 as output pin and start with LED OFF condition
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {

  // Check if serial data is available
  if (Serial.available() > 0) {

    // Read command from serial port
    String cmd = Serial.readStringUntil('\n');
    //Serial.println(cmd);

    if (cmd.equals("on")) {  
      // Turn the LED ON
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED is turned ON");
    }
    else if (cmd.equals("off")) {
      // Turn the LED OFF
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED is turned OFF");
    }
    else {
      Serial.println("Please enter valid input (on or off)");
    }
  }

delay(100);
}