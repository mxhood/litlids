#define ledPin 13
#define button 8

int state = 0;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0') {
  digitalWrite(ledPin, LOW); // LED ON
  state = 0;
 }
 
 // Reading the button
 buttonState = digitalRead(button);
 if (buttonState == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on LED
 }
 else {
   Serial.write('0');
 }  
}
