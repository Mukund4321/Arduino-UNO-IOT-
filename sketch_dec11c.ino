const int trigPin = 3;
const int echoPin = 6;

// defines variables
float duration;
float distance;

/* Statements in the setup() function are run only once */
void setup() {
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	Serial.begin(9600); // Starts the serial communication
}

/* Statements in the loop() function will run repeatedly till interrupted */
void loop() {

	digitalWrite(trigPin, LOW);	// Clears the trigPin
	delayMicroseconds(2);		// Pauses the program for 2 microseconds

	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);			// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, LOW);

	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculating the distance
	distance= duration*0.034/2;

	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);
	delay(200);
}