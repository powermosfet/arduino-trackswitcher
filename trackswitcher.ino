/*
  Track switcher
 */

#include "motor.h"

const int PIN_OBSTACLE_SENSOR = 6;
const int MSEC_MOTOR_RUN_PERIOD = 1000;
const int MOTOR_SPEED = 200;

Motor *switcherMotor;
bool oldObstacleDetected;

void setup() {
  switcherMotor = new Motor(A, FORWARDS);
}

void changeDirection() {
  switcherMotor->changeDirection();
}

void loop() {
  bool newObstacleDetected = !digitalRead(PIN_OBSTACLE_SENSOR);

  if(!oldObstacleDetected && newObstacleDetected) {
    switcherMotor->runFor(MSEC_MOTOR_RUN_PERIOD, MOTOR_SPEED)->then(changeDirection);
  }
  
  switcherMotor->update();

  oldObstacleDetected = newObstacleDetected;
  delay(100);
}
