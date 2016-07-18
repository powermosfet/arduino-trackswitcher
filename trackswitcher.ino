/*
  Track switcher
 */

#include "motor.h"
#include "pin.h"

const int PIN_OBSTACLE_SENSOR = 6;
const int RUN_TIME            = 1000;
const int MOTOR_SPEED         = 255;

Motor switcherMotor(A, FORWARDS);
Pin irSensor(PIN_OBSTACLE_SENSOR);

void setup() {
  irSensor.onEdge(FALLING_EDGE, [](){
    switcherMotor.runFor(RUN_TIME, MOTOR_SPEED).then([](){
      switcherMotor.changeDirection();
    });
  });
}

void loop() {
  irSensor.update();
  switcherMotor.update();

  delay(100);
}
