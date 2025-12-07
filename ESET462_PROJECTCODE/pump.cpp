#include "Arduino.h"
#include "pump.h"

pump::pump(int in1, int in2) {
    pin1 = in1;
    pin2 = in2;
};

void pump::begin() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);

    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
};

void pump::drive(int pwm) {
    pwm = map(pwm, 0, 100, 0, 255);
    analogWrite(pin1, pwm);
    analogWrite(pin2, 0);
};