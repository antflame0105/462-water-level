#ifndef pump_h
#define pump_h

#include "Arduino.h"

class pump {
  public:
    pump(int in1, int in2);
    void begin();
    void drive(int pwm);
  private:
    int pin1, pin2;
};

#endif