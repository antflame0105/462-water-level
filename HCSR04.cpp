#include "HCSR04.h"
#include "Arduino.h"

HCSR04::HCSR04(int triggerPin, int echoPin) {
  trig = triggerPin;
  echo = echoPin;
};

void HCSR04::sound() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(echo, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration*.0343)/2;
};

void HCSR04::begin() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
};

float HCSR04::getDist() {
  return distance;
};
