int forcePin = A0;
int val = 0;
int maxVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // baud rate of our bluetooth module
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(forcePin);
  //Serial.println(val);
  delay(250);

  if (val > maxVal) {
    maxVal = val;
  }

  if (val == 0) {
    Serial.println(maxVal);
  }

}


