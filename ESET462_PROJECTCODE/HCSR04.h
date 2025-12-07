#ifndef HCSR04_h
#define HCSR04_h

#include "Arduino.h"
class HCSR04 {
  private:
    float distance, duration;
    int trig, echo;


  public:
    HCSR04(int trigPin, int echoPin);
    void begin();
    void sound();
    float getDist();
};

#endif