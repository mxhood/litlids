void setup() {
  pinMode( 6 , OUTPUT);  // Must be a PWM pin
}

void loop() {
  
  analogWrite( 6 , 153 );  // 60% duty cycle
  delay(500);              // play for 0.5s

  analogWrite( 6 , 0 );    // 0% duty cycle (off)
  delay(4000);             // wait for 4s

}
