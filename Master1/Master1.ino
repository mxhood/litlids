#define ledPin 13
#define button 8

int state = '0';
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
  state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
 }
 else {
  digitalWrite(ledPin, LOW); // LED ON
 }

buttonState = digitalRead(button);
if (buttonState == HIGH) {
  Serial.write('1'); // signal turns everything off. 
}


 // Reading the button
// buttonState = digitalRead(button);
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
//  if (buttonState == HIGH && previous == 0 && millis() - time > debounce) {
//    if (lightState == 1)
//      lightState = 0;
//    else
//      lightState = 1;
//
//    time = millis();    
//  }
//  Serial.write(lightState);
//  previous = buttonState;

//if (buttonState == HIGH) {
//  if (lastState == 0) {
//    Serial.write('1');
//    lastState = 1;
//  } else {
//    Serial.write('0');
//    lastState = 0;
//  }
//} 
//delay(200);

// 
// if (buttonState == HIGH && !currentState) {
//   Serial.write('1'); // Sends '1' to the master to turn on LED
//   currentState = true;
//   delay(50)
// }
// if (buttonState == HIGH && currentState) {
//   Serial.write('0');
//   currentState = false;
// }  
}
