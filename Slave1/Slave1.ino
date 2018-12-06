//WORKER ADDRESS
//98d3:41:fd33ba
#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);
#define ledPin 9

int forcePin = A0;
int val = 0;
char state = '0';

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
  BTserial.begin(38400);
}

void loop() {
 if(BTserial.available() > 0){ // Checks whether data is comming from the serial port
    state = BTserial.parseInt(); // Reads the data from the serial port
    Serial.print("**************");
    buffer(50);
 }
 
// Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, LOW); // LED OFF
 } else {
  digitalWrite(ledPin, LOW); // LED OFF
  Serial.write(state);
 }
 
 // Reading the pressure
 val = analogRead(forcePin);
 if (val > 50) {
    BTserial.write('1'); // Sends '1' to the master to turn on LED
    Serial.write('1');
 }
 else {
    BTserial.write('0'); 
 }
}
