#define ledPin 8
#define button 2

int buttonState = 0;
int currentState = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}
  
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    if (currentState == 1) {
      digitalWrite(ledPin, LOW);
      currentState = 0;
    } else {
      digitalWrite(ledPin, HIGH);
      currentState = 1;
    }
  }
}
