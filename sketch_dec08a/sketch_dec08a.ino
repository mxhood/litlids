int forcePin = A0;
long val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(forcePin);
  Serial.println(val);
  delay(250);
}
