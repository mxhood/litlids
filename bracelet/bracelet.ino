#define ledPin 8
#define button 2
#define motorPin 4

int buttonState = 0;
int currentState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(motorPin, OUTPUT);
}
  
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if ((buttonState == HIGH) && (currentState == 0)) {
        buttonState == LOW;
        currentState = 1;
        for (int i=0; i<20; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          //vib_pattern(1000, 750, 500, 250, 255, 127);
          digitalWrite(ledPin, LOW);
          delay(500);
          if (currentState == 1) {
            if (buttonState == HIGH) {
              currentState = 0;
            }
          }
    }
    }
}

//two different durations, intensities, and gap lengths
//x = gap length 1, y = gap length 2
//z = duration 1, q = duration 2
//a = intensity 1, b = intensity 2
void vib_pattern(int x, int y, int z, int q, int a, int b) {
  analogWrite(motorPin, 0);
  delay(x);
  analogWrite(motorPin, a);
  delay(z);
  analogWrite(motorPin, 0);
  delay(y);
  analogWrite(motorPin, b);
  delay(q);
}
