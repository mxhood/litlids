#include <SoftwareSerial.h>
#define ledPin 9
#define ledPinG 10
#define ledPinO 11

// Choose two pins for SoftwareSerial
SoftwareSerial rSerial(2, 3); // RX, TX

// light output

// touch sensor input

// For SparkFun's tags, we will receive 16 bytes on every
// tag read, but throw four away. The 13th space will always
// be 0, since proper strings in Arduino end with 0

// These constants hold the total tag length (tagLen) and
// the length of the part we want to keep (idLen),
// plus the total number of tags we want to check against (kTags)
const int tagLen = 16;
const int idLen = 13;
const int kTags = 4;

// Put your known tags here!
char knownTags[kTags][idLen] = {
             "111111111111",
             "444444444444",
             "555555555555",
             "7A005B0FF8D6"
};

// Empty array to hold a freshly scanned tag
char newTag[idLen];

// Forcepin info
int forcePin = A0;
int val = 0;

// Scan timer
long scanTime = 0;

// lid status (on = 1, off = 2)
boolean lidOn = false;

void setup() {
  // Starts the hardware and software serial ports
   Serial.begin(9600);
   rSerial.begin(9600);

  // set pin and sensor
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPinG, OUTPUT);
  digitalWrite(ledPinG, LOW);
  pinMode(ledPinO, OUTPUT);
  digitalWrite(ledPinO), LOW);
}

void loop() {
  // Counter for the newTag array
  int i = 0;
  // Variable to hold each byte read from the serial buffer
  int readByte;
  // Flag so we know when a tag is over
  boolean tag = false;

  // This makes sure the whole tag is in the serial buffer before
  // reading, the Arduino can read faster than the ID module can deliver!
  if (rSerial.available() == tagLen) {
    tag = true;
  }

  if (tag == true) {
    while (rSerial.available()) {
      // Take each byte out of the serial buffer, one at a time
      readByte = rSerial.read();

      /* This will skip the first byte (2, STX, start of text) and the last three,
      ASCII 13, CR/carriage return, ASCII 10, LF/linefeed, and ASCII 3, ETX/end of 
      text, leaving only the unique part of the tag string. It puts the byte into
      the first space in the array, then steps ahead one spot */
      if (readByte != 2 && readByte!= 13 && readByte != 10 && readByte != 3) {
        newTag[i] = readByte;
        i++;
      }

      // If we see ASCII 3, ETX, the tag is over
      if (readByte == 3) {
        tag = false;
      }

    }
  }


  // don't do anything if the newTag array is full of zeroes
  if (strlen(newTag)== 0) {
    return;
  }

  else {
    int total = 0;

    for (int ct=0; ct < kTags; ct++){
        total += checkTag(newTag, knownTags[ct]);
    }

    // If newTag matched any of the tags
    // we checked against, total will be 1
    if (total > 0) {

      // OWNER
      // set timer, flash green
      scanTime = millis();
      digitalWrite(ledPinG, HIGH);
      delay(300);
      digitalWrite(ledPinG, LOW);
    }

    else {
        // FALSE
        // flash orange pin
        // set timer to 0
        scanTime = 0;
        digitalWrite(ledPinO, HIGH);
        delay(300);
        digitalWrite(ledPinO, LOW);
      
        // This prints out unknown cards so you can add them to your knownTags as needed
        Serial.print("Unknown tag! ");
        Serial.print(newTag);
        Serial.println();
    }
  }

  // Once newTag has been checked, fill it with zeroes
  // to get ready for the next tag read
  for (int c=0; c < idLen; c++) {
    newTag[c] = 0;
  }

  // Reading the pressure
 val = analogRead(forcePin);
 if (val > 50) {
    // lid is put on
    if (!lidOn) {
      lidOn = true;
    } 
    buffer(50);
 }
 // lid is off
 else {
    // lid was taken off
    if (lidOn) {
      unsigned long currentMillis = millis();
      long diff = currentMillis - scanTime;
      // After scan
      // turn off alarm
      if (diff <= 500) {
        digitalWrite(ledPin, LOW);
      } 
      // Not after scan
      // Turn on alarms, send bluetooth
      else {
        digitalWrite(ledPin, HIGH);
      }
      lidOn = false;
    } 
    buffer(50);
 }
}

// This function steps through both newTag and one of the known
// tags. If there is a mismatch anywhere in the tag, it will return 0,
// but if every character in the tag is the same, it returns 1
int checkTag(char nTag[], char oTag[]) {
    for (int i = 0; i < idLen; i++) {
      if (nTag[i] != oTag[i]) {
        return 0;
      }
    }
  return 1;
}
