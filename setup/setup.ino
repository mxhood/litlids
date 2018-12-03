//WORKER ADDRESS
//98d3:41:fd33ba

#define ledPin 9

int forcePin = A0;
int val = 0;
int state = 0;

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
 
 // Reading the pressure
 val = analogRead(forcePin);
 if (val > 10) {
   Serial.write('1'); // Sends '1' to the master to turn on LED
 }
 else {
 Serial.write('0'); }  
}
