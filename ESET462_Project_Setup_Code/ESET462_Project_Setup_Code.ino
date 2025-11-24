#include "pump.h"
#include "HCSR04.h"

// declare the motors
pump pump1(10, 11);
pump pump2(3, 9);

// declare the sensors
HCSR04 sensor1(4, 5);
HCSR04 sensor2(7, 6);


float error; //define error

void setup() {
  //start everything up
  pump1.begin();
  pump2.begin();
  sensor1.begin();
  sensor2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1.sound(); //remeasure our distance
  sensor2.sound(); //^cont.

  pump1.drive(50); //ex for driving at 50% duty cycle

  error = sensor1.getDist() - sensor2.getDist();
  delay(100);
}
