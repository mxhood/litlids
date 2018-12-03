const int motorPin = 5;

void setup() {
  pinMode( motorPin , OUTPUT);  // Must be a PWM pin
}

void loop() {
  
 int x;

 for( x = 0 ; x < 154 ; x++ ) {

    
     analogWrite( motorPin , x );

 }

 analogWrite( motorPin , 0 );

 delay(3000);

}

