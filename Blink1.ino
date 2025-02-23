
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i=2;i<=4;i++){
  digitalWrite(i, HIGH);            // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(i, LOW);             // turn the LED off by making the voltage LOW
  delay(1000); 
}              
                                  // wait for a second
}
