#include <Arduino.h>

int redLED = D1;
int yellowLED = D2;
int greenLED = D0;

// // put function declarations here:
// int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(1000);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(5000);
  digitalWrite(greenLED, LOW);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}