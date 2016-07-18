/*
  Track switcher
 */

#include "motor.h"
#include "pin.h"

const int PIN_OBSTACLE_SENSOR = 6;
const int MSEC_MOTOR_RUN_PERIOD = 1000;
const int MOTOR_SPEED = 255;

Motor *switcherMotor;
Pin *irSensor;

void changeDirection() {
  switcherMotor->changeDirection();
}

void runMotor() {
  switcherMotor->runFor(MSEC_MOTOR_RUN_PERIOD, MOTOR_SPEED)->then(changeDirection);
}

void setup() {
  switcherMotor = new Motor(A, FORWARDS);
  irSensor = new Pin(PIN_OBSTACLE_SENSOR);
  irSensor->onEdge(FALLING_EDGE, runMotor);
}

void loop() {
  irSensor->update();
  switcherMotor->update();

  delay(100);
}
