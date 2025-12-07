#include "pump.h"
#include "HCSR04.h"

// declare the motors
pump pump1(10, 11);
pump pump2(3, 9);

// declare the sensors
HCSR04 sensor1(5, 4);
HCSR04 sensor2(8, 13);

float Ts = .107;

int kp = 5;
int ki = .1;
int kd = 0.9;

float error, last_error, rate_of_error, cumulative_error; //define error
float u_k;


void setup() {
  //start everything up
  pump1.begin();
  pump2.begin();
  sensor1.begin();
  sensor2.begin();

  Serial.begin(9600);

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1.sound(); //remeasure our distance
  sensor2.sound(); //^cont.

  // // step response code
  // if (error > 0) {
  //   pump1.drive(0);
  //   pump2.drive(0);
  //   pwm = 0;
  // } else if (error < 0) {
  //   pump1.drive(0);
  //   pump2.drive(100);
  //   pwm = 100;

  // } else {
  //   pump1.drive(0);
  //   pump2.drive(0);
  //   pwm = 0;
  // }
  u_k = kp*error + ki*cumulative_error + kd*rate_of_error;

  u_k = constrain(u_k, -100, 100);
  

  if (u_k > 2) {
    u_k = map(u_k, 0, 100, 25, 100);
    pump1.drive(u_k);
    pump2.drive(0);
    Serial.print(u_k);

  } else if (u_k < -2) {
    u_k = map(-u_k, 0, 100, 25, 100);
    pump1.drive(0);
    pump2.drive(u_k); 
    Serial.print(-u_k);

  } else {
    pump1.drive(0);
    pump2.drive(0); 
    Serial.print(u_k);

  }
  
  Serial.print(", ");
  Serial.print(error);

  last_error = error;
  rate_of_error = (error - last_error) / Ts;
  error = sensor1.getDist() - sensor2.getDist();
  cumulative_error += error*Ts;

  Serial.print(", ");
  Serial.print(sensor1.getDist());
  Serial.print(", ");
  Serial.println(sensor2.getDist());
  delay(100);
}
